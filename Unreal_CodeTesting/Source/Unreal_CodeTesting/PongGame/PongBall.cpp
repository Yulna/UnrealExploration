// Fill out your copyright notice in the Description page of Project Settings.


#include "PongBall.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
APongBall::APongBall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BallMesh"));
	BallMesh->SetupAttachment(RootComponent);
	
	BallMesh->OnComponentBeginOverlap.AddUniqueDynamic(this, &APongBall::OnComponentBeginOverlap);
	//BallMesh->OnComponentHit.AddUniqueDynamic(this, &APongBall::OnComponentHit);

	BallMesh->SetCollisionEnabled(ECollisionEnabled::Type::QueryAndPhysics);
	BallMesh->SetCollisionProfileName(FName(TEXT("OverlapAll")));
	BallMesh->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	//BallMesh->SetCollisionProfileName(FName(TEXT("BlockAll")));

}

// Called when the game starts or when spawned
void APongBall::BeginPlay()
{
	Super::BeginPlay();
	StartMovementDelayed(StartDelay);
}

// Called every frame
void APongBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (ShouldMove)
	{
		AddActorWorldOffset(Direction * Speed, true);
	}
}

// Y - Side
// X - Up/down
void APongBall::StartMovement()
{
	PickRandomDirection();
	ShouldMove = true;
}

void APongBall::StartMovementDelayed(float Delay)
{
	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, [&]() {
		StartMovement();
		}, Delay, false);
}

void APongBall::PickRandomDirection()
{
	int32 Side = FMath::RandRange(0, 1) ? 1 : -1;

	float RandAngle = FMath::RandRange(UE_PI / 16, (15 * UE_PI) / 16);
	Direction.X = cos(RandAngle);
	Direction.Y = Side * sin(RandAngle);

	Direction.Normalize();
}

void APongBall::ResetBall()
{
	SetActorLocation(FVector::ZeroVector);
	ShouldMove = false;
	StartMovementDelayed(StartDelay); 
}


void APongBall::OnComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	//GEngine->AddOnScreenDebugMessage(-1, 999.0f, FColor::Silver, TEXT("Bouncing"));
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, TEXT("Bouncing"));

	//GEngine->AddOnScreenDebugMessage(-1, 999.0f, FColor::Blue, FString::Printf(TEXT("Normals: x-%.8f y-%.8f z-%.8f"), Hit.Normal.X, Hit.Normal.Y, Hit.Normal.Z));
	//GEngine->AddOnScreenDebugMessage(-1, 999.0f, FColor::Blue, FString::Printf(TEXT("NormalImpulse: x-%.8f y-%.8f z-%.8f"), NormalImpulse.X, NormalImpulse.Y, NormalImpulse.Z));

	

	//Direction.X *= -1;
}

void APongBall::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{


	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Purple, TEXT("Bouncing"));


	if (OtherActor->Tags.Contains(FName("Player")))
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, TEXT("Player hit"));
		
		Direction = CalculateDirectionChange(OtherActor, SweepResult.ImpactPoint);
		//Direction.Y *= -1;
		return;
	}
	
	if (OtherActor->Tags.Contains(FName("Goal")))
	{
		ResetBall();
	}

	Direction.X *= -1;
}

FVector APongBall::CalculateDirectionChange(AActor* PlayerActor, FVector ImpactPoint)
{
	FVector NewDirection = FVector::ZeroVector;

	FBox BoudingBox = PlayerActor->GetComponentsBoundingBox();
	FVector Center = BoudingBox.GetCenter();
	FVector Extends = BoudingBox.GetExtent();
	GEngine->AddOnScreenDebugMessage(-1, 999.0f, FColor::Orange, FString::Printf(TEXT("ImpactPoint: %f | %f | %f"), ImpactPoint.X, ImpactPoint.Y, ImpactPoint.Z));

	float DistanceX = abs(Center.X - ImpactPoint.X);
	float Percentile = (Extends.X - DistanceX) / Extends.X;


	float Angle = (UE_PI / 8) + (((UE_PI * .5f) - (UE_PI / 8)) * Percentile);

	//Invert angle in Y axis
	/*if (ImpactPoint.X < Center.X)
	{
		Angle = UE_PI - Angle;
	}*/

	int sign = (Direction.Y > 0) ? 1 : -1;
	GEngine->AddOnScreenDebugMessage(-1, 999.0f, FColor::Orange, FString::Printf(TEXT("Percentile: %f"), Percentile));

	GEngine->AddOnScreenDebugMessage(-1, 999.0f, FColor::Orange, FString::Printf(TEXT("Angle: %frad  -  %fdeg"), Angle, (Angle*180)/UE_PI));

	GEngine->AddOnScreenDebugMessage(-1, 999.0f, FColor::Orange, FString::Printf(TEXT("Direction Y: %f"), Direction.Y));

	GEngine->AddOnScreenDebugMessage(-1, 999.0f, FColor::Orange, FString::Printf(TEXT("Y Sign: %i"), sign));

	NewDirection.X = cos(Angle) /* (Percentile > .9) ? -1 : 1*/;
	NewDirection.Y = sin(Angle) * (Direction.Y > 0) ? -1 : 1;
	NewDirection.Normalize();

	return NewDirection;
}


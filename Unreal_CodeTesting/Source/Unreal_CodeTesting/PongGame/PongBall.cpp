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
	
	//BallMesh->OnComponentBeginOverlap.AddUniqueDynamic(this, &APongBall::OnComponentBeginOverlap);
	BallMesh->OnComponentHit.AddUniqueDynamic(this, &APongBall::OnComponentHit);

	BallMesh->SetCollisionEnabled(ECollisionEnabled::Type::QueryAndPhysics);
	//BallMesh->SetCollisionProfileName(FName(TEXT("OverlapAll")));
	BallMesh->SetCollisionProfileName(FName(TEXT("BlockAll")));

}

// Called when the game starts or when spawned
void APongBall::BeginPlay()
{
	Super::BeginPlay();


	Direction.X = FMath::RandRange(-1, 1);
	Direction.Y = FMath::RandRange(-1, 1);
	Direction.Normalize();

	
	

	//UStaticMeshComponent* mesh = FindComponentByClass<UStaticMeshComponent>();
	//mesh->OnComponentHit.Add(this, &APongBall::OnComponentHit);

}

// Called every frame
void APongBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	AddActorWorldOffset(Direction * Speed);

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
		Direction.Y *= -1;

	}
	
	if (OtherActor->Tags.Contains(FName("Goal")))
	{

	}


	//GEngine->AddOnScreenDebugMessage(-1, 999.0f, FColor::Blue, FString::Printf(TEXT("Normals: x-%.8f y-%.8f z-%.8f"), SweepResult.Normal.X, SweepResult.Normal.Y, SweepResult.Normal.Z));
	//Direction = SweepResult.Normal;

	Direction.X *= -1;
}


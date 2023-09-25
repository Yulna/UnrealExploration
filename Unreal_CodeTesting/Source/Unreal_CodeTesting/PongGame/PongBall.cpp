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

	Direction.X *= -1;
}

void APongBall::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{


	Direction.X *= -1;
}


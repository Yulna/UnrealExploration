// Fill out your copyright notice in the Description page of Project Settings.


#include "PongGame/PongGoal.h"
#include "Components/StaticMeshComponent.h"
#include "PongGameState.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
APongGoal::APongGoal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GoalMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BallMesh"));
	GoalMesh->SetupAttachment(RootComponent);

	GoalMesh->OnComponentBeginOverlap.AddUniqueDynamic(this, &APongGoal::OnComponentBeginOverlap);
	//GoalMesh->OnComponentHit.AddUniqueDynamic(this, &APongGoal::OnComponentHit);

}

// Called when the game starts or when spawned
void APongGoal::BeginPlay()
{
	Super::BeginPlay();
	


}

// Called every frame
void APongGoal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APongGoal::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, TEXT("Goal start"));

	if (OtherActor->Tags.Contains(FName("Ball")))
	{ 
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, TEXT("Goal made"));
		APongGameState* pongGameState = (APongGameState*)UGameplayStatics::GetGameState(this);
		pongGameState->ScorePoints(PlayerId, 1);
	}
}


// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PongGoal.generated.h"

UCLASS()
class UNREAL_CODETESTING_API APongGoal : public AActor
{
	GENERATED_BODY()

public: //properties

	UPROPERTY(VisibleAnywhere)
	int PlayerId = 0;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* GoalMesh = nullptr;

public:	
	// Sets default values for this actor's properties
	APongGoal();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UFUNCTION()
	void OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


};

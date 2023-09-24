// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PongBall.generated.h"

class UStaticMeshComponent;

UCLASS()
class UNREAL_CODETESTING_API APongBall : public AActor
{	
	GENERATED_BODY()

public:
	
	UPROPERTY(VisibleAnywhere, Category = "GameData|Debug")
	FVector Direction = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, Category = "GameData")
	float Speed = 0.0f;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BallMesh = nullptr;
	

public:	
	APongBall();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;


private:

	UFUNCTION()
	void OnComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

};

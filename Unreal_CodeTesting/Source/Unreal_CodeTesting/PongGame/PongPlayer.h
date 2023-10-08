// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PongPlayer.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class UStaticMeshComponent;

UCLASS()
class UNREAL_CODETESTING_API APongPlayer : public APawn
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* PongMappingContext = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction = nullptr;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* PaddleMesh = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	int PlayerIndex = 0;

	UPROPERTY(EditAnywhere, Category = "GameData")
	float Speed = 1.0f;



public:
	// Sets default values for this pawn's properties
	APongPlayer();

	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


protected:

	void Move(const FInputActionValue& Value);


};

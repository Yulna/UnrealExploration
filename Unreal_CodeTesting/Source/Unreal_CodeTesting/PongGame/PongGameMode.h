// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "PongGameMode.generated.h"

class UInputMappingContext;
class APongPlayer;
class APongGoal;
/**
 * 
 */
UCLASS()
class UNREAL_CODETESTING_API APongGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 PlayersNum = 2;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<APongPlayer> PlayerType = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<APongGoal> GoalBlueprint = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UInputMappingContext* PongMappingContextPlayer1 = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UInputMappingContext* PongMappingContextPlayer2 = nullptr;

public:

	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;
	
	virtual void BeginPlay() override;

	void SpawnBall();	


private:

	void CreateAdditionalControllers();

	void SpawnPlayers();

	void SpawnGoal(FVector playerLocation, int32 playerId);

};

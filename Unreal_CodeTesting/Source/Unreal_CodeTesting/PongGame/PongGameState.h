// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "PongGameState.generated.h"

/**
 * 
 */
UCLASS()
class UNREAL_CODETESTING_API APongGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:

	UPROPERTY(VisibleAnywhere)
	TMap<int32, int> playersPoints;


public:

	virtual void HandleBeginPlay();


	void RegisterPlayer(int32 playerId);

	void ScorePoints(int32 playerId, int points);

};

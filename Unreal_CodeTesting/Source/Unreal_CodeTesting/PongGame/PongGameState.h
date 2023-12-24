#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "PongGameState.generated.h"


DECLARE_MULTICAST_DELEGATE_TwoParams(FOnScorePoints, int32, int);


UCLASS()
class UNREAL_CODETESTING_API APongGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:

	UPROPERTY(VisibleAnywhere)
	TMap<int32, int> playersPoints;

	FOnScorePoints OnScorePoints;


public:

	virtual void HandleBeginPlay();

	void RegisterPlayer(int32 playerId);

	void ScorePoints(int32 playerId, int points);

};

// Fill out your copyright notice in the Description page of Project Settings.


#include "PongGame/UI/PongHUDScore.h"
#include "PongGame/PongGameState.h"

#include "Kismet/GameplayStatics.h"


void UPongHUDScore::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	APongGameState* pongGameState = Cast<APongGameState>(UGameplayStatics::GetGameState(this));

	if (!pongGameState) 
	{
		return;
	}
	pongGameState->OnScorePoints.AddUObject(this, &UPongHUDScore::OnScoreUpdate);

}

void UPongHUDScore::RegisterId(int32 PlayerId, FName PlayerTag)
{
	if (!PlayersTag.Contains(PlayerId))
	{
		PlayersTag.Add(PlayerId, PlayerTag);
	}
}



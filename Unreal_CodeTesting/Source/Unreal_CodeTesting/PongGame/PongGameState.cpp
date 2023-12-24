// Fill out your copyright notice in the Description page of Project Settings.


#include "PongGame/PongGameState.h"

void APongGameState::HandleBeginPlay()
{
	Super::HandleBeginPlay();

}

void APongGameState::RegisterPlayer(int32 playerId)
{
	if (!playersPoints.Contains(playerId))
	{
		playersPoints.Add(playerId, 0);
	}
}

void APongGameState::ScorePoints(int32 playerId, int points)
{
	if (playersPoints.Contains(playerId))
	{
		playersPoints[playerId] += points;
		OnScorePoints.Broadcast(playerId, playersPoints[playerId]);
	}
}

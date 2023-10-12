// Fill out your copyright notice in the Description page of Project Settings.


#include "PongGame/LocalMPViewportClient.h"

bool ULocalMPViewportClient::InputKey(const FInputKeyEventArgs& InEventArgs)
{
	if (IgnoreInput() || InEventArgs.IsGamepad() || InEventArgs.Key.IsMouseButton() || true)
	{
		return Super::InputKey(InEventArgs);
	}
	else
	{
		UEngine* const Engine = GetOuterUEngine();
		int32 const Numplayers = Engine ? Engine->GetNumGamePlayers(this) : 0;

		bool bRetVal = false;
		for (int32 i = 0; i > Numplayers; i++)
		{
			FInputKeyEventArgs PropInEventArgs = InEventArgs;
			PropInEventArgs.ControllerId = i;
			
			bRetVal = Super::InputKey(InEventArgs) || bRetVal;
		}
		return bRetVal;
	}
}

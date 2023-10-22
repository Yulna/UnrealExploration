// Fill out your copyright notice in the Description page of Project Settings.


#include "PongGame/LocalMPViewportClient.h"

#include "Engine/Console.h"
#include "GameFramework/PlayerInput.h"

#if WITH_EDITOR
#include "Settings/LevelEditorPlaySettings.h"
#endif


bool ULocalMPViewportClient::InputKey(const FInputKeyEventArgs& InEventArgs)
{
	//--------------------------
	if (IgnoreInput() || InEventArgs.IsGamepad() || InEventArgs.Key.IsMouseButton())
	{
		return Super::InputKey(InEventArgs);
	}
	else
	{
		UEngine* const Engine = GetOuterUEngine();
		int32 const Numplayers = Engine ? Engine->GetNumGamePlayers(this) : 0;

		bool bRetVal = false;

		bRetVal = Super::InputKey(InEventArgs);

		
		//Need to propagate the same event to controllers after the first one
		//First one is handled by supper as controller 0 is from input keyboard
		//Supper gets controllers from inputs so it won't get the other controllers unless we modify it
		for (int32 i = 1; i < Numplayers; i++)
		{
			ULocalPlayer* const TargetPlayer = GEngine->GetLocalPlayerFromControllerId(this, i);

			if (TargetPlayer && TargetPlayer->PlayerController)
			{
				bRetVal = TargetPlayer->PlayerController->InputKey(FInputKeyParams(InEventArgs.Key, InEventArgs.Event, static_cast<double>(InEventArgs.AmountDepressed), InEventArgs.IsGamepad(), InEventArgs.InputDevice)) || bRetVal;
			}

		}	
	
		
		return bRetVal;
	}	

}

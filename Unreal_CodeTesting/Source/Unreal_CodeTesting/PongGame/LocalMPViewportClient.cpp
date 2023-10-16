// Fill out your copyright notice in the Description page of Project Settings.


#include "PongGame/LocalMPViewportClient.h"

#include "Engine/Console.h"
#include "GameFramework/PlayerInput.h"

#if WITH_EDITOR
#include "Settings/LevelEditorPlaySettings.h"
#endif


bool ULocalMPViewportClient::InputKey(const FInputKeyEventArgs& InEventArgs)
{
	
	if (IgnoreInput() || InEventArgs.IsGamepad() || InEventArgs.Key.IsMouseButton())
	{
		return Super::InputKey(InEventArgs);
	}
	else
	{
		UEngine* const Engine = GetOuterUEngine();
		int32 const Numplayers = Engine ? Engine->GetNumGamePlayers(this) : 0;

		bool bRetVal = false;


		
		for (int32 i = 0; i < Numplayers; i++)
		{
			ULocalPlayer* const TargetPlayer = GEngine->GetLocalPlayerFromControllerId(this, i);

			if (TargetPlayer && TargetPlayer->PlayerController)
			{
				TargetPlayer->PlayerController->InputKey(FInputKeyParams(InEventArgs.Key, InEventArgs.Event, static_cast<double>(InEventArgs.AmountDepressed), InEventArgs.IsGamepad(), InEventArgs.InputDevice));
			}

		}
		

		
		/*for (int32 i = 0; i < Numplayers; i++)
		{
			FInputKeyEventArgs PropInEventArgs = InEventArgs;
			PropInEventArgs.ControllerId = i;
			

			bRetVal = Super::InputKey(PropInEventArgs) || bRetVal;
		}*/
		
		return bRetVal;
	}	

}

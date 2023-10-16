// Fill out your copyright notice in the Description page of Project Settings.


#include "PongGame/LocalMPPlayerController.h"


#include "GameFramework/PlayerInput.h"
#include "IXRTrackingSystem.h"
#include "IXRInput.h"
#include "GameFramework/HUD.h"

bool ALocalMPPlayerController::InputKey(const FInputKeyParams& Params)
{
	bool bResult = false;


	// Any analog values can simply be passed to the UPlayerInput
	if (Params.Key.IsAnalog())
	{
		if (PlayerInput)
		{
			bResult = PlayerInput->InputKey(Params);
		}
	}
	// But we need special case XR handling for non-analog values...
	else
	{
		if (GEngine->XRSystem.IsValid())
		{
			auto XRInput = GEngine->XRSystem->GetXRInput();
			if (XRInput && XRInput->HandleInputKey(PlayerInput, Params.Key, Params.Event, Params.Delta.X, Params.IsGamepad()))
			{
				return true;
			}
		}

		if (PlayerInput)
		{
			bResult = PlayerInput->InputKey(Params);
			if (bEnableClickEvents && (ClickEventKeys.Contains(Params.Key) || ClickEventKeys.Contains(EKeys::AnyKey)))
			{
				FVector2D MousePosition;
				UGameViewportClient* ViewportClient = CastChecked<ULocalPlayer>(Player)->ViewportClient;
				if (ViewportClient && ViewportClient->GetMousePosition(MousePosition))
				{
					UPrimitiveComponent* ClickedPrimitive = nullptr;
					if (bEnableMouseOverEvents)
					{
						ClickedPrimitive = CurrentClickablePrimitive.Get();
					}
					else
					{
						FHitResult HitResult;
						const bool bHit = GetHitResultAtScreenPosition(MousePosition, CurrentClickTraceChannel, true, HitResult);
						if (bHit)
						{
							ClickedPrimitive = HitResult.Component.Get();
						}
					}
					if (GetHUD())
					{
						if (GetHUD()->UpdateAndDispatchHitBoxClickEvents(MousePosition, Params.Event))
						{
							ClickedPrimitive = nullptr;
						}
					}

					if (ClickedPrimitive)
					{
						switch (Params.Event)
						{
						case IE_Pressed:
						case IE_DoubleClick:
							ClickedPrimitive->DispatchOnClicked(Params.Key);
							break;

						case IE_Released:
							ClickedPrimitive->DispatchOnReleased(Params.Key);
							break;

						case IE_Axis:
						case IE_Repeat:
							break;
						}
					}

					bResult = true;
				}
			}
		}
	}

	return bResult;
}

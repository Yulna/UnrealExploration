// Copyright Epic Games, Inc. All Rights Reserved.

#include "Unreal_CodeTestingGameMode.h"
#include "Unreal_CodeTestingCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUnreal_CodeTestingGameMode::AUnreal_CodeTestingGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

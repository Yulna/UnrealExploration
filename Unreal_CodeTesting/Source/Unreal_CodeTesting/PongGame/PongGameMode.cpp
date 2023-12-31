// Fill out your copyright notice in the Description page of Project Settings.


#include "PongGame/PongGameMode.h"

#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerState.h"
#include "GameFramework/PlayerStart.h"
#include "PongPlayer.h"
#include "PongGoal.h"
#include "PongGame/UI/PongHUDGlobalWidget.h"
#include "PongGame/UI/PongHUDScore.h"

#include "EnhancedInputSubsystems.h"

void APongGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);


}

void APongGameMode::BeginPlay()
{
	Super::BeginPlay();	
	CreateUI();
	CreateAdditionalControllers();
	SpawnPlayers();
}

void APongGameMode::SpawnBall()
{


}

void APongGameMode::CreateUI()
{
	GlobalWidget = CreateWidget<UPongHUDGlobalWidget>(GetWorld(), *GlobalWidgetClass);
	GlobalWidget->AddToViewport(100);
}

void APongGameMode::CreateAdditionalControllers()
{
	for (int32 Index = 1; Index < PlayersNum; ++Index)
	{
		constexpr bool bSpawnPlayerController = true;
		APlayerController* NewPlayerController = UGameplayStatics::CreatePlayer(this, Index, bSpawnPlayerController);

		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Emerald, FString::Printf(TEXT("APongGamemode::Creating new controller")));
		UE_LOG(LogTemp, Warning, TEXT("APongGamemode::Creating new controller"));
	}
}

void APongGameMode::SpawnPlayers()
{
	TArray<AActor*> PlayerStarts;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerStart::StaticClass(), PlayerStarts);

	for (int32 i = 0; i < PlayerStarts.Num(); i++)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Cyan, FString::Printf(TEXT("APongGamemode::Creating new players:%i"), i));

		FVector Location = PlayerStarts[i]->GetTransform().GetLocation();
		FRotator Rotator = PlayerStarts[i]->GetTransform().Rotator();

		APongPlayer* NewPlayer = GetWorld()->SpawnActor<APongPlayer>(PlayerType, Location, Rotator);

		TArray<class ULocalPlayer*> LocalPlayers = GetGameInstance()->GetLocalPlayers();
		if (i < LocalPlayers.Num())
		{
			APlayerController* PlayerController = LocalPlayers[i]->GetPlayerController(GetWorld());

			if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
			{
				GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Cyan, FString::Printf(TEXT("APongGamemode::Assigning input for player:%i"), i));
				if (i == 0)
				{
					Subsystem->AddMappingContext(PongMappingContextPlayer1, 0);
				}
				else
				{
					Subsystem->AddMappingContext(PongMappingContextPlayer2, 0);
				}
			}
			PlayerController->Possess(NewPlayer);
			SpawnGoal(Location, PlayerController->PlayerState->GetPlayerId(), Cast<APlayerStart>(PlayerStarts[i])->PlayerStartTag);
			if (GlobalWidget)
			{
				GlobalWidget->HUDScore->RegisterId(PlayerController->PlayerState->GetPlayerId(), Cast<APlayerStart>(PlayerStarts[i])->PlayerStartTag);
			}
		}
	}
}

void APongGameMode::SpawnGoal(FVector PlayerLocation, int32 PlayerId, FName PlayerTag)
{
	FVector SpawnLocation = DisplacePlayerGoal(PlayerLocation, PlayerTag);	
	APongGoal* NewGoal = GetWorld()->SpawnActor<APongGoal>(GoalBlueprint, SpawnLocation, FRotator::ZeroRotator);
	NewGoal->PlayerId = PlayerId;
}

FVector APongGameMode::DisplacePlayerGoal(FVector Location, FName PlayerTag)
{
	if (PlayerTag == "Player1")
	{
		Location.Y -= GoalDisplacement;
	}
	if (PlayerTag == "Player2")
	{
		Location.Y += GoalDisplacement;
	}
	return Location;
}

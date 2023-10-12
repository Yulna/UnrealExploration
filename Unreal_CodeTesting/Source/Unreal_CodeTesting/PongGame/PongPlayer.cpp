// Fill out your copyright notice in the Description page of Project Settings.


#include "PongGame/PongPlayer.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PongPlayer.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
APongPlayer::APongPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PaddleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlayerPaddle"));
	PaddleMesh->SetupAttachment(RootComponent);	

}

// Called when the game starts or when spawned
void APongPlayer::BeginPlay()
{
	Super::BeginPlay();
	


	//APlayerController* PlayerController = nullptr;
	


	//TArray<class ULocalPlayer*> LocalPlayers = GetGameInstance()->GetLocalPlayers();

	/*
	if (LocalPlayers.Num() <= PlayerIndex)
	{

		FString Error;
		ULocalPlayer* LocalPlayer = GetGameInstance()->CreateLocalPlayer(FGenericPlatformMisc::GetPlatformUserForUserIndex(PlayerIndex), Error, true);
		PlayerController = LocalPlayer->PlayerController;


		GEngine->AddOnScreenDebugMessage(-1, 999.0f, FColor::Green, FString::Printf(TEXT("APongPlayer::Creating player:%i"), PlayerIndex));

		UE_LOG(LogTemp, Warning, TEXT("APlayer::Error %s"), *Error);
	}
	else 
	{
		PlayerController = GetGameInstance()->GetLocalPlayers()[PlayerIndex]->PlayerController;
	}
	*/
	/*
	if (GetGameInstance()->GetLocalPlayers().Num() > PlayerIndex)
	{
		GEngine->AddOnScreenDebugMessage(-1, 999.0f, FColor::Cyan , FString::Printf(TEXT("APongPlayer::Getting player")));

		PlayerController = GetGameInstance()->GetLocalPlayers()[PlayerIndex]->PlayerController;
	}*/

	/*PlayerController = Cast<APlayerController>(Controller);


	if (PlayerController != nullptr)
	{		
		PlayerController->Possess(this);

		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			GEngine->AddOnScreenDebugMessage(-1, 999.0f, FColor::Green, FString::Printf(TEXT("APongPlayer::Assigning input for player:%i"), PlayerIndex));
			Subsystem->AddMappingContext(PongMappingContext, 0);
		}
	}*/


	/*
	//if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(PongMappingContext, 0);
		}
	}*/
	
}

// Called every frame
void APongPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APongPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APongPlayer::Move);
	}
}

void APongPlayer::Move(const FInputActionValue& Value)
{

	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 999.0f, FColor::Silver, FString::Printf(TEXT("APongPlayer::MovementInput - Move value:%.1f"), MovementVector.X));

		AddActorWorldOffset(FVector::ForwardVector *	 MovementVector.X * Speed);
	}

}


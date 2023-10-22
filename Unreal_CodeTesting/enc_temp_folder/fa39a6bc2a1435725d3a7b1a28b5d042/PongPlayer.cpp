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

		//if ( this->GetActorLocation().X  )

		AddActorWorldOffset(FVector::ForwardVector * MovementVector.X * Speed);
	}

}


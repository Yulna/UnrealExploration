// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PongHUDScore.generated.h"

/**
 * 
 */
UCLASS()
class UNREAL_CODETESTING_API UPongHUDScore : public UUserWidget
{
	GENERATED_BODY()
public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TMap<int32, FName> PlayersTag;


public:

	virtual void NativeOnInitialized() override;
	
	UFUNCTION()
	void RegisterId(int32 PlayerId, FName PlayerTag);


protected:

	UFUNCTION(BlueprintImplementableEvent)
	void OnScoreUpdate(int32 PlayerId, int Score);


};

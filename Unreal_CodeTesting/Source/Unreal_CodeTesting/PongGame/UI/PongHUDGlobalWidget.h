// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PongHUDGlobalWidget.generated.h"

class UPongHUDScore;

UCLASS()
class UNREAL_CODETESTING_API UPongHUDGlobalWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	class UPongHUDScore* HUDScore;
	
};

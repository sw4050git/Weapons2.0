// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "CPP_WeaponsSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class WEAPONS_API UCPP_WeaponsSaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString SlotName;

	UFUNCTION(BlueprintCallable)
	void Save();
};

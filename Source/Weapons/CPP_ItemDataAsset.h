// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPP_ItemDataAssetBase.h"
#include "GA_ItemBase.h"
#include "CPP_ItemDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class WEAPONS_API UCPP_ItemDataAsset : public UCPP_ItemDataAssetBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 MaxCount;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UGA_ItemBase> ItemAbility;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool Consumable;

};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ST_ShopItem.h"
#include "ST_ShopWeapon.h"
#include "ST_ShopLineup.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct FST_ShopLineup
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FST_ShopItem> Items;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FST_ShopWeapon> Weapons;

};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPP_WeaponDataAsset.h"
#include "ST_ShopWeapon.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FST_ShopWeapon
{
	GENERATED_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCPP_WeaponDataAsset* WeaponData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Sold;
};

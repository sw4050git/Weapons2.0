// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CPP_WeaponDataAsset.h"
#include "ST_ItemData.h"
#include "CPP_SortStuff.generated.h"

/**
 * 
 */
UCLASS()
class WEAPONS_API UCPP_SortStuff : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable,Category="SortItem")
	static void SortItemByID(TArray<FST_ItemData> Array,TArray<FST_ItemData>& SortedArray);

	UFUNCTION(BlueprintCallable, Category = "SortWeapon")
	static void SortWeaponByID(TArray<UCPP_WeaponDataAsset*> Array, TArray<UCPP_WeaponDataAsset*>& SortedArray);

};

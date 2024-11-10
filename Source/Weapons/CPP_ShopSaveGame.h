// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPP_WeaponsSaveGame.h"
#include "ST_ShopLineup.h"
#include "CPP_ShopSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class WEAPONS_API UCPP_ShopSaveGame : public UCPP_WeaponsSaveGame
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FST_ShopLineup ShopLineup;

	UFUNCTION(BlueprintCallable)
	void InitShopLineup(FST_ShopLineup DefaultLineup);

	void SortShopLineup();
};

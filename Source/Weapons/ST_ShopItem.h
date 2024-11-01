// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPP_ItemDataAsset.h"
#include "ST_ShopItem.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FST_ShopItem
{
	GENERATED_BODY()
	
	//BP(UCPP)‚Íƒ|ƒCƒ“ƒ^‚Å“ü‚ê‚é
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCPP_ItemDataAsset* ItemData=nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Count=0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Sold=false;

};

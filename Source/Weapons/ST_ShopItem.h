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
	
	//BP(UCPP)はポインタで入れる
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCPP_ItemDataAsset* ItemData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Count;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Sold;

};

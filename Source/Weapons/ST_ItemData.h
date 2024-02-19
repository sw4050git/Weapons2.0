// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPP_ItemDataAsset.h"
#include "ST_ItemData.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FST_ItemData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCPP_ItemDataAsset* ItemData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Count;
};
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
	UCPP_ItemDataAsset* ItemData=nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Count=0;

	bool operator==(const FST_ItemData& V)const;

	void AddCount(const int32 Count);
};

FORCEINLINE uint32 GetTypeHash(const FST_ItemData& Item)
{
	return FCrc::MemCrc32(&Item, sizeof(FST_ItemData));
}

FORCEINLINE bool FST_ItemData::operator==(const FST_ItemData& V)const 
{
	return ItemData == V.ItemData;
}

FORCEINLINE void FST_ItemData::AddCount(const int32 Value)
{
	Count = FMath::Clamp(Count+Value,0,ItemData->MaxCount);
}

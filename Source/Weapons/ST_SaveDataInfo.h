// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPP_LevelSaveData.h"
#include "ST_SaveDataInfo.generated.h"

/**
 *
 */

USTRUCT(BlueprintType)
struct FST_SaveDataInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGuid PlayerID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText PlayerName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FDateTime LastPlayTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName LastPlayLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UCPP_LevelSaveData> LastPlayLevelSaveDataClass;

};

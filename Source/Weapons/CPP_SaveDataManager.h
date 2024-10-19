// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "ST_SaveDataInfo.h"
#include "CPP_SaveDataManager.generated.h"

/**
 * 
 */
UCLASS()
class WEAPONS_API UCPP_SaveDataManager : public USaveGame
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TMap<FGuid, FST_SaveDataInfo> SaveDataInfos;

	UFUNCTION(BlueprintCallable, Category = "SaveDataManager")
	bool GetSaveDataInfo(FGuid PlayerID, FST_SaveDataInfo& NewSaveDataInfo);

	UFUNCTION(BlueprintCallable, Category = "SaveDataManager")
	void UpdateSaveDataInfo(FST_SaveDataInfo NewSaveDataInfo);

	UFUNCTION(BlueprintCallable,Category="SaveDataManager")
	void GetSortedSaveDataInfosByLastPlayTime(TArray<FST_SaveDataInfo>& SortedSaveDataInfos);
	
};

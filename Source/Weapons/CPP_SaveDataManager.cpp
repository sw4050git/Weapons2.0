// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_SaveDataManager.h"
#include "Kismet/GameplayStatics.h"

void UCPP_SaveDataManager::UpdateSaveDataInfo(FST_SaveDataInfo NewSaveDataInfo) 
{
	SaveDataInfos.Add(NewSaveDataInfo.PlayerID, NewSaveDataInfo);
	UGameplayStatics::SaveGameToSlot(this, "SaveDataManeger", 0);
}

bool UCPP_SaveDataManager::GetSaveDataInfo(FGuid PlayerID, FST_SaveDataInfo& NewSaveDataInfo) 
{
	if (SaveDataInfos.Contains(PlayerID))
	{
		NewSaveDataInfo = SaveDataInfos[PlayerID];
		return true;
	}
	else return false;
}

void UCPP_SaveDataManager::GetSortedSaveDataInfosByLastPlayTime(TArray<FST_SaveDataInfo>& SortedSaveDataInfos)
{
	SaveDataInfos.GenerateValueArray(SortedSaveDataInfos);
	SortedSaveDataInfos.Sort([](const FST_SaveDataInfo A, const FST_SaveDataInfo B) {return A.LastPlayTime > B.LastPlayTime; });
}
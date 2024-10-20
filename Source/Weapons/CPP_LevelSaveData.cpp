// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_LevelSaveData.h"

void UCPP_LevelSaveData::AddActionedActorID(FGuid ActionedActorID) 
{
	ActionedActorIDs.Add(ActionedActorID);
}
// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_WeaponsSaveGame.h"
#include "Kismet/GameplayStatics.h"

void UCPP_WeaponsSaveGame::Save() 
{
	UGameplayStatics::SaveGameToSlot(this, SlotName, 0);
}


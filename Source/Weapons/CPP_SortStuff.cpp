// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_SortStuff.h"

void UCPP_SortStuff::SortItemByID(TArray<FST_ItemData> Array, TArray<FST_ItemData>& SortedArray)
{
	Array.Sort([](const FST_ItemData A, const FST_ItemData B) {return A.ItemData->ID < B.ItemData->ID; });
	SortedArray = Array;
}

void UCPP_SortStuff::SortWeaponByID(TArray<UCPP_WeaponDataAsset*> Array, TArray<UCPP_WeaponDataAsset*>& SortedArray) {
	Array.Sort([](const UCPP_WeaponDataAsset& A, const UCPP_WeaponDataAsset& B) {return A.ID < B.ID; });
	SortedArray = Array;
}
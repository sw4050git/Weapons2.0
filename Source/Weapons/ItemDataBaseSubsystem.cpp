// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemDataBaseSubsystem.h"

UItemDataBaseSubsystem::UItemDataBaseSubsystem() {
	SelectedItemIndex = 0;
	SelectedWeaponIndex = 0;
	EquippedItems.SetNum(5);
	EquippedWeapons.SetNum(3);
}

void UItemDataBaseSubsystem::AddItem(FST_ItemData NewItem) {
	if (Items.Contains(NewItem)) {
		FST_ItemData* AugendItemPtr= Items.Find(NewItem);
		AugendItemPtr->AddCount(NewItem.Count);
		if (EquippedItems.Contains(*AugendItemPtr)) 
		{
			*EquippedItems.FindByKey(*AugendItemPtr) = *AugendItemPtr;
		} 
	}
	else {
		Items.Add(NewItem);
		for (FST_ItemData& EquippedItem : EquippedItems) {
			if (EquippedItem.ItemData == nullptr) {
				EquippedItem = NewItem;
				break;
			}
		}
	}
	ED_UpdateItem.Broadcast();
}

void UItemDataBaseSubsystem::ConsumeItem() {
	FST_ItemData* SelectedItemPtr = &EquippedItems[SelectedItemIndex];
	if (SelectedItemPtr->ItemData != nullptr && SelectedItemPtr->ItemData->Consumable) {
		SelectedItemPtr->AddCount(-1);
		Items.Find(*SelectedItemPtr)->AddCount(-1);
		if (SelectedItemPtr->Count == 0) {
			Items.Remove(*SelectedItemPtr);
			*SelectedItemPtr = { nullptr ,0};
		}
		ED_UpdateItem.Broadcast();
	}
}

int32 UItemDataBaseSubsystem::GetItemCount(UCPP_ItemDataAsset* ItemData)const {
	if (Items.Contains({ ItemData,0 })) {
		return Items.Find({ ItemData,0 })->Count;
	}
	return 0;
}

void UItemDataBaseSubsystem::SetEquippedItems(TArray<FST_ItemData> NewEquippedItems) 
{
	EquippedItems = NewEquippedItems;
	ED_UpdateItem.Broadcast();
}

void UItemDataBaseSubsystem::GetEquippedItemData(int32 EquippedItemIndex, FST_ItemData& ItemData) const{
	ItemData = EquippedItems[EquippedItemIndex];
}

void UItemDataBaseSubsystem::EquippItem(int32 EquippedItemIndex, FST_ItemData ItemData) {
	if (ItemData.ItemData != nullptr) 
	{
		for (FST_ItemData& EquippedItem : EquippedItems) {
			if (EquippedItem == ItemData) EquippedItem = { nullptr,0 };
		}
		EquippedItems[EquippedItemIndex] = ItemData;
		ED_UpdateItem.Broadcast();
	}
}

void UItemDataBaseSubsystem::ClearEquippedItem(int32 EquippedItemIndex) {
	EquippedItems[EquippedItemIndex] = { nullptr ,0 };
	ED_UpdateItem.Broadcast();
}

void UItemDataBaseSubsystem::GetSortedItemsByID(TArray<FST_ItemData>& SortedItems) const{
	SortedItems = Items.Array();
	SortedItems.Sort([](const FST_ItemData A, const FST_ItemData B) {return A.ItemData->ID < B.ItemData->ID; });
}

void UItemDataBaseSubsystem::ItemSelect(bool IsRight) {
	if (IsRight) SelectedItemIndex = (SelectedItemIndex+1) % EquippedItems.Num();
	else  SelectedItemIndex = (SelectedItemIndex-1 + EquippedItems.Num()) % EquippedItems.Num();
	ED_UpdateItem.Broadcast();
}

void UItemDataBaseSubsystem::GetSelectedItemData(FST_ItemData& ItemData) const{
	ItemData = EquippedItems[SelectedItemIndex];
}

void UItemDataBaseSubsystem::AddWeapon(UCPP_WeaponDataAsset* NewWeapon) {
	Weapons.Add(NewWeapon);
	for (UCPP_WeaponDataAsset*& EquippedWeapon : EquippedWeapons) {
		if (EquippedWeapon == nullptr) {
			EquippedWeapon = NewWeapon;
			break;
		}
	}
	ED_UpdateWeapon.Broadcast();
}

void UItemDataBaseSubsystem::SetEquippedWeapons(TArray<UCPP_WeaponDataAsset*> NewEquippedWeapons)
{
	EquippedWeapons = NewEquippedWeapons;
	ED_UpdateWeapon.Broadcast();
}

void UItemDataBaseSubsystem::GetEquippedWeaponData(int32 EquippedWeaponIndex, class UCPP_WeaponDataAsset*& WeaponData) const{
	WeaponData = EquippedWeapons[EquippedWeaponIndex];
}

void UItemDataBaseSubsystem::EquippWeapon(int32 EquippedWeaponIndex, UCPP_WeaponDataAsset* WeaponData) {
	if(WeaponData!=nullptr)
	{
		int32 index = EquippedWeapons.Find(WeaponData);
		if (index != INDEX_NONE) {
			EquippedWeapons[index] = nullptr;
		}
		EquippedWeapons[EquippedWeaponIndex] = WeaponData;
		ED_UpdateWeapon.Broadcast();
	}
}

void UItemDataBaseSubsystem::ClearEquippedWeaponData(int32 EquippedWeaponIndex) {
	EquippedWeapons[EquippedWeaponIndex] = nullptr;
	ED_UpdateWeapon.Broadcast();
}

void UItemDataBaseSubsystem::GetSortedWeaponsByID(TArray<UCPP_WeaponDataAsset*>& SortedWeapons) const{
	SortedWeapons = Weapons.Array();
	SortedWeapons.Sort([](const UCPP_WeaponDataAsset& A, const UCPP_WeaponDataAsset& B) {return A.ID < B.ID; });
}

void UItemDataBaseSubsystem::WeaponSelect(bool IsRight) {
	if (IsRight) SelectedWeaponIndex = (SelectedWeaponIndex+1) % EquippedWeapons.Num();
	else  SelectedWeaponIndex = (SelectedWeaponIndex- 1 + EquippedWeapons.Num()) % EquippedWeapons.Num();
	ED_UpdateWeapon.Broadcast();
}

void UItemDataBaseSubsystem::GetSelectedWeaponData(class UCPP_WeaponDataAsset*& WeaponData) const{
	WeaponData = EquippedWeapons[SelectedWeaponIndex];
}
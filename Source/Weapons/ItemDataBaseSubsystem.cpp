// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemDataBaseSubsystem.h"

UItemDataBaseSubsystem::UItemDataBaseSubsystem() {
	SelectedItemIndex = 0;
	SelectedWeaponIndex = 0;
	//EquippedItems.SetNum(5);
	for (int32 i = 0; i < 5; i++) {
		EquippedItems.Add({ nullptr,0 });
	}
	EquippedWeapons.SetNum(3);
}

void UItemDataBaseSubsystem::AddItem(FST_ItemData NewItem) {
	if (Items.Contains(NewItem.ItemData)) {
		Items[NewItem.ItemData] += NewItem.Count;
	}
	else {
		Items.Add(NewItem.ItemData, NewItem.Count);
	}
	ED_UpdateItem.Broadcast();
}

void UItemDataBaseSubsystem::ConsumeItem() {
	if (EquippedItems[SelectedItemIndex].ItemData != nullptr) {
		if (EquippedItems[SelectedItemIndex].ItemData->Consumable) {
			Items[EquippedItems[SelectedItemIndex].ItemData]--;
			EquippedItems[SelectedItemIndex].Count--;
			if (Items[EquippedItems[SelectedItemIndex].ItemData] == 0) {
				Items.Remove(EquippedItems[SelectedItemIndex].ItemData);
				EquippedItems[SelectedItemIndex].ItemData = nullptr;
				EquippedItems[SelectedItemIndex].Count = 0;
			}
			ED_UpdateItem.Broadcast();
		}
	}
}

void UItemDataBaseSubsystem::GetEquippedItemData(int32 EquippedItemIndex, FST_ItemData& ItemData) const{
	ItemData = EquippedItems[EquippedItemIndex];
}

void UItemDataBaseSubsystem::SetEquippedItemData(int32 EquippedItemIndex, FST_ItemData ItemData) {

	for (FST_ItemData& EquippedItem: EquippedItems) {
		if (EquippedItem.ItemData == ItemData.ItemData) EquippedItem = { nullptr,0 };
	}
	EquippedItems[EquippedItemIndex] = ItemData;
	ED_UpdateItem.Broadcast();
}

void UItemDataBaseSubsystem::ClearEquippedItem(int32 EquippedItemIndex) {
	EquippedItems[EquippedItemIndex] = { nullptr ,0 };
	ED_UpdateItem.Broadcast();
}

void UItemDataBaseSubsystem::GetSortedItemsByID(TArray<FST_ItemData>& SortedItems) const{
	for (auto It = Items.CreateConstIterator(); It; ++It) {
		SortedItems.Add({ It.Key(),It.Value() });
	}
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
	ED_UpdateWeapon.Broadcast();
}

void UItemDataBaseSubsystem::GetEquippedWeaponData(int32 EquippedWeaponIndex, class UCPP_WeaponDataAsset*& WeaponData) const{
	WeaponData = EquippedWeapons[EquippedWeaponIndex];
}

void UItemDataBaseSubsystem::SetEquippedWeaponData(int32 EquippedWeaponIndex, UCPP_WeaponDataAsset* WeaponData) {
	int32 index = EquippedWeapons.Find(WeaponData);
	if (index != INDEX_NONE) {
		EquippedWeapons[index] = nullptr;
	}
	EquippedWeapons[EquippedWeaponIndex] = WeaponData;
	ED_UpdateWeapon.Broadcast();
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
// Fill out your copyright notice in the Description page of Project Settings.


#include "ShopManagerSubsystem.h"
#include "ST_ShopItem.h"
#include "ST_ShopWeapon.h"


void UShopManagerSubsystem::InitShopItems(TArray<FST_ShopItem> NewItems) {
	ShopItems = NewItems;
	ED_UpdateShopItems.Broadcast();
}


bool UShopManagerSubsystem::BuyItem(int32 BuyingItemIndex, int32 Count) {
	//�͈͊O or Count���傫�������甄���s����
	if (Count > ShopItems[BuyingItemIndex].Count || BuyingItemIndex < 0 || BuyingItemIndex >= ShopItems.Num()) {
		return false;
	}

	ShopItems[BuyingItemIndex].Count -= Count;

	if (ShopItems[BuyingItemIndex].Count == 0) {
		ShopItems[BuyingItemIndex].Sold = true;
	}

	ED_UpdateShopItems.Broadcast();
	return true;
}

void UShopManagerSubsystem::InitShopWeapons(TArray<FST_ShopWeapon> NewWeapons) {
	ShopWeapons = NewWeapons;
	ED_UpdateShopWeapons.Broadcast();
}

bool UShopManagerSubsystem::BuyWeapon(int32 BuyingWeaponIndex) {
	//�͈͊O�Ȃ甄���s����
	if (BuyingWeaponIndex < 0 || BuyingWeaponIndex >= ShopWeapons.Num()) {
		return false;
	}

	ShopWeapons[BuyingWeaponIndex].Sold = true;
	ED_UpdateShopWeapons.Broadcast();
	return true;
}
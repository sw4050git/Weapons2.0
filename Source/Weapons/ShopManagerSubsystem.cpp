// Fill out your copyright notice in the Description page of Project Settings.


#include "ShopManagerSubsystem.h"
#include "ST_ShopItem.h"
#include "ST_ShopWeapon.h"


void UShopManagerSubsystem::InitShopItems(TArray<FST_ShopItem> NewItems) {
	ShopItems = TArray<FST_ShopItem>(NewItems);
	ED_UpdateShopItems.Broadcast();
}

//‚±‚êShopItem‚ÌCount < ˆø”‚ÌCount‚Ì‚Æ‚«‚Ç‚¤‚·‚éH
void UShopManagerSubsystem::BuyItem(int32 BuyingItemIndex, int32 Count) {
	ShopItems[BuyingItemIndex].Count -= Count;

	if (ShopItems[BuyingItemIndex].Count <= 0) {
		ShopItems[BuyingItemIndex].Sold = true;
	}

	ED_UpdateShopItems.Broadcast();
}

void UShopManagerSubsystem::InitShopWeapons(TArray<FST_ShopWeapon> NewWeapons) {
	ShopWeapons = TArray<FST_ShopWeapon>(NewWeapons);
	ED_UpdateShopWeapons.Broadcast();
}

void UShopManagerSubsystem::BuyWeapon(int32 BuyingWeaponIndex) {
	ShopWeapons[BuyingWeaponIndex].Sold = true;
	ED_UpdateShopWeapons.Broadcast();
}
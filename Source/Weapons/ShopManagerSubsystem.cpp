// Fill out your copyright notice in the Description page of Project Settings.


#include "ShopManagerSubsystem.h"

void UShopManagerSubsystem::InitShop(FST_ShopLineup Lineup) {
	ShopLineup = Lineup;
}

bool UShopManagerSubsystem::BuyItem(int32 BuyingItemIndex, int32 Count) {
	//範囲外 or Countが大きすぎたら売買不成立
	if (Count > ShopLineup.Items[BuyingItemIndex].Count || BuyingItemIndex < 0 || BuyingItemIndex >= ShopLineup.Items.Num()) {
		return false;
	}

	ShopLineup.Items[BuyingItemIndex].Count -= Count;

	if (ShopLineup.Items[BuyingItemIndex].Count == 0) {
		ShopLineup.Items[BuyingItemIndex].Sold = true;
	}

	ED_UpdateShopItems.Broadcast();
	return true;
}

bool UShopManagerSubsystem::BuyWeapon(int32 BuyingWeaponIndex) {
	//範囲外なら売買不成立
	if (BuyingWeaponIndex < 0 || BuyingWeaponIndex >= ShopLineup.Weapons.Num()) {
		return false;
	}

	ShopLineup.Weapons[BuyingWeaponIndex].Sold = true;
	ED_UpdateShopWeapons.Broadcast();
	return true;
}
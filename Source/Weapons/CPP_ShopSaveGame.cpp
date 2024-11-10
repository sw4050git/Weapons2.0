// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_ShopSaveGame.h"

void UCPP_ShopSaveGame::InitShopLineup(FST_ShopLineup DefaultLineup) 
{
	FST_ShopLineup NewLineup;
	for (FST_ShopItem DefaultShopItem : DefaultLineup.Items) 
	{
		bool IsContain = false;
		for (FST_ShopItem ShopItem : ShopLineup.Items) {
			if (ShopItem.ItemData == DefaultShopItem.ItemData) 
			{
				NewLineup.Items.Add(ShopItem);
				IsContain = true;
			}
		}
		if (!IsContain) NewLineup.Items.Add(DefaultShopItem);
	}
	for (FST_ShopWeapon DefaultShopWeapon : DefaultLineup.Weapons)
	{
		bool IsContain = false;
		for (FST_ShopWeapon ShopWeapon : ShopLineup.Weapons) {
			if (ShopWeapon.WeaponData == DefaultShopWeapon.WeaponData) 
			{
				NewLineup.Weapons.Add(ShopWeapon);
				IsContain = true;
			}
		}
		if (!IsContain) NewLineup.Weapons.Add(DefaultShopWeapon);
	}
	ShopLineup = NewLineup;
	SortShopLineup();
	return;
}

void UCPP_ShopSaveGame::SortShopLineup() 
{
	ShopLineup.Items.Sort([](const FST_ShopItem A, const FST_ShopItem B) {return A.ItemData->ID < B.ItemData->ID; });
	ShopLineup.Weapons.Sort([](const FST_ShopWeapon A, const FST_ShopWeapon B) {return A.WeaponData->ID < B.WeaponData->ID; });
}
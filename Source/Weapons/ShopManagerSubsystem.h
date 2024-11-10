// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ST_ShopItem.h"
#include "ST_ShopWeapon.h"
#include "ST_ShopLineup.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ShopManagerSubsystem.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FED_UpdateShopItems);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FED_UpdateShopWeapons);

UCLASS()
class WEAPONS_API UShopManagerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "ShopManager")
	FST_ShopLineup ShopLineup;

	/// <summary>
	/// ショップのラインナップを初期化
	/// </summary>
	/// <param name="Lineup">ショップのラインナップ</param>
	UFUNCTION(BlueprintCallable, Category = "ShopManger")
	void InitShop(FST_ShopLineup Lineup);

	/// <summary>
	/// アイテムの購入処理
	/// </summary>
	/// <returns>購入成功時True,そうでなければFalse</returns>
	UFUNCTION(BlueprintCallable, Category = "ShopManger")
	bool BuyItem(int32 BuyingItemIndex, int32 Count);

	/// <summary>
	/// 武器の購入処理
	/// </summary>
	/// <returns>購入成功時True,そうでなければFalse</returns>
	UFUNCTION(BlueprintCallable, Category = "ShopManger")
	bool BuyWeapon(int32 BuyingWeaponIndex);

	UPROPERTY(BlueprintAssignable, Category = "ShopManager")
	FED_UpdateShopItems ED_UpdateShopItems;

	UPROPERTY(BlueprintAssignable, Category = "ShopManager")
	FED_UpdateShopWeapons ED_UpdateShopWeapons;


};

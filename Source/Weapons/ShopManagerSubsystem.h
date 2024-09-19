// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ST_ShopItem.h"
#include "ST_ShopWeapon.h"
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
	/// <summary>
	/// ショップで売られているアイテムのリスト
	/// </summary>
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "ShopManager")
	TArray<FST_ShopItem> ShopItems;

	/// <summary>
	/// ショップで売られている武器のリスト
	/// </summary>
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "ShopManager")
	TArray<FST_ShopWeapon> ShopWeapons;

	/// <summary>
	/// ショップ画面に移行する際の関数
	/// ショップで売られるアイテムのリストを構成
	/// </summary>
	/// <param name="NewItems">ショップで売られるアイテムのリスト</param>
	UFUNCTION(BlueprintCallable, Category = "ShopManger")
	void InitShopItems(TArray<FST_ShopItem> NewItems);

	/// <summary>
	/// アイテムの売買処理
	/// </summary>
	/// <param name="BuyingItemIndex">買うアイテムのインデックス</param>
	/// <param name="Count">そのアイテムをどれだけ買うか</param>
	/// <returns>売買成功か</returns>
	UFUNCTION(BlueprintCallable, Category = "ShopManger")
	bool BuyItem(int32 BuyingItemIndex, int32 Count);

	/// <summary>
	/// ショップ画面に移行する際の関数
	/// ショップで売られる武器のリストを構成
	/// </summary>
	/// <param name="NewWeapons">ショップで売られる武器のリスト</param>
	UFUNCTION(BlueprintCallable, Category = "ShopManger")
	void InitShopWeapons(TArray<FST_ShopWeapon> NewWeapons);

	/// <summary>
	/// 武器の売買処理
	/// </summary>
	/// <param name="BuyingWeaponIndex">買う武器のインデックス</param>
	/// <returns>売買成功か</returns>
	UFUNCTION(BlueprintCallable, Category = "ShopManger")
	bool BuyWeapon(int32 BuyingWeaponIndex);

	UPROPERTY(BlueprintAssignable, Category = "ShopManager")
	FED_UpdateShopItems ED_UpdateShopItems;

	UPROPERTY(BlueprintAssignable, Category = "ShopManager")
	FED_UpdateShopWeapons ED_UpdateShopWeapons;


};

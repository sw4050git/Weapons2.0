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
	/// �V���b�v�̃��C���i�b�v��������
	/// </summary>
	/// <param name="Lineup">�V���b�v�̃��C���i�b�v</param>
	UFUNCTION(BlueprintCallable, Category = "ShopManger")
	void InitShop(FST_ShopLineup Lineup);

	/// <summary>
	/// �A�C�e���̍w������
	/// </summary>
	/// <returns>�w��������True,�����łȂ����False</returns>
	UFUNCTION(BlueprintCallable, Category = "ShopManger")
	bool BuyItem(int32 BuyingItemIndex, int32 Count);

	/// <summary>
	/// ����̍w������
	/// </summary>
	/// <returns>�w��������True,�����łȂ����False</returns>
	UFUNCTION(BlueprintCallable, Category = "ShopManger")
	bool BuyWeapon(int32 BuyingWeaponIndex);

	UPROPERTY(BlueprintAssignable, Category = "ShopManager")
	FED_UpdateShopItems ED_UpdateShopItems;

	UPROPERTY(BlueprintAssignable, Category = "ShopManager")
	FED_UpdateShopWeapons ED_UpdateShopWeapons;


};

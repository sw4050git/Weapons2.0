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
	/// �V���b�v�Ŕ����Ă���A�C�e���̃��X�g
	/// </summary>
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "ShopManager")
	TArray<FST_ShopItem> ShopItems;

	/// <summary>
	/// �V���b�v�Ŕ����Ă��镐��̃��X�g
	/// </summary>
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "ShopManager")
	TArray<FST_ShopWeapon> ShopWeapons;

	/// <summary>
	/// �V���b�v��ʂɈڍs����ۂ̊֐�
	/// �V���b�v�Ŕ�����A�C�e���̃��X�g���\��
	/// </summary>
	/// <param name="NewItems">�V���b�v�Ŕ�����A�C�e���̃��X�g</param>
	UFUNCTION(BlueprintCallable, Category = "ShopManger")
	void InitShopItems(TArray<FST_ShopItem> NewItems);

	/// <summary>
	/// �A�C�e���̔�������
	/// </summary>
	/// <param name="BuyingItemIndex">�����A�C�e���̃C���f�b�N�X</param>
	/// <param name="Count">���̃A�C�e�����ǂꂾ��������</param>
	/// <returns>����������</returns>
	UFUNCTION(BlueprintCallable, Category = "ShopManger")
	bool BuyItem(int32 BuyingItemIndex, int32 Count);

	/// <summary>
	/// �V���b�v��ʂɈڍs����ۂ̊֐�
	/// �V���b�v�Ŕ����镐��̃��X�g���\��
	/// </summary>
	/// <param name="NewWeapons">�V���b�v�Ŕ����镐��̃��X�g</param>
	UFUNCTION(BlueprintCallable, Category = "ShopManger")
	void InitShopWeapons(TArray<FST_ShopWeapon> NewWeapons);

	/// <summary>
	/// ����̔�������
	/// </summary>
	/// <param name="BuyingWeaponIndex">��������̃C���f�b�N�X</param>
	/// <returns>����������</returns>
	UFUNCTION(BlueprintCallable, Category = "ShopManger")
	bool BuyWeapon(int32 BuyingWeaponIndex);

	UPROPERTY(BlueprintAssignable, Category = "ShopManager")
	FED_UpdateShopItems ED_UpdateShopItems;

	UPROPERTY(BlueprintAssignable, Category = "ShopManager")
	FED_UpdateShopWeapons ED_UpdateShopWeapons;


};

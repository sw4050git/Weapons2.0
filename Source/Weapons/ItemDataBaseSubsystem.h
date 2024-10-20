// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "CPP_WeaponDataAsset.h"
#include "CPP_ItemDataAsset.h"
#include "ST_ItemData.h"
#include "ItemDataBaseSubsystem.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FED_UpdateItem);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FED_UpdateWeapon);

UCLASS()
class WEAPONS_API UItemDataBaseSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UItemDataBaseSubsystem();

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "ItemDataBase")
	TMap<UCPP_ItemDataAsset*, int32> Items;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, EditFixedSize, Category = "ItemDataBase")
	TArray<FST_ItemData> EquippedItems;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "ItemDataBase")
	int32 SelectedItemIndex;

	UFUNCTION(BlueprintCallable, Category="ItemDataBase")
	void AddItem(FST_ItemData NewItem);

	UFUNCTION(BlueprintCallable, Category = "ItemDataBase")
	void ConsumeItem();

	UFUNCTION(BlueprintCallable, Category = "ItemDataBase")
	void SetEquippedItems(TArray<FST_ItemData> NewEquippedItems);

	UFUNCTION(BlueprintCallable, Category = "ItemDataBase")
	void GetEquippedItemData(int32 EquippedItemIndex, FST_ItemData& ItemData) const;

	UFUNCTION(BlueprintCallable, Category = "ItemDataBase")
	void EquippItem(int32 EquippedItemIndex, FST_ItemData ItemData);

	UFUNCTION(BlueprintCallable, Category = "ItemDataBase")
	void ClearEquippedItem(int32 EquippedItemIndex);

	UFUNCTION(BlueprintCallable, Category = "ItemDataBase")
	void GetSortedItemsByID(TArray<FST_ItemData>& SortedItems) const;

	UFUNCTION(BlueprintCallable, Category = "ItemDataBase")
	void ItemSelect(bool IsRight);

	UFUNCTION(BlueprintCallable, Category = "ItemDataBase")
	void GetSelectedItemData(FST_ItemData& ItemData) const;

	UPROPERTY(BlueprintAssignable, Category = "ItemDataBase")
	FED_UpdateItem ED_UpdateItem;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "WeaponDataBase")
	TSet<UCPP_WeaponDataAsset*> Weapons;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, EditFixedSize, Category = "WeaponDataBase")
	TArray<UCPP_WeaponDataAsset*> EquippedWeapons;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "WeaponDataBase")
	int32 SelectedWeaponIndex;

	UFUNCTION(BlueprintCallable, Category = "WeaponDataBase")
	void AddWeapon(UCPP_WeaponDataAsset* NewWeapon);

	UFUNCTION(BlueprintCallable, Category = "WeaponDataBase")
	void SetEquippedWeapons(TArray<UCPP_WeaponDataAsset*> NewEquippedWeapons);

	UFUNCTION(BlueprintCallable, Category = "WeaponDataBase")
	void GetEquippedWeaponData(int32 EquippedWeaponIndex, class UCPP_WeaponDataAsset*& WeaponData) const;

	UFUNCTION(BlueprintCallable, Category = "WeaponDataBase")
	void EquippWeapon(int32 EquippedWeaponIndex, UCPP_WeaponDataAsset* WeaponData);

	UFUNCTION(BlueprintCallable, Category = "WeaponDataBase")
	void ClearEquippedWeaponData(int32 EquippedWeaponIndex);

	UFUNCTION(BlueprintCallable, Category = "WeaponDataBase")
	void GetSortedWeaponsByID(TArray<UCPP_WeaponDataAsset*>& SortedWeapons) const;

	UFUNCTION(BlueprintCallable, Category = "WeaponDataBase")
	void WeaponSelect(bool IsRight);

	UFUNCTION(BlueprintCallable, Category = "WeaponDataBase")
	void GetSelectedWeaponData(class UCPP_WeaponDataAsset*& WeaponData) const;

	UPROPERTY(BlueprintAssignable, Category = "WeaponDataBase")
	FED_UpdateWeapon ED_UpdateWeapon;
	
};

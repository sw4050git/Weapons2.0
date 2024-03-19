// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPP_ItemDataAssetBase.h"
#include "CPP_WeaponBase.h"
#include "Element.h"
#include "Abilities/GameplayAbility.h"
#include "CPP_WeaponDataAsset.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class WEAPONS_API UCPP_WeaponDataAsset : public UCPP_ItemDataAssetBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<ACPP_WeaponBase> WeaponClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<TSubclassOf<UGameplayAbility>> ComboAbilitys;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Attack")
	float Attack;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Attack")
	float Attack_Flame;

	UPROPERTY(BlueprintReadWrite, EditAnywhere,Category = "Attack")
	float Attack_Water;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Attack")
	float Attack_Ice;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Attack")
	float Attack_Wind;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Attack")
	float Attack_Thunder;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Attack")
	float Attack_Mud;
	
};

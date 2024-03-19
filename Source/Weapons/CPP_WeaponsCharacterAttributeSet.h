// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "Element.h"
#include "CPP_WeaponsCharacterAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */

UCLASS()
class WEAPONS_API UCPP_WeaponsCharacterAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	UCPP_WeaponsCharacterAttributeSet();

	//GameplayEffecté¿çsÇÃå„Ç…é¿çsÇ≥ÇÍÇÈä÷êî
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponsCharacterAttributes")
	FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS(UCPP_WeaponsCharacterAttributeSet, Stamina)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponsCharacterAttributes")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UCPP_WeaponsCharacterAttributeSet, Health)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponsCharacterAttributes")
	FGameplayAttributeData Damage;
	ATTRIBUTE_ACCESSORS(UCPP_WeaponsCharacterAttributeSet, Damage)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponsCharacterAttributes")
	FGameplayAttributeData Attack_Base;
	ATTRIBUTE_ACCESSORS(UCPP_WeaponsCharacterAttributeSet, Attack_Base)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponsCharacterAttributes")
	FGameplayAttributeData Attack_Flame;
	ATTRIBUTE_ACCESSORS(UCPP_WeaponsCharacterAttributeSet, Attack_Flame)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponsCharacterAttributes")
	FGameplayAttributeData Attack_Thunder;
	ATTRIBUTE_ACCESSORS(UCPP_WeaponsCharacterAttributeSet, Attack_Thunder)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponsCharacterAttributes")
	FGameplayAttributeData Attack_Ice;
	ATTRIBUTE_ACCESSORS(UCPP_WeaponsCharacterAttributeSet, Attack_Ice)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponsCharacterAttributes")
	FGameplayAttributeData Attack_Water;
	ATTRIBUTE_ACCESSORS(UCPP_WeaponsCharacterAttributeSet, Attack_Water)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponsCharacterAttributes")
	FGameplayAttributeData Attack_Wind;
	ATTRIBUTE_ACCESSORS(UCPP_WeaponsCharacterAttributeSet, Attack_Wind)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponsCharacterAttributes")
	FGameplayAttributeData Attack_Mud;
	ATTRIBUTE_ACCESSORS(UCPP_WeaponsCharacterAttributeSet, Attack_Mud)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponsCharacterAttributes")
	FGameplayAttributeData AttackMultiplier_Buf;
	ATTRIBUTE_ACCESSORS(UCPP_WeaponsCharacterAttributeSet, AttackMultiplier_Buf)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponsCharacterAttributes")
	FGameplayAttributeData AttackMultiplier_Motion;
	ATTRIBUTE_ACCESSORS(UCPP_WeaponsCharacterAttributeSet, AttackMultiplier_Motion)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponsCharacterAttributes")
	FGameplayAttributeData Defence_Base;
	ATTRIBUTE_ACCESSORS(UCPP_WeaponsCharacterAttributeSet, Defence_Base)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponsCharacterAttributes")
	FGameplayAttributeData Defence_Flame;
	ATTRIBUTE_ACCESSORS(UCPP_WeaponsCharacterAttributeSet, Defence_Flame)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponsCharacterAttributes")
	FGameplayAttributeData Defence_Thunder;
	ATTRIBUTE_ACCESSORS(UCPP_WeaponsCharacterAttributeSet, Defence_Thunder)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponsCharacterAttributes")
	FGameplayAttributeData Defence_Ice;
	ATTRIBUTE_ACCESSORS(UCPP_WeaponsCharacterAttributeSet, Defence_Ice)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponsCharacterAttributes")
	FGameplayAttributeData Defence_Water;
	ATTRIBUTE_ACCESSORS(UCPP_WeaponsCharacterAttributeSet, Defence_Water)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponsCharacterAttributes")
	FGameplayAttributeData Defence_Wind;
	ATTRIBUTE_ACCESSORS(UCPP_WeaponsCharacterAttributeSet, Defence_Wind)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponsCharacterAttributes")
	FGameplayAttributeData Defence_Mud;
	ATTRIBUTE_ACCESSORS(UCPP_WeaponsCharacterAttributeSet, Defence_Mud)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponsCharacterAttributes")
	FGameplayAttributeData DefenceMultiplier_Buf;
	ATTRIBUTE_ACCESSORS(UCPP_WeaponsCharacterAttributeSet, DefenceMultiplier_Buf)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponsCharacterAttributes")
	FGameplayAttributeData DamageReduction_Shield;
	ATTRIBUTE_ACCESSORS(UCPP_WeaponsCharacterAttributeSet, DamageReduction_Shield)

	static FGameplayAttribute GetAttacksAttribute(EElement Element);

	static FGameplayAttribute GetDefencesAttribute(EElement Element);
};

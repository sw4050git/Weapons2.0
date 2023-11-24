// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
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
	FGameplayAttributeData AttackBase;
	ATTRIBUTE_ACCESSORS(UCPP_WeaponsCharacterAttributeSet, AttackBase)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponsCharacterAttributes")
	FGameplayAttributeData AttackMotionMultiplier;
	ATTRIBUTE_ACCESSORS(UCPP_WeaponsCharacterAttributeSet, AttackMotionMultiplier)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponsCharacterAttributes")
	FGameplayAttributeData AttackItemMultiplier;
	ATTRIBUTE_ACCESSORS(UCPP_WeaponsCharacterAttributeSet, AttackItemMultiplier)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponsCharacterAttributes")
	FGameplayAttributeData DefenseMultiplier;
	ATTRIBUTE_ACCESSORS(UCPP_WeaponsCharacterAttributeSet, DefenseMultiplier)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponsCharacterAttributes")
	FGameplayAttributeData Damage;
	ATTRIBUTE_ACCESSORS(UCPP_WeaponsCharacterAttributeSet, Damage)

};

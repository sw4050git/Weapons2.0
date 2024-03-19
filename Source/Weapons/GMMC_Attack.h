// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "Element.h"
#include "GMMC_Attack.generated.h"

/**
 * 
 */
UCLASS()
class WEAPONS_API UGMMC_Attack : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()

public:
	UGMMC_Attack();

	UPROPERTY()
	FGameplayEffectAttributeCaptureDefinition AttacksDef[(int32)EElement::Max];
	UPROPERTY()
	FGameplayEffectAttributeCaptureDefinition AttackMultiplier_BufDef;
	UPROPERTY()
	FGameplayEffectAttributeCaptureDefinition AttackMultiplier_MotionDef;

	UPROPERTY()
	FGameplayEffectAttributeCaptureDefinition DefencesDef[(int32)EElement::Max];
	UPROPERTY()
	FGameplayEffectAttributeCaptureDefinition DefenceMultiplier_BufDef;
	UPROPERTY()
	FGameplayEffectAttributeCaptureDefinition DamageReduction_ShieldDef;

	float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;
};

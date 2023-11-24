// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
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
	FGameplayEffectAttributeCaptureDefinition AttackBaseDef;
	UPROPERTY()
	FGameplayEffectAttributeCaptureDefinition AttackMotionMultiplierDef;
	UPROPERTY()
	FGameplayEffectAttributeCaptureDefinition AttackItemMultiplierDef;
	UPROPERTY()
	FGameplayEffectAttributeCaptureDefinition DefenseMultiplierDef;

	float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;
};

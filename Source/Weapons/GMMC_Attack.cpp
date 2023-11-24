// Fill out your copyright notice in the Description page of Project Settings.


#include "GMMC_Attack.h"
#include "CPP_WeaponsCharacterAttributeSet.h"

UGMMC_Attack::UGMMC_Attack() 
{
	AttackBaseDef.AttributeToCapture = UCPP_WeaponsCharacterAttributeSet::GetAttackBaseAttribute();
	AttackBaseDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Source;
	AttackBaseDef.bSnapshot = true;

	AttackMotionMultiplierDef.AttributeToCapture = UCPP_WeaponsCharacterAttributeSet::GetAttackMotionMultiplierAttribute();
	AttackMotionMultiplierDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Source;
	AttackMotionMultiplierDef.bSnapshot = true;

	AttackItemMultiplierDef.AttributeToCapture = UCPP_WeaponsCharacterAttributeSet::GetAttackItemMultiplierAttribute();
	AttackItemMultiplierDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Source;
	AttackItemMultiplierDef.bSnapshot = true;

	DefenseMultiplierDef.AttributeToCapture = UCPP_WeaponsCharacterAttributeSet::GetDefenseMultiplierAttribute();
	DefenseMultiplierDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	DefenseMultiplierDef.bSnapshot = false;
	
	RelevantAttributesToCapture.Add(AttackBaseDef);
	RelevantAttributesToCapture.Add(AttackMotionMultiplierDef);
	RelevantAttributesToCapture.Add(AttackItemMultiplierDef);
	RelevantAttributesToCapture.Add(DefenseMultiplierDef);
}

float UGMMC_Attack::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const 
{
	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	FAggregatorEvaluateParameters EvaluationParameters;
	EvaluationParameters.SourceTags = SourceTags;
	EvaluationParameters.TargetTags = TargetTags;

	float AttackBase = 0.f;
	float AttackMotionMultiplier = 0.f;
	float AttackItemMultiplier = 0.f;
	float DefenseMultiplier = 0.f;

	GetCapturedAttributeMagnitude(AttackBaseDef, Spec, EvaluationParameters, AttackBase);
	GetCapturedAttributeMagnitude(AttackMotionMultiplierDef, Spec, EvaluationParameters, AttackMotionMultiplier);
	GetCapturedAttributeMagnitude(AttackItemMultiplierDef, Spec, EvaluationParameters, AttackItemMultiplier);
	GetCapturedAttributeMagnitude(DefenseMultiplierDef, Spec, EvaluationParameters, DefenseMultiplier);
	if (DefenseMultiplier == 0.f) {
		DefenseMultiplier = 1.f;
	}

	UE_LOG(LogTemp, Display, TEXT("AttackBase:%f"), AttackBase);
	UE_LOG(LogTemp, Display, TEXT("AttackMotion:%f"), AttackMotionMultiplier);
	UE_LOG(LogTemp, Display, TEXT("AttackItem:%f"), AttackItemMultiplier);
	UE_LOG(LogTemp, Display, TEXT("Defense:%f"), DefenseMultiplier);

	return  AttackBase * AttackMotionMultiplier * AttackItemMultiplier / DefenseMultiplier;
}

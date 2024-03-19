// Fill out your copyright notice in the Description page of Project Settings.


#include "GMMC_Attack.h"
#include "CPP_WeaponsCharacterAttributeSet.h"

UGMMC_Attack::UGMMC_Attack() 
{
	for (EElement Element : TEnumRange<EElement>())
	{
		AttacksDef[static_cast<int32>(Element)].AttributeToCapture = UCPP_WeaponsCharacterAttributeSet::GetAttacksAttribute(Element);
		AttacksDef[static_cast<int32>(Element)].AttributeSource = EGameplayEffectAttributeCaptureSource::Source;
		AttacksDef[static_cast<int32>(Element)].bSnapshot = true;
		RelevantAttributesToCapture.Add(AttacksDef[static_cast<int32>(Element)]);
	}
	AttackMultiplier_BufDef.AttributeToCapture = UCPP_WeaponsCharacterAttributeSet::GetAttackMultiplier_BufAttribute();
	AttackMultiplier_BufDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Source;
	AttackMultiplier_BufDef.bSnapshot = true;
	RelevantAttributesToCapture.Add(AttackMultiplier_BufDef);

	AttackMultiplier_MotionDef.AttributeToCapture = UCPP_WeaponsCharacterAttributeSet::GetAttackMultiplier_MotionAttribute();
	AttackMultiplier_MotionDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Source;
	AttackMultiplier_MotionDef.bSnapshot = true;
	RelevantAttributesToCapture.Add(AttackMultiplier_MotionDef);

	for (EElement Element : TEnumRange<EElement>())
	{
		DefencesDef[static_cast<int32>(Element)].AttributeToCapture = UCPP_WeaponsCharacterAttributeSet::GetDefencesAttribute(Element);
		DefencesDef[static_cast<int32>(Element)].AttributeSource = EGameplayEffectAttributeCaptureSource::Source;
		DefencesDef[static_cast<int32>(Element)].bSnapshot = true;
		RelevantAttributesToCapture.Add(DefencesDef[static_cast<int32>(Element)]);
	}
	DefenceMultiplier_BufDef.AttributeToCapture = UCPP_WeaponsCharacterAttributeSet::GetDefenceMultiplier_BufAttribute();
	DefenceMultiplier_BufDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	DefenceMultiplier_BufDef.bSnapshot = false;
	RelevantAttributesToCapture.Add(DefenceMultiplier_BufDef);

	DamageReduction_ShieldDef.AttributeToCapture = UCPP_WeaponsCharacterAttributeSet::GetDamageReduction_ShieldAttribute();
	DamageReduction_ShieldDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	DamageReduction_ShieldDef.bSnapshot = false;
	RelevantAttributesToCapture.Add(DamageReduction_ShieldDef);

}

float UGMMC_Attack::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const 
{
	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	FAggregatorEvaluateParameters EvaluationParameters;
	EvaluationParameters.SourceTags = SourceTags;
	EvaluationParameters.TargetTags = TargetTags;

	float Attacks[(int32)EElement::Max] = {};
	float AttackMultiplier_Buf = 0.f;
	float AttackMultiplier_Motion = 0.f;

	float Defences[(int32)EElement::Max] = {};
	float DefenceMultiplier_Buf = 0.f;
	float DamageReduction_Shield = 0.f;

	for (EElement Element : TEnumRange<EElement>()) 
	{
		GetCapturedAttributeMagnitude(AttacksDef[static_cast<int32>(Element)], Spec, EvaluationParameters, Attacks[static_cast<int32>(Element)]);
	}
	GetCapturedAttributeMagnitude(AttackMultiplier_BufDef, Spec, EvaluationParameters, AttackMultiplier_Buf);
	GetCapturedAttributeMagnitude(AttackMultiplier_MotionDef, Spec, EvaluationParameters, AttackMultiplier_Motion);

	for (EElement Element : TEnumRange<EElement>())
	{
		GetCapturedAttributeMagnitude(DefencesDef[static_cast<int32>(Element)], Spec, EvaluationParameters, Defences[static_cast<int32>(Element)]);
	}
	GetCapturedAttributeMagnitude(DefenceMultiplier_BufDef, Spec, EvaluationParameters, DefenceMultiplier_Buf);
	GetCapturedAttributeMagnitude(DamageReduction_ShieldDef, Spec, EvaluationParameters, DamageReduction_Shield);

	float Damage = 0.f;
	for (EElement Element : TEnumRange<EElement>())
	{
		float Attack = Attacks[static_cast<int32>(Element)] * AttackMultiplier_Buf * AttackMultiplier_Buf;
		float Defence = Defences[static_cast<int32>(Element)] * DefenceMultiplier_Buf;
		Damage+= FMath::Max(Attack - Defence, 0.f);
	}
	Damage *= (1 - DamageReduction_Shield / 100);

	return  Damage;
}

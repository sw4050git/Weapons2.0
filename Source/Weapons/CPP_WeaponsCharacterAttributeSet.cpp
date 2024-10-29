// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_WeaponsCharacterAttributeSet.h"
#include "CPP_WeaponsCharacter.h"
#include "GameplayEffect.h"
#include "GameplayEffectExtension.h"


UCPP_WeaponsCharacterAttributeSet::UCPP_WeaponsCharacterAttributeSet()
{
	Stamina = 100.f;
	Health = 100.f;
	MagicPoint = 100.f;

	Attack_Base = 0.f;
	Attack_Flame = 0.f;
	Attack_Ice = 0.f;
	Attack_Mud = 0.f;
	Attack_Thunder = 0.f;
	Attack_Wind = 0.f;
	Attack_Water = 0.f;
	AttackMultiplier_Buf = 1.f;
	AttackMultiplier_Motion = 1.f;

	Defence_Base = 0.f;
	Defence_Flame = 0.f;
	Defence_Ice = 0.f;
	Defence_Mud = 0.f;
	Defence_Thunder = 0.f;
	Defence_Wind = 0.f;
	Defence_Water = 0.f;
	DefenceMultiplier_Buf = 1.f;
	DamageReduction_Shield = 0.f;
}

void UCPP_WeaponsCharacterAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == GetStaminaAttribute())
	{
		SetStamina(FMath::Clamp(GetStamina(), 0.f, 100.f));
	}

	if (Data.EvaluatedData.Attribute == GetMagicPointAttribute())
	{
		SetMagicPoint(FMath::Clamp(GetMagicPoint(), 0.f, 100.f));
	}

	AActor* TargetActor = Data.Target.GetAvatarActor();
	ACPP_WeaponsCharacter* TargetCharacter = Cast<ACPP_WeaponsCharacter>(TargetActor);

	AActor* SourceActor = Data.EffectSpec.GetContext().GetOriginalInstigator();

	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		if (Data.EvaluatedData.ModifierOp == EGameplayModOp::Additive)
		{
			UE_LOG(LogTemp, Log, TEXT("%f"),Data.EvaluatedData.Magnitude);
			if (Data.EvaluatedData.Magnitude < 0.f)
			{
				if (TargetCharacter)
				{
					if (GetHealth() > 0)
					{
						TargetCharacter->OnDamaged(GetDamage(), GetHealth(), SourceActor);
					}
					else
					{
						TargetCharacter->OnDied(GetDamage(), SourceActor);
					}
				}
				InitDamage(0.f);
			}
		}
		InitHealth(FMath::Clamp(GetHealth(), 0.f, 100.f));
	}
}

FGameplayAttribute UCPP_WeaponsCharacterAttributeSet::GetAttacksAttribute(EElement Element) 
{
	switch (Element) 
	{
		case EElement::Base: 
		{
			return GetAttack_BaseAttribute();
		}
		case EElement::Flame:
		{
			return GetAttack_FlameAttribute();
		}
		case EElement::Water:
		{
			return GetAttack_WaterAttribute();
		}
		case EElement::Ice:
		{
			return GetAttack_IceAttribute();
		}
		case EElement::Thunder:
		{
			return GetAttack_ThunderAttribute();
		}
		case EElement::Mud:
		{
			return GetAttack_MudAttribute();
		}
		case EElement::Wind:
		{
			return GetAttack_WindAttribute();
		}
	}
	return nullptr;
}

FGameplayAttribute UCPP_WeaponsCharacterAttributeSet::GetDefencesAttribute(EElement Element)
{
	switch (Element)
	{
		case EElement::Base:
		{
			return GetDefence_BaseAttribute();
		}
		case EElement::Flame:
		{
			return GetDefence_FlameAttribute();
		}
		case EElement::Water:
		{
			return GetDefence_WaterAttribute();
		}
		case EElement::Ice:
		{
			return GetDefence_IceAttribute();
		}
		case EElement::Thunder:
		{
			return GetDefence_ThunderAttribute();
		}
		case EElement::Mud:
		{
			return GetDefence_MudAttribute();
		}
		case EElement::Wind:
		{
			return GetDefence_WindAttribute();
		}
	}
	return nullptr;
}
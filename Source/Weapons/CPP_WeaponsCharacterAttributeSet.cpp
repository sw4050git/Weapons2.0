// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_WeaponsCharacterAttributeSet.h"
#include "CPP_WeaponsCharacter.h"
#include "GameplayEffect.h"
#include "GameplayEffectExtension.h"

UCPP_WeaponsCharacterAttributeSet::UCPP_WeaponsCharacterAttributeSet() :
	Stamina(100.f), Health(100.f), AttackBase(1.f), AttackMotionMultiplier(1.f), AttackItemMultiplier(1.f), DefenseMultiplier(1.f)
{
}

void UCPP_WeaponsCharacterAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == GetStaminaAttribute())
	{
		SetStamina(FMath::Clamp(GetStamina(), 0.f, 100.f));
	}

	AActor* TargetActor = Data.Target.GetAvatarActor();
	ACPP_WeaponsCharacter* TargetCharacter = Cast<ACPP_WeaponsCharacter>(TargetActor);

	AActor* SourceActor = Data.EffectSpec.GetContext().GetOriginalInstigator();

	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		if (Data.EvaluatedData.ModifierOp == EGameplayModOp::Additive)
		{
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
			}
			InitDamage(0.f);
		}
		InitHealth(FMath::Clamp(GetHealth(), 0.f, 100.f));
	}


}
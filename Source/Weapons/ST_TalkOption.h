// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "ST_TalkOption.generated.h"
/**
 * 
 */

USTRUCT(BlueprintType)
struct FST_TalkOption
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText OptionText = FText();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName NextTag = FName();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UGameplayAbility> EventAbility = nullptr;
};


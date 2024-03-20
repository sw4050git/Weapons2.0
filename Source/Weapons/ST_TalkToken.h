// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ST_TalkOption.h"
#include "ST_TalkToken.generated.h"
/**
 * 
 */

USTRUCT(BlueprintType)
struct FST_TalkToken
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName NextTag = FName();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Name=FText();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Text=FText();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UGameplayAbility> EventAbility = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FST_TalkOption> Options;
};
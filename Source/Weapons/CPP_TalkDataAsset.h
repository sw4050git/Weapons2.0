// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ST_TalkToken.h"
#include "CPP_TalkDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class WEAPONS_API UCPP_TalkDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UCPP_TalkDataAsset();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<FName, FST_TalkToken> TalkData;
};

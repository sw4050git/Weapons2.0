// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "CPP_LevelSaveData.generated.h"

/**
 * 
 */
UCLASS()
class WEAPONS_API UCPP_LevelSaveData : public USaveGame
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSet<FGuid> ActionedActorIDs;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName CurrentStartTag="Start";

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USoundBase* LevelBGM;

	UFUNCTION(BlueprintCallable, Category="LevelSaveData")
	void AddActionedActorID(FGuid ActionedActorID);
	
};

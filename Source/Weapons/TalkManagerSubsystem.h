// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "CPP_TalkDataAsset.h"
#include "ST_TalkToken.h"
#include "TalkManagerSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class WEAPONS_API UTalkManagerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	UTalkManagerSubsystem();

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "TalkManager")
	UCPP_TalkDataAsset* TalkDataAsset = nullptr;

	UFUNCTION(BlueprintCallable, Category = "TalkManager")
	void SetTalkData(UCPP_TalkDataAsset* NewTalkData);

	UFUNCTION(BlueprintCallable, Category = "TalkManager")
	bool GetFirstToken(FST_TalkToken& FirstToken) const;

	UFUNCTION(BlueprintCallable, Category = "TalkManager")
	bool GetNextToken(FName NextTag, FST_TalkToken& NextToken) const;

};

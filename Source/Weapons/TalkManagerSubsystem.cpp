// Fill out your copyright notice in the Description page of Project Settings.


#include "TalkManagerSubsystem.h"

UTalkManagerSubsystem::UTalkManagerSubsystem() {

}

void UTalkManagerSubsystem::SetTalkData(UCPP_TalkDataAsset* NewTalkDataAsset) {
	TalkDataAsset = NewTalkDataAsset;
}

bool UTalkManagerSubsystem::GetFirstToken(FST_TalkToken& FirstToken) const {
	if (TalkDataAsset != nullptr)
	{
		if (TalkDataAsset->TalkData.Contains(FName("Start")))
		{
			FirstToken = TalkDataAsset->TalkData["Start"];
			return true;
		}
	}
	FirstToken = FST_TalkToken();
	return false;
}

bool UTalkManagerSubsystem::GetNextToken(FName NextTag,FST_TalkToken& NextToken) const{
	if (TalkDataAsset != nullptr) 
	{
		if (TalkDataAsset->TalkData.Contains(NextTag)) {
			NextToken = TalkDataAsset->TalkData[NextTag];
			return true;
		}
	}
	NextToken = FST_TalkToken();
	return false;
}



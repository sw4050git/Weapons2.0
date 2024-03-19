// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Element.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EElement : uint8 {
	Base,
	Flame,
	Ice,
	Water,
	Thunder,
	Mud,
	Wind,

	Max
};
ENUM_RANGE_BY_COUNT(EElement, EElement::Max);
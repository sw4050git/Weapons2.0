// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CPP_WeaponsCharacterAttributeSet.h"
#include "CPP_WeaponsCharacter.generated.h"

UCLASS()
class WEAPONS_API ACPP_WeaponsCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACPP_WeaponsCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY()
	UCPP_WeaponsCharacterAttributeSet* CPP_WeaponsCharacterAttributeSet;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "WeaponsCharacterAttributeSet")
	virtual float GetStamina();
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "WeaponsCharacterAttributeSet")
	virtual float GetHealth();

	UFUNCTION(BlueprintImplementableEvent, Category = "Reaction")
	void OnDamaged(float Damage, float Health, AActor* Attacker);
	UFUNCTION(BlueprintImplementableEvent, Category = "Reaction")
	void OnDied(float Damage, AActor* Attacker);

};

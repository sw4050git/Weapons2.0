// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_WeaponsCharacter.h"

// Sets default values
ACPP_WeaponsCharacter::ACPP_WeaponsCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CPP_WeaponsCharacterAttributeSet = CreateDefaultSubobject<UCPP_WeaponsCharacterAttributeSet>(TEXT("AttributeSet"));
	AbilitySystem = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystem"));
}

// Called when the game starts or when spawned
void ACPP_WeaponsCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_WeaponsCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

UAbilitySystemComponent* ACPP_WeaponsCharacter::GetAbilitySystemComponent() const 
{
	return AbilitySystem;
}

// Called to bind functionality to input
void ACPP_WeaponsCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float ACPP_WeaponsCharacter::GetStamina()
{
	return CPP_WeaponsCharacterAttributeSet->GetStamina();
}

float ACPP_WeaponsCharacter::GetHealth()
{
	return CPP_WeaponsCharacterAttributeSet->GetHealth();
}

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PickUp.h"
#include "Ability.h"
#include "Flamethrower.h"
#include "CarAbilityComponent.h"
#include "FlamethrowerPickUp.generated.h"

/**
 * 
 */
UCLASS()
class AGILE4TEST_API AFlamethrowerPickUp : public APickUp
{
	GENERATED_BODY()

public:
	AFlamethrowerPickUp();
	AAbility* ability;
};

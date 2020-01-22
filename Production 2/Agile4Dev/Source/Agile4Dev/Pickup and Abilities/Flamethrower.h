// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ability.h"
#include "Flamethrower.generated.h"

/**
 * 
 */
UCLASS()
class AGILE4DEV_API AFlamethrower : public AAbility
{
	GENERATED_BODY()
public:
	AFlamethrower();
	virtual void Activate();
	virtual void Use();
	int abilityID;
};

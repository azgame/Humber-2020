// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PickUp.h"
#include "HealthPickUp.generated.h"

/**
 * 
 */
UCLASS()
class AGILE4TEST_API AHealthPickUp : public APickUp
{
	GENERATED_BODY()

public:
	AHealthPickUp();
	FStatPickUp stats;

};

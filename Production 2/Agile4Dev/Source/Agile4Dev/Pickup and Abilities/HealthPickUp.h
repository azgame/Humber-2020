// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PickUp.h"
#include "HealthPickUp.generated.h"

/**
 * 
 */
UCLASS()
class AGILE4DEV_API AHealthPickUp : public APickUp
{
	GENERATED_BODY()

public:
	AHealthPickUp();
	FString key;
	int val;


	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CarPickupComponent.generated.h"

USTRUCT()
struct FStatPickUp
{
	GENERATED_BODY()


		UPROPERTY()
		int val;
	UPROPERTY()
		FString key;

	FStatPickUp() {
		val = 0;
		key = "";
	}

	FStatPickUp(int val_, FString key_) {
		val = val_;
		key = key_;
	}


};
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class AGILE4DEV_API UCarPickupComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCarPickupComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void StatPickUp(FStatPickUp pickUp_);
	int* RetrieveStats(FString key_);
	TMap<FString, int> stats;

		
};

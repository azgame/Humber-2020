// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickUp.generated.h"

USTRUCT(BlueprintType)
struct AGILE4TEST_API FStatPickUp
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Key")
	FString key;
	UPROPERTY(BlueprintReadWrite, Category = "Value")
	int val;
};

UCLASS()
class AGILE4TEST_API APickUp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickUp();
	int id;
	virtual void Initialize();
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

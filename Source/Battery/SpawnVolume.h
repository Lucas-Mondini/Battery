// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "SpawnVolume.generated.h"

UCLASS()
class BATTERY_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnVolume();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Spawning")
		TSubclassOf<class APickup> WhatToSpawn;

public:	
	// Called every frame
	//virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintPure, Category = "Spawning")
		FVector GetRandomPointInVolume();
	UFUNCTION(BlueprintPure, Category = "Spawning")
        FRotator GetRandomObjectRotation();

	FORCEINLINE UBoxComponent* GetWhereToSpawn() const { return WhereToSpawn; };

private:
	//Spawn Area
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning", meta = (AllowPrivateAccess = "true"))
		UBoxComponent* WhereToSpawn;
	
	void SpawnPickup();
};

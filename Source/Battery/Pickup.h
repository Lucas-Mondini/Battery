// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Pickup.generated.h"

UCLASS()
class BATTERY_API APickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickup();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** true when pickup can be used. */
	bool bIsActive;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Getter and setter for bIsActive
	UFUNCTION(BlueprintPure, Category = "Pickup")
		bool IsActive();
	UFUNCTION(BlueprintCallable, Category = "Pickup")
	void SetActive(bool newState);
	//Getter and setter for bIsActive

	/* Return the mesh for the pickup*/
	FORCEINLINE class UStaticMeshComponent* GetMesh() const { return PickupMesh; }

	UFUNCTION(BlueprintNativeEvent, Category = "Pickup")
	void WasCollected();
	virtual void WasCollected_Implementation();

	/*Static Mesh to represent the pickup in the level */
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup", meta= (AllowPrivateAcsses = "true") )
        	UStaticMeshComponent* PickupMesh;

};

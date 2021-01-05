// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnVolume.h"
#include  "Kismet/KismetMathLibrary.h"
#include  "Pickup.h"

// Sets default values
ASpawnVolume::ASpawnVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	WhereToSpawn = CreateDefaultSubobject<UBoxComponent>(TEXT("WhereToSpawn"));
	RootComponent = WhereToSpawn;

}

// Called when the game starts or when spawned
void ASpawnVolume::BeginPlay()
{
	Super::BeginPlay();
	
}

FVector ASpawnVolume::GetRandomPointInVolume()
{
	FVector SpawnOrigin, SpawnExtend;
	SpawnOrigin = WhereToSpawn->Bounds.Origin;
	SpawnExtend = WhereToSpawn->Bounds.BoxExtent;

	return  UKismetMathLibrary::RandomPointInBoundingBox(SpawnOrigin, SpawnExtend);
}

FRotator ASpawnVolume::GetRandomObjectRotation()
{
	FRotator Rotation;
	Rotation.Pitch = FMath::FRand() * 360.0f;
	Rotation.Yaw = FMath::FRand() * 360.0f;
	Rotation.Roll = FMath::FRand() * 360.0f;

	return Rotation;
}

void ASpawnVolume::SpawnPickup()
{
	UWorld* const World = GetWorld();
	FVector SpawnLocation = GetRandomPointInVolume();
	FRotator SpawnRotation = GetRandomObjectRotation();
	if(WhatToSpawn && World)
	{
		FActorSpawnParameters SpawnParameters;
		SpawnParameters.Owner = this;
		SpawnParameters.Instigator = GetInstigator();

		APickup* const SpawnedPickup = World->SpawnActor<APickup>(WhatToSpawn, SpawnLocation, SpawnRotation, SpawnParameters);

	}
}

// Called every frame
/* Remove if PrimaryActorTick.bCanEverTick = true
void ASpawnVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
*/

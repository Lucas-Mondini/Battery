// Copyright Epic Games, Inc. All Rights Reserved.

#include "BatteryGameMode.h"
#include "BatteryCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABatteryGameMode::ABatteryGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

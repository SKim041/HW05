// Copyright Epic Games, Inc. All Rights Reserved.

#include "HW05GameMode.h"
#include "HW05Character.h"
#include "UObject/ConstructorHelpers.h"

AHW05GameMode::AHW05GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

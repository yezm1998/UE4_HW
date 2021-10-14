// Copyright Epic Games, Inc. All Rights Reserved.

#include "homework1GameMode.h"
#include "homework1Character.h"
#include "UObject/ConstructorHelpers.h"

Ahomework1GameMode::Ahomework1GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

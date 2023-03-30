// Copyright Epic Games, Inc. All Rights Reserved.

#include "ArduinoProjectGameMode.h"
#include "ArduinoProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AArduinoProjectGameMode::AArduinoProjectGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}

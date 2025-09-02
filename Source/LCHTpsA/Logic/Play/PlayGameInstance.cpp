// Copyright Epic Games, Inc. All Rights Reserved.

#include "Logic/Play/PlayGameInstance.h"

UPlayGameInstance::UPlayGameInstance()
{
	// Constructor implementation
}

void UPlayGameInstance::Init()
{
	Super::Init();

	// Play-specific game instance initialization
	// Initialize persistent systems, save/load data, etc.
}

void UPlayGameInstance::Shutdown()
{
	// Play-specific cleanup before shutdown
	
	Super::Shutdown();
}

void UPlayGameInstance::OnStart()
{
	Super::OnStart();

	// Called when starting a new game session
}

void UPlayGameInstance::LoadComplete(const float LoadTime, const FString& MapName)
{
	Super::LoadComplete(LoadTime, MapName);

	// Called when a level has finished loading
}

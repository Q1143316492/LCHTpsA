// Copyright Epic Games, Inc. All Rights Reserved.

#include "Logic/Play/PlayGameState.h"

APlayGameState::APlayGameState()
{
	// Set this actor to call Tick() every frame
	PrimaryActorTick.bCanEverTick = true;
}

void APlayGameState::BeginPlay()
{
	Super::BeginPlay();

	// Play-specific game state initialization
}

void APlayGameState::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Update game state logic for Play scenarios
}

void APlayGameState::HandleBeginPlay()
{
	Super::HandleBeginPlay();

	// Handle game state initialization when ready to receive updates
}

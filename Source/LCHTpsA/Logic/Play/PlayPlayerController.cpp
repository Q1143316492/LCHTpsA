// Copyright Epic Games, Inc. All Rights Reserved.

#include "Logic/Play/PlayPlayerController.h"

APlayPlayerController::APlayPlayerController()
{
	// Set this actor to call Tick() every frame
	PrimaryActorTick.bCanEverTick = true;
}

void APlayPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// Play-specific player controller initialization
}

void APlayPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Setup input bindings for Play scenarios
}

void APlayPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Player controller update logic for Play scenarios
}

void APlayPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	// Handle pawn possession in Play scenarios
}

void APlayPlayerController::OnUnPossess()
{
	Super::OnUnPossess();

	// Handle pawn unpossession in Play scenarios
}

// Copyright Epic Games, Inc. All Rights Reserved.

#include "Logic/Play/PlayPlayerState.h"

APlayPlayerState::APlayPlayerState()
{
    // Set this actor to call Tick() every frame
    PrimaryActorTick.bCanEverTick = true;
}

void APlayPlayerState::BeginPlay()
{
    Super::BeginPlay();

    // Play-specific player state initialization
}

void APlayPlayerState::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Update player state logic for Play scenarios
}

void APlayPlayerState::CopyProperties(APlayerState* PlayerState)
{
    Super::CopyProperties(PlayerState);

    // Copy Play-specific player state properties
}

void APlayPlayerState::Reset()
{
    Super::Reset();

    // Reset Play-specific player state data
}

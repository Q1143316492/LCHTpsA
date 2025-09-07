// Copyright Epic Games, Inc. All Rights Reserved.

#include "Logic/Play/PlayHUD.h"
#include "Engine/Canvas.h"
#include "Engine/Engine.h"

APlayHUD::APlayHUD()
{
    // Set this actor to call Tick() every frame
    PrimaryActorTick.bCanEverTick = true;
}

void APlayHUD::BeginPlay()
{
    Super::BeginPlay();

    // Play-specific HUD initialization
}

void APlayHUD::DrawHUD()
{
    Super::DrawHUD();

    // Draw HUD elements for Play scenarios
    // Example: Health bar, score, crosshair, etc.
}

void APlayHUD::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // HUD update logic for Play scenarios
}

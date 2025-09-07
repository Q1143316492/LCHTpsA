// Copyright Epic Games, Inc. All Rights Reserved.

#include "Logic/Play/PlayGameMode.h"
#include "Logic/Play/PlayPlayerController.h"
#include "Logic/Play/PlayCharacter.h"
#include "Logic/Play/PlayGameState.h"
#include "Logic/Play/PlayPlayerState.h"
#include "Logic/Play/PlayHUD.h"

APlayGameMode::APlayGameMode()
{
    // Set default classes for Play game mode
    PlayerControllerClass = APlayPlayerController::StaticClass();
    DefaultPawnClass = APlayCharacter::StaticClass();
    GameStateClass = APlayGameState::StaticClass();
    PlayerStateClass = APlayPlayerState::StaticClass();
    HUDClass = APlayHUD::StaticClass();
}

void APlayGameMode::BeginPlay()
{
    Super::BeginPlay();

    // Play-specific initialization logic goes here
}

void APlayGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
    Super::InitGame(MapName, Options, ErrorMessage);

    // Additional game initialization logic for Play scenarios
}

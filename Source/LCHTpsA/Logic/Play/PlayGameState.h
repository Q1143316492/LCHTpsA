// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "PlayGameState.generated.h"

/**
 * Game State for Play scenarios - tracks game session data
 */
UCLASS()
class LCHTPSA_API APlayGameState : public AGameStateBase
{
    GENERATED_BODY()

public:
    /** Constructor */
    APlayGameState();

protected:
    /** Called when the game starts or when spawned */
    virtual void BeginPlay() override;

    /** Called every frame */
    virtual void Tick(float DeltaTime) override;

public:
    /** Called when game state is ready to receive updates */
    virtual void HandleBeginPlay() override;
};

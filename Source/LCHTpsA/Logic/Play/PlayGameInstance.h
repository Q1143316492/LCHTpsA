// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PlayGameInstance.generated.h"

/**
 * Game Instance for Play scenarios - handles persistent data across level transitions
 */
UCLASS()
class LCHTPSA_API UPlayGameInstance : public UGameInstance
{
    GENERATED_BODY()

public:
    /** Constructor */
    UPlayGameInstance();

protected:
    /** Called when the game instance is initialized */
    virtual void Init() override;

    /** Called when the game instance is shutting down */
    virtual void Shutdown() override;

public:
    /** Called when starting a new game session */
    virtual void OnStart() override;

    /** Called when a level is loaded */
    virtual void LoadComplete(const float LoadTime, const FString& MapName) override;
};

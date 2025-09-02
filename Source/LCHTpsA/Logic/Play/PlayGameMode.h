// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PlayGameMode.generated.h"

/**
 * Game Mode for Play scenarios in the third-person game
 */
UCLASS()
class LCHTPSA_API APlayGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	/** Constructor */
	APlayGameMode();

protected:
	/** Called when the game starts or when spawned */
	virtual void BeginPlay() override;

	/** Called to initialize the game mode */
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;
};

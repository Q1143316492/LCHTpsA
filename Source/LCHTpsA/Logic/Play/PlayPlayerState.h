// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "PlayPlayerState.generated.h"

/**
 * Player State for Play scenarios - tracks individual player data
 */
UCLASS()
class LCHTPSA_API APlayPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	/** Constructor */
	APlayPlayerState();

protected:
	/** Called when the game starts or when spawned */
	virtual void BeginPlay() override;

	/** Called every frame */
	virtual void Tick(float DeltaTime) override;

public:
	/** Called when player state is copied from another player state */
	virtual void CopyProperties(APlayerState* PlayerState) override;

	/** Called when player state data needs to be reset */
	virtual void Reset() override;
};

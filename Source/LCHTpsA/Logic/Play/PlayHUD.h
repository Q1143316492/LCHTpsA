// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PlayHUD.generated.h"

/**
 * HUD for Play scenarios
 */
UCLASS()
class LCHTPSA_API APlayHUD : public AHUD
{
	GENERATED_BODY()

public:
	/** Constructor */
	APlayHUD();

protected:
	/** Called when the game starts or when spawned */
	virtual void BeginPlay() override;

	/** Called to draw the HUD */
	virtual void DrawHUD() override;

public:
	/** Called every frame */
	virtual void Tick(float DeltaTime) override;
};

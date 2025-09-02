// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayPlayerController.generated.h"

/**
 * Player Controller for Play scenarios
 */
UCLASS()
class LCHTPSA_API APlayPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	/** Constructor */
	APlayPlayerController();

protected:
	/** Called when the game starts or when spawned */
	virtual void BeginPlay() override;

	/** Called to bind functionality to input */
	virtual void SetupInputComponent() override;

	/** Called every frame */
	virtual void Tick(float DeltaTime) override;

public:
	/** Called when possessing a pawn */
	virtual void OnPossess(APawn* InPawn) override;

	/** Called when unpossessing a pawn */
	virtual void OnUnPossess() override;
};

// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayPlayerController.generated.h"

class UInputMappingContext;

/**
 * Player Controller for Play scenarios
 */
UCLASS()
class LCHTPSA_API APlayPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	APlayPlayerController();

protected:
	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;

	virtual void Tick(float DeltaTime) override;

public:
	virtual void OnPossess(APawn* InPawn) override;

	virtual void OnUnPossess() override;

protected:
	UPROPERTY(EditAnywhere, Category = "Input")
	TArray<UInputMappingContext*> DefaultMappingContexts;
};

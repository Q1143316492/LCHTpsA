// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayCharacter.generated.h"

/**
 * Character class for Play scenarios in the third-person game
 */
UCLASS()
class LCHTPSA_API APlayCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	/** Constructor */
	APlayCharacter();

protected:
	/** Called when the game starts or when spawned */
	virtual void BeginPlay() override;

	/** Called to bind functionality to input */
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	/** Called every frame */
	virtual void Tick(float DeltaTime) override;

	/** Called when this Pawn is possessed by a PlayerController */
	virtual void PossessedBy(AController* NewController) override;

	/** Called when this Pawn is no longer possessed by a PlayerController */
	virtual void UnPossessed() override;
};

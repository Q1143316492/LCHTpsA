// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "PlayCharacter.generated.h"

/**
 * Character class for Play scenarios in the third-person game
 */
UCLASS()
class LCHTPSA_API APlayCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	APlayCharacter();

protected:
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	virtual void Tick(float DeltaTime) override;
	
	virtual void PossessedBy(AController* NewController) override;

	virtual void UnPossessed() override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;
};

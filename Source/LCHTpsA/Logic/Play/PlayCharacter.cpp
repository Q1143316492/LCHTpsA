// Copyright Epic Games, Inc. All Rights Reserved.

#include "Logic/Play/PlayCharacter.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

APlayCharacter::APlayCharacter()
{
	// Set this character to call Tick() every frame
	PrimaryActorTick.bCanEverTick = true;

	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
}

void APlayCharacter::BeginPlay()
{
	Super::BeginPlay();

	// Play-specific character initialization
}

void APlayCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Setup input bindings for Play character
}

void APlayCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Character update logic for Play scenarios
}

void APlayCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// Handle character possession in Play scenarios
}

void APlayCharacter::UnPossessed()
{
	Super::UnPossessed();

	// Handle character unpossession in Play scenarios
}

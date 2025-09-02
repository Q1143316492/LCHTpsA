// Copyright Epic Games, Inc. All Rights Reserved.

#include "Logic/Play/PlayPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"
#include "Widgets/Input/SVirtualJoystick.h"

APlayPlayerController::APlayPlayerController()
{
	PrimaryActorTick.bCanEverTick = true;
}

void APlayPlayerController::BeginPlay()
{
	Super::BeginPlay();

}

void APlayPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (IsLocalPlayerController())
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
		{
			for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
			{
				Subsystem->AddMappingContext(CurrentContext, 0);
			}
		}
	}
}

void APlayPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APlayPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
}

void APlayPlayerController::OnUnPossess()
{
	Super::OnUnPossess();
}

// Copyright Epic Games, Inc. All Rights Reserved.

#include "LCHCharacterAnimBase.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "Logic/Play/PlayCharacter.h"

ULCHCharacterAnimBase::ULCHCharacterAnimBase()
{
    
}

void ULCHCharacterAnimBase::NativeInitializeAnimation()
{
    Super::NativeInitializeAnimation();

    if (APlayCharacter* OwningCharacter = Cast<APlayCharacter>(TryGetPawnOwner()))
    {
        if (UCharacterMovementComponent* MoveComp = OwningCharacter->GetCharacterMovement())
        {
            Velocity = MoveComp->Velocity;
            VelocityLastFrame = Velocity;
            SpeedDirection = Velocity.GetSafeNormal();
        }
    }

}

void ULCHCharacterAnimBase::NativeUpdateAnimation(float DeltaSeconds)
{
    Super::NativeUpdateAnimation(DeltaSeconds);

    if (APlayCharacter* OwningCharacter = Cast<APlayCharacter>(TryGetPawnOwner()))
    {
        if (UCharacterMovementComponent* MoveComp = OwningCharacter->GetCharacterMovement())
        {
            // Update character states first (crouch, death, etc.)
            UpdateCharacterStates(MoveComp);
            
            // Update all movement-related data
            UpdateMovementData(DeltaSeconds);
        }
    }
}

void ULCHCharacterAnimBase::UpdateMovementData(float DeltaSeconds)
{
    APlayCharacter* OwningCharacter = Cast<APlayCharacter>(TryGetPawnOwner());
    if (!GetWorld() || !OwningCharacter)
    {
        return;
    }

    UCharacterMovementComponent* MoveComp = OwningCharacter->GetCharacterMovement();
    if (!MoveComp)
    {
        return;
    }

    // Update all movement-related properties through helper functions
    UpdateMovementProperties(MoveComp, DeltaSeconds);
    UpdateVelocityAndSpeed(MoveComp);
    UpdateAccelerationAndMovementFlags(MoveComp, DeltaSeconds);
    UpdateMovementMode(MoveComp);
    UpdateMovementState();
    UpdateStance();

    // Store previous frame data
    VelocityLastFrame = MoveComp->Velocity;
}

void ULCHCharacterAnimBase::UpdateCharacterStates(UCharacterMovementComponent* MoveComp)
{
    if (!MoveComp)
    {
        return;
    }

    // Update crouch state based on movement component
    bCrouch = MoveComp->bWantsToCrouch;
    
    // TODO: Implement proper death state logic based on character health/state
    // For now, just initialize to false
    bDie = false;
    
    // Note: This function could be expanded to include other character states like:
    // - Health-based states
    // - Combat states
    // - Special ability states
    // - Equipment states
}

void ULCHCharacterAnimBase::UpdateMovementProperties(UCharacterMovementComponent* MoveComp, float DeltaSeconds)
{
    if (!MoveComp)
    {
        return;
    }

    APlayCharacter* OwningCharacter = Cast<APlayCharacter>(TryGetPawnOwner());
    if (!OwningCharacter)
    {
        return;
    }

    // Update character transform for local space calculations
    CharacterTransform = OwningCharacter->GetActorTransform();
    
    // Update controller rotation if available
    if (AController* Controller = OwningCharacter->GetController())
    {
        ControllerRotator = Controller->GetControlRotation();
    }
}

void ULCHCharacterAnimBase::UpdateVelocityAndSpeed(UCharacterMovementComponent* MoveComp)
{
    if (!MoveComp)
    {
        return;
    }

    // Update velocity and calculate speed
    Velocity = MoveComp->Velocity;
    Speed = Velocity.Size2D();
    SpeedDirection = Velocity.GetSafeNormal();
    bHasVelocity = Speed > KINDA_SMALL_NUMBER;

    if (bHasVelocity)
    {
        LastNonZeroVelocity = Velocity;
    }

    // Convert world space velocity direction to local space if we have speed
    if (Speed > 0.f)
    {
        APlayCharacter* OwningCharacter = Cast<APlayCharacter>(TryGetPawnOwner());
        if (OwningCharacter)
        {
            SpeedDirection = OwningCharacter->GetRootComponent()->GetComponentTransform().InverseTransformVectorNoScale(SpeedDirection);
            SpeedDirection.Z = 0.f;
            SpeedDirection.Normalize();
        }
    }
}

void ULCHCharacterAnimBase::UpdateAccelerationAndMovementFlags(UCharacterMovementComponent* MoveComp, float DeltaSeconds)
{
    if (!MoveComp || !GetWorld())
    {
        return;
    }

    Acceleration = MoveComp->GetCurrentAcceleration();
    bAcceleration = Acceleration.Size() > KINDA_SMALL_NUMBER;
    bInAir = MoveComp->IsFalling();
    
    // Calculate velocity acceleration (rate of change of velocity direction)
    const float WorldDeltaSeconds = GetWorld()->GetDeltaSeconds();
    const float SafeDeltaSeconds = FMath::Max(WorldDeltaSeconds, KINDA_SMALL_NUMBER);
    VelocityAcceleration = (SpeedDirection - VelocityLastFrame.GetSafeNormal()) / SafeDeltaSeconds;
}

void ULCHCharacterAnimBase::UpdateMovementMode(UCharacterMovementComponent* MoveComp)
{
    if (!MoveComp)
    {
        return;
    }

    MovementModeLastFrame = MovementMode;
    
    switch (MoveComp->MovementMode)
    {
    case MOVE_None:
    case MOVE_Walking:
    case MOVE_NavWalking:
        MovementMode = ECharacterMovementModeType::Grounded;
        break;
    case MOVE_Falling:
        MovementMode = ECharacterMovementModeType::InAir;
        break;
    case MOVE_Swimming:
    case MOVE_Flying:
    case MOVE_Custom:
    case MOVE_MAX:
    default:
        // Keep current movement mode for unsupported modes
        break;
    }
}

void ULCHCharacterAnimBase::UpdateMovementState()
{
    MovementStateLastFrame = MovementState;
    
    if (bInAir)
    {
        MovementState = ECharacterMovementStateType::InAir;
    }
    else if (IsMoving())
    {
        MovementState = ECharacterMovementStateType::Moving;
    }
    else
    {
        MovementState = ECharacterMovementStateType::Idle;
    }
}

void ULCHCharacterAnimBase::UpdateStance()
{
    StanceLastFrame = Stance;
    if (bCrouch)
    {
        Stance = ECharacterStanceType::Crouching;
    }
    else
    {
        Stance = ECharacterStanceType::Standing;
    }
}

FVector ULCHCharacterAnimBase::CalculateRelativeAccelerationAmount() const
{
    const APlayCharacter* OwningCharacter = Cast<APlayCharacter>(GetOwningActor());
    if (!OwningCharacter)
    {
        return FVector::ZeroVector;
    }

    const UCharacterMovementComponent* MoveComp = OwningCharacter->GetCharacterMovement();
    if (!MoveComp)
    {
        return FVector::ZeroVector;
    }

    const float MaxAcceleration = MoveComp->GetMaxAcceleration();
    const float MaxBrakingDeceleration = MoveComp->GetMaxBrakingDeceleration();
    
    if (MaxAcceleration <= KINDA_SMALL_NUMBER || MaxBrakingDeceleration <= KINDA_SMALL_NUMBER)
    {
        return FVector::ZeroVector;
    }

    FVector RelativeAcceleration;
    
    // Check if we're accelerating (moving in same direction as velocity) or braking
    if (FVector::DotProduct(Acceleration, Velocity) > 0.f)
    {
        // Accelerating
        const FVector ClampedAcceleration = Acceleration.GetClampedToMaxSize(MaxAcceleration);
        RelativeAcceleration = ClampedAcceleration / MaxAcceleration;
    }
    else
    {
        // Braking or turning
        const FVector ClampedAcceleration = Acceleration.GetClampedToMaxSize(MaxBrakingDeceleration);
        RelativeAcceleration = ClampedAcceleration / MaxBrakingDeceleration;
    }
    
    // Convert to local space using character transform
    return CharacterTransform.GetRotation().UnrotateVector(RelativeAcceleration);
}

FVector ULCHCharacterAnimBase::GetActorForwardVector() const
{
    if (APlayCharacter* OwningCharacter = Cast<APlayCharacter>(TryGetPawnOwner()))
    {
        return OwningCharacter->GetActorForwardVector();
    }
    return FVector::ForwardVector;
}

FRotator ULCHCharacterAnimBase::GetActorRotation() const
{
    if (APlayCharacter* OwningCharacter = Cast<APlayCharacter>(TryGetPawnOwner()))
    {
        return OwningCharacter->GetActorRotation();
    }
    return FRotator::ZeroRotator;
}

FTransform ULCHCharacterAnimBase::GetActorTransform() const
{
    if (APlayCharacter* OwningCharacter = Cast<APlayCharacter>(TryGetPawnOwner()))
    {
        return OwningCharacter->GetActorTransform();
    }
    return FTransform::Identity;
}

bool ULCHCharacterAnimBase::IsMoving() const
{
    return Speed > 5.f && bAcceleration;
}

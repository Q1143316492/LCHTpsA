// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "LCHAnimBase.h"
#include "Logic/Character/LCHCharacterType.h"
#include "LCHCharacterAnimBase.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class LCHTPSA_API ULCHCharacterAnimBase : public ULCHAnimBase
{
    GENERATED_BODY()

public:
    ULCHCharacterAnimBase();

    void UpdateMovementData(float DeltaSeconds);

    UFUNCTION(BlueprintPure, Category = "AnimInstance|StepMatching", meta = (BlueprintThreadSafe))
    FVector CalculateRelativeAccelerationAmount() const;

    UFUNCTION(BlueprintPure, Category = "AnimInstance|StepMatching", meta = (BlueprintThreadSafe))
    virtual FVector GetActorForwardVector() const;

    UFUNCTION(BlueprintPure, Category = "AnimInstance|StepMatching", meta = (BlueprintThreadSafe))
    virtual FRotator GetActorRotation() const;

    UFUNCTION(BlueprintPure, Category = "AnimInstance|StepMatching", meta = (BlueprintThreadSafe))
    virtual FTransform GetActorTransform() const;

    UFUNCTION(BlueprintPure, Category = "AnimInstance|Move", meta = (BlueprintThreadSafe))
    bool IsMoving() const;

protected:
    virtual void NativeInitializeAnimation() override;

    virtual void NativeUpdateAnimation(float DeltaSeconds) override;

private:
    // Core update functions
    void UpdateCharacterStates(class UCharacterMovementComponent* MoveComp);
    void UpdateMovementProperties(class UCharacterMovementComponent* MoveComp, float DeltaSeconds);
    void UpdateVelocityAndSpeed(class UCharacterMovementComponent* MoveComp);
    void UpdateAccelerationAndMovementFlags(class UCharacterMovementComponent* MoveComp, float DeltaSeconds);
    void UpdateMovementMode(class UCharacterMovementComponent* MoveComp);
    void UpdateMovementState();
    void UpdateStance();

public:
    UPROPERTY(Category = LCHCharacter, BlueprintReadOnly)
    FTransform CharacterTransform = FTransform::Identity;

    UPROPERTY(Category = LCHCharacter, BlueprintReadOnly)
    FVector SpeedDirection = FVector::ZeroVector;

    UPROPERTY(Category = LCHCharacter, BlueprintReadOnly)
    FVector Velocity = FVector::ZeroVector;

    UPROPERTY(Category = LCHCharacter, BlueprintReadOnly)
    FVector Acceleration = FVector::ZeroVector;

    UPROPERTY(Category = LCHCharacter, BlueprintReadOnly)
    FVector VelocityAcceleration = FVector::ZeroVector;

    UPROPERTY(Category = LCHCharacter, BlueprintReadOnly)
    FVector VelocityLastFrame = FVector::ZeroVector;

    UPROPERTY(Category = LCHCharacter, BlueprintReadOnly)
    FVector LastNonZeroVelocity = FVector::ZeroVector;

    UPROPERTY(Category = LCHCharacter, BlueprintReadOnly)
    FRotator ControllerRotator = FRotator::ZeroRotator;

    UPROPERTY(Category = LCHCharacter, BlueprintReadOnly)
    float Speed = 0.f;

    UPROPERTY(Category = LCHCharacter, BlueprintReadOnly)
    bool bAcceleration = false;

    UPROPERTY(Category = LCHCharacter, BlueprintReadOnly)
    bool bHasVelocity = false;

    UPROPERTY(Category = LCHCharacter, BlueprintReadOnly)
    bool bInAir = false;

    UPROPERTY(Category = LCHCharacter, BlueprintReadOnly)
    bool bDie = false;

    UPROPERTY(Category = LCHCharacter, BlueprintReadOnly)
    bool bCrouch = false;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AnimAttribute")
    ECharacterMovementModeType MovementMode = ECharacterMovementModeType::Grounded;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AnimAttribute")
    ECharacterMovementModeType MovementModeLastFrame = ECharacterMovementModeType::Grounded;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AnimAttribute")
    ECharacterMovementStateType MovementState = ECharacterMovementStateType::Idle;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AnimAttribute")
    ECharacterMovementStateType MovementStateLastFrame = ECharacterMovementStateType::Idle;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AnimAttribute")
    ECharacterStanceType Stance = ECharacterStanceType::Standing;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AnimAttribute")
    ECharacterStanceType StanceLastFrame = ECharacterStanceType::Standing;
};

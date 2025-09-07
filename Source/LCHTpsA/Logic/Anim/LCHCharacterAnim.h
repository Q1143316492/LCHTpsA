// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Input/Reply.h"
#include "Logic/Anim/LCHCharacterAnimBase.h"
#include "PoseSearch/PoseSearchTrajectoryLibrary.h"
#include "Animation/AnimExecutionContext.h"
#include "Animation/AnimNodeReference.h"
#include "BoneControllers/AnimNode_OffsetRootBone.h"
#include "PoseSearch/PoseSearchTrajectoryTypes.h"
#include "PoseSearch/PoseSearchLibrary.h"
#include "Animation/TrajectoryTypes.h"
#include "Logic/Core/LCHCoreTypes.h"
#include "LCHCharacterAnim.generated.h"

class APlayCharacter;
/**
 * for movement matching
 */
UCLASS(Blueprintable, BlueprintType)
class LCHTPSA_API ULCHCharacterAnim : public ULCHCharacterAnimBase
{
    GENERATED_BODY()

public:
    ULCHCharacterAnim();

protected:
    virtual void NativeInitializeAnimation() override;
    virtual void NativeUpdateAnimation(float DeltaSeconds) override;

    void GenerateTrajectory(float DeltaSeconds);

public:
    UFUNCTION(BlueprintPure, Category = "AnimInstance|Move", meta = (BlueprintThreadSafe))
    bool IsStarting() const;

    UFUNCTION(BlueprintPure, Category = "AnimInstance|Move", meta = (BlueprintThreadSafe))
    bool ShouldTurnInPlace() const;

    UFUNCTION(BlueprintPure, Category = "AnimInstance|Move", meta = (BlueprintThreadSafe))
    bool IsDelaySpeed() const;

    UFUNCTION(BlueprintPure, Category = "AnimInstance|Move", meta = (BlueprintThreadSafe))
    bool IsPivot() const;

    UFUNCTION(BlueprintPure, Category = "AnimInstance|OffsetRoot", meta = (BlueprintThreadSafe))
    EOffsetRootBoneMode GetOffsetRootRotationMode() const;

    UFUNCTION(BlueprintPure, Category = "AnimInstance|OffsetRoot", meta = (BlueprintThreadSafe))
    EOffsetRootBoneMode GetOffsetRootTranslationMode() const;

    UFUNCTION(BlueprintPure, Category = "AnimInstance|OffsetRoot", meta = (BlueprintThreadSafe))
    float GetOffsetRootTranslationHalfLife() const;

    UFUNCTION(BlueprintPure, Category = "AnimInstance|OffsetRoot", meta = (BlueprintThreadSafe))
    float GetMMBlendTime();

    UFUNCTION(BlueprintPure, Category = "AnimInstance|OffsetRoot", meta = (BlueprintThreadSafe))
    EPoseSearchInterruptMode GetMMInterruptMode();

    UFUNCTION(BlueprintPure, Category = "AnimInstance|OffsetRoot", meta = (BlueprintThreadSafe))
    FQuat GetDesiredFacing();

    bool IsDebugDraw() const { return bDrawDebug; }
public:
    UPROPERTY(EditAnywhere, Category = "AnimAttribute")
    bool bDrawDebug;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AnimAttribute")
    FPoseSearchTrajectoryData TrajectoryGenerationData_Idle;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AnimAttribute")
    FPoseSearchTrajectoryData TrajectoryGenerationData_Moving;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AnimAttribute")
    FTransformTrajectory QueryTrajectory;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AnimAttribute")
    float PreviousDesiredControllerYaw;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AnimAttribute")
    FVector FutureVelocity;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AnimAttribute")
    ECharacterGaitType GaitType;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AnimAttribute")
    ECharacterGaitType GaitLastFrame;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AnimAttribute")
    ECharacterRotationModeType RotationModeType;

    UPROPERTY(Category = ShooterVRCharacter, BlueprintReadOnly)
    FRotator MeshAndActorOffset;

protected:
    UPROPERTY()
    TWeakObjectPtr<APlayCharacter> CachedCharacter;

    FResetBool bDelaySpeed;

    UPROPERTY()
    bool bDoOnceDelaySpeed;
};

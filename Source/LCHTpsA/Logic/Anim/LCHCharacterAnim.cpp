// Copyright Epic Games, Inc. All Rights Reserved.

#include "Logic/Anim/LCHCharacterAnim.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "PoseSearch/MotionMatchingAnimNodeLibrary.h"
#include "Camera/CameraComponent.h"


ULCHCharacterAnim::ULCHCharacterAnim()
{
    MeshAndActorOffset = FRotator::ZeroRotator;
    MeshAndActorOffset.Yaw = -90.f;

    bDoOnceDelaySpeed = false;
    RotationModeType = ECharacterRotationModeType::UseControllerRotation;
    GaitLastFrame = ECharacterGaitType::Walking;

}

void ULCHCharacterAnim::NativeInitializeAnimation()
{
    Super::NativeInitializeAnimation();

}

void ULCHCharacterAnim::NativeUpdateAnimation(float DeltaSeconds)
{
    Super::NativeUpdateAnimation(DeltaSeconds);
    GenerateTrajectory(DeltaSeconds);
}

void ULCHCharacterAnim::GenerateTrajectory(float DeltaSeconds)
{
    FTransformTrajectory OutTrajectory;
    UPoseSearchTrajectoryLibrary::PoseSearchGenerateTransformTrajectory(
        GetOwningComponent()->GetAnimInstance(),
        Speed > 0.f ? TrajectoryGenerationData_Moving : TrajectoryGenerationData_Idle,
        GetDeltaSeconds(),
        QueryTrajectory,
        PreviousDesiredControllerYaw,
        OutTrajectory,
        -1.f,
        30,
        0.1f,
        15);

    TArray<AActor*> ActorsToIgnore;
    ActorsToIgnore.Add(GetOwningActor());

    FPoseSearchTrajectory_WorldCollisionResults OutCollisionResult;
    UPoseSearchTrajectoryLibrary::HandleTransformTrajectoryWorldCollisions(
        GetWorld(),
        this,
        OutTrajectory,
        true,
        0.01f,
        QueryTrajectory,
        OutCollisionResult,
        ETraceTypeQuery::TraceTypeQuery1,
        false,
        ActorsToIgnore,
        IsDebugDraw() ? EDrawDebugTrace::ForDuration : EDrawDebugTrace::None,
        true,
        150.f);

    FTransformTrajectorySample OutATrajectorySample;
    FTransformTrajectorySample OutBTrajectorySample;
    UPoseSearchTrajectoryLibrary::GetTransformTrajectorySampleAtTime(QueryTrajectory, 0.5f, OutATrajectorySample, false);
    UPoseSearchTrajectoryLibrary::GetTransformTrajectorySampleAtTime(QueryTrajectory, 0.4f, OutBTrajectorySample, false);

    FutureVelocity = (OutATrajectorySample.Position - OutBTrajectorySample.Position) * 10.f;
}

bool ULCHCharacterAnim::IsStarting() const
{
    return false;
}

bool ULCHCharacterAnim::ShouldTurnInPlace() const
{
    return false;
}

bool ULCHCharacterAnim::IsDelaySpeed() const
{
    return false;
}

bool ULCHCharacterAnim::IsPivot() const
{
    return false;
}

EOffsetRootBoneMode ULCHCharacterAnim::GetOffsetRootRotationMode() const
{
    return EOffsetRootBoneMode();
}

EOffsetRootBoneMode ULCHCharacterAnim::GetOffsetRootTranslationMode() const
{
    return EOffsetRootBoneMode();
}

float ULCHCharacterAnim::GetOffsetRootTranslationHalfLife() const
{
    return 0.0f;
}

float ULCHCharacterAnim::GetMMBlendTime()
{
    return 0.0f;
}

EPoseSearchInterruptMode ULCHCharacterAnim::GetMMInterruptMode()
{
    return EPoseSearchInterruptMode();
}

FQuat ULCHCharacterAnim::GetDesiredFacing()
{
    return FQuat::Identity;
}

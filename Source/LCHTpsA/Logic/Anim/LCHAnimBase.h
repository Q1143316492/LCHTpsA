// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Retargeter/IKRetargeter.h"
#include "Retargeter/RetargetOps/IKChainsOp.h" // FRetargetIKChainSettings, FIKRetargetIKChainsOpSettings
#include "LCHAnimBase.generated.h"

/**
 * Base AnimInstance class for LCH project
 */
UCLASS(Blueprintable, BlueprintType)
class LCHTPSA_API ULCHAnimBase : public UAnimInstance
{
	GENERATED_BODY()

public:
	ULCHAnimBase();

protected:
	virtual void NativeInitializeAnimation() override;

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	UFUNCTION(BlueprintPure, Category = "RedirectAnim", meta = (BlueprintThreadSafe))
	FRetargetProfile GetRetargetProfile() const;

public:
	/**
	 * The IK Retargeter asset to use for this animation instance.
	 */
	UPROPERTY (VisibleAnywhere, BlueprintReadonly,Category = "AnimAttrubute")
	UIKRetargeter* IKRetargeter;

	UPROPERTY (EditDefaultsOnly, Category = "AnimAttrubute")
	TMap<FName, UIKRetargeter*> IKRetargeter_Map;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AnimAttribute")
	FRetargetIKChainSettings ChainSettings_LeftArm;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AnimAttribute")
	FRetargetIKChainSettings ChainSettings_RightArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AnimAttribute")
	FRetargetProfile CustomRetargetProfile;

protected:
	void UpdateChainSettings();
};

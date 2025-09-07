// Copyright Epic Games, Inc. All Rights Reserved.

#include "Logic/Anim/LCHAnimBase.h"
#include "GameFramework/Character.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Retargeter/IKRetargetProfile.h" // FRetargetProfile, FRetargetOpProfile

ULCHAnimBase::ULCHAnimBase()
{
}

void ULCHAnimBase::NativeInitializeAnimation()
{
    Super::NativeInitializeAnimation();
    UpdateChainSettings();
}

void ULCHAnimBase::NativeUpdateAnimation(float DeltaSeconds)
{
    Super::NativeUpdateAnimation(DeltaSeconds);
    UpdateChainSettings();
}

FRetargetProfile ULCHAnimBase::GetRetargetProfile() const
{
    // Animation Thread

    // Build an Op Profile for IK Chains Op and override left/right arm chain settings.
    FIKRetargetIKChainsOpSettings IKChainsSettings;
    {
        FRetargetIKChainSettings LeftSettings = ChainSettings_LeftArm;
        const float LeftAlpha = GetCurveValue(TEXT("Retarget_Hand_L_BlendToSource"));
        LeftSettings.BlendToSource = FMath::Lerp(ChainSettings_LeftArm.BlendToSource, 1.0, LeftAlpha);
        LeftSettings.StaticLocalOffset = FMath::Lerp(ChainSettings_LeftArm.StaticLocalOffset, FVector::ZeroVector, LeftAlpha);
        IKChainsSettings.ChainsToRetarget.Add(LeftSettings);
    }
    {
        FRetargetIKChainSettings RightSettings = ChainSettings_RightArm;
        const float RightAlpha = GetCurveValue(TEXT("Retarget_Hand_R_BlendToSource"));
        RightSettings.BlendToSource = FMath::Lerp(ChainSettings_RightArm.BlendToSource, 1.0, RightAlpha);
        RightSettings.StaticLocalOffset = FMath::Lerp(ChainSettings_RightArm.StaticLocalOffset, FVector::ZeroVector, RightAlpha);
        IKChainsSettings.ChainsToRetarget.Add(RightSettings);
    }

    FRetargetProfile Profile;
    FRetargetOpProfile OpProfile;
    OpProfile.OpToApplySettingsTo = NAME_None;
    OpProfile.SettingsToApply.InitializeAs(FIKRetargetIKChainsOpSettings::StaticStruct(), reinterpret_cast<const uint8*>(&IKChainsSettings));
    Profile.RetargetOpProfiles.Add(MoveTemp(OpProfile));
    return Profile;
}

void ULCHAnimBase::UpdateChainSettings()
{
    // Main Thread

    if (!GetOwningComponent() || GetOwningComponent()->ComponentTags.IsEmpty())
    {
        return;
    }

    FName InFindTag = GetOwningComponent()->ComponentTags[0];

    if (UIKRetargeter** InRetargeter = IKRetargeter_Map.Find(InFindTag))
    {
        IKRetargeter = *InRetargeter;
        FRetargetProfile AssetDefaults;
        AssetDefaults.FillProfileWithAssetSettings(*InRetargeter);

        TArray<FIKRetargetIKChainsOpSettings*> FoundSettings;
        AssetDefaults.GetOpSettingsByTypeInProfile<FIKRetargetIKChainsOpSettings>(FoundSettings);
        if (FoundSettings.Num() > 0)
        {
            const FIKRetargetIKChainsOpSettings* ChainsOp = FoundSettings[0];
            for (const FRetargetIKChainSettings& ChainSettings : ChainsOp->ChainsToRetarget)
            {
                if (ChainSettings.TargetChainName == TEXT("LeftArm"))
                {
                    ChainSettings_LeftArm = ChainSettings;
                }
                else if (ChainSettings.TargetChainName == TEXT("RightArm"))
                {
                    ChainSettings_RightArm = ChainSettings;
                }
            }
        }
    }
}

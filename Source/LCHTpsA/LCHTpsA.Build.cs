// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class LCHTpsA : ModuleRules
{
	public LCHTpsA(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"LCHTpsA",
			"LCHTpsA/Logic",
			"LCHTpsA/Logic/Play",
			"LCHTpsA/Variant_Platforming",
			"LCHTpsA/Variant_Platforming/Animation",
			"LCHTpsA/Variant_Combat",
			"LCHTpsA/Variant_Combat/AI",
			"LCHTpsA/Variant_Combat/Animation",
			"LCHTpsA/Variant_Combat/Gameplay",
			"LCHTpsA/Variant_Combat/Interfaces",
			"LCHTpsA/Variant_Combat/UI",
			"LCHTpsA/Variant_SideScrolling",
			"LCHTpsA/Variant_SideScrolling/AI",
			"LCHTpsA/Variant_SideScrolling/Gameplay",
			"LCHTpsA/Variant_SideScrolling/Interfaces",
			"LCHTpsA/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}

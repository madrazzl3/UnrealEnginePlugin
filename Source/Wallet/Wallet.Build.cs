// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Wallet : ModuleRules
{
    public Wallet(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core"
            }
            );

        bUseRTTI = true;
        bEnableExceptions = true;
        bEnableUndefinedIdentifierWarnings = true;

        CppStandard = CppStandardVersion.Cpp17;
        ShadowVariableWarningLevel = WarningLevel.Off;
    }
}

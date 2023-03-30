// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ArduinoProject : ModuleRules
{
	public ArduinoProject(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}

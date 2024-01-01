// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AlterAriaEditorTarget : TargetRules
{
	public AlterAriaEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V4;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_3;
		ExtraModuleNames.Add("AlterAria");
		RegisterModulesCreatedByRider();
	}

	private void RegisterModulesCreatedByRider()
	{
		ExtraModuleNames.AddRange(new string[] { "Character", "Input", "Player" });
	}
}

using UnrealBuildTool;

public class Input : ModuleRules
{
	public Input(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicDependencyModuleNames.AddRange(new [] { "Core", "EnhancedInput", "GameplayTags" });
		PrivateDependencyModuleNames.AddRange(new [] { "CoreUObject", "Engine" });
	}
}
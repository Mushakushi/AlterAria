using UnrealBuildTool;

public class Input : ModuleRules
{
	public Input(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicDependencyModuleNames.AddRange(new [] { "Core", "EnhancedInput" });
		PrivateDependencyModuleNames.AddRange(new [] { "CoreUObject", "Engine" });
	}
}
using UnrealBuildTool;

public class Input : ModuleRules
{
	public Input(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicDependencyModuleNames.AddRange(new [] { "Core" });
		PrivateDependencyModuleNames.AddRange(new [] { "CoreUObject", "Engine" });
	}
}
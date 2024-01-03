using UnrealBuildTool;

public class Character : ModuleRules
{
	public Character(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicDependencyModuleNames.AddRange(new [] { "Core", "ModularGameplay", "ModularGameplayActors" });
		PrivateDependencyModuleNames.AddRange(new [] { "CoreUObject", "Engine", "EnhancedInput" });
	}
}
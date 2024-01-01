// Copyright (c) 2024, Matthew Brown. All rights reserved.
// A lot of code from the Lyra sample project, which is
// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;
using EpicGames.Core;
using UnrealBuildBase;
using System;
using System.IO;

// ReSharper disable All

public class AlterAriaTarget : TargetRules
{
	public AlterAriaTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V4;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_3;
		ExtraModuleNames.Add("AlterAria");
		RegisterModulesCreatedByRider();
		ConfigureGameFeaturePlugins(this); 
	}

	private void RegisterModulesCreatedByRider()
	{
		ExtraModuleNames.AddRange(new string[] { "Character", "Input", "Player" });
	}
	
	private static Dictionary<string, JsonObject> AllPluginRootJsonObjectsByName = new();
	
	public static void ConfigureGameFeaturePlugins(TargetRules Target)
	{
		var bBuildAllGameFeaturePlugins = ShouldEnableAllGameFeaturePlugins(Target); 
		
		// Load all of the game feature .uplugin descriptors
		var CombinedPluginList = new List<FileReference>();

		if (Target.ProjectFile == null) return; 
		var GameFeaturePluginRoots = Unreal
			.GetExtensionDirs(Target.ProjectFile.Directory, Path.Combine("Plugins", "GameFeatures"));
		
		foreach (var SearchDir in GameFeaturePluginRoots)
		{
			CombinedPluginList.AddRange(PluginsBase.EnumeratePlugins(SearchDir));
		}

		if (CombinedPluginList.Count == 0) return; 
		
		var AllPluginReferencesByName = new Dictionary<string, List<string>>();

		foreach (var PluginFile in CombinedPluginList)
		{
			if (PluginFile == null || !FileReference.Exists(PluginFile)) continue;
			var bEnabled = false;
			var bForceDisabled = false;
			try
			{
				if (!AllPluginRootJsonObjectsByName.TryGetValue(PluginFile.GetFileNameWithoutExtension(), out var RawObject))
				{
					RawObject = JsonObject.Read(PluginFile);
					AllPluginRootJsonObjectsByName.Add(PluginFile.GetFileNameWithoutExtension(), RawObject);
				}

				// Validate that all GameFeaturePlugins are disabled by default
				// If EnabledByDefault is true and a plugin is disabled the name will be embedded in the executable
				// If this is a problem, enable this warning and change the game feature editor plugin templates
				// to disable EnabledByDefault for new plugins
				bool bEnabledByDefault;
				if (!RawObject.TryGetBoolField("EnabledByDefault", out bEnabledByDefault) || bEnabledByDefault == true)
				{
					// Console.WriteLine($"GameFeaturePlugin {PluginFile.GetFileNameWithoutExtension()}, "
					//				$"does not set EnabledByDefault to false. This is required for built-in GameFeaturePlugins.");
				}

				// Validate that all GameFeaturePlugins are set to explicitly loaded
				// This is important because game feature plugins expect to be loaded after project startup
				bool bExplicitlyLoaded;
				if (!RawObject.TryGetBoolField("ExplicitlyLoaded", out bExplicitlyLoaded) || bExplicitlyLoaded == false)
				{
					Console.WriteLine($"GameFeaturePlugin {PluginFile.GetFileNameWithoutExtension()}, " +
					                  $"does not set ExplicitlyLoaded to true. This is required for GameFeaturePlugins.");
				}

				// You could read an additional field here that is project specific, e.g.,
				//string PluginReleaseVersion;
				//if (RawObject.TryGetStringField("MyProjectReleaseVersion", out PluginReleaseVersion))
				//{
				//		bEnabled = SomeFunctionOf(PluginReleaseVersion, CurrentReleaseVersion) || bBuildAllGameFeaturePlugins;
				//}

				if (bBuildAllGameFeaturePlugins)
				{
					// We are in a mode where we want all game feature plugins, except ones we can't load or compile
					bEnabled = true;
				}

				// Prevent using editor-only feature plugins in non-editor builds
				bool bEditorOnly;
				if (RawObject.TryGetBoolField("EditorOnly", out bEditorOnly))
				{
					if (bEditorOnly && (Target.Type != TargetType.Editor) && !bBuildAllGameFeaturePlugins)
					{
						// The plugin is editor only and we are building a non-editor target, so it is disabled
						bForceDisabled = true;
					}
				}
				// else { // EditorOnly is optional }

				// some plugins should only be available in certain branches
				if (RawObject.TryGetStringField("RestrictToBranch", out var RestrictToBranch))
				{
					if (!Target.Version.BranchName.Equals(RestrictToBranch, StringComparison.OrdinalIgnoreCase))
					{
						// The plugin is for a specific branch, and this isn't it
						bForceDisabled = true;
						Console.WriteLine($"GameFeaturePlugin {PluginFile.GetFileNameWithoutExtension()} " +
						                  $"was marked as restricted to other branches. Disabling.");
					}
					else
					{
						Console.WriteLine($"GameFeaturePlugin {PluginFile.GetFileNameWithoutExtension()} " +
						                  $"was marked as restricted to this branch. Leaving enabled.");
					}
				}

				// Plugins can be marked as NeverBuild which overrides the above
				if (RawObject.TryGetBoolField("NeverBuild", out var bNeverBuild) && bNeverBuild)
				{
					// This plugin was marked to never compile, so don't
					bForceDisabled = true;
					Console.WriteLine($"GameFeaturePlugin {PluginFile.GetFileNameWithoutExtension()} " +
					                  $"was marked as NeverBuild, disabling.");
				}

				// Keep track of plugin references for validation later
				if (RawObject.TryGetObjectArrayField("Plugins", out var PluginReferencesArray))
				{
					foreach (var ReferenceObject in PluginReferencesArray)
					{
						if (!ReferenceObject.TryGetBoolField("Enabled", out var bRefEnabled) || bRefEnabled != true) continue;
						if (!ReferenceObject.TryGetStringField("Name", out var PluginReferenceName)) continue;
						
						var ReferencerName = PluginFile.GetFileNameWithoutExtension();
							
						if (!AllPluginReferencesByName.ContainsKey(ReferencerName))
						{
							AllPluginReferencesByName[ReferencerName] = new List<string>();
						}
						AllPluginReferencesByName[ReferencerName].Add(PluginReferenceName);
					}
				}
			}
			catch (JsonParseException ParseException)
			{
				Console.WriteLine($"Failed to parse GameFeaturePlugin file {PluginFile.GetFileNameWithoutExtension()}, " +
				                  $"disabling. Exception: {ParseException.Message}");
				bForceDisabled = true;
			}

			// Disabled has priority over enabled
			if (bForceDisabled)
			{
				bEnabled = false;
			}

			// Print out the final decision for this plugin
			Console.WriteLine($"ConfigureGameFeaturePlugins() has decided to " +
			                  $"{(bEnabled ? "enable" : (bForceDisabled ? "disable" : "ignore"))} feature " +
			                  $"{PluginFile.GetFileNameWithoutExtension()}");

			// Enable or disable it
			if (bEnabled)
			{
				Target.EnablePlugins.Add(PluginFile.GetFileNameWithoutExtension());
			}
			else if (bForceDisabled)
			{
				Target.DisablePlugins.Add(PluginFile.GetFileNameWithoutExtension());
			}
		}
	}

	public static bool ShouldEnableAllGameFeaturePlugins(TargetRules Target)
	{
		if (Target.Type == TargetType.Editor)
		{
			// With return true, editor builds will build all game feature plugins, but it may or may not load them all.
			// This is so you can enable plugins in the editor without needing to compile code.
			// return true;
		}

		// By default use the default plugin rules as set by the plugin browser in the editor
		// This is important because this code may not be run at all for launcher-installed versions of the engine
		return false;
	}
}

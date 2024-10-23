// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class MongoDB : ModuleRules
{
	public MongoDB(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		// Type = ModuleType.External;
		
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "Projects" });
		
		PrivateIncludePaths.AddRange(new string[] { Path.Combine(ModuleDirectory, "Private") });
		
		string IncludesPath = Path.GetFullPath(Path.Combine(ModuleDirectory, "ThirdParty/MongoLibrary/include/")); 
		PublicIncludePaths.Add(IncludesPath);
		
		foreach (var File in Directory.GetFiles(Path.GetFullPath(Path.Combine(ModuleDirectory, "ThirdParty/MongoLibrary/libs/"))))
		{
			PublicAdditionalLibraries.Add(File);
		}
		
		foreach(string File in Directory.GetFiles(Path.GetFullPath(Path.Combine(ModuleDirectory, "ThirdParty/MongoLibrary/bin/"))))
		{
			RuntimeDependencies.Add(File);
			PublicDelayLoadDLLs.Add(Path.GetFileName(File));
		}
	}
}


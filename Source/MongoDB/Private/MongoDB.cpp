// Copyright Epic Games, Inc. All Rights Reserved.

#include "MongoDB.h"

#include "HAL/FileManagerGeneric.h"
#include "Misc/MessageDialog.h"
#include "Modules/ModuleManager.h"

#include "Misc/Paths.h"
#include "HAL/PlatformProcess.h"
#include "Interfaces/IPluginManager.h"

#include <mongocxx/instance.hpp>

#define LOCTEXT_NAMESPACE "FMongoDBModule"

void FMongoDBModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	// Get the base directory of this plugin

	FString BaseDirectory = IPluginManager::Get().FindPlugin("MongoDB")->GetBaseDir();
	FString DLLPath = FPaths::Combine(BaseDirectory, TEXT("Source/MongoDB/ThirdParty/MongoDBLibrary/bin"));

	TArray<FString> Files;
	
	FFileManagerGeneric::Get().FindFiles(Files, *DLLPath, TEXT("*.dll"));
	for (auto File : Files)
	{
		void* Handle = FPlatformProcess::GetDllHandle(*File);
		if (Handle)
		{
			FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("ThirdPartyLibraryError", "Loaded third party library"));
		}
		else
		{
			FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("ThirdPartyLibraryError", "Failed to load third party library"));
		}		
	}

	static mongocxx::instance Instance{};
}

void FMongoDBModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	FString BaseDirectory = IPluginManager::Get().FindPlugin("MongoDB")->GetBaseDir();
	FString DLLPath = FPaths::Combine(BaseDirectory, TEXT("Source/MongoDB/ThirdParty/MongoDBLibrary/bin"));

	TArray<FString> Files;	
	FFileManagerGeneric::Get().FindFiles(Files, *DLLPath, TEXT("*.dll"));

	for (auto File : Files)
	{
		void* Handle = FPlatformProcess::GetDllHandle(*File);
		if(Handle)
		{
			FPlatformProcess::FreeDllHandle(Handle); 
		}		
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FMongoDBModule, MongoDB)

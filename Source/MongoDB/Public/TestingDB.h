// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "TestingDB.generated.h"

UCLASS(Blueprintable, BlueprintType)
class MONGODB_API UTestingDB : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void Test();

protected:
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FString DatabaseName = "admin";

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FString CollectionName = "test";

private:

	FString UriString = "mongodb+srv://thiagompmoraes:cllZLZIuYtImnzWQ@lostburncluster.ydgo7.mongodb.net/?retryWrites=true&w=majority&appName=LostburnCluster";
};


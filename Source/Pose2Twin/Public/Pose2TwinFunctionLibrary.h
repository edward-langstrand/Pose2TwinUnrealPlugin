// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Pose2TwinFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class POSE2TWIN_API UPose2TwinFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static FString BytesToStringUTF8(const TArray<uint8>& Bytes);
	
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static TArray<uint8> UTF8StringToBytes(const FString& String);
};

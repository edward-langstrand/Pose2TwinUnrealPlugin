// Fill out your copyright notice in the Description page of Project Settings.


#include "Pose2TwinFunctionLibrary.h"

#include <string>

#include "Kismet/KismetStringLibrary.h"

FString UPose2TwinFunctionLibrary::BytesToStringUTF8(const TArray<uint8>& Bytes)
{
	return FString(reinterpret_cast<const UTF8CHAR*>(Bytes.GetData()));	
}

TArray<uint8> UPose2TwinFunctionLibrary::UTF8StringToBytes(const FString& String)
{
	// TArray<uint8> OutBytes;
	// OutBytes.Reserve(String.Len());
	// StringToBytes(String, OutBytes.GetData(), String.Len()*2);
	// return OutBytes;
	
	// const TArray<UTF8CHAR> UTF8Array = StringToArray<UTF8CHAR, WIDECHAR>(String.GetCharArray().GetData(), String.Len());
	
	// return TArray<uint8>(UTF8Array);
	// TArray Result(reinterpret_cast<const uint8*>(TCHAR_TO_UTF8(String.GetCharArray().GetData())), String.Len());
	
	// Result.RemoveAt(0, 2);
	// Result.RemoveAt(Result.Num()-1);
	const FTCHARToUTF8 Convert(*String);
	return TArray<uint8>(reinterpret_cast<const uint8*>(Convert.Get()), Convert.Length());
}

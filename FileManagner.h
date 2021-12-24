// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FileManagner.generated.h"

/**
 * 
 */
UCLASS()
class LEARN_API UFileManagner : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	// check if file exists, the blueprint function"file exists" can only check files contained in the project folder,so have to make another one,but it can't do a damn thing now
	UFUNCTION(BlueprintCallable, Category = "Custom", meta = (Keywords = "Check"))
		static bool CheckFileExists(FString FilePath);

	// save the tarray<fstring> into a file 
	UFUNCTION(BlueprintCallable, Category = "Custom", meta = (Keywords = "Save"))
		static bool SaveStringArray2File(FString SavePath, FString FileName, TArray<FString> SaveText, bool AllowOverwriting);

	// if branch
	UFUNCTION(BlueprintCallable, Category = "Custom", meta = (Keywords = "IfCheck"))
		static void IfBranchQuickCheckPrint(bool flag);
	
	// load csv file to tarray<Fstring>
	UFUNCTION(BlueprintCallable, Category = "Custom", meta = (Keywords = "LoadCsv"))
		static TArray<FString> LoadCsv2TArray(FString FilePath);

	// find index by split the first string 
	UFUNCTION(BlueprintCallable, Category = "Custom", meta = (Keywords = "SplitString"))
		static TArray<FString> StringCutter(FString OriString,FString SplitTarget);

	UFUNCTION(BlueprintCallable, Category = "Custom", meta = (Keywords = "SplitString"))
		static void Test( FString InString, int InInt);

	UFUNCTION(BlueprintCallable, Category = "Custom", meta = (Keywords = "SplitString"))
		static TArray<FVector> VectorsMaker(TArray<FString> ArrayIn, int PointsNum);

	/*
	
	UFUNCTION(BluprintCallable, Category = "Custom", meta = (Keywords = "Load"))
		static TArray<FString> LoadCsv2TArray(FString FilePath);

	UFUNCTION(BluprintCallable, Category = "Custom", meta = (Keywords = "makevectors"))
		static TArray<FVector> MakeVectors(FString FilePath);
	*/
	
};

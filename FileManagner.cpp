// Fill out your copyright notice in the Description page of Project Settings.


#include "FileManagner.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "Engine.h"
#include "printstring.h"
#include "HAL/PlatformFilemanager.h"


bool UFileManagner::CheckFileExists(FString FilePath)
{
	return FPaths::FileExists(FilePath);
}


bool UFileManagner::SaveStringArray2File(FString SavePath, FString FileName, TArray<FString> SaveText, bool AllowOverwriting)
{
	// complete the filepath
	SavePath += '\\';
	SavePath += FileName;
	if (true)
	{
		;
	}
	return false;
}

void UFileManagner::IfBranchQuickCheckPrint(bool flag)
{
	if (flag) 
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, TEXT("True"));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, TEXT("False"));
	}
}

TArray<FString> UFileManagner::LoadCsv2TArray(FString FilePath)
{
	TArray<FString> file_content;
	if (CheckFileExists(FilePath))
	{
		FFileHelper::LoadFileToStringArray(file_content, *FilePath);
		return file_content;
	}
	else
	{
		return file_content;
	}
}

/*

bool UFileManagner::StringCutter(FString OriString, FString SplitTarget, TArray<FString> StringItems)
{
	if (OriString.Find(SplitTarget) < 0)
	{
		return false;
	}
	bool cut_flag_ = true;
	FString left_string_;
	FString right_string_;
	while (cut_flag_)
	{
		cut_flag_ = OriString.Split(SplitTarget, &left_string_, &right_string_);
		if (cut_flag_)
		{
			printfstring(left_string_);
			StringItems.Add(left_string_);
			OriString = right_string_;
		}
		else
		{
			cut_flag_ = false;
		}
	}
	return !cut_flag_;
}
*/

TArray<FString> UFileManagner::StringCutter(FString OriString, FString SplitTarget)
{
	TArray<FString> Res_;
	if (OriString.Find(SplitTarget) < 0)
	{
		return Res_;
	}
	else
	{
		bool cut_flag_ = true;
		FString left_string_;
		FString right_string_;
		while (cut_flag_)
		{
			cut_flag_ = OriString.Split(SplitTarget, &left_string_, &right_string_);
			if (cut_flag_)
			{
				Res_.Add(left_string_);
				OriString = right_string_;
			}
			else
			{
				cut_flag_ = false;
			}
		}
	}
	return Res_;
}

void UFileManagner::Test(FString InString, int InInt)
{
	InString = "Has Changed";
	InInt = 100;
}

TArray<FVector> UFileManagner::VectorsMaker(TArray<FString> ArrayIn, int PointsNum = 4)
{
	TArray<FVector> Res_;
	int32 array_length = ArrayIn.Num();
	if (array_length != PointsNum*3)
	{
		return Res_;
	}
	else
	{	
		// define a lambda func to transform FString into float
		auto s2f = [=](FString str_) {return FCString::Atof(*str_); };
		// define a lambda func to transform 3 FString into FVector
		auto maker = [=](FString x, FString y, FString z) { return FVector(s2f(x), s2f(y), s2f(z)); };
		for (int i = 0; i < 4; i++)
		{
			// add the points vector into res_
			Res_.Add(maker(ArrayIn[i], ArrayIn[i+1], ArrayIn[i+2]));
		}
	}
	return Res_;
}





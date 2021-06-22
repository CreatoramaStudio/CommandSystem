// Fill out your copyright notice in the Description page of Project Settings.

#include "CommandSystemLog.h"

DEFINE_LOG_CATEGORY(LogCommandSystem);

void PrintInfoCommands(const FString& String)
{
	UE_LOG(LogCommandSystem, Display, TEXT("%s"), *String);
}

void PrintWarningCommands(const FString& String)
{
	UE_LOG(LogCommandSystem, Warning, TEXT("%s"), *String);
}

void PrintErrorCommands(const FString& String)
{
	UE_LOG(LogCommandSystem, Error, TEXT("%s"), *String);
}
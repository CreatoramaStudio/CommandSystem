// Fill out your copyright notice in the Description page of Project Settings.

#include "LogCommandSystem.h"

DEFINE_LOG_CATEGORY(LogCommandSystem);

void FLogCommandSystem::Info(const FString& String)
{
	UE_LOG(LogCommandSystem, Display, TEXT("%s"), *String);
}

void FLogCommandSystem::Warning(const FString& String)
{
	UE_LOG(LogCommandSystem, Warning, TEXT("%s"), *String);
}

void FLogCommandSystem::Error(const FString& String)
{
	UE_LOG(LogCommandSystem, Error, TEXT("%s"), *String);
}
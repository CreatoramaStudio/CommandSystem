// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/CommandInterfaces.h"
#include "Subsystems/WorldSubsystem.h"

#include "CommandSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCommandChanged);

/**
* 
*/
UCLASS()
class COMMANDSYSTEM_API UCommandSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

	public:

	UPROPERTY(BlueprintAssignable, Category = "Commands")
	FCommandChanged OnAddCommand;

	UPROPERTY(BlueprintAssignable, Category = "Commands")
	FCommandChanged OnUndoCommand;

	UPROPERTY(BlueprintAssignable, Category = "Commands")
	FCommandChanged OnRedoCommand;

	protected:

	UPROPERTY()
	TArray<TScriptInterface<ICommand>> Commands;

	UPROPERTY()
	int32 Index;

	private:

	public:

	UCommandSubsystem();

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "Commands")
	void AddCommand(const TScriptInterface<ICommand> Command);

	UFUNCTION(BlueprintCallable, Category = "Commands")
	void UndoCommand();

	UFUNCTION(BlueprintCallable, Category = "Commands")
	void RedoCommand();

	UFUNCTION(BlueprintCallable, Category = "Commands")
	void ClearAllCommands();

	UFUNCTION(BlueprintCallable, Category = "Commands")
	TArray<UObject*> GetCommandObjects();

	UFUNCTION(BlueprintPure, Category = "Commands")
	int32 GetNumberOfCommands() const;

	UFUNCTION(BlueprintPure, Category = "Commands")
	int32 GetIndex() const;

	UFUNCTION(BlueprintPure, Category = "Commands")
	bool CanUndoCommand() const;

	UFUNCTION(BlueprintPure, Category = "Commands")
	bool CanRedoCommand() const;

	protected:

	private:
	
};
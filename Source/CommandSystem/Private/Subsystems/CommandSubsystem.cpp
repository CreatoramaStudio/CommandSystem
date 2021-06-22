// Fill out your copyright notice in the Description page of Project Settings.

#include "Subsystems/CommandSubsystem.h"
#include "CommandSystemLog.h"

UCommandSubsystem::UCommandSubsystem()
{
	
}

void UCommandSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	
}

void UCommandSubsystem::Deinitialize()
{
	
}

void UCommandSubsystem::AddCommand(const TScriptInterface<ICommand> Command)
{
	if (Index < Commands.Num())
	{
		Commands.RemoveAt(Index,Commands.Num() - Index);
	}
	Commands.Add(Command);
	ICommand::Execute_Execute(Command.GetObject());
	Index++;
}

void UCommandSubsystem::UndoCommand()
{
	if (Commands.Num() == 0)
	{
		return;
	}
	if (Index > 0)
	{
		ICommand::Execute_Undo(Commands[Index - 1].GetObject());
		Index--;
	}
}

void UCommandSubsystem::RedoCommand()
{
	if (Commands.Num() == 0)
	{
		return;
	}

	if (Index < Commands.Num())
	{
		Index++;
		ICommand::Execute_Execute(Commands[Index - 1].GetObject());
	}
}

TArray<UObject*> UCommandSubsystem::GetCommandObjects()
{
	TArray<UObject*> Objects;
	for(auto Command : Commands)
	{
		Objects.Add(Command.GetObject());
	}
	return Objects;
}

int32 UCommandSubsystem::GetNumberOfCommands() const
{
	return Commands.Num();
}

int32 UCommandSubsystem::GetIndex() const
{
	return Index;
}

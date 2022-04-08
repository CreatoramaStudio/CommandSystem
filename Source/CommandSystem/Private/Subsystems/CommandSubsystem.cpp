// Fill out your copyright notice in the Description page of Project Settings.

#include "Subsystems/CommandSubsystem.h"
#include "LogCommandSystem.h"

UCommandSubsystem::UCommandSubsystem()
{
	
}

void UCommandSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	
}

void UCommandSubsystem::Deinitialize()
{
	ClearAllCommands();
}

void UCommandSubsystem::AddCommand(const TScriptInterface<ICommand> Command)
{
	if (!Command.GetObject())
	{
		return;
	}
	
	if (Index < Commands.Num())
	{
		Commands.RemoveAt(Index,Commands.Num() - Index);
	}
	
	Commands.Add(Command);
	ICommand::Execute_Execute(Command.GetObject());
	Index++;

	
	OnAddCommand.IsBound() ? OnAddCommand.Broadcast() : FLogCommandSystem::Info("UCommandSubsystem::AddCommand OnAddCommand.IsBound is false");
}

void UCommandSubsystem::UndoCommand()
{
	if (Commands.Num() <= 0)
	{
		return;
	}
	
	if (Index > 0)
	{
		ICommand::Execute_Undo(Commands[FMath::Clamp(Index - 1,0,Commands.Num()-1)].GetObject());
		Index--;

		OnUndoCommand.IsBound() ? OnUndoCommand.Broadcast() : FLogCommandSystem::Info("UCommandSubsystem::UndoCommand OnUndoCommand.IsBound is false");
	}
}

void UCommandSubsystem::RedoCommand()
{
	if (Commands.Num() <= 0)
	{
		return;
	}

	if (Index < Commands.Num())
	{
		Index++;
		ICommand::Execute_Execute(Commands[FMath::Clamp(Index - 1,0,Commands.Num()-1)].GetObject());

		OnRedoCommand.IsBound() ? OnRedoCommand.Broadcast() : FLogCommandSystem::Info("UCommandSubsystem::RedoCommand OnRedoCommand.IsBound is false");
	}
}

void UCommandSubsystem::ClearAllCommands()
{
	Index = 0;
	Commands.Empty();
}

TArray<UObject*> UCommandSubsystem::GetCommandObjects()
{
	TArray<TObjectPtr<UObject>> Objects;
	
	for(auto Command : Commands)
	{
		if (const TObjectPtr<UObject> Object = Command.GetObject())
		{
			Objects.Add(Object);
		}
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

bool UCommandSubsystem::CanUndoCommand() const
{
	return Commands.Num() > 0 && Index > 0;
}

bool UCommandSubsystem::CanRedoCommand() const
{
	return Commands.Num() > 0 && Index < Commands.Num();
}

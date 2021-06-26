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

	if (OnAddCommand.IsBound())
	{
		OnAddCommand.Broadcast();
	}
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

		if (OnUndoCommand.IsBound())
		{
			OnUndoCommand.Broadcast();
		}
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

		if (OnRedoCommand.IsBound())
		{
			OnRedoCommand.Broadcast();
		}
	}
}

void UCommandSubsystem::ClearAllCommands()
{
	Index = 0;
	Commands.Empty();
}

TArray<UObject*> UCommandSubsystem::GetCommandObjects()
{
	TArray<UObject*> Objects;
	
	for(auto Command : Commands)
	{
		if (UObject* Object = Command.GetObject())
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

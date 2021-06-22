#pragma once

#include "UObject/Interface.h"
#include "CommandInterfaces.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UCommand: public UInterface
{
	GENERATED_BODY()
};

/**
*
*/
class COMMANDSYSTEM_API ICommand
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
	public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Command")
	void Execute();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Command")
	void Undo();
	
};
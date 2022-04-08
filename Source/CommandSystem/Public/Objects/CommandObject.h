#pragma once

#include "CoreMinimal.h"
#include "Interfaces/CommandInterfaces.h"
#include "CommandObject.generated.h"

class UCommandSubsystem;
/**
* 
*/
UCLASS(Blueprintable)
class COMMANDSYSTEM_API UCommandObject : public UObject, public ICommand
{
	GENERATED_BODY()

	public:
	
	protected:

	UPROPERTY(BlueprintReadOnly, Category = "Commands",meta = (ExposeOnSpawn="true"))
	TObjectPtr<AActor> Owner;

	private:

	public:

	UCommandObject();

	virtual UWorld* GetWorld() const override;

	protected:

	private:

};

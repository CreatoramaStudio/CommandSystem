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

	private:

	public:

	protected:

	UFUNCTION(BlueprintCallable, Category = "Commands")
	AActor* SpawnActor(const TSubclassOf<AActor> Class, const FTransform Transform, const ESpawnActorCollisionHandlingMethod CollisionHandlingMethod,AActor* Owner,APawn* Instigator);

	UFUNCTION(BlueprintPure, Category = "Commands")
	UCommandSubsystem* GetCommandSubsystem() const;

	private:

};

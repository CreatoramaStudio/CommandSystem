#include "Objects/CommandObject.h"
#include "Subsystems/CommandSubsystem.h"

AActor* UCommandObject::SpawnActor(const TSubclassOf<AActor> Class, const FTransform Transform, const ESpawnActorCollisionHandlingMethod CollisionHandlingMethod,AActor* Owner,APawn* Instigator)
{
	FActorSpawnParameters Parameters;
	Parameters.Owner = Owner;
	Parameters.Instigator = Instigator;
	Parameters.SpawnCollisionHandlingOverride = CollisionHandlingMethod;
	return  GetWorld()->SpawnActor<AActor>(Class,Transform,Parameters);
}

UCommandSubsystem* UCommandObject::GetCommandSubsystem() const
{
	return  GetWorld()->GetSubsystem<UCommandSubsystem>();
}

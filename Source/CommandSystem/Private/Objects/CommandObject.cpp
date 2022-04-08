#include "Objects/CommandObject.h"

UCommandObject::UCommandObject()
{
}

UWorld* UCommandObject::GetWorld() const
{
	if(!Owner)
	{
		return nullptr;
	}

	return Owner->GetWorld();
}

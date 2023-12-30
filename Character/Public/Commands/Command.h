// Copyright (c) 2024, Matthew Brown. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Command.generated.h"

class UBaseCharacterComponent; 

/**
 * 	A command object that acts upon a player. 
 */
UCLASS(Abstract, Blueprintable, BlueprintType)
class CHARACTER_API UCommand : public UObject
{
	GENERATED_BODY()

public:
	/** Controlled character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UBaseCharacterComponent* Target;
	
	/** Executes this command. */
	UFUNCTION(BlueprintCallable)
	virtual void Execute() PURE_VIRTUAL(UCommand::Execute);
};

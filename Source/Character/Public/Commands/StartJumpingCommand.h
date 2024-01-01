// Copyright (c) 2024, Matthew Brown. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Command.h"
#include "UObject/Object.h"
#include "StartJumpingCommand.generated.h"

/**
 * Command that makes a target character jump. 
 */
UCLASS()
class CHARACTER_API UStartJumpingCommand : public UCommand
{
	GENERATED_BODY()

public:
	UStartJumpingCommand();
	
	/**
	 * Sets the initial values for this command
	 * @param Character The target character. 
	 */
	UFUNCTION()
	void Initialize(ABaseCharacterComponent* Character); 

	/** Executes the command. */
	virtual void Execute() override;
};

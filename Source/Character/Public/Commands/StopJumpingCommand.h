// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Command.h"
#include "UObject/Object.h"
#include "StopJumpingCommand.generated.h"

/**
 * A command that makes a target character stop jumping. 
 */
UCLASS()
class CHARACTER_API UStopJumpingCommand : public UCommand
{
	GENERATED_BODY()

public:
	UStopJumpingCommand();
	
	/**
	 * Sets the initial values for this command
	 * @param Character The target character. 
	 */
	UFUNCTION()
	void Initialize(UBaseCharacterComponent* Character);

	/** Executes the command. */
	virtual void Execute() override;
};

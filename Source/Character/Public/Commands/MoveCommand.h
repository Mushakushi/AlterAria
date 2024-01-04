// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Command.h"
#include "UObject/Object.h"
#include "MoveCommand.generated.h"

class ABaseCharacter; 

/**
 * A command that makes a target character move. 
 */
UCLASS()
class CHARACTER_API UMoveCommand : public UCommand
{
	GENERATED_BODY()

public:
	UMoveCommand(); 

	/** The vector used to execute the command */
	UPROPERTY()
	FVector2D MovementVector;

	/**
	 * Sets the initial values for this command
	 * @param Character The target character. 
	 * @param Vector The direction to move. 
	 */
	void Initialize(ABaseCharacter* Character, const FVector2D& Vector);
	
	virtual void Execute() override;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Command.h"
#include "UObject/Object.h"
#include "LookCommand.generated.h"

class ABaseCharacterComponent; 

/**
 * A command that makes a target character move. 
 */
UCLASS()
class CHARACTER_API ULookCommand : public UCommand
{
	GENERATED_BODY()

public:
	ULookCommand(); 

	/** Where to look */
	UPROPERTY()
	FVector2D LookAxisVector;

	/**
	 * Sets the initial values for this command
	 * @param Character The target character. 
	 * @param Vector The direction to move. 
	 */
	UFUNCTION()
	void Initialize(ABaseCharacterComponent* Character, const FVector2D& Vector);

	/** Executes the command. */
	virtual void Execute() override;
};

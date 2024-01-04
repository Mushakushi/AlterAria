// Copyright (c) 2024, Matthew Brown. All rights reserved.


#include "Commands/MoveCommand.h"
#include "..\..\Public\BaseCharacter.h"

UMoveCommand::UMoveCommand()
{
	MovementVector = FVector2D();
}

void UMoveCommand::Initialize(ABaseCharacter* Character, const FVector2D& Vector)
{
	Target = Character;
	MovementVector = Vector; 
}

void UMoveCommand::Execute()
{
	if (Target == nullptr) return; 
	Target->Move(MovementVector);
}


// Copyright (c) 2024, Matthew Brown. All rights reserved.


#include "Commands/LookCommand.h"
#include "BaseCharacter.h"

ULookCommand::ULookCommand()
{
	LookAxisVector = FVector2D(); 
}

void ULookCommand::Initialize(ABaseCharacter* Character, const FVector2D& Vector)
{
	Target = Character;
	LookAxisVector = Vector; 
}

void ULookCommand::Execute()
{
	if (Target == nullptr) return; 
	Target->Look(LookAxisVector); 
}


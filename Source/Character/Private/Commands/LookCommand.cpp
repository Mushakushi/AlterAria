// Copyright (c) 2024, Matthew Brown. All rights reserved.


#include "Commands/LookCommand.h"
#include "..\..\Public\BaseCharacterComponent.h"

ULookCommand::ULookCommand()
{
	LookAxisVector = FVector2D(); 
}

void ULookCommand::Initialize(ABaseCharacterComponent* Character, const FVector2D& Vector)
{
	Target = Character;
	LookAxisVector = Vector; 
}

void ULookCommand::Execute()
{
	if (Target == nullptr) return; 
	Target->Look(LookAxisVector); 
}


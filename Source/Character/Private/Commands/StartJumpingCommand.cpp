// Copyright (c) 2024, Matthew Brown. All rights reserved.


#include "Commands/StartJumpingCommand.h"
#include "..\..\Public\BaseCharacterComponent.h"

UStartJumpingCommand::UStartJumpingCommand()
{
}

void UStartJumpingCommand::Initialize(ABaseCharacterComponent* Character)
{
	Target = Character; 
}

void UStartJumpingCommand::Execute()
{
	if (Target == nullptr) return; 
	Target->Jump(); 
}

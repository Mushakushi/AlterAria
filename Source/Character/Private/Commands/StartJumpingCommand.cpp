// Copyright (c) 2024, Matthew Brown. All rights reserved.


#include "Commands/StartJumpingCommand.h"
#include "..\..\Public\BaseCharacter.h"

UStartJumpingCommand::UStartJumpingCommand()
{
}

void UStartJumpingCommand::Initialize(ABaseCharacter* Character)
{
	Target = Character; 
}

void UStartJumpingCommand::Execute()
{
	if (Target == nullptr) return; 
	Target->Jump(); 
}

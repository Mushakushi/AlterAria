// Copyright (c) 2024, Matthew Brown. All rights reserved.


#include "Commands/StopJumpingCommand.h"
#include "..\..\Public\BaseCharacter.h"

UStopJumpingCommand::UStopJumpingCommand()
{
}

void UStopJumpingCommand::Initialize(ABaseCharacter* Character)
{
	Target = Character; 
}

void UStopJumpingCommand::Execute()
{
	if (Target == nullptr) return; 
	Target->StopJumping();
}

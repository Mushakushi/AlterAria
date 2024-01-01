// Copyright (c) 2024, Matthew Brown. All rights reserved.


#include "Commands/StopJumpingCommand.h"
#include "..\..\Public\BaseCharacterComponent.h"

UStopJumpingCommand::UStopJumpingCommand()
{
}

void UStopJumpingCommand::Initialize(ABaseCharacterComponent* Character)
{
	Target = Character; 
}

void UStopJumpingCommand::Execute()
{
	if (Target == nullptr) return; 
	Target->StopJumping();
}

// Copyright (c) 2024, Matthew Brown. All rights reserved.


#include "BaseCharacterMovementComponent.h"


// Sets default values for this component's properties
UBaseCharacterMovementComponent::UBaseCharacterMovementComponent()
{
	
}

bool UBaseCharacterMovementComponent::CanAttemptJump() const
{
	// can jump while crouching, Falling included for double-jump and non-zero jump hold time, but validated by character.
	// https://github.com/EpicGames/UnrealEngine/blob/072300df18a94f18077ca20a14224b5d99fee872/Samples/Games/Lyra/Source/LyraGame/Character/LyraCharacterMovementComponent.cpp
	return IsJumpAllowed() && (IsMovingOnGround() || IsFalling()); 
}

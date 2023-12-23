// Copyright (c) 2024, Matthew Brown. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "InputHandler.generated.h"

/**
 * Manages input mappings and bindings using an input config data asset.
 * @see https://github.com/EpicGames/UnrealEngine/blob/072300df18a94f18077ca20a14224b5d99fee872/Samples/Games/Lyra/Source/LyraGame/Input/LyraInputComponent.h
 */
UCLASS(Config=Input) 
class INPUT_API UInputHandler : public UObject
{
	GENERATED_BODY()

public:
	template<class UserClass, typename FunctionType>
	void BindAction();
};

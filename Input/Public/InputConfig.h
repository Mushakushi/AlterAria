// Copyright (c) 2024, Matthew Brown. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "InputConfig.generated.h"

/**
 * Non-mutable data asset that contains input configuration properties.
 * @see https://github.com/EpicGames/UnrealEngine/blob/072300df18a94f18077ca20a14224b5d99fee872/Samples/Games/Lyra/Source/LyraGame/Input/LyraInputConfig.h
 */
UCLASS(BlueprintType, Const)
class INPUT_API UInputConfig : public UObject
{
	GENERATED_BODY()

public:
	
};

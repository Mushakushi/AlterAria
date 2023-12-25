// Copyright (c) 2024, Matthew Brown. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Object.h"
#include "InputConfig.generated.h"

class UInputAction;

/**
 * Non-mutable data asset that contains input configuration properties.
 * @see https://github.com/EpicGames/UnrealEngine/blob/072300df18a94f18077ca20a14224b5d99fee872/Samples/Games/Lyra/Source/LyraGame/Input/LyraInputConfig.h
 */
UCLASS(BlueprintType, Const)
class INPUT_API UInputConfig : public UObject
{
	GENERATED_BODY()

public:
	UInputConfig();

	/** Maps a gameplay tag to an input action */ 
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Meta = (TitleProperty = "InputAction"))
	TMap<FGameplayTag, TObjectPtr<const UInputAction>> TaggedInputActions; 
};

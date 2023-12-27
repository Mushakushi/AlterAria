// Copyright (c) 2024, Matthew Brown. All rights reserved.

#pragma once

#include "InputConfig.h"
#include "EnhancedInputComponent.h"
#include "InputHandler.generated.h"

/**
 * Manages input mappings and bindings using an input config data asset.
 * @see https://github.com/EpicGames/UnrealEngine/blob/072300df18a94f18077ca20a14224b5d99fee872/Samples/Games/Lyra/Source/LyraGame/Input/LyraInputComponent.h
 */
UCLASS(Config=Input)
class INPUT_API UInputHandler : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
	UInputHandler();
	
	template<class UserClass, typename FunctionType>
	void BindInputAction(const UInputConfig* InputConfig, const FGameplayTag& InputTag, ETriggerEvent TriggerEvent, UserClass* Object, FunctionType Function);
};

template <class TObject, typename TFunction>
void UInputHandler::BindInputAction(const UInputConfig* InputConfig, const FGameplayTag& InputTag, ETriggerEvent TriggerEvent, TObject* Object, TFunction Function)
{
	check(InputConfig); 
	if (const UInputAction* InputAction = *InputConfig->TaggedInputActions.Find(InputTag))
	{
		BindAction(InputAction, TriggerEvent, Object, Function); 
	}
}



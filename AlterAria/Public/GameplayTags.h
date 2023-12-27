// Copyright (c) 2024, Matthew Brown. All rights reserved.

#pragma once

#include "NativeGameplayTags.h"

namespace GameplayTags
{
	ALTERARIA_API	UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Move);
	ALTERARIA_API	UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Look_Mouse);
	ALTERARIA_API	UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Look_Stick);
	ALTERARIA_API	UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Jump);

	ALTERARIA_API	FGameplayTag FindTagByString(const FString& TagString, bool bMatchPartialString = false);
};
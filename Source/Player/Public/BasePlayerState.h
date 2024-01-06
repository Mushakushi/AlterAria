// Copyright (c) 2024, Matthew Brown. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "ModularPlayerState.h"
#include "UObject/Object.h"
#include "BasePlayerState.generated.h"

class ABasePlayerController;
/**
 * 
 */
UCLASS()
class PLAYER_API ABasePlayerState : public AModularPlayerState
{
	GENERATED_BODY()

public:
	ABasePlayerState();

	UFUNCTION(BlueprintCallable, Category = "Game|PlayerState")
	ABasePlayerController* GetBasePlayerController() const;

	
};

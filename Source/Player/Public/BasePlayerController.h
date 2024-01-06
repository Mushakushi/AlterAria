// Copyright (c) 2024, Matthew Brown. All rights reserved.

#pragma once


#include "CommonPlayerController.h"
#include "BasePlayerController.generated.h"

class ABasePlayerState;
/**
 * Base player controller for this project 
 */
UCLASS()
class PLAYER_API ABasePlayerController : public ACommonPlayerController
{
	GENERATED_BODY()

public: 
	ABasePlayerState* GetBasePlayerState() const;

protected: 
	virtual void OnPlayerStateChanged();
	void InitPlayerState() override;

private:
	void BroadcastOnPlayerStateChanged();
};

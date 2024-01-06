// Copyright (c) 2024, Matthew Brown. All rights reserved.
// modified from: https://github.com/EpicGames/UnrealEngine/blob/072300df18a94f18077ca20a14224b5d99fee872/Samples/Games/Lyra/Source/LyraGame/Character/LyraPawnData.h
// which is Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Engine/DataAsset.h"

#include "PawnData.generated.h"

class UInputConfig;
/**
 * Non-mutable primary data asset for pawns 
 */
UCLASS()
class PLAYER_API UPawnData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPawnData();
	
	// Input configuration used by player controlled pawns to create input mappings and bind input actions.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Lyra|Input")
	TObjectPtr<UInputConfig> InputConfig;
};

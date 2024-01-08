// Copyright (c) 2024, Matthew Brown. All rights reserved.
// modified from: https://github.com/EpicGames/UnrealEngine/blob/072300df18a94f18077ca20a14224b5d99fee872/Samples/Games/Lyra/Source/LyraGame/Character/LyraPawnData.h
// which is Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Engine/DataAsset.h"

#include "PawnData.generated.h"

class APawn; 
class UInputConfig;

/**
 * Non-mutable primary data asset for pawns 
 */
UCLASS()
class CHARACTER_API UPawnData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPawnData();

	// Class to instantiate for this pawn (should usually derive from ABasePawn or ABaseCharacter).
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Game|Pawn")
	TSubclassOf<APawn> PawnClass;
	
	// Ability sets to grant to this pawn's ability system.
	// UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Game|Abilities")
	// TArray<TObjectPtr<UAbilitySet>> AbilitySets;

	// What mapping of ability tags to use for actions taking by this pawn
	// UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Game|Abilities")
	// TObjectPtr<UAbilityTagRelationshipMapping> TagRelationshipMapping;

	// Input configuration used by player controlled pawns to create input mappings and bind input actions.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Game|Input")
	TObjectPtr<UInputConfig> InputConfig;

	// Default camera mode used by player controlled pawns.
	// UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Game|Camera")
	// TSubclassOf<UBaseCameraMode> DefaultCameraMode;
};

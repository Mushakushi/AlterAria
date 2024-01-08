// Copyright (c) 2024, Matthew Brown. All rights reserved.

#pragma once

#include "GameplayTagAssetInterface.h"
#include "ModularCharacter.h"
#include "Logging/LogMacros.h"

#include "BaseCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class ABaseCharacterPlayerController; 
struct FInputActionValue;
struct FGameplayTagContainer;
struct FGameplayTag;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS(config=Game)
class ABaseCharacter : public AModularCharacter, public IGameplayTagAssetInterface
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;

public:
	ABaseCharacter();

	UFUNCTION(BlueprintCallable, Category="Game|Character")
	ABaseCharacterPlayerController* GetBaseCharacterPlayerController() const;

	UFUNCTION(BlueprintCallable, Category = "Lyra|Character")
	APlayerState* GetPlayerState() const;


	virtual void PossessedBy(AController* NewController) override;
	virtual void UnPossessed() override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	void InitializeGameplayTags();
	
	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;
	virtual bool HasMatchingGameplayTag(FGameplayTag TagToCheck) const override;
	virtual bool HasAllMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const override;
	virtual bool HasAnyMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const override;
	
	virtual void FellOutOfWorld(const UDamageType& dmgType) override;

	void OnDeathStarted(AActor*); 
	
	/**
	 * Moves the character. Called for movement input
	 * @param MovementVector The Vector along which to move  
	 */
	void Move(const FVector2d& MovementVector);

	/**
	 * Called for looking input
	 * @param LookAxisVector The Vector to look at
	 */
	void Look(const FVector2d& LookAxisVector);

	/** Returns CameraBoom subobject **/
	FORCEINLINE USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	
	/** Returns FollowCamera subobject **/
	FORCEINLINE UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};


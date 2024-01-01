// Copyright (c) 2024, Matthew Brown. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BaseCharacterPlayerController.generated.h"

class ABaseCharacterComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

UCLASS()
class CHARACTER_API ABaseCharacterPlayerController : public APawn
{
	GENERATED_BODY()
	
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* InputActionJump;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* InputActionMove;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* InputActionLook;

public:
	ABaseCharacterPlayerController();

	/** Controlled character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Commands")
	ABaseCharacterComponent* Target;

protected:
	/** Called for movement input */
	UFUNCTION()
	void HandleMove(const FInputActionValue& Value);

	/** Called for looking input */
	UFUNCTION()
	void HandleLook(const FInputActionValue& Value);

	/** Called for jump input start */
	UFUNCTION()
	void HandleJump();

	/** Called for jump input end */
	UFUNCTION()
	void HandleStopJumping(); 
	
	// APawn interface
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	
	// To add mapping context
	virtual void BeginPlay() override;
};

// Copyright (c) 2024, Matthew Brown. All rights reserved.


#include "BaseCharacterPlayerController.h"
#include "..\Public\BaseCharacterComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Commands/StartJumpingCommand.h"
#include "Commands/LookCommand.h"
#include "Commands/MoveCommand.h"
#include "Commands/StopJumpingCommand.h"

class UEnhancedInputLocalPlayerSubsystem;

// Sets default values
ABaseCharacterPlayerController::ABaseCharacterPlayerController()
{
	PrimaryActorTick.bCanEverTick = false;
	if (ABaseCharacterComponent* OwnerCharacter = Cast<ABaseCharacterComponent>(GetOwner()); OwnerCharacter != nullptr)
	{
		Target = OwnerCharacter;
	}
}

void ABaseCharacterPlayerController::HandleMove(const FInputActionValue& Value)
{
	const FVector2D MovementVector = Value.Get<FVector2D>();
	UMoveCommand* Command = NewObject<UMoveCommand>();
	Command->Initialize(Target, MovementVector);
	Command->Execute(); 
}

void ABaseCharacterPlayerController::HandleLook(const FInputActionValue& Value)
{
	const FVector2D LookAxisVector = Value.Get<FVector2D>();
	ULookCommand* Command = NewObject<ULookCommand>();
	Command->Initialize(Target, LookAxisVector);
	Command->Execute(); 
}

void ABaseCharacterPlayerController::HandleJump()
{
	UStartJumpingCommand* Command = NewObject<UStartJumpingCommand>();
	Command->Execute(); 
}

void ABaseCharacterPlayerController::HandleStopJumping()
{
	UStopJumpingCommand* Command = NewObject<UStopJumpingCommand>();
	Command->Execute(); 
}

// Called when the game starts or when spawned
void ABaseCharacterPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	//Add Input Mapping Context
	if (const APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

// Called to bind functionality to input
void ABaseCharacterPlayerController::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) 
	{
		EnhancedInputComponent->BindAction(InputActionJump, ETriggerEvent::Started,   this, &ABaseCharacterPlayerController::HandleJump);
		EnhancedInputComponent->BindAction(InputActionJump, ETriggerEvent::Completed, this, &ABaseCharacterPlayerController::HandleStopJumping);
		EnhancedInputComponent->BindAction(InputActionMove, ETriggerEvent::Triggered, this, &ABaseCharacterPlayerController::HandleMove);
		EnhancedInputComponent->BindAction(InputActionLook, ETriggerEvent::Triggered, this, &ABaseCharacterPlayerController::HandleLook);
	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input component!"), *GetNameSafe(this));
	}
}


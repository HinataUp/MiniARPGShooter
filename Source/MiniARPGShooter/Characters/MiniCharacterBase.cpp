// Fill out your copyright notice in the Description page of Project Settings.


#include "MiniCharacterBase.h"

#include "EnhancedInputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


class UEnhancedInputLocalPlayerSubsystem;
// Sets default values
AMiniCharacterBase::AMiniCharacterBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMiniCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	WalkSpeed = 400.f;
	SprintSpeed = 700.f;
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
}

// Called every frame
void AMiniCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


// Called to bind functionality to input
void AMiniCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	// 角色内部将具体的动作 和 输入绑定
	UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (!EIC) { return; }
	EIC->BindAction(IA_Move, ETriggerEvent::Triggered, this, &AMiniCharacterBase::OnMove);

	EIC->BindAction(IA_Look, ETriggerEvent::Triggered, this, &AMiniCharacterBase::OnLook);
	EIC->BindAction(IA_Jump, ETriggerEvent::Triggered, this, &AMiniCharacterBase::OnJumpPressed);
	EIC->BindAction(IA_Jump, ETriggerEvent::Completed, this, &AMiniCharacterBase::OnJumpReleased);
	EIC->BindAction(IA_Sprint, ETriggerEvent::Triggered, this, &AMiniCharacterBase::OnSprintPressed);
	EIC->BindAction(IA_Sprint, ETriggerEvent::Completed, this, &AMiniCharacterBase::OnSprintReleased);
}

void AMiniCharacterBase::OnMove(const FInputActionValue& Value)
{
	const FVector2D Axis = Value.Get<FVector2d>();
	if (Controller)
	{
		const FRotator YawRot(0.f, Controller->GetControlRotation().Yaw, 0.f);
		const FVector Forward = FRotationMatrix(YawRot).GetUnitAxis(EAxis::X);
		const FVector Right = FRotationMatrix(YawRot).GetUnitAxis(EAxis::Y);
		AddMovementInput(Forward, Axis.Y);
		AddMovementInput(Right, Axis.X);
	}
}

void AMiniCharacterBase::OnLook(const FInputActionValue& Value)
{
	const FVector2D Axis = Value.Get<FVector2D>();
	AddControllerYawInput(Axis.X);
	AddControllerPitchInput(-Axis.Y);
}

void AMiniCharacterBase::OnJumpPressed()
{
	Jump();
}

void AMiniCharacterBase::OnJumpReleased()
{
	StopJumping();
}

void AMiniCharacterBase::OnSprintPressed()
{
	GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
}

void AMiniCharacterBase::OnSprintReleased()
{
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
}

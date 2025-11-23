// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/Character.h"
#include "MiniCharacterBase.generated.h"

class UInputAction;
class UInputMappingContext;

UCLASS()
class MINIARPGSHOOTER_API AMiniCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMiniCharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


#pragma region Input

protected:
	UPROPERTY(EditDefaultsOnly, category="Input")
	UEnhancedInputComponent* EnhancedInputComponent;

	UPROPERTY(EditDefaultsOnly, category="Input")
	UInputAction* IA_Move;
	UPROPERTY(EditDefaultsOnly, category="Input")
	UInputAction* IA_Look;
	UPROPERTY(EditDefaultsOnly, category="Input")
	UInputAction* IA_Jump;
	UPROPERTY(EditDefaultsOnly, category="Input")
	UInputAction* IA_Sprint;

private:
	void OnMove(const FInputActionValue& InputActionValue);
	void OnLook(const FInputActionValue& InputActionValue);
	void OnJumpPressed();
	void OnJumpReleased();
	void OnSprintPressed();
	void OnSprintReleased();

	UPROPERTY(EditDefaultsOnly, category="Input")
	float SprintSpeed = 0.0f;
	UPROPERTY(EditDefaultsOnly, category="Input")
	float WalkSpeed = 0.f;
#pragma endregion
};

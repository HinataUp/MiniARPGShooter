// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MiniControllerBase.generated.h"

class UInputMappingContext;
/**
 * 
 */
UCLASS()
class MINIARPGSHOOTER_API AMiniControllerBase : public APlayerController
{
	GENERATED_BODY()

public:
	AMiniControllerBase();
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* InPawn) override;
	virtual void OnUnPossess() override;

protected:
	UPROPERTY(EditDefaultsOnly, Category="HUD")
	TSubclassOf<UUserWidget> HUDClass;

	UPROPERTY(Transient)
	UUserWidget* HUDWidget;
	
#pragma region Input
protected:
	UPROPERTY(EditDefaultsOnly, Category="Input")
	UInputMappingContext* InputMappingContext;
#pragma endregion
};

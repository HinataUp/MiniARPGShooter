// Fill out your copyright notice in the Description page of Project Settings.


#include "MiniControllerBase.h"

#include "EnhancedInputSubsystems.h"
#include "Blueprint/UserWidget.h"
#include "Utilities/Log/MiniGamesLog.h"

AMiniControllerBase::AMiniControllerBase()
{
}

void AMiniControllerBase::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogMiniGame, Warning, TEXT("BeginPlay"));

	if (HUDClass)
	{
		HUDWidget = CreateWidget<UUserWidget>(this, HUDClass);
		if (HUDWidget)
		{
			HUDWidget->AddToViewport(0);
		}
	}
	FInputModeGameAndUI Mode;
	// 光标 不锁定在视口上
	Mode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	SetInputMode(Mode);
	bShowMouseCursor = false;

	// 控制端配置 输入
	if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsys = ULocalPlayer::GetSubsystem<
			UEnhancedInputLocalPlayerSubsystem>(LocalPlayer))
		{
			if (InputMappingContext)
			{
				Subsys->AddMappingContext(InputMappingContext, 0);
			}
		}
	}
}

void AMiniControllerBase::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	UE_LOG(LogMiniGame, Warning, TEXT("OnPossess"));
}

void AMiniControllerBase::OnUnPossess()
{
	Super::OnUnPossess();
	UE_LOG(LogMiniGame, Warning, TEXT("UnOnPossess"));
}

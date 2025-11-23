// Fill out your copyright notice in the Description page of Project Settings.


#include "MiniControllerBase.h"

#include "Utilities/Log/MiniGamesLog.h"

void AMiniControllerBase::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogMiniGame, Warning, TEXT("BeginPlay"));
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

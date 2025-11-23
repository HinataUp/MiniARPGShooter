// Fill out your copyright notice in the Description page of Project Settings.


#include "MiniCharacterBase.h"


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
}


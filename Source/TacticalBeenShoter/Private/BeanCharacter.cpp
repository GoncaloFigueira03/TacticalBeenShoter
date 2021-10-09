// Fill out your copyright notice in the Description page of Project Settings.


#include "BeanCharacter.h"

// Sets default values
ABeanCharacter::ABeanCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABeanCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABeanCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABeanCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BeanCharacter.generated.h"

UCLASS()
class TACTICALBEENSHOTER_API ABeanCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABeanCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float JumpHeight;

protected:

	// Move Right or Forward Funcion
	void MoveForward(float AxisVal);
	void MoveRight(float AxisVal);
	void DoubleJump();
	int DoubleJumpCounter;

	virtual void Landed(const FHitResult& Hit) override;
	
	//Crouch Start Stop Function
	void StartCrouch();
	void StopCrouch();

	// Start Stop Sprint
	void StartSprint();
	void StopSprint();

	// Start Stop Sliding
	void StartSlide();
	void StopSlide();

	// Determines if player is crouching
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	bool isCrouching;

	// Determines if player is sprinting
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	bool isSprinting;

	// Determines if player is sliding
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	float isSliding;

	// Calling Max Walk Speed
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	float MaxWalkSpeed;

	// Setting up base turn rates
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	float BaseTurnRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	float BaseLookUpRate;


	// Setting the slidability of the player SKRRRRRRR
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	float BrakingFrictionFactor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	float BrakingDecelerationWalkingl;

};

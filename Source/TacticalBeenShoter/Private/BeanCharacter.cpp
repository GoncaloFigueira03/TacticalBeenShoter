#include "BeanCharacter.h"
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/InputSettings.h"

// Sets default values
ABeanCharacter::ABeanCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set Default Capsule Half Height 88.0f 
	GetCapsuleComponent()->InitCapsuleSize(34.0f, 88.0f);

	// Set Base Turn Rates
	BaseTurnRate = 45.0f;
	BaseLookUpRate = 45.0f;

	// Set Default Max Speeds
	MaxWalkSpeed = 600.0f;

	// Set Default Braking Friction Factor
	BrakingFrictionFactor = 1.0f;

	// Jumping/Double jumping variables
	JumpHeight = 600.f;
	DoubleJumpCounter=0;
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

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ABeanCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ABeanCharacter::MoveRight);

	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ABeanCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &ABeanCharacter::AddControllerPitchInput);

	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &ABeanCharacter::DoubleJump);

	PlayerInputComponent->BindAction(TEXT("Crouch"), IE_Pressed, this, &ABeanCharacter::StartCrouch);
	PlayerInputComponent->BindAction(TEXT("Crouch"), IE_Released, this, &ABeanCharacter::StopCrouch);

	PlayerInputComponent->BindAction(TEXT("Sprint"), IE_Pressed, this, &ABeanCharacter::StartSprint);
	PlayerInputComponent->BindAction(TEXT("Sprint"), IE_Released, this, &ABeanCharacter::StopSprint);

	PlayerInputComponent->BindAction(TEXT("Slide"), IE_Pressed, this, &ABeanCharacter::StartSlide);
	PlayerInputComponent->BindAction(TEXT("Slide"), IE_Released, this, &ABeanCharacter::StopSlide);

}

void ABeanCharacter::MoveForward(float AxisVal)
{
	AddMovementInput(GetActorForwardVector() * AxisVal);
}

void ABeanCharacter::MoveRight(float AxisVal)
{
	AddMovementInput(GetActorRightVector() * AxisVal);
}

void ABeanCharacter::StartSprint()
{
	GetCharacterMovement()->MaxWalkSpeed = 900.0f;

	isSprinting = true;

}

void ABeanCharacter::StopSprint()
{
	GetCharacterMovement()->MaxWalkSpeed = 600.0f;

	isSprinting = false;

}

void ABeanCharacter::StartSlide()
{
	GetCharacterMovement()->BrakingFrictionFactor = 0.1f;
	GetCharacterMovement()->BrakingDecelerationWalking = 1.0f;

	isSliding = true;
}

void ABeanCharacter::StopSlide()
{
	GetCharacterMovement()->BrakingFrictionFactor = 1.0f;
	GetCharacterMovement()->BrakingDecelerationWalking = 1.0f;

	isSliding = false;
}


void ABeanCharacter::StartCrouch()
{
	GetCapsuleComponent()->SetCapsuleHalfHeight(44.0f);
	GetCharacterMovement()->MaxWalkSpeed = 300.0f;
	ABeanCharacter::Crouch();

	isCrouching = true;
}

void ABeanCharacter::StopCrouch()
{
	GetCapsuleComponent()->SetCapsuleHalfHeight(88.0f);
	GetCharacterMovement()->MaxWalkSpeed = 600.0f;
	ABeanCharacter::UnCrouch();

	isCrouching = false;
}

void ABeanCharacter::Landed(const FHitResult& Hit)
{
	DoubleJumpCounter = 0;
}

void ABeanCharacter::DoubleJump()
{
	if(DoubleJumpCounter <= 1)
	{
		ACharacter::LaunchCharacter(FVector(0,0,JumpHeight), false, true);
		DoubleJumpCounter++;
	}
}

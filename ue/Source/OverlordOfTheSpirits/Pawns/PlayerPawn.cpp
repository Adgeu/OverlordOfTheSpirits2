// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"

#include "Camera/CameraComponent.h"
#include "Cameras/Components/OSSpringArmComponent.h"
#include "Components/ArrowComponent.h"
#include "Controllers/OSPlayerController.h"
#include "Kismet/GameplayStatics.h"

APlayerPawn::APlayerPawn()
{
	SpringArmComponent = CreateDefaultSubobject<UOSSpringArmComponent>("SpringArm");
	SpringArmComponent->SetupAttachment(GetRootComponent());

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("Camera");
	CameraComponent->SetupAttachment(SpringArmComponent);
}

void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();

	GetMeshComponent()->OnClicked.AddDynamic(this, &APlayerPawn::OnPawnSelected);
}

void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("PawnCameraTurn", SpringArmComponent, &UOSSpringArmComponent::TurnAtRate);
	InputComponent->BindAxis("PawnCameraLookUp", SpringArmComponent, &UOSSpringArmComponent::LookUpAtRate);

	InputComponent->BindAction("EnablePawnCameraRotation", IE_Pressed, SpringArmComponent, &UOSSpringArmComponent::StartRotateCamera);
	InputComponent->BindAction("EnablePawnCameraRotation", IE_Released, SpringArmComponent, &UOSSpringArmComponent::StopRotateCamera);

	InputComponent->BindAction("ReturnToBoardCameraFromPawn", IE_Pressed, this, &APlayerPawn::ReturnToBoardCamera);
}

void APlayerPawn::ReturnToBoardCamera()
{
	AOSPlayerController* PlayerController = Cast<AOSPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (PlayerController)
	{
		PlayerController->ReturnToBoardCamera();
	}
}

void APlayerPawn::OnPawnSelected(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed)
{
	if (!GetController() || !GetController()->IsPlayerController())
	{
		APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
		if (PlayerController)
		{
			PlayerController->Possess(this);
		}
	}
}

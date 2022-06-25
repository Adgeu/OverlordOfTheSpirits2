// Fill out your copyright notice in the Description page of Project Settings.


#include "BoardCamera.h"

#include "Camera/CameraComponent.h"
#include "Components/OSSpringArmComponent.h"

ABoardCamera::ABoardCamera()
{
	USceneComponent* Root = CreateDefaultSubobject<USceneComponent>("Root");
	SetRootComponent(Root);

	SpringArmComponent = CreateDefaultSubobject<UOSSpringArmComponent>("SpringArm");
	SpringArmComponent->bDoCollisionTest = false;
	SpringArmComponent->SetupAttachment(GetRootComponent());

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("Camera");
	CameraComponent->SetupAttachment(SpringArmComponent);
}

void ABoardCamera::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("BoardCameraTurn", SpringArmComponent, &UOSSpringArmComponent::TurnAtRate);
	InputComponent->BindAxis("BoardCameraLookUp", SpringArmComponent, &UOSSpringArmComponent::LookUpAtRate);
	InputComponent->BindAxis("ZoomBoardCamera", SpringArmComponent, &UOSSpringArmComponent::Zoom);

	InputComponent->BindAction("EnableBoardCameraRotation", IE_Pressed, SpringArmComponent, &UOSSpringArmComponent::StartRotateCamera);
	InputComponent->BindAction("EnableBoardCameraRotation", IE_Released, SpringArmComponent, &UOSSpringArmComponent::StopRotateCamera);
}

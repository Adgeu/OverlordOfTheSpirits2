// Fill out your copyright notice in the Description page of Project Settings.


#include "OSPlayerController.h"

#include "Cameras/BoardCamera.h"
#include "Kismet/GameplayStatics.h"


void AOSPlayerController::ReturnToBoardCamera()
{
	if (CachedBoardCamera.IsValid())
	{
		Possess(CachedBoardCamera.Get());
	}
}

void AOSPlayerController::BeginPlay()
{
	Super::BeginPlay();

	CachedBoardCamera = Cast<ABoardCamera>(UGameplayStatics::GetActorOfClass(GetWorld(), ABoardCamera::StaticClass()));
	check(CachedBoardCamera.IsValid());

	FInputModeGameAndUI InputMode;
	SetInputMode(InputMode);

	bShowMouseCursor = true;
	bEnableClickEvents = true;
}

void AOSPlayerController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);

	if (!CachedBoardCamera.IsValid())
	{
		return;
	}

	FViewTargetTransitionParams Params;
	Params.BlendTime = CameraTransitionBlendTime;
	Params.bLockOutgoing = true;
	SetViewTarget(InPawn, Params);
}

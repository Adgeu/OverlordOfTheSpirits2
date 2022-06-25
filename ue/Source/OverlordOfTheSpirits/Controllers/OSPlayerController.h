// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "OSPlayerController.generated.h"

UCLASS()
class OVERLORDOFTHESPIRITS_API AOSPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	/** Posses on main board camera. */
	void ReturnToBoardCamera();
	
protected:
	virtual void BeginPlay() override;
	virtual void SetPawn(APawn* InPawn) override;

	// Transition time for changing between cameras.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Camera", meta = (Units = "s", ClampMin = 0.0))
	float CameraTransitionBlendTime = 1.0f;

private:
	// Cached main board camera.
	TWeakObjectPtr<class ABoardCamera> CachedBoardCamera;
};

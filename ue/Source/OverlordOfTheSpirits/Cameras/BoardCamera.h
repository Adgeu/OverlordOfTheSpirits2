// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BoardCamera.generated.h"

class USceneComponent;
class UOSSpringArmComponent;
class UCameraComponent;

/**
 * Main camera for navigating the board.
 */
UCLASS()
class OVERLORDOFTHESPIRITS_API ABoardCamera : public APawn
{
	GENERATED_BODY()

public:
	ABoardCamera();

protected:
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

#pragma region Components
	
public:
	/** Returns SpringArm subobject. */
	FORCEINLINE UOSSpringArmComponent* GetSpringArmComponent() const
	{
		return SpringArmComponent;
	}

	/** Returns Camera subobject. */
	FORCEINLINE UCameraComponent* GetCameraComponent() const
	{
		return CameraComponent;
	}
	
private:
	// SpringArm positioning camera and handle rotation and zoom inputs.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UOSSpringArmComponent* SpringArmComponent;

	// Camera.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* CameraComponent;

#pragma endregion ~Components
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OSPawnBase.h"
#include "PlayerPawn.generated.h"

class UOSSpringArmComponent;
class UCameraComponent;
class UArrowComponent;

UCLASS()
class OVERLORDOFTHESPIRITS_API APlayerPawn : public AOSPawnBase
{
	GENERATED_BODY()

public:
	APlayerPawn();
	
protected:
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	/** Requesting PlayerController on return to main board camera view. */
	void ReturnToBoardCamera();

private:
	UFUNCTION()
	void OnPawnSelected(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed);

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
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UOSSpringArmComponent* SpringArmComponent;

	// Camera.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* CameraComponent;

#pragma endregion ~Components
};

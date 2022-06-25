// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SpringArmComponent.h"
#include "OSSpringArmComponent.generated.h"

/**
 * Custom SpringArmComponent.
 * 
 * Added functionality:
 *	- Turn and LookUp;
 *	- Zoom.
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class OVERLORDOFTHESPIRITS_API UOSSpringArmComponent : public USpringArmComponent
{
	GENERATED_BODY()

public:
	/** Called via input to turn. */
	void TurnAtRate(float Value);

	/** Called via input to turn look up/down. */
	void LookUpAtRate(float Value);

	/** Called for adding value of the target arm length. */
	void Zoom(float Value);

	/** Start Turn and LookUp. */
	FORCEINLINE void StartRotateCamera()
	{
		bCanRotateCamera = true;
	}

	/** Stop Turn and LookUp. */
	FORCEINLINE void StopRotateCamera()
	{
		bCanRotateCamera = false;
	}
	
protected:
	// Enable SpringArm turn.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Rotation")
	bool bEnableTurn = true;

	// Turn rate multiplier.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Camera Rotation", meta = (ClampMin = 0.0, EditCondition = "bEnableTurn", EditConditionHides))
	float TurnRate = 60.0f;

	// Enable SpringArm look up.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Rotation")
	bool bEnableLookUp = true;

	// LookUp rate multiplier.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Camera Rotation", meta = (ClampMin = 0.0, EditCondition = "bEnableLookUp", EditConditionHides))
	float LookUpRate = 60.0f;

	// Min for SpringArm pitch angle.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Camera Rotation", meta = (Units = "Degrees", ClampMin = -360.0, ClampMax = 360.0, EditCondition = "bEnableLookUp", EditConditionHides))
	float MinPitchAngle = -360.0f;

	// Max for SpringArm pitch angle.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Camera Rotation", meta = (Units = "Degrees", ClampMin = -360.0, ClampMax = 360.0, EditCondition = "bEnableLookUp", EditConditionHides))
	float MaxPitchAngle = 360.0f;

	// Enable SpringArm zoom.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Zoom")
	bool bEnableZoom = true;

	// Zoom intensity multiplier.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Camera Zoom", meta = (ClampMin = 0.0, EditCondition = "bEnableZoom", EditConditionHides))
	float ZoomIntensity = 10000.0f;

	// Min value for SpringArm zoom.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Camera Zoom", meta = (ClampMin = 0.0, EditCondition = "bEnableZoom", EditConditionHides))
	float MinZoomValue = 300.0f;

	// Max value for SpringArm zoom.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Camera Zoom", meta = (ClampMin = 0.0, EditCondition = "bEnableZoom", EditConditionHides))
	float MaxZoomValue = 3000.0f;

private:
	// Can the SpringArm Turn and LookUp?
	bool bCanRotateCamera = false;
};

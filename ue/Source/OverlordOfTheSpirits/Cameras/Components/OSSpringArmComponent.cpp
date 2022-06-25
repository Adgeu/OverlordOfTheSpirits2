// Fill out your copyright notice in the Description page of Project Settings.


#include "OSSpringArmComponent.h"

void UOSSpringArmComponent::TurnAtRate(float Value)
{
	if (bEnableTurn && bCanRotateCamera && !FMath::IsNearlyZero(Value))
	{
		const FRotator Rotation = GetRelativeRotation();
		const float NewYaw = Rotation.Yaw + Value * TurnRate * GetWorld()->GetDeltaSeconds();
		SetRelativeRotation(FRotator(Rotation.Pitch, NewYaw, Rotation.Roll));
	}
}

void UOSSpringArmComponent::LookUpAtRate(float Value)
{
	if (bEnableLookUp && bCanRotateCamera && !FMath::IsNearlyZero(Value))
	{
		const FRotator Rotation = GetRelativeRotation();
		const float NewPitch = FMath::ClampAngle(Rotation.Pitch + Value * LookUpRate * GetWorld()->GetDeltaSeconds(), MinPitchAngle, MaxPitchAngle);
		SetRelativeRotation(FRotator(NewPitch, Rotation.Yaw, Rotation.Roll));
	}
}

void UOSSpringArmComponent::Zoom(float Value)
{
	if (bEnableZoom)
	{
		TargetArmLength = FMath::Clamp(TargetArmLength + Value * ZoomIntensity * GetWorld()->GetDeltaSeconds(), MinZoomValue, MaxZoomValue);
	}
}

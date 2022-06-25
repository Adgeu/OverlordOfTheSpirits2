// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "OSPawnBase.generated.h"

class UStaticMeshComponent;
class UCapsuleComponent;
class UAimComponent;

UCLASS(Abstract)
class OVERLORDOFTHESPIRITS_API AOSPawnBase : public APawn
{
	GENERATED_BODY()

public:
	AOSPawnBase();

#pragma region Components

public:
	/** Returns Capsule subobject. */
	FORCEINLINE UCapsuleComponent* GetCapsuleComponent() const
	{
		return CapsuleComponent;
	}

	/** Returns StaticMesh subobject. */
	FORCEINLINE UStaticMeshComponent* GetMeshComponent() const
	{
		return MeshComponent;
	}

private:
	// Collision capsule
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UCapsuleComponent* CapsuleComponent;

	// Static mesh of the pawn.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* MeshComponent;

#pragma endregion ~Components
};

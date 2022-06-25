// Fill out your copyright notice in the Description page of Project Settings.


#include "OSPawnBase.h"

#include "Components/CapsuleComponent.h"

AOSPawnBase::AOSPawnBase()
{
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>("Root");
	SetRootComponent(CapsuleComponent);
	
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	MeshComponent->SetupAttachment(GetRootComponent());
}

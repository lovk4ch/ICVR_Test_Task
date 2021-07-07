// Fill out your copyright notice in the Description page of Project Settings.


#include "Cube.h"

// Sets default values
ACube::ACube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>("Root");
	Root->SetMobility(EComponentMobility::Static);
	RootComponent = Root;
	
	Cube = CreateDefaultSubobject<UStaticMeshComponent>("Cube");
	Cube->AttachToComponent(Root, FAttachmentTransformRules::KeepWorldTransform);
}

// Called when the game starts or when spawned
void ACube::BeginPlay()
{
	Super::BeginPlay();
	MaterialInstance = Cube->CreateDynamicMaterialInstance(0, Cube->GetMaterial(0));
}

// Called every frame
void ACube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACube::SetColor(FName MaterialParameter, FLinearColor Color)
{
	MaterialInstance->SetVectorParameterValue(MaterialParameter, Color);
}
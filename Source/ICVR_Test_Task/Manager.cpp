// Fill out your copyright notice in the Description page of Project Settings.


#include "Manager.h"
#include "CameraPawn.h"

// Sets default values
AManager::AManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AManager::BeginPlay()
{
	Super::BeginPlay();
	
	ACameraPawn* CameraPawn = Cast<ACameraPawn>(GetWorld()->GetFirstPlayerController()->GetPawn());
	CameraPawn->BeforeCameraMoved.AddDynamic(this, &AManager::Predict);

	if (IsValid(CubeActor))
	{
		for (int i = 0; i < 3000; i++)
		{
			ACube* Cube = GetWorld()->SpawnActor<ACube>(CubeActor.Get(),
				FVector(
					FMath::RandRange(-15000, 15000),
					FMath::RandRange(-15000, 15000),
					FMath::RandRange(25, 1175)),
				FRotator());
			Cubes.Add(Cube);
		}
	}
}

// Called every frame
void AManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AManager::Predict(FVector location)
{
	L0_Current = 0;
	L1_Current = 0;
	RenderedCubesCount = 0;

	for (auto Cube : Cubes)
	{
		if (Cube->WasRecentlyRendered())
		{
			const FLinearColor Color = GetColorByDistance(
				FVector::Distance(Cube->GetRootComponent()->GetComponentLocation(), location)
			);
			Cube->SetColor("Color", Color);
			RenderedCubesCount++;
		}
	}
}

FLinearColor AManager::GetColorByDistance(float distance)
{
	if (L0_Current < L0)
	{
		if (distance < R0)
		{
			L0_Current++;
			return FLinearColor::Blue;
		}
	}

	if (L1_Current < L1)
	{
		if (distance < R1)
		{
			L1_Current++;
			return FLinearColor::Yellow;
		}
	}

	return FLinearColor::Red;
}

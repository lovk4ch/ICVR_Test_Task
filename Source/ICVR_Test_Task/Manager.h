// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Cube.h"
#include "GameFramework/Actor.h"
#include "Manager.generated.h"

UCLASS()
class ICVR_TEST_TASK_API AManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/// Properties
	
	UPROPERTY(EditInstanceOnly, Category="SmallField")
	float R0 = 1500;

	UPROPERTY(EditInstanceOnly, Category="SmallField")
	int L0 = 30;
	
	UPROPERTY(VisibleDefaultsOnly, Category="SmallField")
	int L0_Current;

	UPROPERTY(EditInstanceOnly, Category="LargeField")
	float R1 = 5000;

	UPROPERTY(EditInstanceOnly, Category="LargeField")
	int L1 = 100;
	
	UPROPERTY(VisibleDefaultsOnly, Category="LargeField", BlueprintReadWrite)
	int L1_Current;

	UPROPERTY(EditInstanceOnly, Category="Instances")
	TSubclassOf<class ACube> CubeActor;
	
	UPROPERTY(BlueprintReadOnly)
	TArray<ACube*> Cubes;
	
	UPROPERTY(BlueprintReadWrite)
	float RenderedCubesCount;

	/// Functions
	
	UFUNCTION()
	void Predict(FVector location);

	UFUNCTION()
	FLinearColor GetColorByDistance(float distance);
};
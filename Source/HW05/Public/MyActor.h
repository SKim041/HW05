// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/UnrealMathUtility.h"
#include "MyActor.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogMyActor, Log, All);

UCLASS()
class HW05_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();
	void Move();
	int32 Step();
	float Distance(FVector First, FVector Second);
	void CreateEvent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MeshComponent;

	int32 MoveCount = 0;

	FTimerHandle MoveTimerHandle;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	int CountEvnt = 0;
	float TotalDist = 0;

	UPROPERTY(EditAnywhere)
	FVector Start = FVector::ZeroVector;	//FVector(0, 0, 0)

	UPROPERTY(EditAnywhere)
	float EventProbability = 50;

	UPROPERTY(EditAnywhere)
	int32 TotalMoveCount = 10;


};

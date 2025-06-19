// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "Components/StaticMeshComponent.h"

DEFINE_LOG_CATEGORY(LogMyActor);

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;	// 안쓸때 끄기

	// 루트 컴포넌트로 설정
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;
}

void AMyActor::CreateEvent() {
	int RandomValue = FMath::RandRange(1, 100);
	if (RandomValue <= this->EventProbability) {
		this->CountEvnt++;
		UE_LOG(LogMyActor, Warning, TEXT("Event Triggered!"));
	}
	else {
		UE_LOG(LogMyActor, Warning, TEXT("Event Not Triggered"));
	}
}

float AMyActor::Distance(FVector First, FVector Second) {
	float Dist_X = First.X - Second.X;
	float Dist_Y = First.Y - Second.Y;
	float Dist = FMath::Sqrt(Dist_X * Dist_X + Dist_Y * Dist_Y);

	UE_LOG(LogMyActor, Display, TEXT("Traveled Distance: %.3f"), Dist);

	return Dist;
}
void AMyActor::Move() {
	int X = Step();
	int Y = Step();

	TotalDist += Distance(Start, FVector(Start.X + X, Start.Y + Y, 0));

	Start.X += X;
	Start.Y += Y;

	MoveCount++;
	
	UE_LOG(LogMyActor, Display, TEXT("Current Location: %s"), *(Start.ToString()));

	SetActorLocation(Start * 100);
	CreateEvent();

	// 10번 실행 후 타이머 해제
	if (MoveCount == TotalMoveCount) {
		UE_LOG(LogMyActor, Warning,
			TEXT("Total Distance: %.3f, Total Event Count: %d"), TotalDist, CountEvnt);
		GetWorld()->GetTimerManager().ClearTimer(MoveTimerHandle);
	}
}

int32 AMyActor::Step() {
	return FMath::RandRange(0,1);
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	SetActorLocation(Start);
	UE_LOG(LogMyActor, Warning, TEXT("Start Location: %s"), *(Start.ToString()));

	//1초 마다 Move() 실행
	GetWorld()->GetTimerManager().SetTimer(
		MoveTimerHandle,
		this,
		&AMyActor::Move,
		0.3f,
		true
	);
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


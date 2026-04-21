// Fill out your copyright notice in the Description page of Project Settings.


#include "Location.h"

// Sets default values
ALocation::ALocation()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/StarterContent/Architecture/Floor_400x400.Floor_400x400"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial>MaterialAsset(TEXT("/Game/StarterContent/Materials/M_Water_Lake.M_Water_Lake"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}

    PrimaryActorTick.bCanEverTick = true;
	MoveSpeed = 1000.0f;
																	
}


void ALocation::BeginPlay()
{
	Super::BeginPlay();

	//시작위치
	StartLocation = GetActorLocation();

	GetWorld()->GetTimerManager().SetTimer(PlatformTimerHandle, this, &ALocation::CheckTurn, CycleInterval, true);
}



void ALocation::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MoveSpeed = FMath::RandRange(100, 100);

	//이동
	FVector DeltaLocation = FVector::ZeroVector;
	DeltaLocation.Y += DeltaTime * MoveSpeed * Direction;
	AddActorLocalOffset(DeltaLocation);


	
	// 시작점에서 현재점까지의 거리 계산
	float DistanceMoved = FVector::Dist(StartLocation, GetActorLocation());

	//방향전환
	if (DistanceMoved >= RandRange)
	{
		// 방향 반전
		Direction *= -1.0f;
	}
}

	void ALocation::CheckTurn()
	{
		FVector CurLocation = GetActorLocation();
		
		if (CurLocation.Y >= RandRange && Direction > 0 ||
			CurLocation.Y <= -RandRange && Direction < 0)
		{
			Direction = -1 * Direction;

			FVector SpawnPos = CurLocation + FVector(FMath::RandRange(-500, 500), 0, 0);

			ALocation* SpawnedActor1 = GetWorld()->SpawnActor<ALocation>
				(ALocation::StaticClass(), SpawnPos, FRotator::ZeroRotator);
		}
	}



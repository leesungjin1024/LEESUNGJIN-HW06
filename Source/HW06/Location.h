// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Location.generated.h"

UCLASS()
class HW06_API ALocation : public AActor
{
	GENERATED_BODY()



public:
	ALocation();



protected:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* StaticMeshComp;


	// 이동 속도 
	UPROPERTY(EditAnywhere, Category = "Movement")
	float MoveSpeed = 1000.0f;

	// 왕복 범위 
	UPROPERTY(EditAnywhere, Category = "Movement")
	float RandRange = 500.0f;

	//방향
	UPROPERTY(EditAnywhere, Category = "Movement")
	float Direction = 1.0f;

	// 타이머
	UPROPERTY(EditAnywhere, Category = "Movement")
	float CycleInterval = 2.0f;


	FVector StartLocation;
	FTimerHandle PlatformTimerHandle;

	
	void CheckTurn();


};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Rotationd.generated.h"

UCLASS()
class HW06_API ARotationd : public AActor
{
	GENERATED_BODY()
	
public:	

	ARotationd();

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	USceneComponent* SceneRoot;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* StaticMeshComp;

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	float RotationSpeed;

	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};

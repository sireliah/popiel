// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Mouse.h"

#include "GameFramework/Actor.h"
#include "Spawner.generated.h"

UCLASS()
class POPIELTOWER_API ASpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawner();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

        void Spawn();

        bool bTickInEditor;

};

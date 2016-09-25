// Fill out your copyright notice in the Description page of Project Settings.

#include "PopielTower.h"
#include "Spawner.h"

#include <iostream>


// Sets default values
ASpawner::ASpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

        UBoxComponent* MouseBodyComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("RootComponent"));
        RootComponent = MouseBodyComponent;
        MouseBodyComponent->SetCollisionProfileName(TEXT("NoCollision"));
        //bTickInEditor = true;

}

void ASpawner::Spawn() {

   UWorld* const world = GetWorld();

   if (world) {
       FVector new_location = GetActorLocation() + FVector(0.0f, 0.f, 30.f);
       AMouse* spawned_mouse = world->SpawnActor<AMouse>(AMouse::StaticClass(), new_location, {90.0f, 0.0f, 0.0f});
   }
}

// Called when the game starts or when spawned
void ASpawner::BeginPlay()
{
	Super::BeginPlay();
        Spawn();
}

// Called every frame
void ASpawner::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
        int random_number = rand() % 1000;
        if (random_number >= 980) {

            Spawn();

        }

}



#include "PopielTower.h"
#include "MouseSpawner.h"

#include <iostream>

AMouseSpawner::AMouseSpawner() {
    
    PrimaryActorTick.bCanEverTick = true;
    PrimaryActorTick.bStartWithTickEnabled = true;
    UBoxComponent* MouseBodyComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("RootComponent"));
    RootComponent = MouseBodyComponent;
    MouseBodyComponent->SetCollisionProfileName(TEXT("Pawn"));   
    
    
}

void AMouseSpawner::Spawn() {
    
   UWorld* const world = GetWorld();
        
   if (world) {
       FVector new_location = GetActorLocation() + FVector(0.0f, 0.f, 30.f);   
       AMouse* spawned_mouse = world->SpawnActor<AMouse>(AMouse::StaticClass(), new_location, FRotator::ZeroRotator);
   }
}

void AMouseSpawner::BeginPlay() {

    Super::BeginPlay();
    
    Spawn();
    
}

void AMouseSpawner::Tick(float DeltaTime) {
    
    Super::Tick(DeltaTime);
    std::cout << "vsdvsdvsdvsdvsdv\n";
    int random_number = rand() % 100;
    if (random_number == 100) {
        
        Spawn();

    }
    
}



#include "PopielTower.h"
#include "MouseSpawner.h"

AMouseSpawner::AMouseSpawner() {
    
    UBoxComponent* MouseBodyComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("RootComponent"));
    RootComponent = MouseBodyComponent;
    MouseBodyComponent->SetCollisionProfileName(TEXT("Pawn"));   
    
    
}

void AMouseSpawner::BeginPlay() {
    
    Super::BeginPlay();
    
    UWorld* const world = GetWorld();
    
    if (world) {
       FVector new_location = GetActorLocation() + FVector(0.0f, 0.f, 30.f);   
       AMouse* spawned_mouse = world->SpawnActor<AMouse>(AMouse::StaticClass(), new_location, FRotator::ZeroRotator);
    }
    
    
}
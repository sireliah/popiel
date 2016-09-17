
#pragma once

#include "GameFramework/Pawn.h"
#include "Engine/World.h"

#include "Mouse.h"
#include "MouseSpawner.generated.h"


UCLASS()
class POPIELTOWER_API AMouseSpawner: public APawn {
    
    GENERATED_BODY()
    
public:    
    
    AMouseSpawner();

    TSubclassOf<class AMouse> AMouseClass;
    
    void Spawn();
    
    virtual void BeginPlay() override;
    
    virtual void Tick(float DeltaTime) override;
    
    
    
};
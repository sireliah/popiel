
#pragma once

#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "Mouse.h"
#include "MouseSpawner.generated.h"


UCLASS()
class AMouseSpawner: public AActor {
    
    AMouseSpawner();
    
    GENERATED_BODY()
    
    TSubclassOf<class AMouse> AMouseClass;
    
    virtual void BeginPlay() override;
    
    
    
    
};
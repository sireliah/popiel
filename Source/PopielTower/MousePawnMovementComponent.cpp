// Fill out your copyright notice in the Description page of Project Settings.

#include "PopielTower.h"
#include "MousePawnMovementComponent.h"
#include "iostream"


UMousePawnMovementComponent::UMousePawnMovementComponent() {

    blocked = false;

}

void UMousePawnMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {

    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    


    if (!PawnOwner || !UpdatedComponent || ShouldSkipUpdate(DeltaTime)) {
        return;   
    }
    FVector DesiredMovementThisFrame = ConsumeInputVector().GetClampedToMaxSize(1.0f) * DeltaTime; // * 500.0f;
    if (!DesiredMovementThisFrame.IsNearlyZero()) {
        FHitResult Hit;
        SafeMoveUpdatedComponent(DesiredMovementThisFrame, UpdatedComponent->GetComponentRotation(), true, Hit);
        if (Hit.IsValidBlockingHit()) {
           blocked = true;
        }

    }
};

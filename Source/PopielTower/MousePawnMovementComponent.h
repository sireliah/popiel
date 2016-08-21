// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PawnMovementComponent.h"
#include "MousePawnMovementComponent.generated.h"


/**
 * 
 */
UCLASS()
class POPIELTOWER_API UMousePawnMovementComponent : public UPawnMovementComponent
{
	GENERATED_BODY()
	
public:
    virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
	
	
};

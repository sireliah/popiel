// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Mouse.generated.h"

UCLASS()
class POPIELTOWER_API AMouse : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMouse();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	virtual UPawnMovementComponent* GetMovementComponent() const override;

    class UMousePawnMovementComponent* MovementComponent;
    
    void MoveRight();
    
    void Jump();
};

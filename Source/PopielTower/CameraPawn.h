// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "CameraPawn.generated.h"


UCLASS()
class POPIELTOWER_API ACameraPawn : public APawn {
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACameraPawn();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	
protected:
	UPROPERTY(EditAnywhere)
	USpringArmComponent* OurCameraSpringArm;
	UCameraComponent* OurCamera;
	
	// Inputs
	FVector2D MovementInput;
	FVector2D CameraInput;
	
	void MoveRight(float AxisValue);
	
};

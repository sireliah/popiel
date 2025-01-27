// Fill out your copyright notice in the Description page of Project Settings.

#include "PopielTower.h"
#include "CameraPawn.h"


// Sets default values
ACameraPawn::ACameraPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	OurCameraSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));
	OurCameraSpringArm->SetupAttachment(RootComponent);
	OurCameraSpringArm->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 50.0f), FRotator(-50.0f, 0.0f, 0.0f));
	OurCameraSpringArm->TargetArmLength = 400.0f;
	OurCameraSpringArm->CameraLagSpeed = 3.0f;
	
	OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("GameCamera"));
	OurCamera->SetupAttachment(OurCameraSpringArm, USpringArmComponent::SocketName);
	
	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void ACameraPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACameraPawn::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime ); 
	
	if (!MovementInput.IsZero()) {
	    MovementInput = MovementInput.SafeNormal() * 1000.0f;
	    FVector NewLocation = GetActorLocation();
	    NewLocation += GetActorRightVector() * MovementInput.Y * DeltaTime;
	    SetActorLocation(NewLocation);
	  
	}

}

// Called to bind functionality to input
void ACameraPawn::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	
	InputComponent->BindAxis("MoveRight", this, &ACameraPawn::MoveRight);

}

void ACameraPawn::MoveRight(float AxisValue) {
        MovementInput.Y = FMath::Clamp<float>(AxisValue, -10.0f, 10.0f);
}
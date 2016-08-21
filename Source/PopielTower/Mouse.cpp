// Fill out your copyright notice in the Description page of Project Settings.

#include "PopielTower.h"
#include "Mouse.h"
#include "MousePawnMovementComponent.h"


// Sets default values
AMouse::AMouse() {
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    
    // Body of the mouse
    
    UCapsuleComponent* MouseBodyComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("RootComponent"));
    RootComponent = MouseBodyComponent;
    MouseBodyComponent->InitCapsuleSize(40.0f, 70.0f);
    MouseBodyComponent->SetCollisionProfileName(TEXT("Pawn"));
    
    // Mesh
    
    UStaticMeshComponent* CapsuleVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
    // "/Game/StarterContent/Shapes/Shape_NarrowCapsule.Shape_NarrowCapsule";
    CapsuleVisual->SetupAttachment(RootComponent);
    static ConstructorHelpers::FObjectFinder<UStaticMesh> CapsuleVisualAsset(TEXT("/Game/StarterContent/Shapes/kapsulka.kapsulka"));
    if (CapsuleVisualAsset.Succeeded()) {
        CapsuleVisual->SetStaticMesh(CapsuleVisualAsset.Object);
        CapsuleVisual->SetRelativeLocation(FVector(0.0f, 0.0f, -40.0f));
        CapsuleVisual->SetWorldScale3D(FVector(0.5f));
    }
    
    MovementComponent = CreateDefaultSubobject<UMousePawnMovementComponent>(TEXT("CustomMovementComponent"));
    MovementComponent->UpdatedComponent = RootComponent;
}

// Called when the game starts or when spawned
void AMouse::BeginPlay() {
	Super::BeginPlay();
	
}

// Called every frame
void AMouse::Tick( float DeltaTime ) {
	Super::Tick( DeltaTime );
    
    
    MoveRight();
    
    int RandomNumber = rand() % 100;
        
        if (RandomNumber >= 90) {
         
            Jump();
            
        }

}

// Called to bind functionality to input
void AMouse::SetupPlayerInputComponent(class UInputComponent* InputComponent) {
	Super::SetupPlayerInputComponent(InputComponent);

}

UPawnMovementComponent* AMouse::GetMovementComponent() const {
    return MovementComponent;
}

void AMouse::MoveRight() {

    // Move on the x axis.
    
    if (MovementComponent && (MovementComponent->UpdatedComponent == RootComponent)) {

        const FVector MovementDirection = FVector(0.0f, -10.0f, 0.0f).GetClampedToMaxSize(1.0f);
        const float MovementSpeed = 100.0f;
        const FVector Vector = MovementDirection * MovementSpeed;
        MovementComponent->AddInputVector(Vector);
    }
    
}

void AMouse::Jump() {
    
    if (MovementComponent && (MovementComponent->UpdatedComponent == RootComponent)) {
        
        const FVector MovementDirection = FVector(0.0f, 0.0f, 40.0f).GetClampedToMaxSize(1.0f);
        const float MovementSpeed = 400.0f;
        const FVector Vector = MovementDirection * MovementSpeed;
        MovementComponent->AddInputVector(Vector);
        
    }
    
    
}


// Fill out your copyright notice in the Description page of Project Settings.


#include "PopielTower.h"
#include "Mouse.h"
#include "MousePawnMovementComponent.h"
#include "MovementInstruction.h"

#include "iostream"

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
    
    counter = 0;
    
    FMovementInstruction init_struct;
    init_struct.right = 50.0f;
    init_struct.jump = 0.0f;
    
    instructions.Add(init_struct);
}

// Called when the game starts or when spawned
void AMouse::BeginPlay() {
	Super::BeginPlay();
	
}

// Called every frame
void AMouse::Tick( float DeltaTime ) {
	Super::Tick( DeltaTime );
    
    FMovementInstruction recorded;
    
    recorded = instructions[counter];
    
    //std::cout << recorded.jump << "\n";
    
    float jumpheight = 0;
    
    int move_right = float(rand() % 500 + (-2000));
    int random_number = rand() % 100;
        
    if (random_number >= 90) {
        
        jumpheight = Jump();

    }
    
    Gravity();
    
    MoveRight(move_right);

    
    FMovementInstruction moved;
    moved.right = move_right;
    moved.jump = jumpheight;
    
    instructions.Add(moved);
    counter += 1;
}

// Called to bind functionality to input
void AMouse::SetupPlayerInputComponent(class UInputComponent* InputComponent) {

	Super::SetupPlayerInputComponent(InputComponent);

}

UPawnMovementComponent* AMouse::GetMovementComponent() const {
    return MovementComponent;
}

void AMouse::Move(float x, float y, float z, float speed) {
    if (MovementComponent && (MovementComponent->UpdatedComponent == RootComponent)) {

        const FVector MovementDirection = FVector(x, y, z);   //.GetClampedToMaxSize(100.0f);
        const float MovementSpeed = speed;
        const FVector Vector = MovementDirection * MovementSpeed;
        MovementComponent->AddInputVector(Vector);
    }
    
}

void AMouse::MoveRight(float x) {

    // Move on the x axis.
    
    Move(0.0f, x, 0.0f, 400.0f);

}

float AMouse::Jump() {

    float jumpheight = float(rand() % 10000);
    
    Move(0.0f, 0.0f, jumpheight, 1000.0f);
    
    return jumpheight;
    
}

void AMouse::Gravity() {

    Move(0.0f, 0.0f, -1000.0f, 400.0f);
    
}


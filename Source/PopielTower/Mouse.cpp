
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

    MouseBodyComponent->InitCapsuleSize(40.0f, 70.0f);
    MouseBodyComponent->SetCollisionProfileName(TEXT("Pawn"));
    //MouseBodyComponent->SetSimulatePhysics(true);
    //MouseBodyComponent->OnComponentHit.AddDynamic(this, &AMouse::OnHit);
    
    RootComponent = MouseBodyComponent;

    // Mesh
    UStaticMeshComponent* MouseVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
    // "/Game/StarterContent/Shapes/Shape_NarrowCapsule.Shape_NarrowCapsule";
    MouseVisual->SetupAttachment(RootComponent);
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MouseVisualAsset(TEXT("/Game/mysz3_mtl.mysz3_mtl"));
    if (MouseVisualAsset.Succeeded()) {
        MouseVisual->SetStaticMesh(MouseVisualAsset.Object);
        MouseVisual->SetWorldLocationAndRotation(FVector(0.0f, 0.0f, 40.0f), FRotator(90.0f, 0.0f, -90.0f));
        MouseVisual->SetWorldScale3D(FVector(0.2f));
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
void AMouse::Tick( float DeltaSeconds ) {
    
    Super::Tick( DeltaSeconds );
    

    //if (MovementComponent->blocked == true) {
    //
    //}

    FMovementInstruction recorded;
    
    recorded = instructions[counter];

    float jumpheight = 0;
    
    int move_right = float(rand() % 1000 + (-3000));
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

    if (counter >= 1000) {
        Destroy();
    }

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

void AMouse::OnHit(AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) {
    std::cout << "HIT \n";
}

void AMouse::MoveRight(float x) {

    // Move on the x axis.
    
    Move(0.0f, x, 0.0f, 400.0f);

}

float AMouse::Jump() {

    float jumpheight = float(rand() % 10000);
    
    Move(0.0f, 0.0f, jumpheight, 2000.0f);
    
    return jumpheight;
    
}

void AMouse::Gravity() {

    Move(0.0f, 0.0f, -1000.0f, 1000.0f);
    
}


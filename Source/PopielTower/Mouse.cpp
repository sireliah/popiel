
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
    MouseBodyComponent->SetCollisionProfileName(TEXT("Spectator"));
    
    RootComponent = MouseBodyComponent;

    // Mesh
    UStaticMeshComponent* MouseVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
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

    InstructionDelegateAdd.BindUObject(this, &IInstructionInterface::AddToInstruction);
    InstructionDelegateGet.BindUObject(this, &IInstructionInterface::GetInstruction);

    CopyBestInstruction();

    number = rand() % 1000;
}

void AMouse::FireDelegateAdd(TArray<FMovementInstruction> instructions, float efficiency) {
    InstructionDelegateAdd.Execute(instructions, efficiency);
}

TArray<FMovementInstruction> AMouse::FireDelegateGet() {
    return InstructionDelegateGet.Execute();
}

void AMouse::CopyBestInstruction() {

     best_instruction = FireDelegateGet();
     std::cout << "Got best_instruction of len: " << best_instruction.Num() << "\n";
}

void AMouse::BeginPlay() {
    
    Super::BeginPlay();

    GetWorldTimerManager().SetTimer(TimerHandle, this, &AMouse::MovementTimer, 0.1f, true);
	
}

void AMouse::Tick(float DeltaTime) {
    
    Super::Tick(DeltaTime);

    Gravity(DeltaTime);

    counter += 1;

    FVector MouseLocation = GetActorLocation();

    if (MouseLocation.Y < 160 || counter > 1000) {

        InstructionDelegateAdd.BindUObject(this, &IInstructionInterface::AddToInstruction);

        float efficiency = float(MouseLocation.Y) / float(counter);

        FireDelegateAdd(instructions, efficiency);

        Destroy();
    }

}

void AMouse::MovementTimer() {
    if (best_instruction.Num() > 50) {
        MoveUsingInstructions(100.0f);
    } else {
        MoveRandomly(100.0f);
    }
}

// Called to bind functionality to input
void AMouse::SetupPlayerInputComponent(class UInputComponent* InputComponent) {

    Super::SetupPlayerInputComponent(InputComponent);

}

UPawnMovementComponent* AMouse::GetMovementComponent() const {
    return MovementComponent;
}

void AMouse::MoveRandomly(float DeltaTime) {

    float jumpheight = 0;
    int move_right = float(FMath::FRandRange(-200, 20));

    int random_number = rand() % 100;

    if (random_number >= 95) {
        jumpheight = float(FMath::FRandRange(1, 70));
        Jump(jumpheight, DeltaTime);

    }

    MoveRight(move_right, DeltaTime);

    // Save history of movements.
    FMovementInstruction moved;
    moved.right = move_right;
    moved.jump = jumpheight;
    instructions.Add(moved);
}

void AMouse::MoveUsingInstructions(float DeltaTime) {

    if (best_instruction.Num() > 0) {
        FMovementInstruction move = best_instruction.Pop();
        MoveRight(move.right, DeltaTime);
        Jump(move.jump, DeltaTime);
    } else {
        std::cout << "end of instructions! \n";
        Destroy();
    }

}

void AMouse::Move(float x, float y, float z, float speed, float DeltaTime) {
    if (MovementComponent && (MovementComponent->UpdatedComponent == RootComponent)) {

        const FVector MovementDirection = FVector(x, y, z);   //.GetClampedToMaxSize(100.0f);
        const float MovementSpeed = speed;
        const FVector Vector = MovementDirection * MovementSpeed;
        MovementComponent->AddInputVector(Vector);
    }
    
}

void AMouse::MoveRight(float x, float DeltaTime) {

    // Move on the x axis.
    
    Move(0.0f, x, 0.0f, 4000.0f, DeltaTime);

}

void AMouse::Jump(float jumpheight, float DeltaTime) {

    FVector MouseLocation = GetActorLocation();

    MouseLocation.Z += jumpheight * DeltaTime;
    SetActorLocation(MouseLocation, true);

    //Move(0.0f, 0.0f, jumpheight, 2000000.0f, DeltaTime);    
}

void AMouse::Gravity(float DeltaTime) {

    FVector MouseLocation = GetActorLocation();

    MouseLocation.Z -= 5.0f * DeltaTime;
    SetActorLocation(MouseLocation, true);

    //Move(0.0f, 0.0f, -5.0f, 1.0f, DeltaTime);
    
}


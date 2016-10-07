
#pragma once

#include "GameFramework/Pawn.h"
#include "InstructionInterface.h"
#include "Mouse.generated.h"


UCLASS()
class POPIELTOWER_API AMouse : public APawn, public IInstructionInterface {

    GENERATED_BODY()

public:

    AMouse();

    int number;

    virtual void FireDelegateAdd(TArray<FMovementInstruction> instructions, float efficiency) override;

    virtual TArray<FMovementInstruction> FireDelegateGet() override;

    void CopyBestInstruction();

    TArray<FMovementInstruction> best_instruction;

    mutable TArray<FMovementInstruction> instructions;

    mutable double counter;
    
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;
	
    // Called every frame
    virtual void Tick( float DeltaTime ) override;

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

    virtual UPawnMovementComponent* GetMovementComponent() const override;

    class UMousePawnMovementComponent* MovementComponent;
    
    void MovementTimer();

    FTimerHandle TimerHandle;

    void Move(float x, float y, float z, float speed, float DeltaTime);

    void MoveRandomly(float DeltaTime);

    void MoveUsingInstructions(float DeltaTime);

    void MoveRight(float x, float DeltaTime);
    
    void Jump(float jumpheight, float DeltaTime);
    
    void Gravity(float DeltaTime);
};

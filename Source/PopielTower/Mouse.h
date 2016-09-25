
#pragma once

#include "GameFramework/Pawn.h"
#include "MovementInstruction.h"
#include "Mouse.generated.h"


UCLASS()
class POPIELTOWER_API AMouse: public APawn {

	GENERATED_BODY()

public:
    AMouse();

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
    
    void Counter();

    FTimerHandle TimerHandle;

    void Move(float x, float y, float z, float speed, float DeltaTime);

    void MoveRandomly(float DeltaTime);

    void MoveOnInstructions(float DeltaTime);

    void MoveRight(float x, float DeltaTime);
    
    float Jump(float DeltaTime);
    
    void Gravity(float DeltaTime);
};

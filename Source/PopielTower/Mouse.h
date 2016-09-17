
#pragma once

#include "GameFramework/Pawn.h"
#include "MovementInstruction.h"
#include "Mouse.generated.h"


UCLASS()
class POPIELTOWER_API AMouse: public APawn {

	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMouse();

    mutable TArray<FMovementInstruction> instructions;
    mutable double counter;
    
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	virtual UPawnMovementComponent* GetMovementComponent() const override;

    class UMousePawnMovementComponent* MovementComponent;
    
    void Move(float x, float y, float z, float speed);
    
    void MoveRight(float x);
    
    float Jump();
    
    void Gravity();
};

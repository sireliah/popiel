
#pragma once

#include "MovementInstruction.h"
#include "InstructionInterface.generated.h"


DECLARE_DELEGATE_TwoParams(FDelegateSignature, TArray<FMovementInstruction>, float)
DECLARE_DELEGATE_RetVal(TArray<FMovementInstruction>, FDelegateSignature2)


UINTERFACE(MinimalAPI)
class UInstructionInterface : public UInterface {

    GENERATED_UINTERFACE_BODY()

};

class POPIELTOWER_API IInstructionInterface {

    GENERATED_IINTERFACE_BODY()

    IInstructionInterface();

    static FDelegateSignature InstructionDelegateAdd;
    static FDelegateSignature2 InstructionDelegateGet;

    static float best_efficiency;
    static TArray<FMovementInstruction> best_instruction;

    virtual void FireDelegateAdd(TArray<FMovementInstruction> instructions, float efficiency) = 0;
    virtual TArray<FMovementInstruction> FireDelegateGet() = 0;

    void AddToInstruction(TArray<FMovementInstruction> instruction, float efficiency);

    TArray<FMovementInstruction> GetInstruction();
};

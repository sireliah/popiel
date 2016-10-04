
#pragma once

#include "MovementInstruction.h"
#include "InstructionInterface.generated.h"


DECLARE_DELEGATE_OneParam(FDelegateSignature, TArray<FMovementInstruction>)
DECLARE_DELEGATE_RetVal_OneParam(TArray<FMovementInstruction>, FDelegateSignature2, TArray<FMovementInstruction>)


UINTERFACE(MinimalAPI)
class UInstructionInterface : public UInterface {

    GENERATED_UINTERFACE_BODY()

};

class POPIELTOWER_API IInstructionInterface {

    GENERATED_IINTERFACE_BODY()

    static TArray<FMovementInstruction> best_instruction;

    static FDelegateSignature InstructionDelegateAdd;
    static FDelegateSignature2 InstructionDelegateGet;

    virtual void FireDelegateAdd(TArray<FMovementInstruction> instructions) = 0;
    virtual TArray<FMovementInstruction> FireDelegateGet(TArray<FMovementInstruction> instructions) = 0;


    void AddToInstruction(TArray<FMovementInstruction> instruction);

    TArray<FMovementInstruction> GetInstruction(TArray<FMovementInstruction> instructions);
};

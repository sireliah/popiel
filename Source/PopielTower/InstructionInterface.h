// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MovementInstruction.h"
#include "InstructionInterface.generated.h"



UINTERFACE(MinimalAPI)
class UInstructionInterface : public UInterface {

    GENERATED_UINTERFACE_BODY()

};

class POPIELTOWER_API IInstructionInterface {

    GENERATED_IINTERFACE_BODY()

    static TArray<FMovementInstruction> best_instruction;

};

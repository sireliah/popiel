// Fill out your copyright notice in the Description page of Project Settings.

#include "PopielTower.h"
#include "MovementInstruction.h"
#include "InstructionInterface.h"

#include "iostream"

UInstructionInterface::UInstructionInterface(const class FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)

{

}

FDelegateSignature IInstructionInterface::InstructionDelegateAdd = {};
FDelegateSignature2 IInstructionInterface::InstructionDelegateGet = {};


TArray<FMovementInstruction> IInstructionInterface::best_instruction = {};

void IInstructionInterface::AddToInstruction(TArray<FMovementInstruction> instructions) {

    best_instruction = instructions;
}

TArray<FMovementInstruction> IInstructionInterface::GetInstruction(TArray<FMovementInstruction> instructions) {

    //for (int i = 0; i < instruction.Num(); i++) {
    //    std::cout << instruction[i] << " ";
    //}
    //std::cout << "\n";

    return best_instruction;
}

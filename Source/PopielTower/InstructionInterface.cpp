// Fill out your copyright notice in the Description page of Project Settings.

#include "PopielTower.h"
#include "MovementInstruction.h"
#include "InstructionInterface.h"

#include "iostream"

UInstructionInterface::UInstructionInterface(const class FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)

{

}

IInstructionInterface::IInstructionInterface() {



}

FDelegateSignature IInstructionInterface::InstructionDelegateAdd = {};
FDelegateSignature2 IInstructionInterface::InstructionDelegateGet = {};
TArray<FMovementInstruction> IInstructionInterface::best_instruction = {};
float IInstructionInterface::best_efficiency = 0.0f;


void IInstructionInterface::AddToInstruction(TArray<FMovementInstruction> instructions, float efficiency) {
    std::cout << "Old efficiency: " << best_efficiency << " Received efficiency: " << efficiency <<"\n";

    if (efficiency > best_efficiency) {
        std::cout << "This instruction is best so far!\n";
        best_efficiency = efficiency;
        best_instruction = instructions;
    }

}

TArray<FMovementInstruction> IInstructionInterface::GetInstruction() {

    return best_instruction;
}

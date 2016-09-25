// Fill out your copyright notice in the Description page of Project Settings.

#include "PopielTower.h"
#include "MovementInstruction.h"
#include "InstructionInterface.h"


UInstructionInterface::UInstructionInterface(const class FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)

{

}

TArray<FMovementInstruction> IInstructionInterface::best_instruction = {};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/UserDefinedStruct.h"
#include "MovementInstruction.generated.h"



USTRUCT()
struct FMovementInstruction {
   
    GENERATED_BODY()
    
    UPROPERTY()
    float right;
    
    UPROPERTY()
    float jump;
    
    
};
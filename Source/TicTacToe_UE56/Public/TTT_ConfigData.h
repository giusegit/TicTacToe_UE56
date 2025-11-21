// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "TTT_ConfigData.generated.h"

/**
 * 
 */
UCLASS()
class TICTACTOE_UE56_API UTTT_ConfigData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	// grid size 
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Config")
	int32 GridSize;

	// tile size
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Config")
	float TileSize;

	// tile padding percentage
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Config")
	float CellPadding;
	
};

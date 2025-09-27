// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TTT_PlayerInterface.h"
#include "TTT_GameInstance.h"
#include "TTT_GameMode.h"
#include "Kismet/GameplayStatics.h"
#include "TTT_RandomPlayer.generated.h"

UCLASS()
class TICTACTOE_UE56_API ATTT_RandomPlayer : public APawn, public ITTT_PlayerInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATTT_RandomPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};

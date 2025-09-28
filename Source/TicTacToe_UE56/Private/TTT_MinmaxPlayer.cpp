// Fill out your copyright notice in the Description page of Project Settings.


#include "TTT_MinmaxPlayer.h"

// Sets default values
ATTT_MinmaxPlayer::ATTT_MinmaxPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATTT_MinmaxPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATTT_MinmaxPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATTT_MinmaxPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATTT_MinmaxPlayer::OnTurn()
{
}

void ATTT_MinmaxPlayer::OnWin()
{
}

void ATTT_MinmaxPlayer::OnLose()
{
}

int32 ATTT_MinmaxPlayer::EvaluateGrid(TMap<FVector2D, ATile*>& Board)
{
	return int32();
}

bool ATTT_MinmaxPlayer::IsMovesLeft(TMap<FVector2D, ATile*>& Board)
{
	return false;
}

int32 ATTT_MinmaxPlayer::MiniMax(TMap<FVector2D, ATile*>& Board, int32 Depth, bool IsMax)
{
	return int32();
}

FVector2D ATTT_MinmaxPlayer::FindBestMove(TMap<FVector2D, ATile*>& Board)
{
	return FVector2D();
}


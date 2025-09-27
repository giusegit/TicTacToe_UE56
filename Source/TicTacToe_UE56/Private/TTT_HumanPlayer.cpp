// Fill out your copyright notice in the Description page of Project Settings.


#include "TTT_HumanPlayer.h"

// Sets default values
ATTT_HumanPlayer::ATTT_HumanPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATTT_HumanPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATTT_HumanPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATTT_HumanPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


// Fill out your copyright notice in the Description page of Project Settings.


#include "TTT_GameInstance.h"

void UTTT_GameInstance::IncrementScoreHumanPlayer()
{
	ScoreHumanPlayer += 1;
}

void UTTT_GameInstance::IncrementScoreAiPlayer()
{
	ScoreAiPlayer += 1;
}

int32 UTTT_GameInstance::GetScoreHumanPlayer()
{
	return ScoreHumanPlayer;
}

int32 UTTT_GameInstance::GetScoreAiPlayer()
{
	return ScoreAiPlayer;
}

void UTTT_GameInstance::ResetScores()
{
	ScoreHumanPlayer = 0;
	ScoreAiPlayer = 0;
}

FString UTTT_GameInstance::GetTurnMessage()
{
	return CurrentTurnMessage;
}

void UTTT_GameInstance::SetTurnMessage(FString Message)
{
	CurrentTurnMessage = Message;
}

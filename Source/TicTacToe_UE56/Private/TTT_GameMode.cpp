// Fill out your copyright notice in the Description page of Project Settings.


#include "TTT_GameMode.h"
#include "TTT_PlayerController.h"
#include "TTT_HumanPlayer.h"
#include "TTT_RandomPlayer.h"
//#include "TTT_MinimaxPlayer.h"
#include "EngineUtils.h"

ATTT_GameMode::ATTT_GameMode()
{
	PlayerControllerClass = ATTT_PlayerController::StaticClass();
	DefaultPawnClass = ATTT_HumanPlayer::StaticClass();
	FieldSize = 3;
}

void ATTT_GameMode::BeginPlay()
{
	Super::BeginPlay();

	IsGameOver = false;

	MoveCounter = 0;

	//ATTT_HumanPlayer* HumanPlayer = *TActorIterator<ATTT_HumanPlayer>(GetWorld());
	ATTT_HumanPlayer* HumanPlayer = GetWorld()->GetFirstPlayerController()->GetPawn<ATTT_HumanPlayer>();

	if (!IsValid(HumanPlayer))
	{
		UE_LOG(LogTemp, Error, TEXT("No player pawn of type '%s' was found."), *ATTT_HumanPlayer::StaticClass()->GetName());
		return;
	}

	if (GameFieldClass != nullptr)
	{
		GField = GetWorld()->SpawnActor<AGameField>(GameFieldClass);
		GField->Size = FieldSize;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Game Field is null"));
		return;
	}

	float CameraPosX = ((GField->TileSize * FieldSize) + ((FieldSize - 1) * GField->TileSize * GField->CellPadding)) * 0.5f;

	FVector CameraPos(CameraPosX, CameraPosX, 1000.0f);
	HumanPlayer->SetActorLocationAndRotation(CameraPos, FRotationMatrix::MakeFromX(FVector(0, 0, -1)).Rotator());

	// Alternativamente, per avere una telecamera fissa in scena:
	// 1. Aggiungere un Camera Actor nella scena
	// 2. Impostare "Player 0" nel campo "Auto Activate for Player"
	// 3. Togliere la spunta al campo "Constrain Aspect Ratio"
	// 4. Posizionatela e orientatela a vostro piacimento


	// Human player = 0
	Players.Add(HumanPlayer);
	// Random Player
	auto* AI = GetWorld()->SpawnActor<ATTT_RandomPlayer>(FVector(), FRotator());

	// MiniMax Player
	//auto* AI = GetWorld()->SpawnActor<ATTT_MinimaxPlayer>(FVector(), FRotator());

	// AI player = 1
	Players.Add(AI);

	this->ChoosePlayerAndStartGame();
}

void ATTT_GameMode::ChoosePlayerAndStartGame()
{
	CurrentPlayer = FMath::RandRange(0, Players.Num() - 1);

	for (int32 IndexI = 0; IndexI < Players.Num(); IndexI++)
	{
		Players[IndexI]->PlayerNumber = IndexI;
		Players[IndexI]->Sign = IndexI == CurrentPlayer ? ESign::X : ESign::O;
	}
	MoveCounter += 1;
	Players[CurrentPlayer]->OnTurn();
}

void ATTT_GameMode::SetCellSign(const int32 PlayerNumber, const FVector& SpawnPosition)
{
	if (IsGameOver || PlayerNumber != CurrentPlayer)
	{
		return;
	}

	UClass* SignActor = Players[CurrentPlayer]->Sign == ESign::X ? SignXActor : SignOActor;
	FVector Location = GField->GetActorLocation() + SpawnPosition + FVector(0, 0, 10);
	GetWorld()->SpawnActor(SignActor, &Location);

	if (GField->IsWinPosition(GField->GetXYPositionByRelativeLocation(SpawnPosition)))
	{
		IsGameOver = true;
		Players[CurrentPlayer]->OnWin();
		for (int32 IndexI = 0; IndexI < Players.Num(); IndexI++)
		{
			if (IndexI != CurrentPlayer)
			{
				Players[IndexI]->OnLose();
			}
		}
	}
	else if (MoveCounter == (FieldSize * FieldSize))
	{
		// add a timer (3 seconds)
		FTimerHandle TimerHandle;

		GetWorld()->GetTimerManager().SetTimer(TimerHandle, [&]()
			{
				// function to delay
				GField->ResetField();
			}, 3, false);
	}
	else
	{
		TurnNextPlayer();
	}
}

int32 ATTT_GameMode::GetNextPlayer(int32 Player)
{
	Player++;
	if (!Players.IsValidIndex(Player))
	{
		Player = 0;
	}
	return Player;
}

void ATTT_GameMode::TurnNextPlayer()
{
	MoveCounter += 1;
	CurrentPlayer = GetNextPlayer(CurrentPlayer);
	Players[CurrentPlayer]->OnTurn();
}

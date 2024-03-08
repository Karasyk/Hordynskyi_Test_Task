// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModes/T_GameMode.h"

#include "Ball/T_Ball.h"
#include "Kismet/GameplayStatics.h"
#include "Pawns/T_PlayerPawn.h"

void AT_GameMode::StartGame()
{
	TArray<AActor*> BallArray;
	UGameplayStatics::GetAllActorsOfClass(this, AT_Ball::StaticClass(), BallArray);
	Ball = Cast<AT_Ball>(BallArray[0]);
	if (Ball)
	{
		Ball->Start();
	}
}

void AT_GameMode::EndGame()
{	
	if (Ball)
	{
		Ball->GameOver();
	}
}

void AT_GameMode::Logout(AController* Exiting)
{
	Super::Logout(Exiting);
}

void AT_GameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	// possess a pawn
	TArray<AActor*> PawnArray;
	UGameplayStatics::GetAllActorsOfClass(this, AT_PlayerPawn::StaticClass(), PawnArray);
	if (PawnArray.Num() > 0)
	{
		for (AActor* Actor : PawnArray)
		{
			AT_PlayerPawn* PlayerPawn = Cast<AT_PlayerPawn>(Actor);
			if (PlayerPawn && !PlayerPawn->IsPawnControlled())
			{
				NewPlayer->Possess(PlayerPawn);
				PlayerPawn->SetOwner(NewPlayer);
			}
		}
	}

	if (GetNumPlayers() == 2)
	{
		StartGame();
	}
}

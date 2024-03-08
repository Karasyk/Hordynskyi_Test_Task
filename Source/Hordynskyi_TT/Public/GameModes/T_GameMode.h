// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ball/T_Ball.h"
#include "GameFramework/GameModeBase.h"
#include "T_GameMode.generated.h"

/**
 * 
 */
UCLASS()
class HORDYNSKYI_TT_API AT_GameMode : public AGameModeBase
{
	GENERATED_BODY()
public:
	void StartGame();
	void EndGame();

protected:
	virtual void PostLogin(APlayerController* NewPlayer) override;

	virtual void Logout(AController* Exiting) override;
	
	int ConnectedPlayers{};

	UPROPERTY()
	AT_Ball* Ball;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Pawns/T_PlayerPawn.h"
#include "T_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class HORDYNSKYI_TT_API AT_PlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void SetupInputComponent() override;
	virtual void BeginPlay() override;
	
	UPROPERTY()
	AT_PlayerPawn* ControlledPawn;

	virtual void OnPossess(APawn* InPawn) override;
	void MoveRacket(const float Value);
	
};

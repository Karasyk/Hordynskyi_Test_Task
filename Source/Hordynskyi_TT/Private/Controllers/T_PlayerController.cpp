// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/T_PlayerController.h"

#include "Camera/CameraActor.h"
#include "Kismet/GameplayStatics.h"

void AT_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	//InputComponent->BindAxis("MoveRacket", this, &AT_PlayerController::MoveRacket);
}

void AT_PlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void AT_PlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	
	ControlledPawn = CastChecked<AT_PlayerPawn>(InPawn);
	
	TArray<AActor*> CameraArray;
	UGameplayStatics::GetAllActorsOfClass(this, ACameraActor::StaticClass(), CameraArray);
	if (CameraArray.Num() > 0)
	{		
		SetViewTargetWithBlend(CameraArray[0]);
	}
}

void AT_PlayerController::MoveRacket(const float Value)
{
	if (Value != 0.f)
	{
		if(ControlledPawn)
		{
			ControlledPawn->Move(Value * 2.f);
			//GEngine->AddOnScreenDebugMessage(-1,1.f,FColor::Green,FString("Move in CONTROLLER"));
		}
	}
}

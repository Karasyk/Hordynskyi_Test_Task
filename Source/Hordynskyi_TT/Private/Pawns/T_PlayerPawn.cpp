// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/T_PlayerPawn.h"



// Sets default values
AT_PlayerPawn::AT_PlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	bReplicates = true;
	
	RootCollision = CreateDefaultSubobject<UBoxComponent>(FName("Root"));
	RootCollision->SetCollisionProfileName("NoCollision");
	Racket = CreateDefaultSubobject<UStaticMeshComponent>(FName("Racket"));
	Racket->AttachToComponent(RootCollision, FAttachmentTransformRules::KeepRelativeTransform);
	RacketCollision = CreateDefaultSubobject<UBoxComponent>(FName("Racket Collision"));
	RacketCollision->AttachToComponent(Racket, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void AT_PlayerPawn::BeginPlay()
{
	Super::BeginPlay();

	SetReplicateMovement(true);
}

// Called every frame
void AT_PlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AT_PlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	check(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveRacket", this, &AT_PlayerPawn::Move);
}

void AT_PlayerPawn::Move_Implementation(const float Value)
{
	if (Value != 0.f)
	{
		AddActorLocalOffset(FVector(0, Value * 2.f, 0));
	}
}



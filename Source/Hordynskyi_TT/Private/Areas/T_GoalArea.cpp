// Fill out your copyright notice in the Description page of Project Settings.


#include "Areas/T_GoalArea.h"

// Sets default values
AT_GoalArea::AT_GoalArea()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	GoalCollision = CreateDefaultSubobject<UBoxComponent>(FName("Goal Collision"));
}

// Called when the game starts or when spawned
void AT_GoalArea::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &AT_GoalArea::Goal);
}

void AT_GoalArea::Goal(AActor* OverlappedActor, AActor* OtherActor)
{
	if(OtherActor->ActorHasTag("Ball"))
	{
		AT_Ball*Ball = Cast<AT_Ball>(OtherActor);
		Ball->Restart();
	}
}

// Called every frame
void AT_GoalArea::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


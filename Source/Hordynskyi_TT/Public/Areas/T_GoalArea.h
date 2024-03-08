// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ball/T_Ball.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "T_GoalArea.generated.h"

UCLASS()
class HORDYNSKYI_TT_API AT_GoalArea : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AT_GoalArea();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY()
	UBoxComponent* GoalCollision;
	
	UFUNCTION()
	void Goal(AActor* OverlappedActor, AActor* OtherActor);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

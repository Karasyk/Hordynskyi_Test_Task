// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "T_Ball.generated.h"

UCLASS()
class HORDYNSKYI_TT_API AT_Ball : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AT_Ball();

	void PreparingToStart();
	void StartMovement();
	void Start();
	void Restart();
	void GameOver();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bGameover;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* BallMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USphereComponent* BallCollision;

	UFUNCTION()
	void BallHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);
	
	float Speed;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

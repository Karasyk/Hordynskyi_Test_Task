// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball/T_Ball.h"

#include "Kismet/KismetMathLibrary.h"

// Sets default values
AT_Ball::AT_Ball()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	bReplicates = true;

	BallMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("Ball Mesh"));
	RootComponent = BallMesh;
	BallMesh->SetSimulatePhysics(true);
	BallMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	BallMesh->SetEnableGravity(false);
	BallMesh->SetConstraintMode(EDOFMode::XYPlane);
	BallMesh->SetNotifyRigidBodyCollision(true);
	BallMesh->SetAngularDamping(5.0f);
	
	BallCollision = CreateDefaultSubobject<USphereComponent>(FName("Ball Collision"));
	BallCollision->SetupAttachment(BallMesh);
	BallCollision->SetCollisionProfileName("Trigger");

	Tags.Add(TEXT("Ball"));
}


void AT_Ball::StartMovement()
{	
	BallMesh->SetPhysicsLinearVelocity(FVector(FMath::RandRange(-300.f, 300.f),
		(FMath::RandBool() ? 1.f : -1.f) * 500.f,0.f));
}

// Called when the game starts or when spawned
void AT_Ball::BeginPlay()
{
	Super::BeginPlay();

	SetReplicateMovement(true);
	OnActorHit.AddDynamic(this, &AT_Ball::BallHit);
}

void AT_Ball::BallHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{	
	FVector BallVelocity = BallMesh->GetPhysicsLinearVelocity();
	FVector Normal = Hit.ImpactNormal;
	FVector ReflectedVelocity = UKismetMathLibrary::MirrorVectorByNormal(BallVelocity, Normal);
	
	BallMesh->SetPhysicsLinearVelocity(ReflectedVelocity);
	BallMesh->SetPhysicsAngularVelocityInDegrees(FVector::ZeroVector);
}

void AT_Ball::PreparingToStart()
{
	SetActorLocation(FVector::ZeroVector);
	BallMesh->SetPhysicsLinearVelocity(FVector::ZeroVector);
	BallMesh->SetPhysicsAngularVelocityInDegrees(FVector::ZeroVector);
	FTimerHandle UnusedHandle;
	GetWorldTimerManager().SetTimer(UnusedHandle, this, &AT_Ball::StartMovement, 2.0f, false);
}
void AT_Ball::Start()
{
	bGameover = false;
	PreparingToStart();
}

void AT_Ball::Restart()
{
	SetActorLocation(FVector::ZeroVector);
	PreparingToStart();
}

void AT_Ball::GameOver()
{
	bGameover = true;
	BallMesh->SetPhysicsLinearVelocity(FVector::ZeroVector);
}

// Called every frame
void AT_Ball::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


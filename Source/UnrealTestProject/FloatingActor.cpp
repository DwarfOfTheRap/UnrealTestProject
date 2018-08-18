// Fill out your copyright notice in the Description page of Project Settings.

#include "FloatingActor.h"


// Sets default values
AFloatingActor::AFloatingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RandX = FMath::RandRange(0.6f, 1.3f);
	RandY = FMath::RandRange(0.6f, 1.3f);
}

// Called when the game starts or when spawned
void AFloatingActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AFloatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector NewLocation = GetActorLocation();
	float DeltaZ = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	float DeltaY = (FMath::Sin(RandY + RunningTime + DeltaTime) - FMath::Sin(RandY + RunningTime));
	float DeltaX = (FMath::Sin(RandX + RunningTime + DeltaTime) - FMath::Sin(RandX + RunningTime));
	NewLocation.Z += DeltaZ * 20.0f; // Scale our height by a factor of 20
	NewLocation.Y += DeltaY * 20.0f;
	NewLocation.X += DeltaX * 20.0f;

	RunningTime += DeltaTime;
	SetActorLocation(NewLocation);
}


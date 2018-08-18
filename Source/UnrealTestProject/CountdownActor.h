// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Components/TextRenderComponent.h"
#include "Runtime/Engine/Public/TimerManager.h"
#include "CountdownActor.generated.h"

UCLASS()
class UNREALTESTPROJECT_API ACountdownActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACountdownActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// How long, in seconds, the countdown will run.
	UPROPERTY(VisibleAnywhere)
	int32 CountdownTime;

	UPROPERTY(EditAnywhere)
	UTextRenderComponent* CountdownText;

	FTimerHandle CountdownTimerHandle;

	void UpdateTimerDisplay();

	void AdvanceTimer();

	void CountdownHasFinished();
};

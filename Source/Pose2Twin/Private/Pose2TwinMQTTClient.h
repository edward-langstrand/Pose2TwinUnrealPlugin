// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Pose2TwinMQTTClient.generated.h"


UCLASS()
class POSE2TWIN_API APose2TwinMQTTClient : public AActor
{
	GENERATED_BODY()

private:
	TQueue<TArray<uint8>, EQueueMode::Spsc> QueuedMessages;
	
public:	
	// Sets default values for this actor's properties
	APose2TwinMQTTClient();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void HandlePose2TwinPayload(const FString& Topic, const TArray<uint8>& Bytes);
	

};

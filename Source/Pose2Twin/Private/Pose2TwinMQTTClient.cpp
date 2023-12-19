// Fill out your copyright notice in the Description page of Project Settings.


#include "Pose2TwinMQTTClient.h"
#include "Pose2TwinLog.h"

// Sets default values
APose2TwinMQTTClient::APose2TwinMQTTClient()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APose2TwinMQTTClient::BeginPlay()
{
	Super::BeginPlay();
	
}

void APose2TwinMQTTClient::HandlePose2TwinPayload(const FString& Topic, const TArray<uint8>& Bytes)
{
	QueuedMessages.Enqueue(Bytes);
}

// Called every frame
void APose2TwinMQTTClient::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


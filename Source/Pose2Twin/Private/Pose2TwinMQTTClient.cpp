// Fill out your copyright notice in the Description page of Project Settings.


#include "Pose2TwinMQTTClient.h"
#include "Pose2TwinFunctionLibrary.h"
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

	while(!QueuedMessages.IsEmpty())
	{
		TArray<uint8> PayloadBytes;
		if(!QueuedMessages.Dequeue(PayloadBytes)) continue;
		
		FString PayloadString = UPose2TwinFunctionLibrary::BytesToStringUTF8(PayloadBytes);
		//TODO(edward): Missing last character for some reason...
		PayloadString += '}';

		TSharedRef<TJsonReader<>> Reader = FJsonStringReader::Create(PayloadString);
		
		TSharedPtr<FJsonObject> PayloadJSON;
		if(!FJsonSerializer::Deserialize(Reader, PayloadJSON)) continue;

		for (auto It = PayloadJSON.Get()->Values.CreateIterator(); It; ++It)
		{
			UE_LOG(LogPose2Twin, Log, TEXT("JSON KEY: %s"), *It.Key())
		}
	}
}


// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();
	void OpenDoor();
	void CloseDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(EditAnywhere)//UPROPERTY makes variables viewable in editor 
	float OpenAngle = 90.0f;

	UPROPERTY(EditAnywhere)//UPROPERTYmakes variables viewable in editor , this is a trigger volume 
	ATriggerVolume* PressurePlate;

	UPROPERTY(EditAnywhere)
	float DoorCloseDelay = 0.6f;

	UPROPERTY(EditAnywhere)
	float CloseAngle = 180.0f;

	float LastDoorOpenTime;

	AActor* ActorThatOpens; //Pawn inherits from actor

	AActor* Owner;

	
	
};

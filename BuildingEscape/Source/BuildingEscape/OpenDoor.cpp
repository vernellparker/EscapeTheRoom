// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingEscape.h"
#include "OpenDoor.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}




// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	ActorThatOpens= GetWorld()->GetFirstPlayerController()->GetPawn(); //Gets Pawn which is the character 


	
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Poll the trigger volume
	if (PressurePlate ->IsOverlappingActor(ActorThatOpens))
	{
		//if the ActotorThatOpens is in the volume
		OpenDoor();
	}
	
}

void UOpenDoor::OpenDoor()
{
	auto* Owner = GetOwner(); //Gets the owner object

	FRotator NewRotation = FRotator(0.0f, 90.0f, 0.0f); //Creates a rotator

	Owner->SetActorRotation(NewRotation);//Rotates the Owner
}
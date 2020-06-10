// Fill out your copyright notice in the Description page of Project Settings.


#include "Drone.h"




// Sets default values
ADrone::ADrone()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	outCollision = CreateDefaultSubobject<UBoxComponent>(FName{"outCollision"});
	outCollision->SetupAttachment(RootComponent);
	outCollision->SetBoxExtent(FVector{150.0f,150.0f,45.0f});
	
	drone = CreateDefaultSubobject<UStaticMeshComponent>(FName{"Drone"});
	drone->SetupAttachment(outCollision);
	
	wing1 = CreateDefaultSubobject<UStaticMeshComponent>(FName{"wing1"});
	wing1->SetupAttachment(drone,FName{"wing1"});
	arrWings.Add(wing1);
	
	wing2 = CreateDefaultSubobject<UStaticMeshComponent>(FName{"wing2"});
	wing2->SetupAttachment(drone,FName{"wing2"});
	arrWings.Add(wing2);
	
	wing3 = CreateDefaultSubobject<UStaticMeshComponent>(FName{"wing3"});
	wing3->SetupAttachment(drone,FName{"wing3"});
	arrWings.Add(wing3);
	
	wing4 = CreateDefaultSubobject<UStaticMeshComponent>(FName{"wing4"});
	wing4->SetupAttachment(drone,FName{"wing4"});
	arrWings.Add(wing4);

	wingRotateSpeed=3000.0f;
	moveForwardSpeed=2.0f;
	turnSpeed = 1.0f;
	moveUpSpeed = 1.0f;
	
	AutoPossessPlayer = EAutoReceiveInput::Player0;
	AutoReceiveInput = EAutoReceiveInput::Player0;
}



void ADrone::MoveForward(float val)
{
	
	outCollision->AddWorldOffset(outCollision->GetForwardVector()*val*moveForwardSpeed);
}

void ADrone::Turn(float val)
{
	outCollision->AddRelativeRotation(FRotator{0,1,0}*turnSpeed*val);
}

void ADrone::MoveUp(float val)
{
	outCollision->AddWorldOffset(FVector{0,0,1}*val*moveUpSpeed);
}

// Called when the game starts or when spawned
void ADrone::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADrone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	RotateWing(DeltaTime);
}

// Called to bind functionality to input
void ADrone::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("Forward"),this,&ADrone::MoveForward);
	
	PlayerInputComponent->BindAxis(TEXT("Turn"),this,&ADrone::Turn);

	PlayerInputComponent->BindAxis(TEXT("Up"),this,&ADrone::MoveUp);


}

void ADrone::RotateWing(float val)
{
	for(auto wing : arrWings)
	{
		wing->AddRelativeRotation(FRotator{0,val*wingRotateSpeed,0});
	}
	
}


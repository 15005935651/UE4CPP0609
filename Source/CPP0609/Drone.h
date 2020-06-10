// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Pawn.h"
#include "Components/InputComponent.h"
#include "Drone.generated.h"

UCLASS()
class CPP0609_API ADrone : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ADrone();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* drone;

	UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* wing1;

	UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* wing2;

	UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* wing3;

	UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* wing4;
	
	UPROPERTY(VisibleAnywhere)
	UBoxComponent *outCollision;
	
	UPROPERTY(EditAnywhere,Category="Drone")
	float wingRotateSpeed;

	UPROPERTY(EditAnywhere,Category="Drone")
	float moveForwardSpeed;

	UPROPERTY(EditAnywhere,Category="Drone")
	float turnSpeed;

	UPROPERTY(EditAnywhere,Category="Drone")
    float moveUpSpeed;
	

	UFUNCTION()
	void MoveForward(float val);
	UFUNCTION()
	void Turn(float val);
	UFUNCTION()
	void MoveUp(float val);	
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
private:
	void RotateWing(float val);
	TArray<UStaticMeshComponent*> arrWings;
};

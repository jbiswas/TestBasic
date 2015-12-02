// Fill out your copyright notice in the Description page of Project Settings.

#include "TestBasic.h"
#include "FloatingActor.h"


// Sets default values
AFloatingActor::AFloatingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFloatingActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AFloatingActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
    FVector NewLocation = GetActorLocation();
    FRotator Rotation;
    float factor = RunningTime + DeltaTime * 1;
    float DeltaHeight = (FMath::Sin(factor) - FMath::Sin(RunningTime));
    float DeltaWidth = (FMath::Cos(factor) - FMath::Cos(RunningTime));
    NewLocation.Z += DeltaHeight * 20.0f;       //Scale our height by a factor of 20
    NewLocation.Y += DeltaWidth * 20.0f;       //Scale our height by a factor of 20
    RunningTime += DeltaTime;
    SetActorLocation(NewLocation);
    if(FMath::IsNearlyEqual(DeltaHeight, DeltaWidth, 1.e-3f)) {
        FVector ParticleLocation(NewLocation);
        ParticleLocation.Z += 50.f;
        ParticleLocation.X += 100.f;
        UGameplayStatics::SpawnEmitterAtLocation(this, Fire, ParticleLocation, Rotation, true);
    }
}


// Fill out your copyright notice in the Description page of Project Settings.
#include "Item.h"
//#include "Characters/TopDownARPGCharacter.h"
#include "Components/SphereComponent.h"
#include "CollisionSphere.h"

// Sets default values
ACollisionSphere::ACollisionSphere()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	SphereComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	SphereComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
	SphereComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldStatic, ECollisionResponse::ECR_Overlap);
	RootComponent = SphereComponent;

	SphereComponent->OnComponentBeginOverlap.AddUniqueDynamic(this, &ACollisionSphere::OnOverlap);

}

// Called when the game starts or when spawned
void ACollisionSphere::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACollisionSphere::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ACollisionSphere::OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	TArray<AActor*> OverlapItems;
	SphereComponent->GetOverlappingActors(OverlapItems);
	for (auto& CurrentActor : OverlapItems)
	{
		if (CurrentActor != nullptr && CurrentActor != GetOwner())
		{
			AItem* CastingActor = Cast<AItem>(CurrentActor);
			if (IsValid(CastingActor))
				CurrentActor->Destroy();
			break;
		}
	}
	Destroy();
}

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "InventorySystem/Public/SlotStruct.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"


UCLASS(Blueprintable,ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class INVENTORYSYSTEM_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int NumberOfSlots;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FSlotStruct>Inventory;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FDataTableRowHandle CharacterInventory;

	//UFUNCTION()
	//void TogleInventory();

};

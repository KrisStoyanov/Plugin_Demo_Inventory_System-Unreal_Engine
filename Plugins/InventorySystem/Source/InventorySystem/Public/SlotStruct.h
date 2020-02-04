// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "InventorySystem/Public/Item.h"
#include "Item.h"
#include "Engine/DataTable.h"
#include "CoreMinimal.h"
#include "Engine/UserDefinedStruct.h"
#include "SlotStruct.generated.h"


USTRUCT(BlueprintType)
struct INVENTORYSYSTEM_API FSlotStruct : public FTableRowBase
{
	GENERATED_BODY()

		FSlotStruct()
	{
		ItemInSlot = NULL;
		Quantity = 0;
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<AItem> ItemInSlot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Quantity;
};

/**
 * 

UCLASS()
class INVENTORYSYSTEM_API USlotStruct : public UUserDefinedStruct
{
	GENERATED_BODY()
	
}; */

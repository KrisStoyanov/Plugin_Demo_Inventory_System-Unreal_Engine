// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Engine/Texture2D.h"
#include "CoreMinimal.h"
//#include"InventorySystem/Public/Item.h"
#include "Engine/DataTable.h"
#include "Engine/UserDefinedStruct.h"
#include "ItemStruct.generated.h"

USTRUCT(BlueprintType)
struct INVENTORYSYSTEM_API FItemStruct : public FTableRowBase
{	
	GENERATED_BODY()
	
		FItemStruct()
	{
		ItemName = "Default";
		ItemTexture = nullptr;
		IsStackable = true;
		MaxSize = 10;
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString ItemName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UTexture2D* ItemTexture;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsStackable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int MaxSize;
};

/**
 * 
 
UCLASS()
class INVENTORYSYSTEM_API UItemStruct : public UUserDefinedStruct
{
	GENERATED_BODY()
	
};*/

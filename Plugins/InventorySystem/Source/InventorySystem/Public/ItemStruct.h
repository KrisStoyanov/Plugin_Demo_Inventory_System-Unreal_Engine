// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Engine/DataTable.h"
#include "CoreMinimal.h"
//#include"InventorySystem/Public/Item.h"
#include "Engine/Texture2D.h"
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
		//ItemClass = nullptr;
	}

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString ItemName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UTexture2D* ItemTexture;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsStackable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int MaxSize;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
		//TSubclassOf <class AItem> ItemClass;
};

/**
 * 
 
UCLASS()
class INVENTORYSYSTEM_API UItemStruct : public UUserDefinedStruct
{
	GENERATED_BODY()
	
};*/

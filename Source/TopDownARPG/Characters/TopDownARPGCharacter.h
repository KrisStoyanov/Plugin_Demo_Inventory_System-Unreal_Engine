// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once
#include "CollisionSphere.h"
//#include "SphereOfCollision.h"
#include "Components/SphereComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Abilities/Ability.h"
#include "DataTables/TopDownARPGCharacterStruct.h"
#include "TopDownARPGCharacter.generated.h"

UCLASS(Blueprintable)
class ATopDownARPGCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ATopDownARPGCharacter();

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;
	virtual void BeginPlay() override;

	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns CursorToWorld subobject **/
	FORCEINLINE class UDecalComponent* GetCursorToWorld() { return CursorToWorld; }

	FORCEINLINE class UInventoryComponent* GetInventory() { return Inventory; }

	//FORCEINLINE class USphereOfCollision* GetOverlapComponent() { return OverlapComponent; }
	FORCEINLINE class USphereComponent* GetOverlapComponent() { return OverlapComponent; }

	FORCEINLINE float GetHealth() { return Health; }

	//UFUNCTION()
	//virtual void OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	
	UFUNCTION()
		bool ActivateInteract();

	UPROPERTY()
		TSubclassOf<class ACollisionSphere>SC;

	UPROPERTY()
	TArray<UAbility*> AbilityInstances;

private:
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	UPROPERTY(EditAnywhere, Category = Inventory, meta = (AllowPrivateAccess = "true"))
	class UInventoryComponent* Inventory;

	/** A decal that projects to the cursor location. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UDecalComponent* CursorToWorld;

	UPROPERTY(EditAnywhere)
		class USphereComponent* OverlapComponent;
	//class USphereOfCollision* OverlapComponent;
	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<UAbility>> AbilityTemplates;

	UPROPERTY(EditAnywhere)
	FDataTableRowHandle CharacterStatsRow;

	UPROPERTY(EditDefaultsOnly)
	float MaximumHealth;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float Health;

	UFUNCTION()
	void TakeAnyDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigateBy, AActor* DamageCauser);


	void Death();
};


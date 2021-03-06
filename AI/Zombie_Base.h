// This code was written by 康子秋

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Zombie_Base.generated.h"

UCLASS()
class FPS_TESTGAME_API AZombie_Base : public ACharacter
{
	GENERATED_BODY()

public:
	AZombie_Base();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UHealthComponent * HealthComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float AutoDestoryTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class USceneComponent * BloodScene;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)	//默认僵尸攻击力
		float DefaultAttack_HP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Decal")
		TArray<UMaterialInterface *> BloodDecalArray;	//击中单孔贴花数组
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Decal")
		UMaterialInterface * BloodImpactDecal;		//击中单孔贴花

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Decal")
		FVector BloodDecalSize;

protected:
	virtual void BeginPlay() override;

	UFUNCTION(Server, Reliable, WithValidation)
		void DieSet();

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void OnHealthChanged(UHealthComponent* HealthComponent, float Health, float HealthDelta, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);
	
};

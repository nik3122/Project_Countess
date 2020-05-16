// Free to play. By SoNa Games.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Countess_GAGrantingActor.generated.h"

UCLASS()
class PROJECT_COUNTESS_API ACountess_GAGrantingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACountess_GAGrantingActor();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Mesh, meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* BoxComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Mesh, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* StaticMesh;

	UFUNCTION()
	void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GameplayAbility, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class UCountess_GameplayAbility_Base> AbilityToGrant;

	//UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = Broadcast)
	bool Execute_GiveAbilityOnOverlap(TSubclassOf<class UCountess_GameplayAbility_Base> Ability);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



};
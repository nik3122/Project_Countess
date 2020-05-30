// Free to play. By SoNa Games.

#pragma once

#include "Globals/Project_Countess.h"
#include "GameFramework/Actor.h"
#include "Countess_Actor_Fireball.generated.h"

class UStaticMeshComponent;
class USphereComponent;
class UParticleSystem;
class UParticleSystemComponent;
class UStaticMesh;
class UMaterialInterface;
class UProjectileMovementComponent;

/*Our Fireball Actor*/
UCLASS()
class PROJECT_COUNTESS_API ACountess_Actor_Fireball : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACountess_Actor_Fireball();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	USphereComponent* FireballCollision;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* FireballMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UParticleSystem* FireballVFX;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UParticleSystemComponent* FireballVFXComponent;

	UStaticMesh* FireballMesh;

	UMaterialInterface* FireballMaterial;

	UProjectileMovementComponent* FireballProjectileMovementComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



};

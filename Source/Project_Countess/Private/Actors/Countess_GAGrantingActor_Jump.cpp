// Free to play. By SoNa Games.


#include "Actors/Countess_GAGrantingActor_Jump.h"
#include "Components/BoxComponent.h"
#include "Sound/SoundBase.h"
#include "Characters/GameplayAbilities/Abilities/Countess_GameplayAbility_Jump.h"

ACountess_GAGrantingActor_Jump::ACountess_GAGrantingActor_Jump()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	static ConstructorHelpers::FObjectFinder<USoundBase> SoundToPlayObject(TEXT("SoundWave'/Game/MyProjectMain/Audio/Floating_UI_Close.Floating_UI_Close'"));
	if (SoundToPlayObject.Succeeded())
	{
		SoundToPlayOnInteract_HardRef = SoundToPlayObject.Object;
		SoundToPlayOnInteract = SoundToPlayOnInteract_HardRef;
	}

	BoxComponent_HardRef = CreateDefaultSubobject<UBoxComponent>(FName("Box Component"));
	RootComponent = BoxComponent_HardRef;
	BoxComponent_HardRef->SetBoxExtent(FVector(100.f, 100.f, 100.f));

	BoxComponent = BoxComponent_HardRef;
	//BoxComponent->SetCollisionResponseToChannel(ECC_Camera, ECollisionResponse::ECR_Overlap);
	//BoxComponent->SetCollisionResponseToChannel(ECC_Visibility, ECollisionResponse::ECR_Block);

	AbilityToGrant = UCountess_GameplayAbility_Jump::StaticClass();
}


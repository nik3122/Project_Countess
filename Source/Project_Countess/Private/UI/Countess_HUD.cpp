// Free to play. By SoNa Games.


#include "UI/Countess_HUD.h"
#include "UI/Countess_HUD_Widget.h"
#include "UI/Countess_Notify_Widget.h"
#include "UI/Countess_SkillAcquired_Widget.h"
#include "UI/Countess_BMagic_Menu_Widget.h"
#include "UI/Countess_WMagic_Menu_Widget.h"
#include "UI/Inventory/Countess_Inventory_Container.h"

ACountess_HUD::ACountess_HUD()
{
	static ConstructorHelpers::FClassFinder<UCountess_HUD_Widget> Countess_HUD_Widget_Class_Getter(TEXT("/Game/MyProjectMain/Widgets/BP_Countess_HUD_Widget"));
	if (Countess_HUD_Widget_Class_Getter.Succeeded())
	{
		Countess_HUD_Widget_Class = Countess_HUD_Widget_Class_Getter.Class;
		//UE_LOG(LogTemp, Warning, TEXT("HUD Widget Class is %s"), *Countess_HUD_Widget_Class->GetName());
	}

	static ConstructorHelpers::FClassFinder<UCountess_Notify_Widget> Countess_Notify_Widget_Class_Getter(TEXT("/Game/MyProjectMain/Widgets/BP_Countess_Notify_Widget"));
	if (Countess_Notify_Widget_Class_Getter.Succeeded())
	{
		Countess_Notify_Widget_Class = Countess_Notify_Widget_Class_Getter.Class;
	}
	
	static ConstructorHelpers::FClassFinder<UCountess_SkillAcquired_Widget> Countess_SkillAcquired_Widget_Class_Getter(TEXT("/Game/MyProjectMain/Widgets/BP_Countess_Skill_Acquired_Widget"));
	if (Countess_SkillAcquired_Widget_Class_Getter.Succeeded())
	{
		Countess_SkillAcquired_Widget_Class = Countess_SkillAcquired_Widget_Class_Getter.Class;
	}

	static ConstructorHelpers::FClassFinder<UCountess_BMagic_Menu_Widget> Countess_BMagicMenu_Widget_Class_Getter(TEXT("'/Game/MyProjectMain/Widgets/BP_Countess_BMagicMenu_Widget'"));
	if(Countess_BMagicMenu_Widget_Class_Getter.Succeeded())
	{
		Countess_BMagic_Menu_Widget_Class = Countess_BMagicMenu_Widget_Class_Getter.Class;
	}

	static ConstructorHelpers::FClassFinder<UCountess_WMagic_Menu_Widget> Countess_WMagicMenu_Widget_Class_Getter(TEXT("'/Game/MyProjectMain/Widgets/BP_Countess_WMagicMenu_Widget'"));
	if(Countess_WMagicMenu_Widget_Class_Getter.Succeeded())
	{
		Countess_WMagic_Menu_Widget_Class = Countess_WMagicMenu_Widget_Class_Getter.Class;
	}

	static ConstructorHelpers::FClassFinder<UCountess_Inventory_Container> Countess_Inventory_Container_Getter(TEXT("'/Game/MyProjectMain/Widgets/Inventory/WBP_Inventory'"));
	if(Countess_Inventory_Container_Getter.Succeeded())
	{
		Countess_Inventory_Container_Widget_Class = Countess_Inventory_Container_Getter.Class;
	}
}

void ACountess_HUD::BeginPlay()
{
	Super::BeginPlay();
}

void ACountess_HUD::CreateWidgets(class APlayerController* PlayerController, ESlateVisibility Visibility)
{
	if (HUD_Widget)
		return;

	HUD_Widget = CreateWidget<UCountess_HUD_Widget>(PlayerController, Countess_HUD_Widget_Class);
	HUD_Widget->AddToViewport();
	HUD_Widget->SetVisibility(Visibility);
	HUD_Widget->InventoryDropDetected.AddDynamic(this, &ACountess_HUD::InventorySlotDropDetected);
}

bool ACountess_HUD::CreateNotifyWidget(APlayerController* PlayerController, ESlateVisibility Visibility /*= ESlateVisibility::Visible*/)
{
	if (Notify_Widget)
		return true;
	Notify_Widget = CreateWidget<UCountess_Notify_Widget>(PlayerController, Countess_Notify_Widget_Class);
	if (Notify_Widget)
		return true;

	return false;
}

bool ACountess_HUD::CreateSkillAcquiredWidget(APlayerController* PlayerController, ESlateVisibility Visibility /*= ESlateVisibility::Visible*/)
{
	if (Skill_Acquired_Widget)
		return true;
	Skill_Acquired_Widget = CreateWidget<UCountess_SkillAcquired_Widget>(PlayerController, Countess_SkillAcquired_Widget_Class);
	if (Skill_Acquired_Widget)
		return true;

	return false;
}

bool ACountess_HUD::CreateBMagicMenuWidget(APlayerController* PlayerController, ESlateVisibility Visibility)
{
	if(BMagic_Menu_Widget)
		return true;
	BMagic_Menu_Widget = CreateWidget<UCountess_BMagic_Menu_Widget>(PlayerController, Countess_BMagic_Menu_Widget_Class);
	if(BMagic_Menu_Widget)
		return true;

	return false;
}

bool ACountess_HUD::CreateWMagicMenuWidget(APlayerController* PlayerController, ESlateVisibility Visibility)
{
	if(WMagic_Menu_Widget)
		return true;
	WMagic_Menu_Widget = CreateWidget<UCountess_WMagic_Menu_Widget>(PlayerController, Countess_WMagic_Menu_Widget_Class);
	if(WMagic_Menu_Widget)
		return true;

	return false;
}

/*Inventory related*/
bool ACountess_HUD::CreateInventoryContainerWidget(APlayerController* PlayerController, ESlateVisibility Visibility)
{
	if(Inventory_Container)
		return true;
	Inventory_Container = CreateWidget<UCountess_Inventory_Container>(PlayerController, Countess_Inventory_Container_Widget_Class);
	if(Inventory_Container)
		return true;

	return false;
}

void ACountess_HUD::InventorySlotDropDetected(const int32 SlotIndex)
{
	Inventory_Container->ShowDropMenu(SlotIndex);
}


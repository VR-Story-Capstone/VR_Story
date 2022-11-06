// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "USentence_Hud2.h"
#include "USentence_Hud3.h"
#include "USentence_Hud4.h"

AMyGameModeBase::AMyGameModeBase()
	:Super()
{
	word_num = 0;
	static ConstructorHelpers::FClassFinder<UUSentence_Hud2> UI_HUD_2(TEXT("WidgetBlueprint'/Game/Widget/2WordsSentence_HUD.2WordsSentence_HUD_C'"));
	if (UI_HUD_2.Succeeded())
	{
		HUD_Class2 = UI_HUD_2.Class;
	}

	static ConstructorHelpers::FClassFinder<UUSentence_Hud3> UI_HUD_3(TEXT("WidgetBlueprint'/Game/Widget/3WordsSentence_HUD.3WordsSentence_HUD_C'"));
	if (UI_HUD_3.Succeeded())
	{
		HUD_Class3 = UI_HUD_3.Class;
	}

	static ConstructorHelpers::FClassFinder<UUSentence_Hud4> UI_HUD_4(TEXT("WidgetBlueprint'/Game/Widget/4WordsSentence_HUD.4WordsSentence_HUD_C'"));
	if (UI_HUD_4.Succeeded())
	{
		HUD_Class4 = UI_HUD_4.Class;
	}

	static ConstructorHelpers::FClassFinder<APawn> Hud2_Pawn(TEXT("Blueprint'/Game/VRTemplate/Blueprints/VRPawn_For_Two.VRPawn_For_Two_C'"));
	if (Hud2_Pawn.Succeeded())
	{
		Hud2_Pawn_Class = Hud2_Pawn.Class;
	}

	static ConstructorHelpers::FClassFinder<APawn> Hud3_Pawn(TEXT("Blueprint'/Game/VRTemplate/Blueprints/VRPawn_For_Three.VRPawn_For_Three_C'"));
	if (Hud3_Pawn.Succeeded())
	{
		Hud3_Pawn_Class = Hud3_Pawn.Class;
	}

	static ConstructorHelpers::FClassFinder<APawn> Hud4_Pawn(TEXT("Blueprint'/Game/VRTemplate/Blueprints/VRPawn_For_Four.VRPawn_For_Four_C'"));
	if (Hud4_Pawn.Succeeded())
	{
		Hud4_Pawn_Class = Hud4_Pawn.Class;
	}
}

int AMyGameModeBase::SetWordNum(int n)
{
	
	if (n == 2) //2단어 hud를 보여줌
	{
		word_num = 2;
		DefaultPawnClass = Hud2_Pawn_Class;
		UE_LOG(LogTemp, Warning, TEXT("SetWordNum load success######"));
	}
	else if (n == 3) //3단어 hud를 보여줌
	{
		word_num = 3;

		CurrentHud = CreateWidget(GetWorld(), HUD_Class3);
		if (CurrentHud)
		{
			CurrentHud->AddToViewport();
		}
	}
	else if (n == 4) //4단어 hud를 보여줌
	{
		word_num = 4;

		CurrentHud = CreateWidget(GetWorld(), HUD_Class4);
		if (CurrentHud)
		{
			CurrentHud->AddToViewport();
		}
	}
	else
	{
		word_num = 0;
		return -1;
	}
	return n;
}

int AMyGameModeBase::GetWordNum()
{
	return word_num;
}

void AMyGameModeBase::RemoveHud()
{
	HUD_Class2 = NULL; HUD_Class3 = NULL; HUD_Class4 = NULL;
	if (CurrentHud)
	{
		CurrentHud->RemoveFromViewport();
		CurrentHud = NULL;
	}
	SetWordNum(0);
}

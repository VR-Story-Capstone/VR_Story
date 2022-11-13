// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class VRSTORY_API AMyGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
	public:
		AMyGameModeBase();
	private:
		int word_num = 0; //선택된 문장형식의 단어 갯수. 0은 아무것도 아닌상태
	public:
		int SetWordNum(int n); //선택된 단어갯수를 저장하고, 해당하는 HUD를 화면에 띄워줌.(폰을 교체하는 방식으로 이루어짐) 
		int GetWordNum(); 
		void RemoveHud(); //HUD를 지워줌과 동시에 필요한 초기화를 진행.

		/*UPROPERTY()
		TSubclassOf<UUserWidget> HUD_Class2;

		UPROPERTY()
		TSubclassOf<UUserWidget> HUD_Class3;

		UPROPERTY()
		TSubclassOf<UUserWidget> HUD_Class4;*/

		UPROPERTY()
		TSubclassOf<APawn> Main_Pawn_Class;
	
		UPROPERTY()
		TSubclassOf<APawn> Hud2_Pawn_Class;

		UPROPERTY()
		TSubclassOf<APawn> Hud3_Pawn_Class;

		UPROPERTY()
		TSubclassOf<APawn> Hud4_Pawn_Class;

		UPROPERTY()
		APawn* Current_Pawn_Class; //항상 지금 빙의하고있는 폰을 reference 하고있음 (destroy등 하려면 UGameplayStatics::GetAllActorsOfClass사용)

		UPROPERTY()
		APlayerController* controller;
};

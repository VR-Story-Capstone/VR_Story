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
		int word_num = 0; //���õ� ���������� �ܾ� ����. 0�� �ƹ��͵� �ƴѻ���
	public:
		int SetWordNum(int n); //���õ� �ܾ���� �����ϰ�, �ش��ϴ� HUD�� ȭ�鿡 �����.
		int GetWordNum(); 
		void RemoveHud(); //HUD�� �����ܰ� ���ÿ� �ʿ��� �ʱ�ȭ�� ����.

		UPROPERTY()
		TSubclassOf<UUserWidget> HUD_Class2;

		UPROPERTY()
		TSubclassOf<UUserWidget> HUD_Class3;

		UPROPERTY()
		TSubclassOf<UUserWidget> HUD_Class4;

		UPROPERTY()
		TSubclassOf<APawn> Hud2_Pawn_Class;

		UPROPERTY()
		TSubclassOf<APawn> Hud3_Pawn_Class;

		UPROPERTY()
		TSubclassOf<APawn> Hud4_Pawn_Class;

		UPROPERTY()
		UUserWidget* CurrentHud;
};

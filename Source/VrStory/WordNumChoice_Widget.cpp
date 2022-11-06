// Fill out your copyright notice in the Description page of Project Settings.


#include "WordNumChoice_Widget.h"
#include "UMG/Public/Components/Button.h"
#include "MyGameModeBase.h"
#include "Kismet/GameplayStatics.h"

void UWordNumChoice_Widget::NativeConstruct()
{
	Super::NativeConstruct();

	TwoWords->OnClicked.AddDynamic(this,&UWordNumChoice_Widget::Create_TwoWords);
	ThreeWords->OnClicked.AddDynamic(this, &UWordNumChoice_Widget::Create_ThreeWords);
	FourWords->OnClicked.AddDynamic(this, &UWordNumChoice_Widget::Create_FourWords);
}

void UWordNumChoice_Widget::Create_TwoWords()
{
	UE_LOG(LogTemp, Warning, TEXT("two word click success!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"));
	AMyGameModeBase* GameMode=Cast<AMyGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	if (GameMode)
	{
		UE_LOG(LogTemp, Warning, TEXT("Gamemode loading success@@@@@@@@@@@"));
		GameMode->SetWordNum(2); //2�ܾ�� �̷���� HUD�����
	}
}

void UWordNumChoice_Widget::Create_ThreeWords()
{
	AMyGameModeBase* GameMode = Cast<AMyGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	if (GameMode)
	{
		//GameMode->SetWordNum(3); //3�ܾ�� �̷���� HUD�����
	}
}

void UWordNumChoice_Widget::Create_FourWords()
{
	AMyGameModeBase* GameMode = Cast<AMyGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	if (GameMode)
	{
		//GameMode->SetWordNum(4); //4�ܾ�� �̷���� HUD�����
	}
}

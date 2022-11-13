// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "USentence_Hud2.h"
#include "USentence_Hud3.h"
#include "USentence_Hud4.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

AMyGameModeBase::AMyGameModeBase()
	:Super()
{
	word_num = 0;
	/*static ConstructorHelpers::FClassFinder<UUSentence_Hud2> UI_HUD_2(TEXT("WidgetBlueprint'/Game/Widget/2WordsSentence_HUD.2WordsSentence_HUD_C'"));
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
	}*/
	
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
	Current_Pawn_Class= UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	controller=UGameplayStatics::GetPlayerController(GetWorld(),0);
	if (n == 2) //2단어 hud를 보여줌
	{
		word_num = 2;
		FVector SpawnVector;
		FRotator SpawnRotator;
		UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPlayerViewPoint(SpawnVector,SpawnRotator); //현재 플레이어의 위치,회전값 얻기
		controller->UnPossess();//현재 빙의중인 폰 해제
		const FActorSpawnParameters SpawnInfo;
		APawn * NewPawn= GetWorld()->SpawnActor<APawn>(Hud2_Pawn_Class,SpawnVector,SpawnRotator,SpawnInfo); // hud가 있는 새 pawn 스폰(현재 플레이어 위치에)
		controller->Possess(NewPawn); //HUD가 있는 폰으로 변경
		
		if(controller->GetPawn()) //폰을 성공적으로 변경했다면
		{
			UE_LOG(LogTemp, Warning, TEXT("------------------Changing Pawn OK-------------------"));
			AActor* OldActor=Current_Pawn_Class;
			if(GetWorld()->DestroyActor(OldActor))//변경 전 폰을 게임에서 없앰
			{
				UE_LOG(LogTemp, Warning, TEXT("------------------Destroy Access OK-------------------"));
				Current_Pawn_Class=UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
			}
		}
		else //폰 변경 실패
		{
			UE_LOG(LogTemp, Warning, TEXT("------------------Changing Pawn EROOR-------------------"));
		}
	}
	else if (n == 3) //3단어 hud를 보여줌
	{
		word_num = 3;

		FVector SpawnVector;
		FRotator SpawnRotator;
		UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPlayerViewPoint(SpawnVector,SpawnRotator); //현재 플레이어의 위치,회전값 얻기
		controller->UnPossess();//현재 빙의중인 폰 해제
		const FActorSpawnParameters SpawnInfo;
		APawn * NewPawn= GetWorld()->SpawnActor<APawn>(Hud3_Pawn_Class,SpawnVector,SpawnRotator,SpawnInfo); // hud가 있는 새 pawn 스폰(현재 플레이어 위치에)
		controller->Possess(NewPawn); //HUD가 있는 폰으로 변경
		
		if(controller->GetPawn()) //폰을 성공적으로 변경했다면
			{
			UE_LOG(LogTemp, Warning, TEXT("------------------Changing Pawn OK-------------------"));
			AActor* OldActor=Current_Pawn_Class;
			if(GetWorld()->DestroyActor(OldActor))//변경 전 폰을 게임에서 없앰
				{
				UE_LOG(LogTemp, Warning, TEXT("------------------Destroy Access OK-------------------"));
				Current_Pawn_Class=UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
				}
			}
		else //폰 변경 실패
			{
			UE_LOG(LogTemp, Warning, TEXT("------------------Changing Pawn EROOR-------------------"));
			}
	}
	else if (n == 4) //4단어 hud를 보여줌
	{
		word_num = 4;

		FVector SpawnVector;
		FRotator SpawnRotator;
		UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPlayerViewPoint(SpawnVector,SpawnRotator); //현재 플레이어의 위치,회전값 얻기
		controller->UnPossess();//현재 빙의중인 폰 해제
		const FActorSpawnParameters SpawnInfo;
		APawn * NewPawn= GetWorld()->SpawnActor<APawn>(Hud4_Pawn_Class,SpawnVector,SpawnRotator,SpawnInfo); // hud가 있는 새 pawn 스폰(현재 플레이어 위치에)
		controller->Possess(NewPawn); //HUD가 있는 폰으로 변경
		
		if(controller->GetPawn()) //폰을 성공적으로 변경했다면
			{
			UE_LOG(LogTemp, Warning, TEXT("------------------Changing Pawn OK-------------------"));
			AActor* OldActor=Current_Pawn_Class;
			if(GetWorld()->DestroyActor(OldActor))//변경 전 폰을 게임에서 없앰
				{
				UE_LOG(LogTemp, Warning, TEXT("------------------Destroy Access OK-------------------"));
				Current_Pawn_Class=UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
				}
			}
		else //폰 변경 실패
			{
			UE_LOG(LogTemp, Warning, TEXT("------------------Changing Pawn EROOR-------------------"));
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
	/*HUD_Class2 = NULL; HUD_Class3 = NULL; HUD_Class4 = NULL;
	if (CurrentHud)
	{
		CurrentHud->RemoveFromViewport();
		CurrentHud = NULL;
	}
	SetWordNum(0);*/
}

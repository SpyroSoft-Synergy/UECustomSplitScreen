// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomGameViewportClient.h"

UCustomGameViewportClient::UCustomGameViewportClient()
     : Super(FObjectInitializer::Get())
{
     // Resize SplitscreenInfo to fit our custom config
     SplitscreenInfo.SetNum(ECustomSplitScreenType::SplitTypeCount, false);

     // Fill the custom config
     SplitscreenInfo[ECustomSplitScreenType::ThreePlayer].PlayerData.Add(FPerPlayerSplitscreenData(0.33f, 1.00f, 0.66f, 0.00f)); //1
     SplitscreenInfo[ECustomSplitScreenType::ThreePlayer].PlayerData.Add(FPerPlayerSplitscreenData(0.66f, 0.50f, 0.00f, 0.00f)); //2
     SplitscreenInfo[ECustomSplitScreenType::ThreePlayer].PlayerData.Add(FPerPlayerSplitscreenData(0.66f, 0.50f, 0.00f, 0.50f)); //3
}

void UCustomGameViewportClient::UpdateActiveSplitscreenType()
{
     ECustomSplitScreenType::Type SplitType = ECustomSplitScreenType::None;
     const int32 NumPlayers = GEngine->GetNumGamePlayers(GetWorld());

     if (NumPlayers == 3)
     {
         // If Player count is equal 3, select custom Splitscreen
         ActiveSplitscreenType = static_cast<ESplitScreenType::Type>(ECustomSplitScreenType::ThreePlayer);
     }
     else
     {
         // Otherwise fallback to default behaviour
         Super::UpdateActiveSplitscreenType();
     }
}
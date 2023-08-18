// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameViewportClient.h"
#include "Engine/ViewportSplitScreen.h"
#include "CustomGameViewportClient.generated.h"


UENUM(BlueprintType)
namespace ECustomSplitScreenType
{
     enum Type
     {
          // 0 value required by UE
          None,
          // Custom Splitscreen, next value after last built-in splitscreen type
          ThreePlayer = ESplitScreenType::SplitTypeCount,
          SplitTypeCount
     };
}

/**
 * 
 */
UCLASS()
class CUSTOMSPLITSCREEN_API UCustomGameViewportClient : public UGameViewportClient
{
     GENERATED_BODY()

public:
     UCustomGameViewportClient();

     virtual void UpdateActiveSplitscreenType() override;
     
};

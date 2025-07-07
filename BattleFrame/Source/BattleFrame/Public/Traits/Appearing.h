#pragma once
 
#include "CoreMinimal.h"
#include "Appearing.generated.h"
 
/**
 * The state of appearing in game.
 */
USTRUCT(BlueprintType)
struct BATTLEFRAME_API FAppearing
{
	GENERATED_BODY()
 
  public:

	  bool bInitialized = false;
	  bool bStarted = false;
	  float Time = 0.0f;
	  float AnimTime = 0.0f;
	  float DissolveTime = 0.f;

};

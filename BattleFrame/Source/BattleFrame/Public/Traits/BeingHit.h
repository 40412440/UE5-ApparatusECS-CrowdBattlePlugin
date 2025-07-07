#pragma once

#include "CoreMinimal.h"
#include "BeingHit.generated.h"

USTRUCT(BlueprintType)
struct BATTLEFRAME_API FBeingHit
{
	GENERATED_BODY()

public:

	//float AnimTime = 0.0f;
	float GlowTime = 0.0f;
	float JiggleTime = 0.0f;

	//FORCEINLINE void ResetAnim()
	//{
	//	AnimTime = 0;
	//}

	FORCEINLINE void ResetGlow()
	{
		GlowTime = 0.0f;
	}

	FORCEINLINE void ResetJiggle()
	{
		JiggleTime = 0.0f;
	}
};

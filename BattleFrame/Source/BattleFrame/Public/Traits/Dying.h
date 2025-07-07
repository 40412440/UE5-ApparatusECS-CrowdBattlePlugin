#pragma once
 
#include "CoreMinimal.h"
#include "SubjectHandle.h"
#include "Dying.generated.h"
 
USTRUCT(BlueprintType)
struct BATTLEFRAME_API FDying
{
	GENERATED_BODY()
 
  public:

	bool bInitialized = false;

	float Duration = 0.0f;

	float Time = 0.0f;

	float DeathDissolveTime = 0.0f;

	float DeathAnimTime = 0.0f;

	FSubjectHandle Instigator = FSubjectHandle();

	FVector HitDirection = FVector::ZeroVector;

};

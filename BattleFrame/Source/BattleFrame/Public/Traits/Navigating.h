#pragma once

#include "CoreMinimal.h"
#include "FlowField.h"
#include "Navigating.generated.h"

USTRUCT(BlueprintType)
struct BATTLEFRAME_API FNavigating
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FVector> PathPoints;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float TimeLeft = 0;
		
	AFlowField* FlowField = nullptr;

	bool AStarArrived = false;

};

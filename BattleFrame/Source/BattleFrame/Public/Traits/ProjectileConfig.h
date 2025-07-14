#pragma once

#include "CoreMinimal.h"
#include "SubjectHandle.h"
#include "ProjectileConfig.generated.h" 

USTRUCT(BlueprintType)
struct BATTLEFRAME_API FProjectileConfig_Ballistic
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = ""))
	FVector FromPoint = FVector::ZeroVector;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = ""))
	FVector ToPoint = FVector::ZeroVector;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = ""))
	FVector InitialVelocity = FVector::ZeroVector;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = ""))
	float MaxSpeed = 10000;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = ""))
	float TimeOfBirth = 0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = ""))
	float LifeSpan = 3;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = ""))
	float Gravity = -980;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = ""))
	bool bTraceTarget = true;

	UPROPERTY(BlueprintReadWrite,EditAnywhere,meta = (Tooltip = ""))
	FFilter TargetFilter;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = ""))
	bool bTraceObstacle = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ToolTip = ""))
	TArray<TEnumAsByte<EObjectTypeQuery>> ObstacleChannel;

};

USTRUCT(BlueprintType)
struct BATTLEFRAME_API FProjectileConfig_Tracking
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = ""))
	FVector FromPoint = FVector::ZeroVector;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = ""))
	FSubjectHandle TargetToTrack = FSubjectHandle();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = ""))
	FVector InitialVelocity = FVector::ZeroVector;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = ""))
	FVector Acceleration = FVector::ZeroVector;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = ""))
	float MaxSpeed = 10000;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = ""))
	float TimeOfBirth = 0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = ""))
	float LifeSpan = 3;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = ""))
	bool bTraceTarget = true;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = ""))
	FFilter TargetFilter;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = ""))
	bool bTraceObstacle = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ToolTip = ""))
	TArray<TEnumAsByte<EObjectTypeQuery>> ObstacleChannel;

};

//USTRUCT(BlueprintType)
//struct BATTLEFRAME_API FProjectileConfig_StaticSpherical
//{
//	GENERATED_BODY()
//
//public:
//
//	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = ""))
//	FVector FromPoint = FVector::ZeroVector;
//
//	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = ""))
//	FVector ToPoint = FVector::ZeroVector;
//
//	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = ""))
//	float LifeSpan = 3;
//
//	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = ""))
//	bool bTraceTarget = true;
//
//	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = ""))
//	FFilter TargetFilter;
//
//};
//
//USTRUCT(BlueprintType)
//struct BATTLEFRAME_API FProjectileConfig_StaticBeam
//{
//	GENERATED_BODY()
//
//public:
//
//	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = ""))
//	FVector FromPoint = FVector::ZeroVector;
//
//	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = ""))
//	FVector ToPoint = FVector::ZeroVector;
//
//	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = ""))
//	float LifeSpan = 3;
//
//	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = ""))
//	bool bTraceTarget = true;
//
//	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = ""))
//	FFilter TargetFilter;
//
//};
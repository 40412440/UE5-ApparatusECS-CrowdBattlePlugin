#pragma once
 
#include "CoreMinimal.h"
#include "AnimToTextureDataAsset.h"
#include "Animation.generated.h"
 

class ANiagaraSubjectRenderer;

USTRUCT(BlueprintType)
struct BATTLEFRAME_API FAnimation
{
	GENERATED_BODY()

    //-----------------------------------------------------------

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TSoftObjectPtr <UAnimToTextureDataAsset> AnimToTextureDataAsset;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TSoftClassPtr<ANiagaraSubjectRenderer> RendererClass;

    //-------------------------------------------------------------

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = "动画过渡速度"))
    float LerpSpeed = 4;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = "待机动画随机时间偏移"))
    FVector2D IdleRandomTimeOffset = FVector2D(0, 0);

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = "移动动画随机时间偏移"))
    FVector2D MoveRandomTimeOffset = FVector2D(0, 0);

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = "使用待机动画的移速，使用移动动画的移速", DisplayName = "BlendSpace_Idle-Move"))
    FVector2D BS_IdleMove = FVector2D(0, 300);

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = "待机动画播放速度"))
    float IdlePlayRate = 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = "移动动画播放速度"))
    float MovePlayRate = 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = "跳跃动画的索引值,AnimToTextureDataAsset里可查到"))
    int32 IndexOfIdleAnim = 0;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = "跳跃动画的索引值,AnimToTextureDataAsset里可查到"))
    int32 IndexOfMoveAnim = 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = "出生动画的索引值,AnimToTextureDataAsset里可查到"))
    int32 IndexOfAppearAnim = 2;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = "攻击动画的索引值,AnimToTextureDataAsset里可查到"))
    int32 IndexOfAttackAnim = 3;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = "死亡动画的索引值,AnimToTextureDataAsset里可查到"))
    int32 IndexOfDeathAnim = 4;

    //UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = "坠落动画的索引值"))
    //int32 IndexOfFallAnim = 6;

    //UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = "受击动画的索引值"))
    //int32 IndexOfHitAnim = 4;

    //UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = "跳跃动画的索引值"))
    //int32 IndexOfJumpAnim = 7;

};

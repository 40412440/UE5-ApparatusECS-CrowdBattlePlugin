#pragma once

#include "CoreMinimal.h"
#include "AnimToTextureDataAsset.h"
#include "BattleFrameEnums.h"
#include "Animating.generated.h"


USTRUCT(BlueprintType)
struct BATTLEFRAME_API FAnimating
{
    GENERATED_BODY()

private:

    mutable std::atomic<bool> LockFlag{ false };

public:

    void Lock() const
    {
        while (LockFlag.exchange(true, std::memory_order_acquire));
    }

    void Unlock() const
    {
        LockFlag.store(false, std::memory_order_release);
    }

    //-----------------------------------------------------------

    TObjectPtr<UAnimToTextureDataAsset> AnimToTextureData = nullptr;

    //-----------------------------------------------------------

    float AnimIndex0 = 0;
    float AnimPlayRate0 = 0.f;
    float AnimCurrentTime0 = 0.f;
    float AnimOffsetTime0 = 0.f;
    float AnimPauseFrame0 = 0.f;

    float AnimIndex1 = 0;
    float AnimPlayRate1 = 0.f;
    float AnimCurrentTime1 = 0.f;
    float AnimOffsetTime1 = 0.f;
    float AnimPauseFrame1 = 0.f;

    float AnimIndex2 = 0;
    float AnimPlayRate2 = 0.f;
    float AnimCurrentTime2 = 0.f;
    float AnimOffsetTime2 = 0.f;
    float AnimPauseFrame2 = 0.f;

    float AnimLerp0 = 0;
    float AnimLerp1 = 0;

    int32 CurrentMontageSlot = 2;
    int32 SampleRate = 30;

    //-----------------------------------------------------------

    TArray<int32> AnimPauseFrameArray;

    //-----------------------------------------------------------

    float Team = 0;// wip

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = ""))
    float HitGlow = 0;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = ""))
    float Dissolve = 0;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = ""))
    float IceFx = 0;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = ""))
    float FireFx = 0;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = ""))
    float PoisonFx = 0;

    float IceFxInterped = 0;
    float FireFxInterped = 0;
    float PoisonFxInterped = 0;


    //-----------------------------------------------------------

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = ""))
    EAnimState AnimState = EAnimState::BS_IdleMove;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = ""))
    EAnimState PreviousAnimState = EAnimState::Dirty;

    //-----------------------------------------------------------

    FAnimating() {};

    FAnimating(const FAnimating& Anim)
    {
        LockFlag.store(Anim.LockFlag.load());

        AnimToTextureData = Anim.AnimToTextureData;

        Team = Anim.Team;
        HitGlow = Anim.HitGlow;
        Dissolve = Anim.Dissolve;

        IceFx = Anim.IceFx;
        FireFx = Anim.FireFx;
        PoisonFx = Anim.PoisonFx;

        IceFxInterped = Anim.IceFxInterped;
        FireFxInterped = Anim.FireFxInterped;
        PoisonFxInterped = Anim.PoisonFxInterped;

        AnimIndex0 = Anim.AnimIndex0;
        AnimPlayRate0 = Anim.AnimPlayRate0;
        AnimCurrentTime0 = Anim.AnimCurrentTime0;
        AnimOffsetTime0 = Anim.AnimOffsetTime0;
        AnimPauseFrame0 = Anim.AnimPauseFrame0;

        AnimIndex1 = Anim.AnimIndex1;
        AnimPlayRate1 = Anim.AnimPlayRate1;
        AnimCurrentTime1 = Anim.AnimCurrentTime1;
        AnimOffsetTime1 = Anim.AnimOffsetTime1;
        AnimPauseFrame1 = Anim.AnimPauseFrame1;

        AnimIndex2 = Anim.AnimIndex2;
        AnimPlayRate2 = Anim.AnimPlayRate2;
        AnimCurrentTime2 = Anim.AnimCurrentTime2;
        AnimOffsetTime2 = Anim.AnimOffsetTime2;
        AnimPauseFrame2 = Anim.AnimPauseFrame2;

        AnimLerp0 = Anim.AnimLerp0;
        AnimLerp1 = Anim.AnimLerp1;

        CurrentMontageSlot = Anim.CurrentMontageSlot;
        SampleRate = Anim.SampleRate;

        AnimPauseFrameArray = Anim.AnimPauseFrameArray;

        AnimState = Anim.AnimState;
        PreviousAnimState = Anim.PreviousAnimState;
    }

    FAnimating& operator=(const FAnimating& Anim)
    {
        LockFlag.store(Anim.LockFlag.load());

        AnimToTextureData = Anim.AnimToTextureData;

        Team = Anim.Team;
        HitGlow = Anim.HitGlow;
        Dissolve = Anim.Dissolve;

        IceFx = Anim.IceFx;
        FireFx = Anim.FireFx;
        PoisonFx = Anim.PoisonFx;

        IceFxInterped = Anim.IceFxInterped;
        FireFxInterped = Anim.FireFxInterped;
        PoisonFxInterped = Anim.PoisonFxInterped;

        AnimIndex0 = Anim.AnimIndex0;
        AnimPlayRate0 = Anim.AnimPlayRate0;
        AnimCurrentTime0 = Anim.AnimCurrentTime0;
        AnimOffsetTime0 = Anim.AnimOffsetTime0;
        AnimPauseFrame0 = Anim.AnimPauseFrame0;

        AnimIndex1 = Anim.AnimIndex1;
        AnimPlayRate1 = Anim.AnimPlayRate1;
        AnimCurrentTime1 = Anim.AnimCurrentTime1;
        AnimOffsetTime1 = Anim.AnimOffsetTime1;
        AnimPauseFrame1 = Anim.AnimPauseFrame1;

        AnimIndex2 = Anim.AnimIndex2;
        AnimPlayRate2 = Anim.AnimPlayRate2;
        AnimCurrentTime2 = Anim.AnimCurrentTime2;
        AnimOffsetTime2 = Anim.AnimOffsetTime2;
        AnimPauseFrame2 = Anim.AnimPauseFrame2;

        AnimLerp0 = Anim.AnimLerp0;
        AnimLerp1 = Anim.AnimLerp1;

        CurrentMontageSlot = Anim.CurrentMontageSlot;
        SampleRate = Anim.SampleRate;

        AnimPauseFrameArray = Anim.AnimPauseFrameArray;

        AnimState = Anim.AnimState;
        PreviousAnimState = Anim.PreviousAnimState;

        return *this;
    }
};

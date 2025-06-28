#pragma once

#include "CoreMinimal.h"
#include "Move.generated.h"


UENUM(BlueprintType)
enum class EOrientMode : uint8
{
	ToPath UMETA(DisplayName = "ToPath"),
	ToMovement UMETA(DisplayName = "ToMovement"),
	ToMovementForwardAndBackward UMETA(DisplayName = "ToMovementForwardAndBackward")
};

UENUM(BlueprintType)
enum class EGroundTraceMode : uint8
{
	FlowFieldAndSphereTrace	UMETA(DisplayName = "FlowFieldAndSphereTrace", Tooltip = "仅在地形边缘使用球形检测, 推荐"),
	FlowField				UMETA(DisplayName = "FlowField", Tooltip = "使用流场采样高度，悬崖边缘可能不够精确"),
	SphereTrace				UMETA(DisplayName = "SphereTrace", Tooltip = "使用球形扫描检测，很精确但非常贵")
};


USTRUCT(BlueprintType)
struct BATTLEFRAME_API FYawMovement
{
	GENERATED_BODY()

public:

	//---------------Yaw Movement-----------------//

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ClampMin = "0", Tooltip = "转向角速度"))
	float TurnSpeed = 1000;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ClampMin = "0", Tooltip = "转向角加速度"))
	float TurnAcceleration = 1000;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ClampMin = "0", Tooltip = "转向角加速度"))
	EOrientMode TurnMode = EOrientMode::ToMovementForwardAndBackward;

};

USTRUCT(BlueprintType)
struct BATTLEFRAME_API FXYMovement
{
	GENERATED_BODY()

public:

	//---------------XY Movement-----------------//

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ClampMin = "0", Tooltip = "移动速度"))
	float MoveSpeed = 600.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ClampMin = "0", Tooltip = "移动加速度"))
	float MoveAcceleration = 3000.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ClampMin = "0", Tooltip = "刹车减速度"))
	float MoveDeceleration = 3000.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = "速度映射 (X: 与移动方向的夹角, Y: 对应的速度乘数, Z:与移动方向的夹角, W:对应的速度乘数)"))
	FVector4 MoveSpeedRangeMapByAngle = FVector4(0, 1, 180, 1);

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = "速度映射 (X: 与目标点的距离, Y: 对应的速度乘数, Z:与目标点的距离, W:对应的速度乘数)"))
	FVector4 MoveSpeedRangeMapByDist = FVector4(100, 1, 1000, 1);

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ClampMin = "0", Tooltip = "每次地面弹跳移动速度衰减"))
	FVector2D MoveBounceVelocityDecay = FVector2D(0.5f, 0.f);

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = "与移动目标点距离低于该值时停止移动"))
	float AcceptanceRadius = 100.f;

};

USTRUCT(BlueprintType)
struct BATTLEFRAME_API FZMovement
{
	GENERATED_BODY()

public:
	// 添加构造函数
	FZMovement()
	{
		// 默认添加WorldStatic到GroundObjectType
		GroundObjectType.Add(UEngineTypes::ConvertToObjectType(ECC_WorldStatic));
	}

	//---------------Z Movement-----------------//

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = "是否可以飞行"))
	bool bCanFly = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = "随机飞行高度，出生后固定 (X: 最小高度, Y: 最大高度)"))
	FVector2D FlyHeightRange = FVector2D(200.f, 400.f);

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = "重力"))
	float Gravity = -2000.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (Tooltip = "强制死亡高度 (低于此高度时强制移除)"))
	float KillZ = -10000.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (Tooltip = "地面检测模式"))
	EGroundTraceMode GroundTraceMode = EGroundTraceMode::FlowFieldAndSphereTrace;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (Tooltip = "坡度大于这个值，使用球扫检测地面"))
	float SphereTraceAngleThreshold = 45.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ToolTip = "地面碰撞类型"))
	TArray<TEnumAsByte<EObjectTypeQuery>> GroundObjectType;
};



USTRUCT(BlueprintType)
struct BATTLEFRAME_API FMove
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = "是否启用移动属性"))
	bool bEnable = true;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ToolTip = "绘制Debug图形"))
	bool bDrawDebugShape = false;

	//---------------Yaw Movement-----------------//

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = "转向", DisplayName = "Yaw Movement"))
	FYawMovement Yaw;

	//---------------XY Movement-----------------//

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = "平面运动", DisplayName = "XY Movement"))
	FXYMovement XY;

	//---------------Z Movement-----------------//

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Tooltip = "垂直运动", DisplayName = "Z Movement"))
	FZMovement Z;

};

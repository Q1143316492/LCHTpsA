#pragma once


#include "CoreMinimal.h"
#include "LCHCharacterType.generated.h"


UENUM(BlueprintType)
enum class ECharacterRotationModeType : uint8
{
    OrientToMovement        UMETA(DisplayName = "OrientToMovement"),
    UseControllerRotation   UMETA(DisplayName = "UseControllerRotation"),
    None                    UMETA(DisplayName = "None")
};

UENUM(BlueprintType)
enum class ECharacterGaitType : uint8
{
    Walking     UMETA(DisplayName = "Walking"),
    Running     UMETA(DisplayName = "Running"),
    Sprinting   UMETA(DisplayName = "Sprinting")
};

UENUM(BlueprintType)
enum class ECharacterMovementModeType : uint8
{
    Grounded    UMETA(DisplayName = "Grounded"),
    InAir       UMETA(DisplayName = "InAir"),
};

UENUM(BlueprintType)
enum class ECharacterModementStateType : uint8
{
    Idle       UMETA(DisplayName = "Idle"),
    Moving     UMETA(DisplayName = "Moving"),
    InAir      UMETA(DisplayName = "InAir"),
};

UENUM(BlueprintType)
enum class ECharacterStanceType : uint8
{
    Standing    UMETA(DisplayName = "Standing"),
    Crouching   UMETA(DisplayName = "Crouching"),
};

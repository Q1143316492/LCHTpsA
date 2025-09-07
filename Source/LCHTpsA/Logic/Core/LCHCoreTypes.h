// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

/**
 * A boolean wrapper that can be reset automatically or manually.
 * Commonly used for animation flags that need to be cleared after being processed.
 */
struct FResetBool
{
public:
    FResetBool() : bValue(false) {}
    explicit FResetBool(bool InValue) : bValue(InValue) {}

    // Implicit conversion to bool for easy usage
    operator bool() const { return bValue; }

    // Assignment operators
    FResetBool& operator=(bool InValue)
    {
        bValue = InValue;
        return *this;
    }

    FResetBool& operator=(const FResetBool& Other)
    {
        bValue = Other.bValue;
        return *this;
    }

    // Getters and setters
    bool Get() const { return bValue; }
    void Set(bool InValue) { bValue = InValue; }
    void Reset() { bValue = false; }
    void SetTrue() { bValue = true; }

    // Utility functions
    bool IsSet() const { return bValue; }
    bool IsReset() const { return !bValue; }

    // Reset after returning the current value
    bool GetAndReset()
    {
        bool Result = bValue;
        bValue = false;
        return Result;
    }

private:
    bool bValue;
};

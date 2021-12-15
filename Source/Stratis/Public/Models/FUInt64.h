#pragma once

#include "FUInt64.generated.h"

#define PACKED
#pragma pack(push, 1)

USTRUCT(BlueprintType)
struct STRATIS_API FUInt64 {
    GENERATED_BODY()

    uint64 Value;

    operator uint64() const;
    FUInt64();
    FUInt64(uint64 value);
};

#pragma pack(pop)
#undef PACKED

UCLASS(BlueprintType)
class STRATIS_API UUInt64Factory : public UObject
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "UInt64")
    static FUInt64 UInt64FromString(const FString& value);
};
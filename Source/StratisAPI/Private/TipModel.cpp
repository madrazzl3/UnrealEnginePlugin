// Copyright © 2022 Stratis Platform.
//
// This file is part of Stratis Plugin for Unreal Engine. The full copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

/**
 * Stratis Node API
 * Access to the Stratis Node's api.
 *
 * OpenAPI spec version: 1.0
 * 
 *
 * NOTE: This class is auto generated by OpenAPI Generator
 * https://github.com/OpenAPITools/openapi-generator
 * Do not edit the class manually.
 */

#include "TipModel.h"

#include "StratisAPIModule.h"
#include "Helpers.h"

#include "Templates/SharedPointer.h"

namespace stratis
{
namespace api
{

void TipModel::WriteJson(JsonWriter& Writer) const
{
	Writer->WriteObjectStart();
	if (TipHash.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("tipHash")); WriteJsonValue(Writer, TipHash.GetValue());
	}
	if (TipHeight.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("tipHeight")); WriteJsonValue(Writer, TipHeight.GetValue());
	}
	Writer->WriteObjectEnd();
}

bool TipModel::FromJson(const TSharedPtr<FJsonValue>& JsonValue)
{
	const TSharedPtr<FJsonObject>* Object;
	if (!JsonValue->TryGetObject(Object))
		return false;

	bool ParseSuccess = true;

	ParseSuccess &= TryGetJsonValue(*Object, TEXT("tipHash"), TipHash);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("tipHeight"), TipHeight);

	return ParseSuccess;
}

}
}

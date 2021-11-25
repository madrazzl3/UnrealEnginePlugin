#pragma once

#include "CoreMinimal.h"

#include "RequestContext.h"

#include <functional>

class RequestContextManager
{
public:
    template <typename DelegateType, typename RequestType, typename CallbackFunctorType>
    FString createContext(const RequestType& request, TFunction<FHttpRequestPtr(const RequestType&, DelegateType)> requestMethod, CallbackFunctorType&& callback);

    bool disposeContext(const FString& id);

    RequestContext& getContext(const FString& id);
    const RequestContext& getContext(const FString& id) const;

private:
    FString createUniqueID() const;

    TMap<FString, RequestContext> contextStorage_;
};

template <typename DelegateType, typename RequestType, typename CallbackFunctorType>
inline FString RequestContextManager::createContext(const RequestType& request, TFunction<FHttpRequestPtr(const RequestType&, DelegateType)> requestMethod, CallbackFunctorType&& callback)
{
    FString id(createUniqueID());

    TSharedPtr<ApiDelegate> delegatePtr(MakeShared<ApiDelegate>(TInPlaceType<DelegateType>()));

    auto& delegate = delegatePtr->Get<DelegateType>();
    delegate.BindLambda(
        [this, callback = std::move(callback), contextID = id](const auto& response) {
            callback(response);
            this->disposeContext(contextID);
        });

    contextStorage_.Add(id, {.delegate = delegatePtr, .request = requestMethod(request, delegate)});

    return id;
}

bool RequestContextManager::disposeContext(const FString& id)
{
    if (contextStorage_.Contains(id)) {
        contextStorage_.Remove(id);
        return true;
    }

    return false;
}

RequestContext& RequestContextManager::getContext(const FString& id)
{
    return contextStorage_[id];
}

const RequestContext& RequestContextManager::getContext(const FString& id) const
{
    return contextStorage_[id];
}

inline FString RequestContextManager::createUniqueID() const
{
    while (true) {
        FString id(FGuid::NewGuid().ToString());
        if (!contextStorage_.Contains(id)) return id;
    }
}

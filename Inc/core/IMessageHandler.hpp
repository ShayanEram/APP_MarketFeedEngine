#pragma once
#include "TradeMessage.hpp"

class IMessageHandler {
public:
    virtual ~IMessageHandler() = default;
    virtual void onTrade(const TradeMessage& trade) = 0;
    virtual void onQuote(const QuoteMessage& quote) = 0;
};

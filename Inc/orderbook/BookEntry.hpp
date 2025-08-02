#pragma once
#include "TradeMessage.hpp"
#include <map>
#include <mutex>
#include <shared_mutex>

class OrderBook {
public:
    void applyTrade(const TradeMessage& trade);
    void applyQuote(const QuoteMessage& quote);
    std::map<double, uint32_t> getTopOfBook() const;

private:
    std::map<double, uint32_t> bids; // price → quantity
    std::map<double, uint32_t> asks;
    mutable std::shared_mutex bookMutex;
};

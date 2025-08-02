#include "FIXParser.hpp"
#include "FixUtils.hpp"
#include "TradeMessage.hpp"
#include "QuoteMessage.hpp"

void FIXParser::parse(std::string_view raw) {
    auto fields = parseFixFields(raw);

    auto msgTypeIt = fields.find("35");
    if (msgTypeIt == fields.end()) return;

    if (msgTypeIt->second == "D") { // New Order
        TradeMessage trade;
        trade.symbol   = std::string(fields["55"]);
        trade.price    = std::stod(std::string(fields["44"]));
        trade.quantity = std::stoi(std::string(fields["38"]));
        trade.timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(
                            std::chrono::system_clock::now().time_since_epoch()).count();

        if (messageHandler) messageHandler->onTrade(trade);
    }
    else if (msgTypeIt->second == "Q") { // Custom Quote Type
        QuoteMessage quote;
        quote.symbol   = std::string(fields["55"]);
        quote.bidPrice = std::stod(std::string(fields["132"]));
        quote.askPrice = std::stod(std::string(fields["133"]));
        quote.timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(
                            std::chrono::system_clock::now().time_since_epoch()).count();

        if (messageHandler) messageHandler->onQuote(quote);
    }
}

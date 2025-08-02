#pragma once
#include "IParser.hpp"

class FIXParser : public IParser {
public:
    void parse(std::string_view raw) override;
private:
    void parseTrade(std::string_view msg);
    void parseQuote(std::string_view msg);
};

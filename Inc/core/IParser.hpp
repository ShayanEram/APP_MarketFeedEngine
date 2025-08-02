#pragma once
#include <string_view>
#include <memory>

class IMessageHandler;

class IParser {
public:
    virtual ~IParser() = default;
    virtual void parse(std::string_view raw) = 0;

    void setMessageHandler(std::shared_ptr<IMessageHandler> handler) {
        messageHandler = std::move(handler);
    }

protected:
    std::shared_ptr<IMessageHandler> messageHandler;
};

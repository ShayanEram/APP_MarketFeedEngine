#include <thread>
#include <memory>
#include "FIXParser.hpp"
#include "OrderBook.hpp"
#include "ApiPublisher.hpp"
#include "TopBookStrategy.hpp"
#include "FullDepthStrategy.hpp"
#include "SocketHandler.hpp"
#include "PerformanceTimer.hpp"

int main() {
    OrderBook book;
    PerformanceTimer timer;

    auto strategy = std::make_unique<TopBookStrategy>();
    auto publisher = std::make_shared<ApiPublisher>(strategy.get());

    FIXParser parser;
    parser.setMessageHandler(publisher);

    SocketHandler socket("239.0.0.1", 12345); // multicast IP + port

    std::atomic<bool> running{true};

    std::thread feedThread([&]() {
        while (running) {
            auto message = socket.receive();
            timer.start();
            parser.parse(message);
            timer.stop();
        }
    });

    std::thread apiThread([&]() {
        while (running) {
            publisher->publish();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });

    std::this_thread::sleep_for(std::chrono::seconds(10));
    running = false;

    feedThread.join();
    apiThread.join();

    timer.report();

    return 0;
}

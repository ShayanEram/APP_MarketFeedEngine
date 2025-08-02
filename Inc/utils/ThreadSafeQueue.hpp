#pragma once
#include <queue>
#include <mutex>
#include <optional>

template<typename T>
class ThreadSafeQueue {
public:
    void push(T item) {
        std::lock_guard<std::mutex> lock(mu);
        queue.push(std::move(item));
    }

    std::optional<T> pop() {
        std::lock_guard<std::mutex> lock(mu);
        if (queue.empty()) return std::nullopt;
        T item = std::move(queue.front());
        queue.pop();
        return item;
    }

private:
    std::queue<T> queue;
    std::mutex mu;
};

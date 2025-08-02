#pragma once
#include <chrono>
#include <vector>
#include <iostream>

class PerformanceTimer {
public:
    void start() {
        startTime = std::chrono::high_resolution_clock::now();
    }

    void stop() {
        auto end = std::chrono::high_resolution_clock::now();
        latencies.push_back(std::chrono::duration_cast<std::chrono::nanoseconds>(end - startTime).count());
    }

    void report() const {
        std::cout << "Latency Report (ns):\n";
        for (auto l : latencies) std::cout << l << '\n';
    }

private:
    std::chrono::high_resolution_clock::time_point startTime;
    std::vector<long long> latencies;
};

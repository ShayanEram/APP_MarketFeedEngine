# 🏎️ MarketFeedEngine
A performance-oriented C++ application that simulates and parses live market data (FIX or binary), processes updates with lock-free concurrency, and builds a real-time order book. Designed for high-frequency finance environments.

---

## 🚀 Features

- Multi-threaded feed ingestion engine using `std::thread` and lock-free messaging
- Smart parsing of FIX/binary market protocols (zero-copy & memory efficient)
- Efficient in-memory order book using STL and custom data structures
- Modular architecture with `Strategy` and `Observer` design patterns
- Written in **Modern C++** (C++17/C++20): smart pointers, lambdas, templates, etc.
- Network layer using raw **TCP/UDP sockets** and optional multicast
- Easy integration with Python analytics via `Pybind11` (planned)
- Benchmarking tools to measure processing latency in nanoseconds

## 🏗 Project Structure

- `include/` - Header interfaces and modular components
- `src/` - Implementations: parser, feed, orderbook, API
- `messaging/` - Lock-free queues and threading tools
- `network/` - Socket interface (supports multicast)
- `tests/` - Unit and integration tests
- `scripts/` - Utilities like benchmark runners and analyzers

## 📚 Key Concepts Demonstrated

| C++ Concept                      | Used In                                  |
|----------------------------------|-------------------------------------------|
| Smart Pointers (`unique_ptr`)    | Memory safety for parsers and book entries|
| Lambda Expressions               | Event callbacks and parser bindings       |
| Templates / STL Algorithms       | Generic parsing and depth update logic    |
| Multithreading & Atomics         | Feed ingestion & order book update threads|
| Polymorphism / Virtual Functions | Feed handler interface and parser logic   |
| Lock-Free Queues                 | High-performance message passing          |
| TCP/UDP + Multicast              | Market feed connections                   |
| FIX Protocol Parsing             | Binary string handlers in feed layer      |

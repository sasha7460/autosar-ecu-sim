#include "os.hpp"
#include <thread>
#include <chrono>
#include <iostream>

extern bool systemRunning;

bool systemRunning = true;

int main() {
    std::cout << "[System] Starting OS..." << std::endl;
    startOS();
    std::this_thread::sleep_for(std::chrono::seconds(10));
    systemRunning = false;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "[System] Shutdown complete." << std::endl;
    return 0;
}
#include "os.hpp"
#include <thread>
#include <chrono>
#include <iostream>

extern void Rte_Task_10ms();
extern void Rte_Task_20ms();

void startOS() {
    std::thread([] {
        while (systemRunning) {
            Rte_Task_10ms();
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }).detach();

    std::thread([] {
        while (systemRunning) {
            Rte_Task_20ms();
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
        }
    }).detach();
}
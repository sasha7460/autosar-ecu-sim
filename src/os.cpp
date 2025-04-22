#include "os.hpp"
#include "sensor_swc.hpp"
#include "controller_swc.hpp"
#include <thread>
#include <chrono>

void startOS(void) {
    // Simulate the OS scheduler
    while (true) {
        runSensorSWC();
        runControllerSWC();
        
        // Sleep for a short duration to simulate time slicing
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
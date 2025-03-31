
// File: src/sensor_main.cpp
#include "../include/sensor_swc.hpp"
#include "../include/shared_memory.hpp"

int main() {
    SharedMemory shm;
    runSensorSWC(shm);
    return 0;
}

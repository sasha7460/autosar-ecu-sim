// File: src/controller_main.cpp
#include "../include/controller_swc.hpp"
#include "../include/shared_memory.hpp"

int main() {
    SharedMemory shm;
    runControllerSWC(shm);
    return 0;
}

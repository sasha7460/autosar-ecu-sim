// File: include/shared_memory.hpp
#pragma once

#include <string>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/stat.h>
#include <cstring>
#include <iostream>

#define SHM_NAME "/ecu_shared_memory"
#define SHM_SIZE 1024

struct SensorData {
    float temperature;
    float pressure;
};

class SharedMemory {
public:
    SharedMemory();
    ~SharedMemory();

    void writeData(const SensorData& data);
    SensorData readData();

private:
    int shm_fd;
    void* ptr;
};
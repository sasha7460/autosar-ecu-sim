// File: src/shared_memory.cpp
#include "../include/shared_memory.hpp"

SharedMemory::SharedMemory() {
    shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1) {
        perror("shm_open");
        exit(1);
    }

    ftruncate(shm_fd, SHM_SIZE);
    ptr = mmap(0, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (ptr == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }
}

SharedMemory::~SharedMemory() {
    munmap(ptr, SHM_SIZE);
    close(shm_fd);
    shm_unlink(SHM_NAME);
}

void SharedMemory::writeData(const SensorData& data) {
    memcpy(ptr, &data, sizeof(SensorData));
}

SensorData SharedMemory::readData() {
    SensorData data;
    memcpy(&data, ptr, sizeof(SensorData));
    return data;
}


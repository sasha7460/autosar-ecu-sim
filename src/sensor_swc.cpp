#include "rte_sensor_swc.hpp"
#include "shared_types.hpp"

void runSensorSWC() {
    SensorData data;
    Rte_Read_SensorInput(&data);

    data.temperature += 0.5f;
    data.pressure += 0.1f;

    Rte_Write_SensorOutput(&data);
}
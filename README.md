# Classic AUTOSAR-Style ECU Simulation

This project simulates a Classic AUTOSAR-compliant ECU architecture using modern C++. It models key elements of the AUTOSAR runtime stack including Runnables, RTE (Run-Time Environment), and OS task scheduling.

---

## ✅ Features Implemented

- **AUTOSAR-compliant SWC runnables**:
  - `void` functions without parameters
  - Data exchange via RTE APIs (not direct arguments)

- **RTE Layer**:
  - Simulates `Rte_Read` and `Rte_Write` interfaces
  - Shared memory-style data passing using `SensorData` struct

- **Task-Based Scheduling**:
  - Simulated `OSEK/VDX`-style OS using `std::thread`
  - Periodic tasks: `Rte_Task_10ms`, `Rte_Task_20ms`
  - Each task calls mapped RTE wrappers, which invoke SWC runnables

- **Graceful System Shutdown**:
  - Automatic 10-second system run with clean shutdown
  - Threads terminate when `systemRunning = false`

---

## 🧱 Architecture Overview

```
  [ OS Scheduler (10ms) ] ---> Rte_Task_10ms() ---> runSensorSWC()
  [ OS Scheduler (20ms) ] ---> Rte_Task_20ms() ---> runControllerSWC()
  
  [ SWCs ] <--> [ RTE APIs ] <--> Shared SensorData
```

---

## 📁 File Structure

```
.
├── include/
│   ├── os.hpp                  # System control
│   ├── shared_types.hpp        # Data types (e.g., SensorData)
│   ├── rte_sensor_swc.hpp      # RTE for Sensor SWC
│   └── rte_controller_swc.hpp  # RTE for Controller SWC
│
├── src/
│   ├── main.cpp                # Entry point, handles system lifecycle
│   ├── os.cpp                  # Starts periodic tasks
│   ├── rte_task_10ms.cpp       # Maps task to Sensor SWC
│   ├── rte_task_20ms.cpp       # Maps task to Controller SWC
│   ├── sensor_swc.cpp          # Sensor logic
│   ├── controller_swc.cpp      # Controller logic
│   ├── rte_sensor_swc.cpp      # Sensor RTE APIs
│   └── rte_controller_swc.cpp  # Controller RTE APIs
│
├── Makefile                    # Build instructions
```

---

## 🏃 How to Build and Run

```bash
make clean
make
./build/ecu
```

You should see periodic sensor data and controller logs every 10ms and 20ms respectively.

---

## ✍️ Notes

- RTE uses a static variable (`latestSensorData`) to simulate shared memory between SWCs.
- SWCs operate entirely on RTE APIs to reflect Classic AUTOSAR constraints.
- No external libraries required beyond standard C++17.

---

## 📦 Next Improvements (Optional)

- Add basic fault injection and controller monitoring
- Extend RTE simulation with port-based access
- Log all RTE operations to file

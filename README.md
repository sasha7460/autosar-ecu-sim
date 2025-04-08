# Adaptive AUTOSAR ECU Simulation (C++)

This project simulates an Adaptive AUTOSAR-style ECU using open-source C++ on Linux/macOS. It progressively evolves from Classic AUTOSAR concepts into Adaptive architecture — all without needing any hardware or licensed tools.

---

## 🚗 Features Implemented

- **Sensor & Controller SWCs** running in parallel POSIX threads
- **ExecutionManager** that launches and manages apps like Adaptive AUTOSAR
- **JSON configuration** (instead of ARXML) for runtime control
- **Config-driven timing** and behavior
- **Logging** of sensor data and controller decisions
- **Shared Memory IPC** (to be replaced by messaging)

---

## 📁 Project Structure
autosar_ecu_sim/ ├── include/ │ ├── shared_memory.hpp │ ├── sensor_swc.hpp │ ├── controller_swc.hpp │ └── execution_manager.hpp ├── src/ │ ├── shared_memory.cpp │ ├── sensor_swc.cpp │ ├── controller_swc.cpp │ └── execution_manager.cpp ├── config.json ├── main.cpp ├── Makefile └── README.md


---

## 🧩 Next Steps (Planned)

- Replace shared memory with **message queues or sockets**
- Implement **service discovery and registration**
- Introduce **lifecycle state machine**
- Simulate **platform deployment**

---

## 🛠 Build & Run

```bash
make clean && make
./build/ecu

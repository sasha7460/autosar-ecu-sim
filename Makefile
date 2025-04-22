CXX=g++
CXXFLAGS=-std=c++17 -Iinclude -pthread
LDFLAGS=

SRC=src/main.cpp src/os.cpp src/rte_sensor_swc.cpp src/rte_controller_swc.cpp src/sensor_swc.cpp src/controller_swc.cpp

all: ecu

ecu:$(SRC)
	mkdir -p build
	$(CXX) $(CXXFLAGS) -o build/ecu $(SRC) $(LDFLAGS)

clean:
	rm -f build/ecu sensor_log.txt controller_log.txt

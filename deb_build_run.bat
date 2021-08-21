@echo off
cd build
cmake ..
cmake --build . --config Debug --target ALL_BUILD
cd Debug
BlueMarble.exe

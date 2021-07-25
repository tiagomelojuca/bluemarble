@echo off
cd build
cmake ..
cmake --build . --config RelWithDebInfo --target ALL_BUILD

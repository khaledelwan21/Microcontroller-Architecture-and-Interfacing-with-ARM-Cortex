# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "/home/khaled-ahmed-elwan/Microcontroller-Architecture-and-Interfacing-with-ARM-Cortex/Workspace/Rcc_test/build/Debug/Rcc_test.map"
  )
endif()

# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Ultrasound_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Ultrasound_autogen.dir\\ParseCache.txt"
  "Ultrasound_autogen"
  )
endif()

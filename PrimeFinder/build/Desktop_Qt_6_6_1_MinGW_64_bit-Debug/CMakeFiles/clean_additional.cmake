# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\PrimeFinder_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\PrimeFinder_autogen.dir\\ParseCache.txt"
  "PrimeFinder_autogen"
  )
endif()

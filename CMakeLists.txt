cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
project(phd-colours VERSION 0.0.1 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(INCLUDES ${INCLUDES}
    thirdparty/vivid/dependencies/glm/
    thirdparty/vivid/dependencies/json/include/
    thirdparty/vivid/include
    thirdparty/range-v3/include
    thirdparty/fmt/include
    thirdparty/libfort/lib/
)

add_subdirectory(thirdparty/fmt)
set(LIBRARIES ${LIBRARIES} fmt)

# vivid library
FILE(GLOB VIVID_SOURCES thirdparty/vivid/src/*)
add_library(vivid ${VIVID_SOURCES})
target_include_directories(vivid PRIVATE ${INCLUDES})
set(LIBRARIES ${LIBRARIES} vivid)

# fort library
SET(FORT_SOURCES
	thirdparty/libfort/lib/fort.h
	thirdparty/libfort/lib/fort.c
	thirdparty/libfort/lib/fort.hpp
)
add_library(fort ${FORT_SOURCES})
target_include_directories(fort PRIVATE ${INCLUDES})
set(LIBRARIES ${LIBRARIES} fort)


file(GLOB SOURCES
    src/*
)

add_executable(phd-colours ${SOURCES})
target_include_directories(phd-colours PRIVATE ${INCLUDES})
target_link_libraries(phd-colours PRIVATE ${LIBRARIES})

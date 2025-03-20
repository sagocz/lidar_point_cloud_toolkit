cmake_minimum_required(VERSION 3.10)
project(pcd_toolkit)

find_package(PCL REQUIRED)
find_package(OpenCV REQUIRED)
find_package(Boost REQUIRED COMPONENTS program_options)

include_directories(${PCL_INCLUDE_DIRS} ${OpenCV_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS} include)
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_library(pcd_toolkit src/pcd_toolkit.cpp src/pcd_manager.cpp)
target_link_libraries(pcd_toolkit ${PCL_LIBRARIES} ${OpenCV_LIBS} ${Boost_LIBRARIES})

add_executable(pcd_tool src/main.cpp)
target_link_libraries(pcd_tool pcd_toolkit)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
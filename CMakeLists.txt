cmake_minimum_required(VERSION 3.21)

project(VulkanUtils)

include(cmake/CPM.cmake)

set(CMAKE_CXX_STANDARD 17)
option(ENABLE_EXAMPLES "Build sample programs" ON)

add_subdirectory(examples)
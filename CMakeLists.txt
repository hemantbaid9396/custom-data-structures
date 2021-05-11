cmake_minimum_required(VERSION 3.0.0)

project(sample_application VERSION 1.0.0)

# Build the sub-directory Data Structure Containing the Data Structures. 
#  - This will refer the CMakeLists.txt in the Data Structure Folder to check which subdirectories it needs to build
add_subdirectory(DataStructures)

add_executable(
    sample_application
    application.cpp
)

target_link_libraries(
    sample_application PRIVATE Stack
)
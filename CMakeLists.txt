cmake_minimum_required(VERSION 3.30)
project(multithread)

set(CMAKE_CXX_STANDARD 20)

# Collect sources and headers
file(GLOB_RECURSE SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE HEADERS "${PROJECT_SOURCE_DIR}/include/*.h")

message("Sources ${SOURCES}")
message("Headers ${HEADERS}")
# Create executable (no need to include headers here)
add_executable(${PROJECT_NAME} ${SOURCES})

# Add include path
target_include_directories(${PROJECT_NAME} PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

cmake_minimum_required(VERSION 3.30)
project(multithread)

set(CMAKE_CXX_STANDARD 20)

# Collect sources and headers
file(GLOB_RECURSE SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE HEADERS "${PROJECT_SOURCE_DIR}/include/*.h")


add_executable(multithread ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME} PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

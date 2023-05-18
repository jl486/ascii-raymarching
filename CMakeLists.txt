cmake_minimum_required(VERSION 3.26.3)
add_compile_options(-std=c++20)
project(raymarch)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(Vector3)

target_include_directories(${PROJECT_NAME} PUBLIC Vector3)
target_link_directories(${PROJECT_NAME} PRIVATE Vector3)

target_link_libraries(${PROJECT_NAME} vector3)

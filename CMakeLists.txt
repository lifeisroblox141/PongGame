cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(PongGame)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE
	src/main.cpp
        src/globals.cpp
        src/classes/objects/player.cpp
        src/classes/objects/ball.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/lib/libraylib.a")

target_link_libraries(${PROJECT_NAME} PRIVATE 
    GL 
    m 
    pthread 
    dl 
    rt 
    X11
)

target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
#target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src")

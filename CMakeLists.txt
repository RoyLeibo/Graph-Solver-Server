cmake_minimum_required(VERSION 3.13)
project(final_project_second)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(final_project_second main.cpp MySerialServer.cpp MySerialServer.h Server.h OpenThread.cpp
        OpenThread.h MyParallelServer.cpp MyParallelServer.h ClientHandler.h MyTestClient.cpp MyTestClient.h
        OpenSocket.cpp OpenSocket.h Solver.h CacheManager.h FileCacheManager.cpp FileCacheManager.h StringReverse.cpp
        StringReverse.h MyClientHandler.cpp MyClientHandler.h Matrix.cpp Matrix.h)

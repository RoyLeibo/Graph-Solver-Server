cmake_minimum_required(VERSION 3.13)
project(final_project_second)

set(CMAKE_CXX_STANDARD 14)

add_executable(final_project_second main.cpp MySrialServer.cpp MySrialServer.h Server.h OpenThtead.cpp OpenThtead.h MyParallelServer.cpp MyParallelServer.h ChlientHandler.h MyTestClient.cpp MyTestClient.h OpenSocket.cpp OpenSocket.h Solver.h CachMenager.h FileCachMenger.cpp FileCachMenger.h Solution.cpp Solution.h Problem.cpp Problem.h)
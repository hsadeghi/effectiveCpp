cmake_minimum_required(VERSION 3.6)
project(effectiveCPP)

set(CMAKE_CXX_STANDARD 14)

add_executable(effectiveCPP main.cpp CL1.cpp CL1.h singleton.cpp singleton.h partialConst.cpp partialConst.h baseAndDerived.cpp baseAndDerived.h factory.cpp factory.h)
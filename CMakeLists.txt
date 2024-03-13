cmake_minimum_required(VERSION 3.27.5)

project(RNS)

add_executable(${PROJECT_NAME} main.cpp rns.cpp rns.h rns-number.cpp rns-number.h)

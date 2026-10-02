cmake_minimum_required(VERSION 4.3)
project(AED)

set(CMAKE_CXX_STANDARD 20)

add_executable(AED main.cpp)
add_executable(portland portland.cpp)
add_executable(chuva chuva.cpp)
add_executable(cifra cifra.cpp)
add_executable(pilha pilha_min.cpp)
add_executable(parentesis parentesis.cpp)
add_executable(fila media fila_media.cpp)
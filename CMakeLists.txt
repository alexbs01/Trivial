cmake_minimum_required(VERSION 3.20)
project(Trivial C)

set(CMAKE_C_STANDARD 99)

add_executable(Trivial main.c listaPreguntas.c listaPreguntas.h)

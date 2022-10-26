cmake_minimum_required(VERSION 3.23)
project(TD C)

set(CMAKE_C_STANDARD 99)

add_library(TD parser.c tester.c)

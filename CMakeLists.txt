cmake_minimum_required(VERSION 3.16)
project(lab1 C)

set(SOURCE_EXE main.c PolInfo.c polynom.c PolInfo.h tests.c tests.h)


add_executable(main ${SOURCE_EXE})

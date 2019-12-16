cmake_minimum_required(VERSION 3.15)
project(cgame C)

set(CMAKE_C_STANDARD 99)

add_executable(cgame main.c domain/Hero.c domain/Hero.h domain/Enemy.c domain/Enemy.h domain/Laser.c domain/Laser.h domain/World.c domain/World.h app/terminal.c app/terminal.h)

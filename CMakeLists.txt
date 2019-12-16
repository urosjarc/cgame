cmake_minimum_required(VERSION 3.15)
project(cgame C)

set(CMAKE_C_STANDARD 11)

include_directories(app)
include_directories(domain)

add_executable(cgame
        app/terminal.c
        app/terminal.h
        domain/Enemy.c
        domain/Enemy.h
        domain/Hero.c
        domain/Hero.h
        domain/Laser.c
        domain/Laser.h
        domain/World.c
        domain/World.h
        main.c)

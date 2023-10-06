cmake_minimum_required(VERSION 3.26)
project(itmo_repo)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(sem_1)

add_executable(itmo_repo
        sem_1/algo/sort/bubble.cpp
        sem_1/algo/sort/insertion.cpp
        sem_1/algo/sort/merge.cpp
        sem_1/algo/sort/quick.cpp)

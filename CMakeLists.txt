cmake_minimum_required(VERSION 3.14)
project(bruteforce_hash)

set(CMAKE_CXX_STANDARD 14)

find_library(CRYPTO_PP crypto++)

add_executable(bruteforce_hash main.cpp)

target_link_libraries(bruteforce_hash PRIVATE "${CRYPTO_PP}")

cmake_minimum_required(VERSION 3.14)
project(bruteforce_hash)

set(CMAKE_CXX_STANDARD 14)

find_library(CRYPTO_PP crypto++)

add_executable(bruteforce_hash main.cpp  LoadHash.cpp  LoadDict.cpp )
#add_executable(bruteforce_hash main.cpp helperFunctions.h IBruteforce.h RecurciveMD5.h RecurciveMD5.cpp LoadHash.cpp LoadHash.h LoadDict.cpp LoadDict.h testFunctions.h)

target_link_libraries(bruteforce_hash PRIVATE "${CRYPTO_PP}")

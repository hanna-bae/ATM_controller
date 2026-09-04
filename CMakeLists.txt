cmake_minimum_required(VERSION 3.14)

project(ATMController LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(atm_core
    src/ATM.cpp
    src/Account.cpp 
    src/Card.cpp
)

target_include_directories(atm_core
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

add_executable(atm
    src/main.cpp
)

target_link_libraries(atm
    PRIVATE 
        atm_core
)

enable_testing()
add_subdirectory(tests)
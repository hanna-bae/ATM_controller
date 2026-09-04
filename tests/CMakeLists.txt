include(FetchContent)

FetchContent_Declare(
    googletest 
    URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest) 

add_executable(atm_tests
    test_account.cpp 
    test_card.cpp 
    test_atm.cpp
)

target_link_libraries(atm_tests
    PRIVATE 
        atm_core 
        GTest::gtest_main

)

include(GoogleTest)

gtest_discover_tests(atm_tests)
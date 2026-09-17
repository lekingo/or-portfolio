cmake_minimum_required(VERSION 3.15)
project(or_portfolio)
set(CMAKE_CXX_STANDARD 17)
add_executable(main src/main.cpp)
target_link_options(main PRIVATE -mconsole)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.2
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(unit_tests tests/test_basic.cpp)
target_link_libraries(unit_tests PRIVATE gtest_main)

include(GoogleTest)
gtest_discover_tests(unit_tests)

if (MSVC)
    set(CPLEX_ROOT "C:/Program Files/IBM/ILOG/CPLEX_Studio_Community222")
    set(CPLEX_ARCH "x64_windows_msvc14/stat_mda")

    add_executable(test_cplex src/test_cplex.cpp)

    target_include_directories(test_cplex PRIVATE
        ${CPLEX_ROOT}/cplex/include
        ${CPLEX_ROOT}/concert/include
    )

    target_link_directories(test_cplex PRIVATE
        ${CPLEX_ROOT}/cplex/lib/${CPLEX_ARCH}
        ${CPLEX_ROOT}/concert/lib/${CPLEX_ARCH}
    )

    target_link_libraries(test_cplex PRIVATE
        ilocplex
        cplex2220
        concert
    )

    target_compile_definitions(test_cplex PRIVATE IL_STD)
endif()
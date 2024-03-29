cmake_minimum_required(VERSION 2.8.2)
set(CMAKE_CXX_STANDARD 11)  # enable C++11 standard
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra -pthread -g")

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()

# Now simply link against gtest or gtest_main as needed. Eg
include_directories(src)
set(PROJECT_NAME example)

project (${PROJECT_NAME})

add_executable(${PROJECT_NAME}
 ${PROJECT_SOURCE_DIR}/src/example.cpp
 ${PROJECT_SOURCE_DIR}/src/unit.cpp)

 project  (unit_test)
 add_executable(unit_test
 ${PROJECT_SOURCE_DIR}/test/unit_test.cpp
 ${PROJECT_SOURCE_DIR}/src/unit.h
 ${PROJECT_SOURCE_DIR}/src/unit.cpp)
target_link_libraries(unit_test gtest_main)
add_test(NAME example_test COMMAND example)
cmake_minimum_required(VERSION 3.5)

project(HashSet)
set(CMAKE_CXX_STANDARD 14)
message("CMake build type: " ${CMAKE_BUILD_TYPE})

add_subdirectory(3rd-party)

set(source_files
        main.test.cpp
        HashSet
        HashSet.Test.cpp
)

add_executable(hash_set_test
        ${source_files}
        )

target_link_libraries(hash_set_test
        catch
        )
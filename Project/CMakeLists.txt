cmake_minimum_required(VERSION 3.20)

project(agent_aware_storage
    VERSION 0.1.0
    DESCRIPTION "Agent-aware tiered storage engine prototype"
    LANGUAGES CXX
)

include(CTest)

option(AGENT_STORAGE_BUILD_TESTS "Build tests" ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(agent_storage
    src/storage_engine.cpp
)

target_include_directories(agent_storage
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

if(MSVC)
    target_compile_options(agent_storage PRIVATE /W4 /permissive-)
else()
    target_compile_options(agent_storage PRIVATE -Wall -Wextra -Wpedantic)
endif()

if(AGENT_STORAGE_BUILD_TESTS)
    add_executable(agent_storage_smoke_test
        tests/smoke_test.cpp
    )

    target_link_libraries(agent_storage_smoke_test PRIVATE agent_storage)

    add_test(
        NAME agent_storage_smoke_test
        COMMAND agent_storage_smoke_test
    )
endif()

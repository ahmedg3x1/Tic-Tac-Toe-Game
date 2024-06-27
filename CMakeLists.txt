cmake_minimum_required(VERSION 3.5)

project(Tic-Tac-Toe-Game LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add coverage flags
add_compile_options(--coverage -g -O0)
add_link_options(--coverage -g -O0)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

set(MAIN
    src/main.cpp
)

set(TST_MAIN
    test/tst_main.cpp
)

set(SOURCES
    src/Database.cpp
    src/entry_menu.cpp
    src/game_window.cpp
    src/login_window.cpp
    src/profile_menu.cpp
    src/register_window.cpp
)

set(HEADERS
    src/Database.h
    src/entry_menu.h
    src/game_window.h
    src/login_window.h
    src/profile_menu.h
    src/register_window.h
)

set(FORMS
    ui/entry_menu.ui
    ui/game_window.ui
    ui/login_window.ui
    ui/profile_menu.ui
    ui/register_window.ui
)

set(TESTS
    test/tst_database.cpp
    test/tst_game.cpp
    test/tst_integration.cpp
)

add_executable(
    Tic-Tac-Toe-Game WIN32
    ${MAIN}
    ${SOURCES}
    ${HEADERS}
    ${FORMS}
)

target_link_libraries(Tic-Tac-Toe-Game Qt6::Core Qt6::Widgets)


#Fetch GoogleTest
include(FetchContent)
    FetchContent_Declare(
    googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.14.0
    )

FetchContent_MakeAvailable(googletest)


add_executable(
    googletest-part
    ${TST_MAIN}
    ${SOURCES}
    ${HEADERS}
    ${FORMS}
    ${TESTS}
)

target_link_libraries(googletest-part gtest Qt6::Core Qt6::Widgets)



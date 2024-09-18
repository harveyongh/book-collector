cmake_minimum_required(VERSION 3.27)

project(book-collector)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(book.collector src/main.cpp
src/book.cpp
src/library.cpp
src/filehandler.cpp
src/curses.cpp)
target_link_libraries(book.collector ${CURSES_LIBRARIES} panel)

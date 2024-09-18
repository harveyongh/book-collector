cmake_minimum_required(VERSION 3.27)

project(book-collector)

find_package(Curses REQUIRED)

add_executable(book.collector src/main.cpp
src/book.cpp
src/library.cpp
src/filehandler.cpp
src/curses.cpp)

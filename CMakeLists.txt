cmake_minimum_required(VERSION 3.27)

project(book-collector)

set(TESTING "False" CACHE BOOL "Decides whether testing files are created")

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(book.collector src/main.cpp
src/book.cpp
src/library.cpp
src/filehandler.cpp
src/curses.cpp)
target_link_libraries(book.collector ${CURSES_LIBRARIES} panel)

if( TESTING )
  message("Testing files are being built")
  add_executable(testing.curses src/test/testingcurses.cpp src/curses.cpp src/book.cpp)
  target_link_libraries(testing.curses ${CURSES_LIBRARIES} panel)
  endif()

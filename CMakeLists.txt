cmake_minimum_required(VERSION 3.27)

project(book-collector)
add_executable(book.collector src/main.cpp
  src/book/book.cpp src/book/library.cpp src/data/filehandler.cpp)

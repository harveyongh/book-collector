## Overview & Summary
This repo contains a very simple program for managing a text-based book collection. The collections are stored in CSV files and referenced by filename, allowing you to have as many collections as you want. You could store it all in one big collection, or a hundred small ones.

## Tips
* After you make changes to the library, make sure to save the library. The program does not currently autosave.
* When prompted with entry format (e.g. Last, First), be sure to follow that format including spaces.

## Building
To build this project locally on linux, I have included the necessary CMakeLists.txt file that handles most tasks for you. The only things required are Git, a C++ compiler like G++ and its libraries, and Cmake.

``` sh
git clone https://github.com/harveyongh/book-collector.git
cd book-collector/; mkdir build; cd build/
cmake ..; cmake --build .
./book.collector
```


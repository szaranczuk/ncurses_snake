# Simple snake game made in C++17 with NCURSES

Navigation through WSAD keys.  
Keys and board size can be easily changed by modifying main.cpp  
GUI design can be changed by modifying const parameters values in game.hpp

### build deps:
 - `gcc`
 - `cmake`
 - `ncurses`
### additional for Windows:
- `MinGW or any GNU "make" port`


### GNU build proces:
```
$ mkdir build
$ cd build
$ cmake ..
$ make
```

### Windows MinGW build proces:
```
$ mkdir build
$ cd build
$ cmake .. -G "MinGW Makefiles"
$ mingw32-make
```

executable is in build/bin/

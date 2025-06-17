# Game of Life in C++

A simple implementation of Conway's Game of Life using C++ and SFML.

## Features
- Grid-based simulation
- Classic Game of Life rules
- Color-coded cells using SFML

## Build Instructions

### Dependencies
- [SFML](https://www.sfml-dev.org/download.php) (Graphics library)

### Compile (Linux/Mac)
```bash
g++ -o game src/main.cpp -lsfml-graphics -lsfml-window -lsfml-system
```

### Compile (Windows with MinGW)
```bash
g++ -o game.exe src/main.cpp -lsfml-graphics -lsfml-window -lsfml-system
```

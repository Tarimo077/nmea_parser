# NMEA Parser

This project is a C++ program to decode NMEA sentences from a given `.txt` file containing GPS data. The `.txt` file in this case is jogging_path.txt included in this directory.

## Features

- Reads NMEA sentences from a `.txt` file.
- Parses the sentences to extract relevant data (e.g., latitude, longitude, time, etc.).
- Handles common NMEA sentence types such as GPGGA, GPGLL, and GPRMC.
- Modular and portable system design.
- Includes unit tests to verify the correctness of the parsing logic.

## Requirements

- CMake 3.10 or higher
- C++11 or higher
- A C++ compiler (e.g., GCC, Clang, MSVC)
- Ninja build system (optional, recommended)
- Catch2 testing framework (included via CMake)

## Installation

### Windows

1. **Install CMake**: Download and install CMake from [cmake.org](https://cmake.org/download/).
2. **Install Ninja (optional)**: Download and extract Ninja from [ninja-build.org](https://github.com/ninja-build/ninja/releases). Add the directory containing `ninja.exe` to your PATH.
3. **Install a C++ compiler**: Install MinGW or another compiler. Add the `bin` directory to your PATH.

### macOS

1. **Install Homebrew** (if not already installed):
   ```sh
   /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
2. **Install CMake**:
    brew install cmake
3. **Install Ninja (optional)**:
    brew install ninja

### Linux
1. **Install CMake**:
    sudo apt update
    sudo apt install cmake
2. **Install Ninja (optional)**:
    sudo apt install ninja-build
3. **Install a C++ compiler**: 
    sudo apt install build-essential


### Build Instructions
1. **Clone the repository**:
    git clone https://github.com/yourusername/nmea_parser.git
    cd nmea_parser
2. **Create a build directory and navigate to it**:
    mkdir build
    cd build
3. **Run CMake to configure the project**:
    cmake -G "Ninja" ..
### If you are not using Ninja, use:
    cmake ..
4. **Build the project**:
    cmake --build .


### Run the Program
**To run the program and parse the jogging_path.txt file**:
    ./NMEAParser


### Run the Tests
**To run the unit tests**:
    ./NMEAParserTest
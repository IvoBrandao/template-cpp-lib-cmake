# C++ CMake Template for Libraries

This repository provides a robust template for bootstrapping C++ projects, specifically tailored for library development. It is designed to streamline the setup process for projects that require unit testing, a test application, and modular development.

## Features

CMake Integration: Simplifies building and managing your C++ projects.

- Library Support: Includes a template for creating and managing a library.
- Unit Testing with Google Test: Preconfigured for seamless integration with Google Test (GTest).
- Test Application: Links the library to a test application for functional testing and debugging.

## Getting Started

### Prerequisites

Before you begin, ensure you have the following tools installed:

- A C++ compiler (e.g., GCC, Clang, or MSVC).
- CMake (version 3.16 or later).
- Google Test (included or added as a dependency).

### Setting Up the Project

Clone this repository:

```sh
git clone <repository-url>
cd <repository-folder>
```

Create a build directory:

```sh
mkdir build && cd build
```

Configure the project with CMake:

```sh
cmake ..
```

Build the project:

```sh
cmake --build .
```

### Directory structure


```sh
.
├── CMakeLists.txt       # Top-level CMake configuration
├── libs/                # Libraries folder
│   ├── CMakeLists.txt   # CMake configuration for libs
│   └── Mylib/           # Example library
│       ├── CMakeLists.txt # Library-specific CMake configuration
│       ├── include/     # Public headers for the library
│       │   └── mylib.hpp
│       ├── source/      # Implementation files for the library
│       │   └── mylib.cpp
│       └── test/        # Unit tests for the library
│           ├── CMakeLists.txt # CMake configuration for tests
│           ├── fakes/   # Test fakes
│           │   ├── include/
│           │   └── source/
│           ├── mocks/   # Test mocks
│           │   ├── include/
│           │   └── source/
│           └── mylib_test.cpp # Test cases
├── LICENSE              # License file
├── README.md            # Project documentation
└── source/              # Main application source files
    └── main.cpp         # Entry point of the application
```

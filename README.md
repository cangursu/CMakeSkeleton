# CMakeSkeleton Framework

A comprehensive C++ project template using CMake build system. This framework provides a structured approach for C++ projects with separate library and executable components, each with their own test modules.

## Project Structure

```
CMakeSkeleton/
├── lib/               # Library component
│   ├── inc/          # Library header files
│   ├── src/          # Library source files
│   └── test/         # Library unit tests
├── prj/              # Executable component
│   ├── inc/          # Project header files
│   ├── src/          # Project source files
│   └── test/         # Project unit tests
└── bin/              # Output directory for binaries
```

## Features

- Modern CMake setup (minimum version 3.12)
- C++17 standard enforced
- Ccache support for faster builds
- Comprehensive warning flags enabled (-Wall -Wextra -Wpedantic -Werror)
- Google Test integration for unit testing
- Separate debug and release build configurations
- Shared library and executable targets
- Automated version management

## Prerequisites

- CMake (version 3.12 or higher)
- C++17 compatible compiler
- Google Test framework
- Ccache (optional, for build acceleration)

## Build Instructions

```bash
mkdir build && cd build
cmake ..
make
```
Run the tests:
```bash
make test
```

## Configuration Options

- Debug build: `cmake -DCMAKE_BUILD_TYPE=Debug ..`
- Release build: `cmake -DCMAKE_BUILD_TYPE=Release ..`
- Installation path: `cmake -DCMAKE_INSTALL_PREFIX=/your/install/path ..`

## Project Customization

To use this template for your own project:

1. Rename the "CMakeSkeleton" folder to your desired project name
2. Search and replace all instances of "CMakeSkeleton" in the CMake files with your project name
3. Update the version numbers in the library CMakeLists.txt if needed
4. Modify the source files in `lib/src` and `prj/src` with your implementation

## Development Guidelines

- Place all header files in the respective `inc` directories
- Place all source files in the respective `src` directories
- Write unit tests in the respective `test` directories
- Follow the existing project structure for new components
- Use the provided warning flags to maintain code quality

## Advanced Features

- Supports separate compilation of library and executable
- Automated handling of header and source file discovery
- Debug builds include debug symbols (-g3) and disable optimization (-O0)
- Release builds enable high optimization (-O3)
- Public headers are automatically installed to the specified location

## Author

Can Gürsu

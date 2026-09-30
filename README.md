# c-snake-game

A cross-platform TUI-based Snake game written in C11.

## Requirements

* [Git](https://git-scm.com/downloads)
* [CMake](https://cmake.org/download/)
* A C11-compatible compiler (e.g. [GCC](https://gcc.gnu.org/)/[Clang](https://clang.llvm.org/))

## Setup

Clone the repository:

```bash
git clone https://github.com/slymachenko/c-snake-game.git
cd c-snake-game
```

### Debug

Configure and build a debug version:

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
```

To enable sanitizers:

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug -DENABLE_SANITIZERS=ON
cmake --build build
```

### Release

Configure and build a release version:

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

## Run

After building, run the executable:

### Linux / macOS

```bash
./build/c-snake-game
```

### Windows

```powershell
.\build\c-snake-game.exe
```

With Visual Studio or another multi-config generator, specify the configuration:

```bash
cmake --build build --config Release
```

The executable will then be under the corresponding configuration directory.

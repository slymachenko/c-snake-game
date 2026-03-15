# c-snake-game

A cross-platform TUI-based snake game written in pure C11 from scratch.

## Requirements

- [Git](https://git-scm.com/downloads)
- [CMake](https://cmake.org/cmake/help/latest/command/install.html)
- C compiler/toolchain supported by CMake (e.g. GCC/Clang/MSVC)

## Setup

### Debug

Enables all warnings, debug symbols, and sanitizers.

```bash
git clone https://github.com/slymachenko/c-snake-game.git
cd c-snake-game
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
```

> [!NOTE]
> Sanitizer runtime libraries must be installed:
>
> - Fedora/RHEL: `sudo dnf install libasan libubsan`
> - Debian/Ubuntu: `sudo apt install libasan8 libubsan1`
>
> To build without sanitizers: `cmake -S . -B build -DENABLE_SANITIZERS=OFF`

### Release

Fully optimized, stripped binary ready for distribution.

```bash
git clone https://github.com/slymachenko/c-snake-game.git
cd c-snake-game
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

> [!NOTE]
> On multi-config generators (e.g. Visual Studio), omit `-DCMAKE_BUILD_TYPE` and use `--config` at build time:
>
> ```bash
> cmake -S . -B build
> cmake --build build --config Release
> ```

## Running

The built executable is located at:

- Linux/macOS: `build/c-snake-game`
- Windows (Makefiles/Ninja): `build/c-snake-game.exe`
- Windows (Visual Studio): `build/Debug/c-snake-game.exe` or `build/Release/c-snake-game.exe`

# Installation Guide

Step-by-step guide to install and build Morse Code Converter on your system.

## Prerequisites

- **C++17 capable compiler** (GCC 7+, Clang 5+, MSVC 2017+)
- **Git** (to clone the repository)
- **Make** (optional, for easier building)

## Windows (MinGW/MSVC)

### Option 1: Using MinGW

1. **Install MinGW-w64**
   - Download from [mingw-w64.org](https://www.mingw-w64.org/)
   - Add MinGW `bin` folder to your PATH environment variable

2. **Clone the repository**
   ```bash
   git clone https://github.com/HarshYadav152/Morse-Code.git
   cd Morse-Code
   ```

3. **Build the project**
   ```bash
   g++ -std=c++17 MorseCodeConverter.cpp -O2 -o morse.exe
   ```

4. **Run the program**
   ```bash
   morse.exe
   ```

### Option 2: Using Visual Studio

1. Create a new C++ console project
2. Copy `MorseCodeConverter.cpp` to your project
3. Build and run from Visual Studio

## Linux (Ubuntu/Debian)

1. **Install build tools**
   ```bash
   sudo apt-get update
   sudo apt-get install build-essential git
   ```

2. **Clone the repository**
   ```bash
   git clone https://github.com/HarshYadav152/Morse-Code.git
   cd Morse-Code
   ```

3. **Build using Makefile**
   ```bash
   make
   ```

4. **Run the program**
   ```bash
   ./morse
   ```

5. **Clean build artifacts (optional)**
   ```bash
   make clean
   ```

## macOS

1. **Install GCC using Homebrew**
   ```bash
   brew install gcc
   ```

2. **Clone the repository**
   ```bash
   git clone https://github.com/HarshYadav152/Morse-Code.git
   cd Morse-Code
   ```

3. **Build using Makefile**
   ```bash
   make
   ```

4. **Run the program**
   ```bash
   ./morse
   ```

## Alternative Build Methods

### Direct G++ Compilation
If you don't have Make installed:

```bash
g++ -std=c++17 MorseCodeConverter.cpp -O2 -o morse
```

### With Debug Symbols
For debugging:

```bash
g++ -std=c++17 MorseCodeConverter.cpp -g -o morse
```

### With All Warnings
For development:

```bash
g++ -std=c++17 -Wall -Wextra MorseCodeConverter.cpp -O2 -o morse
```

## Troubleshooting

### Issue: "g++: command not found"

**Solution:** Install a C++ compiler for your OS
- **Windows:** Install MinGW or Visual Studio
- **Linux:** `sudo apt-get install build-essential`
- **macOS:** `brew install gcc`

### Issue: "make: command not found"

**Solution:** Either install Make or compile directly:
```bash
g++ -std=c++17 MorseCodeConverter.cpp -O2 -o morse
```

### Issue: Permission denied on Linux/macOS

**Solution:** Add execute permission:
```bash
chmod +x morse
./morse
```

### Issue: Compilation errors with older compiler

**Solution:** Ensure you're using C++17 or later:
```bash
g++ --version  # Check your compiler version
```

If your compiler is too old, upgrade it:
- **Linux:** `sudo apt-get install g++-9` (or newer)
- **macOS:** `brew upgrade gcc`
- **Windows:** Download newer MinGW or Visual Studio

## Verification

After building, verify the installation:

```bash
./morse
```

You should see:
```
====== Morse Code Converter ======
1. Convert Text to Morse
2. Convert Morse to Text
3. Load from File
4. Save to File
5. Exit
==================================
Choose an option:
```

## Next Steps

- Read the [README.md](../README.md) for usage instructions
- Check [CONTRIBUTING.md](../CONTRIBUTING.md) if you want to contribute
- Visit the [documentation](./index.html) for detailed API reference

## Need Help?

- Open an issue on [GitHub](https://github.com/HarshYadav152/Morse-Code/issues)
- Check existing issues for similar problems
- Read the [FAQ section](./index.html) in the documentation
# ⚠️ Important Notice

## Makefile Tab Character Issue

If you encounter the error:
```
Makefile:20: *** missing separator.  Stop.
```

This is caused by **spaces instead of TAB characters** in the Makefile.

### The Problem

Makefiles require **TAB characters** (not spaces) for indentation before command lines. Most text editors convert TABs to spaces by default, which breaks the Makefile.

### The Solution

#### Option 1: Fix in VS Code (Recommended)

1. Open **Settings** (`Ctrl + ,`)
2. Search for `Insert Spaces`
3. **Uncheck** "Editor: Insert Spaces"
4. Close and reopen `Makefile`
5. Re-save the file

Or add this to your `.vscode/settings.json`:
```json
{
    "[makefile]": {
        "editor.insertSpaces": false,
        "editor.detectIndentation": false
    }
}
```

#### Option 2: Compile Without Make

If you don't want to fix the Makefile, compile directly:

**Windows:**
```bash
g++ -std=c++17 -Wall -Wextra -O2 MorseCodeConverter.cpp -o morse.exe
morse.exe
```

**Linux/macOS:**
```bash
g++ -std=c++17 -Wall -Wextra -O2 MorseCodeConverter.cpp -o morse
./morse
```

#### Option 3: Use Build Scripts

Create a simple batch file (`build.bat`) for Windows:
```batch
@echo off
g++ -std=c++17 -Wall -Wextra -O2 MorseCodeConverter.cpp -o morse.exe
if %errorlevel% equ 0 (
    echo Build successful!
    morse.exe
) else (
    echo Build failed!
)
```

Then run:
```bash
build.bat
```

#### Option 4: Install Make on Windows

If you want to use Make:

**Using Chocolatey:**
```bash
choco install make
```

**Using MinGW:**
1. Download [MinGW-w64](https://www.mingw-w64.org/)
2. Install with `mingw32-make`
3. Use: `mingw32-make run`

### Verification

After fixing, test with:
```bash
make
make run
make clean
```

### Need Help?

- Open an issue on [GitHub](https://github.com/HarshYadav152/Morse-Code/issues)
- Check the [Installation Guide](./INSTALLATION_GUIDE.md)
- See [README.md](../README.md) for alternatives

---

**Last Updated:** November 1, 2025
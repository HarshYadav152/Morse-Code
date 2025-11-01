# Morse Code Converter

A full-featured C++ utility to convert text to Morse code and vice versa. Perfect for learning, amateur radio enthusiasts, and developers.

**Author:** Harsh Yadav

## Features

✅ Convert text to Morse code  
✅ Convert Morse code back to text  
✅ Interactive menu-driven interface  
✅ File I/O support (load & save)  
✅ Support for 40+ characters (letters, digits, punctuation)  
✅ Word separation with `/`  
✅ Efficient lookups with `unordered_map`  
✅ Object-oriented design with `MorseConverter` class  

## Supported Characters

**Letters:** A–Z (case-insensitive)  
**Digits:** 0–9  
**Punctuation:** `. , ? : ; - / " ' ( ) = + $ _ @`

## Build

Requires C++11 or later.

```sh
g++ -std=c++17 MorseCodeConverter.cpp -O2 -o morse
```

## Usage

Run interactively:
```sh
./morse
```

**Menu options:**
- Convert text to Morse
- Convert Morse back to text
- Load from file
- Save to file

### Example

```
Input:  HELLO WORLD
Output: .... . .-.. .-.. --- / .-- --- .-. .-.. -..
```

```
Input:  .... . .-.. .-.. --- / .-- --- .-. .-.. -..
Output: HELLO WORLD
```

## Project Structure

```
Morse-Code/
├── MorseCodeConverter.cpp    # Main implementation
├── README.md                 # Documentation
├── LICENSE                   # Open source license
├── .gitignore               # Git ignore rules
└── tests/                    # Unit tests (future)
```

## Roadmap

- [ ] Add unit tests with Google Test
- [ ] Support for prosigns (SOS, END, etc.)
- [ ] Audio output (play Morse sounds)
- [ ] GUI with Qt or wxWidgets
- [ ] Command-line argument support
- [ ] Performance benchmarks
- [ ] Documentation site

## Contributing

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/YourFeature`)
3. Commit changes (`git commit -m 'Add YourFeature'`)
4. Push to branch (`git push origin feature/YourFeature`)
5. Open a Pull Request

## License

This project is licensed under the MIT License – see [LICENSE](LICENSE) file for details.

## Resources

- [Morse Code Wikipedia](https://en.wikipedia.org/wiki/Morse_code)
- [International Morse Code](https://morsecode.world/)
- [Amateur Radio (Ham Radio)](https://www.arrl.org/)

---

Made with ❤️ by Harsh Yadav

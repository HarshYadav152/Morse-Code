#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <fstream>
#include <cctype>

using namespace std;

class MorseConverter {
private:
    unordered_map<char, string> morseCode;
    unordered_map<string, char> reverseMorse;

public:
    MorseConverter() {
        initializeMorse();
    }

    void initializeMorse() {
        morseCode = {
            {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."},
            {'F', "..-."}, {'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"},
            {'K', "-.-"}, {'L', ".-.."}, {'M', "--"}, {'N', "-."}, {'O', "---"},
            {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
            {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"}, {'Y', "-.--"},
            {'Z', "--.."},
            {'0', "-----"}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"}, {'4', "....-"},
            {'5', "....."}, {'6', "-...."}, {'7', "--..."}, {'8', "---.."}, {'9', "----."},
            {'.', ".-.-.-"}, {',', "--..--"}, {'?', "..--.."}, {':', "---..."}, {';', "-.-.-."},
            {'-', "-....-"}, {'/', "-..-."}, {'"', ".-..-."}, {'\'', ".----."}, {'(', "-.--."},
            {')', "-.--.-"}, {'=', "-...-"}, {'+', ".-.-."}, {'$', "...-..-"}, {'_', "..--.-"},
            {'@', ".--.-."}
        };
        
        for (auto& p : morseCode) {
            reverseMorse[p.second] = p.first;
        }
    }

    string textToMorse(const string& text) {
        string result;
        for (char c : text) {
            if (c == ' ') {
                result += " / "; // word separator
            } else {
                char upper = toupper(static_cast<unsigned char>(c));
                auto it = morseCode.find(upper);
                if (it != morseCode.end()) {
                    result += it->second + " ";
                } else {
                    result += "? "; // unknown character
                }
            }
        }
        return result;
    }

    string morseToText(const string& morse) {
        string result;
        string code;
        for (size_t i = 0; i < morse.length(); ++i) {
            if (morse[i] == ' ') {
                if (!code.empty()) {
                    auto it = reverseMorse.find(code);
                    result += (it != reverseMorse.end()) ? it->second : '?';
                    code.clear();
                }
            } else if (morse[i] == '/' && (i + 1 >= morse.length() || morse[i + 1] == ' ')) {
                result += ' ';
            } else {
                code += morse[i];
            }
        }
        if (!code.empty()) {
            auto it = reverseMorse.find(code);
            result += (it != reverseMorse.end()) ? it->second : '?';
        }
        return result;
    }

    void saveToFile(const string& filename, const string& content) {
        ofstream file(filename);
        if (file.is_open()) {
            file << content;
            file.close();
            cout << "Saved to " << filename << endl;
        } else {
            cout << "Error opening file!" << endl;
        }
    }

    string loadFromFile(const string& filename) {
        ifstream file(filename);
        string content, line;
        if (file.is_open()) {
            while (getline(file, line)) {
                content += line + "\n";
            }
            file.close();
        } else {
            cout << "Error opening file!" << endl;
        }
        return content;
    }
};

void displayMenu() {
    cout << "\n====== Morse Code Converter ======\n";
    cout << "1. Convert Text to Morse\n";
    cout << "2. Convert Morse to Text\n";
    cout << "3. Load from File\n";
    cout << "4. Save to File\n";
    cout << "5. Exit\n";
    cout << "==================================\n";
    cout << "Choose an option: ";
}

int main() {
    MorseConverter converter;
    int choice;
    string input, output;

    while (true) {
        displayMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                cout << "Enter text: ";
                getline(cin, input);
                output = converter.textToMorse(input);
                cout << "\nMorse Code: " << output << "\n";
                break;
            }
            case 2: {
                cout << "Enter Morse code (space-separated): ";
                getline(cin, input);
                output = converter.morseToText(input);
                cout << "\nDecoded Text: " << output << "\n";
                break;
            }
            case 3: {
                cout << "Enter filename: ";
                getline(cin, input);
                output = converter.loadFromFile(input);
                cout << "Loaded content:\n" << output << "\n";
                break;
            }
            case 4: {
                cout << "Enter text to save: ";
                getline(cin, input);
                string morse = converter.textToMorse(input);
                cout << "Enter output filename: ";
                getline(cin, output);
                converter.saveToFile(output, morse);
                break;
            }
            case 5:
                cout << "Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
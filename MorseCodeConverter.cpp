// C++ program to convert character into Morse Code using map in STL
#include<iostream>
#include <map>
#include<bits/stdc++.h> 
using namespace std;

int main(){
    string character;
    string firstcharacter;
    string original;

    map<string, string> morseCode;

    morseCode["A"] = ".-"; 
    morseCode["B"] = "-...";
    morseCode["C"] = "-.-.";
    morseCode["D"] = "-..";
    morseCode["E"] = ".";
    morseCode["F"] = "..-.";
    morseCode["G"] = "--.";
    morseCode["H"] = "....";
    morseCode["I"] = "..";
    morseCode["J"] = ".---";
    morseCode["K"] = "-.-";
    morseCode["L"] = ".-..";
    morseCode["M"] = "--";
    morseCode["N"] = "-.";
    morseCode["O"] = "---";
    morseCode["P"] = ".--.";
    morseCode["Q"] = "--.-";
    morseCode["R"] = ".-.";
    morseCode["S"] = "...";
    morseCode["T"] = "-";
    morseCode["U"] = "..-";
    morseCode["V"] = "...-";
    morseCode["W"] = ".--";
    morseCode["X"] = "-..-";
    morseCode["Y"] = "-.--";
    morseCode["Z"] = "--..";
    morseCode["1"] = ".----";
    morseCode["2"] = "..---";
    morseCode["3"] = "...--";
    morseCode["4"] = "....-";
    morseCode["5"] = ".....";
    morseCode["6"] = "-....";
    morseCode["7"] = "--...";
    morseCode["8"] = "---..";
    morseCode["9"] = "----.";
    morseCode["0"] = "-----";
    morseCode["."] = ".-.-.-";
    morseCode[","] = "--..--";
    morseCode["?"] = "..--..";
    morseCode[":"] = "---...";
    morseCode[";"] = "-.-.-.";
    morseCode["-"] = "-....-";
    morseCode["/"] = "-..-.";
    morseCode["\""] = ".-..-."; // \"for "
    morseCode["'"] = ".----.";
    morseCode["("] = "-.--.";
    morseCode[")"] = "-.--.-";
    morseCode["="] = "-...-";
    morseCode["+"] = ".-.-.";
    morseCode["$"] = "...-..-";
    morseCode["_"] = "..--.-";
    morseCode["@"] = ".--.-.";

    cout<<"Enter you character in capital letter (without space): "<<endl;
    cin>>character;
    original = character;
    transform(character.begin(), character.end(), character.begin(), ::toupper); // using STL convert string lower case to upper case
    string morse; // string which store entered character character into morse code 
    string convert=""; // initialize the convert string to empty so that it can append morse code
    map<string, string>::iterator iter; // making the iterator to iterate through the map
    for (int i = 0; i < character.length(); i++) // loop for accessing each element of the character string 
    {
        firstcharacter = character[i]; // store the first (character)element of the string 

        for (iter = morseCode.begin(); iter != morseCode.end(); iter++) // loop for morseCode iterator in map to accaessthe map element first and second
        {
            if (firstcharacter == (*iter).first)// for checking the first  character is equal to map iterator
            {
                morse = (*iter).second; // sgire the firstcharacter corresponding morseCode  
                convert = convert.append(morse); // append morse to the empty string convert
                convert = convert.append(" "); // after each append of a morse character add a space to understand the morseCode
            }
        }
    }

    cout<<"======================================================================================================================================================================================="<<endl;
    cout<<"Your entered character (or group of character) is        : "<<original<<endl;
    cout<<"======================================================================================================================================================================================="<<endl;
    cout<<"Morsecode for your character (or group of character) is  : "<<convert<<endl;
    cout<<"======================================================================================================================================================================================="<<endl;
    

    return 0;
}
#pragma once
#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Tokenizer
{
private:
    string str;
    vector<string> words;

public:
    Tokenizer();                  // it is default instance, is called constructor, it will initialize string empty
    Tokenizer(string a_str);      // Parameterized constructor , it will assign a passing string to tokenizer string
    void clearString();           // it will clear the data from string and assign it to empty.
    void setString(string a_str); // it will set passing string to tokenizer string
    void readWords();             // it will read each word from string separated by space amd store them in words vector.
    vector<int> readIntegers();   // it will read only integers from string, and store them in vector and then return vector
    vector<double> readDoubles(); // it will read only doubles from string, and store them in vector and then return vector
    vector<string> readString();  // it will read only remaining strings from string, and store them in vector and then return vector
    void resetString();           // it will reset string to its orignal value.
};

#endif
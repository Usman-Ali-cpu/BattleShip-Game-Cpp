#pragma once

#include <iostream>
#include <sstream>
#include "Tokenizer.h"
#include <vector>

using namespace std;

Tokenizer::Tokenizer()
{

    str = "";
    words.clear();
}
Tokenizer::Tokenizer(string a_str)
{
    this->str = a_str;
    if (!str.empty())
    {
        string eachword;
        stringstream checktemp(str);
        while (checktemp >> eachword)
            words.push_back(eachword);
    }
}
void Tokenizer::clearString()
{
    str = "";
    words.clear();
}
void Tokenizer::setString(string a_str)
{
    this->str = a_str;
    if (!str.empty())
    {
        string eachword;
        stringstream checktemp(str);
        while (checktemp >> eachword)
            words.push_back(eachword);
    }
}
void Tokenizer::readWords()
{
    if (!str.empty())
    {
        string eachword;
        stringstream checktemp(str);
        while (checktemp >> eachword)
        {
            cout << eachword << endl;
            words.push_back(eachword);
        }
    }
}
vector<int> Tokenizer::readIntegers()
{
    vector<int> integers;
    stringstream ss;
    try
    {
        /* Storing the whole string into string stream */
        ss << str;
        /* Running loop till the end of the stream */
        string temp;
        int found;
        while (!ss.eof())
        {
            /* extracting word by word from stream */
            ss >> temp;
            /* Checking the given word is integer or not */
            if (stringstream(temp) >> found)
            {
                bool check = true;
                for (int i = 0; i < temp.length(); i++)
                {
                    if (temp.at(i) == '.')
                    {
                        check = false;
                    }
                }
                if (check)
                {
                    integers.push_back(found);
                }
            }
            /* To save from space at the end of string */
            temp = "";
        }
    }
    catch (ios_base::failure)
    {
        ss.exceptions(ios::failbit);
        ss.clear();
    }
    return integers;
}
vector<double> Tokenizer::readDoubles()
{
    vector<double> doubles;
    stringstream ss;
    try
    {
        /* Storing the whole string into string stream */
        ss << str;
        /* Running loop till the end of the stream */
        string temp;
        double f;
        while (!ss.eof())
        {
            /* extracting word by word from stream */
            ss >> temp;
            /* Checking the given word is double or not */
            if (stringstream(temp) >> f)
            {
                for (int i = 0; i < temp.length(); i++)
                {
                    if (temp.at(i) == '.')
                    {
                        doubles.push_back(f);
                    }
                }
            }
            /* To save from space at the end of string */
            temp = "";
        }
    }
    catch (ios_base::failure)
    {
        ss.exceptions(ios::failbit);
        ss.clear();
    }
    return doubles;
}
vector<string> Tokenizer::readString()
{
    stringstream ss;
    vector<string> strings;
    try
    {
        /* Storing the whole string into string stream */
        ss << str;
        /* Running loop till the end of the stream */
        string temp;
        double f;
        string found;
        while (!ss.eof())
        {
            /* extracting word by word from stream */
            ss >> temp;
            /* Checking the given word is double or not */
            if (stringstream(temp) >> f)
            {
            }
            else
            {
                found = temp;
                strings.push_back(found);
            }
            /* To save from space at the end of string */
            temp = "";
        }
    }
    catch (ios_base::failure)
    {
        ss.exceptions(ios::failbit);
        ss.clear();
    }
    return strings;
}
void Tokenizer::resetString()
{
    this->str = "";
    for (int i = 0; i < words.size(); i++)
    {
        str += words.at(i) + " ";
    }
}
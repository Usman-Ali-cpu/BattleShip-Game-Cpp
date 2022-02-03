#include "String.h"
#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

String::String(const char *string) //Intialize string by the character array and set the size equal to length
{
    int count = 0;
    for (int i = 0; string[i] != '\0'; i++)
    {
        count++;
    }

    this->string = new char[count + 1];

    for (int i = 0; i < count; i++)
    {
        this->string[i] = string[i];
    }

    this->string[count] = '\0';
    this->size = count;
}

String::String(const String &ref) //Copy Constructor
{
    this->size = ref.size;

    this->string = new char[this->size + 1];

    for (int i = 0; i <= this->size; i++)
    {
        this->string[i] = ref.string[i];
    }
}

String::~String() //Release resources from the string members
{
    delete[] this->string;
    size = 0;
}
void String::print() //Displays the content of the string
{
    for (int i = 0; i < size; i++)
    {
        cout << this->string[i];
    }
}

void String::change(const char *original)
{

    delete[] string;
    size = strlen(original);

    string = new char[size + 1];

    strcpy(string, original);
}

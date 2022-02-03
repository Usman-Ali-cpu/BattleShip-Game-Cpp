#include "String.h"
#include<iostream>
using namespace std;

CString::CString()  //Initialize data and set the size to zero
{
    this->size = 0;
    this->data = new char[size + 1];
    this->data[size] = '\0';
}

CString::CString(char ch) //Initialize data by character and set the size to 2
{
    this->size = 1;
    this->data = new char[2];
    this->data[0] = ch;
    this->data[1] = '\0';
}

CString::CString(const char* string) //Intialize data by the character array and set the size equal to length
{
    int count = 0;
    for (int i = 0; string[i] != '\0'; i++)
    {
        count++;
    }

    this->data = new char[count + 1];

    for (int i = 0; i < count; i++)
    {
        this->data[i] = string[i];
    }

    this->data[count] = '\0';
    this->size = count;

}


CString::CString(const CString& ref) //Copy Constructor
{
    this->size = ref.size;

    this->data = new char[this->size + 1];

    for (int i = 0; i <= this->size; i++)
    {
        this->data[i] = ref.data[i];
    }
}


CString::~CString() //Release resources from the data members
{
    delete[]this->data;
    size = 0;
}

int CString::getSize()
{
    return this->size;
}


void CString::input()
{
    if (this->size == 0)
        resize(10);
    else
        if (getLength() > 0)
            remove(0, getLength());

    cin.getline(data, size);
}



char& CString::at(int index) //Index -> Recieves the index for the string, Return Value -> 
                             //Reference of the aarray location represented by the index
{
    return (this->data[index]);
}

bool CString::isEmpty() //Tells whether the string is empty or not 
{
    if (this->size = 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}



bool CString::isFull()  //Tells whether the string is full or not
{
    if (this->data[this->size] == '\0')
    {
        return true;
    }
    else
    {
        return false;
    }

}


void CString::resize(int newSize) //Resizes the data array to the newSize, sets the size to new value 
{
    char* arr = new char[this->size + 1];
    for (int i = 0; i <= this->size; i++)
    {
        arr[i] = this->data[i];
    }

    delete[]this->data;
    this->data = new char[newSize + 1];

    for (int i = 0; i <= this->size; i++)
    {
        this->data[i] = arr[i];
    }
    this->size = newSize;
    delete[]arr;
}


int CString::getLength()  //Returns the length of the string
{
    int count = 0;
    for (int i = 0; this->data[i] != '\0'; i++)
    {
        count++;
    }

    return count;
}

void CString::display()   //Displays the content of the string
{
    for (int i = 0; i < size; i++)
    {
        cout << this->data[i];
    }
}


int CString::find(CString& subString, int start = 0)  //Find the substring in the calling CString object.
{
    int count = 0;
    int i;
    for (i = start; i < getLength(); i++)
    {
        if (subString[0] == this->data[i])
        {
            count = 0;
            int num = i;
            for (int j = 0; j < subString.getLength(); j++)
            {
                if (subString[j] == this->data[num])
                {
                    count++;
                }
                num++;
            }
            if (count == subString.getLength())
            {
                return i;
            }
        }
    }
    return -1;
}


void CString::insert(int index, CString& subString) //Insert the substring at given index in the calling object
{
    if (index >= 0)
    {
        int newSize = this->size + subString.size;
        char* arr = new char[newSize + 1];
        int j = 0;
        for (int i = 0; i <= this->size; i++)
        {
            if (i == index)
            {
                for (int k = 0; k < subString.size; k++)
                {
                    arr[j] = subString.data[k];
                    j++;
                }
            }
            arr[j] = this->data[i];
            j++;
        }
        delete[]this->data;
        this->data = arr;
        this->size = newSize;
    }

}

void CString::remove(int index, int count = 1)  //Remove the characters starting from index
{
    if (index >= 0 && count >= 0)
    {
        int newSize = (this->size) - count;
        char* arr = new char[newSize + 1];

        int j = 0;
        for (int i = 0; i <= getLength(); i++)
        {
            if (index == i)
            {
                i = i + count;
            }
            arr[j] = this->data[i];
            j++;
        }

        delete[]this->data;
        this->data = new char[newSize + 1];

        for (int i = 0; i <= newSize; i++)
        {
            this->data[i] = arr[i];
        }

        this->size = newSize;
        delete[]arr;
    }

}

int CString::replace(CString& oldString, CString& newString) // Find all the occurences of old substring and  replace it with new substring
{
    int num = 0;
    int count = 0;
    int start = 0;

    while (num != -1)
    {
        num = find(oldString, start);
        start = start + oldString.size;

        if (num != -1)
        {
            remove(num, oldString.size);
            insert(num, newString);
            count++;
        }
    }

    return count;

}

void CString::trimLeft() //Removes all the white spaces to the left of the string.
{
    while (this->data[0] == ' ')
    {
        remove(0, 1);
    }
}


void CString::trimRight()   //Removes all the white spaces to the right of the string.
{
    for (int i = (this->size - 1); this->data[i] == ' '; i--)
    {
        remove(i, 1);
    }

}

void CString::trim()   //Removes all the white spaces to the left and right of the string.
{
    trimLeft();
    trimRight();
}

void CString::makeUpper() //Change all the alphabets to uppercase
{
    for (int i = 0; i < this->size; i++)
    {
        if (this->data[i] >= 'a' && this->data[i] <= 'z')
        {
            this->data[i] = this->data[i] - 32;
        }
    }

}

void CString::makeLower()  //Change all the alphabets to lowercase
{
    for (int i = 0; i < this->size; i++)
    {
        if (this->data[i] >= 'A' && this->data[i] <= 'Z')
        {
            this->data[i] = this->data[i] + 32;
        }
    }
}

void CString::reverse()   //Reverse the string stored in data
{
    char* arr = new char[this->size + 1];
    int j = (this->size - 1);
    for (int i = 0; i < this->size; i++)
    {
        arr[i] = this->data[j];
        j--;
    }
    arr[this->size] = this->data[this->size];

    delete[]this->data;
    this->data = new char[size + 1];

    for (int i = 0; i <= size; i++)
    {
        this->data[i] = arr[i];
    }

    delete[]arr;
}


int CString::compare(CString& newString)//Behaves exactly likes strcmp and compares the calling object to referenced object
{
    int newSize;
    if (this->size > newString.size)
    {
        newSize = this->size;
    }
    else
    {
        newSize = newString.size;
    }

    for (int i = 0; i < newSize; i++)
    {
        if (this->data[i] != newString.data[i])
        {
            return (this->data[i] - newString.data[i]);
        }
    }
    return 0;
}

//Return Values
//  < 0 - > The first character that does not match has a lower value 
//          than the referenced object's character
//    0 - > Both strings are equal
//  > 0 - > The first character that does not match has a greater value 
//          than the referenced object's character

void CString::concatEqual(const CString& s2) //Adds the value from CString s2 to the array of calling object
{
    int newSize = this->size + s2.size;
    int i = this->size;
    resize(newSize);
    for (int j = 0; j <= s2.size; j++)
    {
        this->data[i] = s2.data[j];
        i++;
    }
}


void CString::concatEqual(const char* const s2) //Adds the value from const char * s2 to the array of calling object
{
    int count = 0;
    for (int i = 0; s2[i] != '\0'; i++)
    {
        count++;
    }

    int newSize = this->size + count;
    int i = this->size;
    resize(newSize);
    for (int j = 0; j <= count; j++)
    {
        this->data[i] = s2[j];
        i++;
    }
}


bool CString::isEqual(const CString& s2) // Checks if the passed string is equal to the calling object string or not
{
    int newSize;
    if (this->size > s2.size)
    {
        newSize = this->size;
    }
    else
    {
        newSize = s2.size;
    }

    for (int i = 0; i < newSize; i++)
    {
        if (this->data[i] != s2.data[i])
        {
            return false;
        }
    }
    return true;
}

bool CString::isEqual(const char* const s2) // Checks if the passed string is equal to the calling object string or not
{
    int count = 0;
    for (int i = 0; s2[i] != '\0'; i++)
    {
        count++;
    }
    int newSize;
    if (this->size > count)
    {
        newSize = this->size;
    }
    else
    {
        newSize = count;
    }


    for (int i = 0; i < newSize; i++)
    {
        if (this->data[i] != s2[i])
        {
            return false;
        }
    }
    return true;
}


CString CString::concat(const CString& s2) const // Concatinates the string passed to the value of the calling object in a NEW Cstring
                                                   // and returns the reference to the NEW CString
{
    int newSize = this->size + s2.size;
    CString result(*this);
    result.resize(newSize);
    int i = this->size;
    for (int j = 0; j <= s2.size; j++)
    {
        result.data[i] = s2.data[j];
        i++;
    }
    return result;
}

CString CString::concat(const char* const s2) const  // Concatinates the string passed to the value of the calling object in a NEW Cstring
                                               // and returns the reference to the NEW CString
{
    int count = 0;
    for (int i = 0; s2[i] != '\0'; i++)
    {
        count++;
    }
    int newSize = this->size + count;

    CString result(s2);
    result.resize(newSize);
    int i = this->size;
    for (int j = 0; j <= count; j++)
    {
        result.data[i] = s2[j];
        i++;
    }
    return result;
}

CString& CString::operator = (const CString& ref) // Assignment Operator: Assigns the value of ref to the calling object (this pointer)
{
    this->size = ref.size;
    delete[]this->data;
    this->data = new char[this->size + 1];
    for (int i = 0; i <= this->size; i++)
    {
        this->data[i] = ref.data[i];
    }
    return *this;
}

CString& CString::operator = (const char* ref)// Assignment Operator: Assigns the value of ref to the calling object (this pointer)
{
    int count = 0;
    for (int i = 0; ref[i] != '\0'; i++)
    {
        count++;
    }

    delete[]this->data;
    this->data = new char[count + 1];

    for (int i = 0; i < count; i++)
    {
        this->data[i] = ref[i];
    }

    this->data[count] = '\0';
    this->size = count;

    return *this;
}


char& CString::operator [](const int index)// The array operator returns the character 
                                             //at a specific index in the given CString array.
{
    if (index >= 0 && index < this->size)
        return (this->data[index]);
    else
    {
        cout << "ERROR!Invalid Index." << endl;
        exit(0);
    }
}


void CString::operator +=(const CString& s2)
{
    concatEqual(s2);
}

void CString::operator +=(const char* s2)  //Adds the value from CString s2 to the array of calling object
{
    concatEqual(s2);
}


int CString::operator ==(const CString& s2)// Checks if the passed string is equal to the calling object string or not
{
    return isEqual(s2);
}


int CString::operator ==(const char* s2)// Checks if the passed string is equal to the calling object string or not
{
    return isEqual(s2);
}

CString CString::operator+(const CString& s2) const  // Concatinates the string passed to the value of the calling object in a NEW Cstring
                                                         // and returns the object of the NEW CString
{
    return concat(s2);
}

CString CString::operator+(const char* const s2) const // Concatinates the string passed to the value of the calling object in a NEW Cstring
                                                           // and returns the object of the NEW CString
{
    return concat(s2);
}


CString::operator int()
{
    return this->size;
}


istream& operator >> (istream& in, CString& string)
{
    if (string.size == 0)
    {
        string.resize(20);
    }
    else
        if (string.getLength() > 0)
        {
            string.remove(0, string.getLength());
        }

    in.getline(string.data, string.size);
    return in;
}


ostream& operator << (ostream& out, const CString& string)
{
    for (int i = 0; string.data[i] != '\0'; i++)
    {
        out << string.data[i];
    }

    return out;
}





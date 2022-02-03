#include "ItemType.cpp"
using namespace std;

#ifndef UNSORTEDTYPE_H
#define UNSORTEDTYPE_H

class UnsortedType
{
private:
    ItemType *listData; // Pointer to head of list
    int length;
    int current;

public:
    UnsortedType()
    {
        length = 10;
        listData = new ItemType[length];
        current = 0;
    } // Constructor

    UnsortedType(int size)
    {
        length = size;
        current = 0;
        listData = new ItemType[length];
    }
    ~UnsortedType()
    {
        current = 0;
        length = 0;

    } // Destructor
    void MakeEmpty()
    {
        current = 0;

    } // Returns the list to the empty state
    bool IsFull() const
    {
        if (current >= length)
        {
            return true;
        }
        return false;
    } // Determines whether list is full
    int GetLength() const
    {
        return length;
    } // Determines the number of elements in list

    // Retrieves list element whose key
    // matches item's key (if present)
    void PutItem(ItemType item)
    {
        listData[current] = item;

        current++; // Increment length of list
    }              // Adds item to list

    void ResetList()
    {
        current = 0;
    } // Initializes current position for
      // an iteration through the list
    ItemType GetNextItem(int i)
    {
        i++;
        if (i < length)
        {
            return listData[i];
        }
        else
        {
            return listData[length - 1];
        }
    } // Gets the next element in list
    // Splits a list into two based on the item
    void print()
    {
        for (int i = 0; i < current; i++)
        {
            listData[i].Print();
        }
        cout << endl;
    }
};
#endif

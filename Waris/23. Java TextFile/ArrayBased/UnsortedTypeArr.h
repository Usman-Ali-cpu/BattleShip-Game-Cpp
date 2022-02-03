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
    UnsortedType(); // Constructor
    UnsortedType(int size);
    ~UnsortedType();       // Destructor
    void MakeEmpty();      // Returns the list to the empty state
    bool IsFull() const;   // Determines whether list is full
    int GetLength() const; // Determines the number of elements in list

    // Retrieves list element whose key
    // matches item's key (if present)
    void PutItem(ItemType item); // Adds item to list

    void ResetList();          // Initializes current position for
                               // an iteration through the list
    ItemType GetNextItem(int); // Gets the next element in list
    // Splits a list into two based on the item
    void print();
};
#endif
#include "ItemType.cpp"
using namespace std;

#ifndef UNSORTEDTYPE_H
#define UNSORTEDTYPE_H

class UnsortedType
{
private:
    struct NodeType
    {
        ItemType info;
        NodeType *next;
    };

    NodeType *listData; // Pointer to head of list
    int length;         // # of items (nodes) in list
    NodeType *currentPos;

public:
    UnsortedType();        // Constructor
    ~UnsortedType();       // Destructor
    void MakeEmpty();      // Returns the list to the empty state
    bool IsFull() const;   // Determines whether list is full
    int GetLength() const; // Determines the number of elements in list

    ItemType GetItem(ItemType &item, bool &found);
    // Retrieves list element whose key
    // matches item's key (if present)
    void PutItem(ItemType item);    // Adds item to list
    void DeleteItem(ItemType item); // Deletes element whose key
                                    // matches item's key.

    void ResetList();       // Initializes current position for
                            // an iteration through the list
    ItemType GetNextItem(); // Gets the next element in list
    void SplitList(ItemType item, UnsortedType &list1, UnsortedType &list2);
    // Splits a list into two based on the item
};
#endif
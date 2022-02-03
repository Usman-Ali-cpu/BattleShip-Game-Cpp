#include "UnsortedType.h"
#include <iostream>
using namespace std;

UnsortedType::UnsortedType()
{
    length = 0;
    listData = NULL;
}

//---------------------------------------------
UnsortedType::~UnsortedType()
{
    NodeType *tempPtr;

    // Loop removes all nodes from list
    // deallocating space for each one
    while (listData != NULL)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
}

void UnsortedType::MakeEmpty()
// Post: List is empty
{
    NodeType *tempPtr;

    // Loop removes all nodes from list
    // deallocating space for each one
    while (listData != NULL)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }

    length = 0;
}

bool UnsortedType::IsFull() const
{
    NodeType *location;
    // Try adding a new node, if successful, there
    // is room for more nodes so list is NOT full
    try
    {
        location = new NodeType;
        delete location;
        return false;
    }
    // If adding a new node was unsuccessful,
    // the list is full
    catch (bad_alloc)
    {
        return true;
    }
}

//---------------------------------------------
int UnsortedType::GetLength() const
{
    return length;
}

void UnsortedType::PutItem(ItemType item)
{
    NodeType *location = new NodeType;
    location->info = item;
    location->next = listData;
    listData = location;

    length++; // Increment length of list
}

ItemType UnsortedType::GetItem(ItemType &item, bool &found)
{
    bool moreToSearch;
    NodeType *location;

    location = listData;
    found = false;

    moreToSearch = (location != NULL);

    while (moreToSearch && !found)
    {
        switch (item.ComparedTo(location->info))
        {
        case LESS:
        case GREATER:
            location = location->next;
            moreToSearch = (location != NULL);
            break;
        case EQUAL:
            found = true;
            item = location->info;
            break;
        }
    }
    return item;
}

void UnsortedType::DeleteItem(ItemType item)
{
    NodeType *location;
    NodeType *tempLocation;

    location = listData;

    if (item.ComparedTo(location->info) == EQUAL)
    {
        tempLocation = location;
        listData = listData->next;
    }
    else
    {
        while (!((item.ComparedTo((location->next)->info) == EQUAL)))
            location = location->next;

        tempLocation = location->next;
        location->next = (location->next)->next;
    }

    delete tempLocation;
    length--;
}

void UnsortedType::ResetList()
{
    currentPos = NULL;
}

ItemType UnsortedType::GetNextItem()
{
    if (currentPos == NULL)
        currentPos = listData;
    else
        currentPos = currentPos->next;

    return currentPos->info;
}

//---------------------------------------------
void UnsortedType::SplitList(ItemType item, UnsortedType &list1, UnsortedType &list2)
{
    ItemType location;
    ResetList();
    for (int counter = 1, length = GetLength(); counter <= length; counter++)
    {
        location = GetNextItem();

        switch (location.ComparedTo(item))
        {
        case LESS:
        case EQUAL:
            list1.PutItem(location);
            break;
        case GREATER:
            list2.PutItem(location);
            break;
        };
    };
}
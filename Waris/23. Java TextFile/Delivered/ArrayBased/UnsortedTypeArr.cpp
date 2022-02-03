#include "UnsortedTypeArr.h"
#include <iostream>
using namespace std;

UnsortedType::UnsortedType()
{
    length = 10;
    listData = new ItemType[length];
    current = 0;
}
UnsortedType::UnsortedType(int size)
{
    length = size;
    current = 0;
    listData = new ItemType[length];
}
UnsortedType::~UnsortedType()
{
    current = 0;
    length = 0;
}

void UnsortedType::MakeEmpty()
// Post: List is empty
{
    current = 0;
}

bool UnsortedType::IsFull() const
{
    if (current >= length)
    {
        return true;
    }
    return false;
}

int UnsortedType::GetLength() const
{
    return length;
}
void UnsortedType::PutItem(ItemType item)
{
    listData[current] = item;

    current++; // Increment length of list
}

void UnsortedType::ResetList()
{
    current = 0;
}

ItemType UnsortedType::GetNextItem(int i)
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
}
void UnsortedType::print()
{
    for (int i = 0; i < current; i++)
    {
        listData[i].Print();
    }
    cout << endl;
}
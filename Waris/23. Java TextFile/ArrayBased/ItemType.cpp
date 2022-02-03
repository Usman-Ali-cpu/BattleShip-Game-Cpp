#include <iostream>
#include <string>
#include "ItemType.h"
using namespace std;

//------------------------------
//         ItemType
//     default constructor
//------------------------------
ItemType::ItemType()
{
    value = 0;
}

//------------------------------
//         ComparedTo
// Compares one ItemType object to another.  Returns
//   LESS, if self "comes before" item
//   GREATER, if self "comes after" item
//   EQUAL, if self and item are the same
//------------------------------
RelationType ItemType::ComparedTo(ItemType otherItem) const
{
    if (value < otherItem.value)
        return LESS;
    else if (value > otherItem.value)
        return GREATER;
    else
        return EQUAL;
}

//------------------------------
//         Initialize
//------------------------------
void ItemType::Initialize(int number)
{
    value = number;
}

//------------------------------
//           Print
// Adds ItemType value to output stream
//------------------------------
void ItemType::Print() const
// pre:  out has been opened.
// post: value has been sent to the stream cout.
{
    cout << value << " ";
}
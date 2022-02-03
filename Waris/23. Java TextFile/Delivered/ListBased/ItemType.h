#include <string>
using namespace std;

#ifndef ITEMTYPE_H
#define ITEMTYPE_H

const int MAX_ITEMS = 25;
enum RelationType
{
    LESS,
    GREATER,
    EQUAL
};

class ItemType
{
private:
    int value;

public:
    ItemType()
    {
        value = 0;
    }
    RelationType ComparedTo(ItemType otherItem) const
    {
        if (value < otherItem.value)
            return LESS;
        else if (value > otherItem.value)
            return GREATER;
        else
            return EQUAL;
    }
    void Print() const
    {
        cout << value << " ";
    }
    void Initialize(int number)
    {
        value = number;
    }
};
#endif
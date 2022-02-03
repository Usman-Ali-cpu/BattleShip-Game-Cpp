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
    ItemType();
    RelationType ComparedTo(ItemType) const;
    void Print() const;
    void Initialize(int number);
};
#endif
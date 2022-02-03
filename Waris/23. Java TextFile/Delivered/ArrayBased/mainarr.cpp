#include <iostream>
using namespace std;

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

void SplitLists(UnsortedType list, ItemType item, UnsortedType &list1, UnsortedType &list2)
{

    // Some variables
    ItemType currentItem;
    int length = list.GetLength();

    // First, start at the beginning of list
    list.ResetList();
    // And make sure the two other lists are empty
    list1.MakeEmpty();
    list2.MakeEmpty();
    for (int counter = 0; counter < length; counter++)
    {
        currentItem = list.GetNextItem(counter);

        if (GREATER == currentItem.ComparedTo(item))
            list2.PutItem(currentItem);
        else
            list1.PutItem(currentItem);
    }
}

int main()
{
    UnsortedType list(14);
    int arr[] = {5, -12, 34, 34, 5, 45, 8, -6, 15, 40, 20, 2, 1, 12};
    for (int i = 0; i < 14; i++)
    {
        ItemType item;
        item.Initialize(arr[i]);
        list.PutItem(item);
    }

    ItemType itemsplit;
    itemsplit.Initialize(8);
    UnsortedType split1(14);
    UnsortedType split2(14);
    split1.MakeEmpty();
    split2.MakeEmpty();
    SplitLists(list, itemsplit, split1, split2);
    cout << "First Part : ";
    split1.print();
    cout << "\nSecond Part : ";
    split2.print();

    return 0;
}
#include <iostream>
#include "UnsortedTypeArr.cpp"
using namespace std;

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
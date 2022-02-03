#include <iostream>
#include "UnsortedType.cpp"
using namespace std;

void PrintList(UnsortedType &list)
{
    int length;
    ItemType item;

    list.ResetList();
    length = list.GetLength();
    for (int counter = 1; counter <= length; counter++)
    {
        item = list.GetNextItem();
        bool check;
        ItemType it;
        list.GetItem(it, check);
        if (check)
        {
            cout << endl;
            return;
        }

        item.Print();
        cout << " ";
    }
    return;
}

void SplitList(UnsortedType &list, ItemType item, UnsortedType &list1, UnsortedType &list2)
{
    list.SplitList(item, list1, list2);
}

int main()
{
    UnsortedType list;
    int arr[] = {5, -12, 34, 34, 5, 45, 8, -6, 15, 40, 20, 2, 1, 12};
    for (int i = 0; i < 14; i++)
    {
        ItemType item;
        item.Initialize(arr[i]);
        list.PutItem(item);
    }

    ItemType itemsplit;
    itemsplit.Initialize(8);
    UnsortedType split1;
    UnsortedType split2;
    PrintList(list);
    SplitList(list, itemsplit, split1, split2);
    cout << "\nAfter Spliting \n";
    cout << "\nFirst Part : ";
    PrintList(split1);
    cout << "\nSecond Part : ";
    PrintList(split2);

    return 0;
}
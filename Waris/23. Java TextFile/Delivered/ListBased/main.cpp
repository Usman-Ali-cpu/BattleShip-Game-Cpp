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
    struct NodeType
    {
        ItemType info;
        NodeType *next;
    };

    NodeType *listData; // Pointer to head of list
    int length;         // # of items (nodes) in list
    NodeType *currentPos;

public:
    UnsortedType()
    {
        length = 0;
        listData = NULL;

    } // Constructor
    ~UnsortedType()
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
    } // Destructor
    void MakeEmpty()
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
    } // Returns the list to the empty state
    bool IsFull() const
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
    } // Determines whether list is full
    int GetLength() const
    {
        return length;
    } // Determines the number of elements in list

    ItemType GetItem(ItemType &item, bool &found)
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
    // Retrieves list element whose key
    // matches item's key (if present)
    void PutItem(ItemType item)
    {
        NodeType *location = new NodeType;
        location->info = item;
        location->next = listData;
        listData = location;

        length++; // Increment length of list
    }             // Adds item to list
    void DeleteItem(ItemType item)
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
    } // Deletes element whose key
      // matches item's key.

    void ResetList()
    {
        currentPos = NULL;
    } // Initializes current position for
      // an iteration through the list
    ItemType GetNextItem()
    {
        if (currentPos == NULL)
            currentPos = listData;
        else
            currentPos = currentPos->next;

        return currentPos->info;

    } // Gets the next element in list
    void SplitList(ItemType item, UnsortedType &list1, UnsortedType &list2)
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
    // Splits a list into two based on the item
};

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
    cout << "***************  List based Spliting   ******************" << endl;
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
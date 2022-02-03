#include <iostream>
using namespace std;

class Node
{
public:
    int val;    // the value that this node stores
    Node *next; // a pointer to the next node in the list
                // you can add constructors or other functionality if you find it useful or necessary
};

class Linked_List
{
private:
    unsigned int length; // the number of nodes contained in the list
    Node *MergeDescendingSort(Node *lst1, Node *lst2);
    void SplitList(Node *source, Node **front, Node **back);
    void DescMergeSort(Node **thead);
    void AscMergeSort(Node **thead);
    Node *MergeAscendingSort(Node *lst1, Node *lst2);

public:
    Node *head = NULL; // a pointer to the first node in the list
                       // anything else you need...
    int get_length();
    // note: there is no set_length(unsigned int) (the reasoning should be intuitive)
    void print();                                     // output a list of all integers contained within the list
    void clear();                                     // delete the entire list (remove all nodes and reset length to 0)
    unsigned int push_front(int);                     // insert a new value at the front of the list (returns the new length of the list)
    unsigned int push_back(int);                      // insert a new value at the back of the list (returns the new length of the list)
    unsigned int insert(int val, unsigned int index); // insert a new value in the list at the specified index (returns the new length of the list)
    //void sort_ascending();                            // sort the nodes in ascending order. You must implement the recursive Merge Sort algorithm
    // Note: it's okay if sort_ascending() calls a recursive private function to perform the sorting.
    //void sort_descending();                           // sort the nodes in descending order
    int countPrime();
    // linked list

    void sort_descending();
    void sort_ascending();

    // Merge Sort
};


int main()
{
    Linked_List li;
    while (true)
    {
        int num;
        cout << "Please enter a number: ";
        cin >> num;
        li.push_back(num);

        char ch;
        cout << "Do you want another num(y or n): ";
        cin >> ch;
        while (ch == 'Y' || ch == 'y')
        {
            cout << "Enter a number: ";
            cin >> num;
            li.push_back(num);
            cout << "Do you want another num(y or n): ";
            cin >> ch;
            if (ch == 'N' || ch == 'n')
            {
                break;
            }
        }
        char order;
        getchar();
        cout << "Sort ascending or descending (a or d)? ";
        cin >> order;
        if (order == 'a')
        {
            li.sort_ascending();
        }
        else
        {
            li.sort_descending();
        }
        cout << "Your linked list is: ";
        li.print();

        char end;
        getchar();
        cout << "You have " << li.countPrime() << " prime number(s) in you list." << endl;
        cout << "Do you want to do this again (y or n)? ";
        cin >> end;

        if (end == 'n' || end == 'N')
        {
            return 0;
        }
        li.clear();
        system("cls");
    }

    return 0;
}
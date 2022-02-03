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
    Node *head; // a pointer to the first node in the list
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

int Linked_List::get_length()
{
    length = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        // cout << temp->val << " " << endl;
        temp = temp->next;
        length++;
    }
    return length;
}
void Linked_List::print()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
unsigned int Linked_List::push_front(int val)
{
    if (head == NULL)
    {
        head = new Node();
        head->next = NULL;
        head->val = val;
    }
    else
    {
        Node *temp = new Node();
        temp->next = head;
        temp->val = val;
        head = temp;
    }
    return ++length;
}

void Linked_List::clear()
{
    Node *temp = head;
    while (temp != NULL)
    {
        Node *t = temp;
        temp = temp->next;
        delete t;
    }
    length = 0;
    head = NULL;
}
unsigned int Linked_List::push_back(int val)
{
    if (head == NULL)
    {
        head = new Node();
        head->next = NULL;
        head->val = val;
    }
    else
    {
        Node *temp = new Node();
        temp->val = val;
        Node *t = head;
        while (t->next != NULL)
        {
            t = t->next;
        }
        t->next = temp;
    }
    return ++length;
}
bool isPrime(int val)
{
    bool flag = true;
    for (int i = 2; i <= val / 2; i++)
    {
        if (val % i == 0)
        {
            flag = false;
            break;
        }
    }
    return flag;
}
int Linked_List::countPrime()
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        if (isPrime(temp->val))
        {
            cout << "Prime : " << temp->val << " ";
            count++;
        }
        temp = temp->next;
    }
    cout << "\nPrime number are : " << count;
    cout << endl;
    return count;
}
unsigned int Linked_List::insert(int val, unsigned int index)
{
    if (head == NULL)
    {
        return 0;
    }
    Node *temp = head;
    for (int i = 0; i < index - 1; i++)
    {
        temp = temp->next;
    }
    if (temp == head)
    {
        Node *n = new Node();
        n->val = val;
        n->next = head;
        head = n;
    }
    else if (temp->next == NULL)
    {
        Node *htemp = head;
        while (htemp->next != NULL)
        {
            htemp = htemp->next;
        }
        Node *add = new Node();
        add->val = val;
        add->next = NULL;
        htemp->next = add;
    }
    else
    {
        Node *t = new Node();
        t->val = val;
        t->next = NULL;
        Node *tnext = temp->next;
        temp->next = t;
        t->next = tnext;
    }
    return ++length;
}

Node *Linked_List::MergeDescendingSort(Node *lst1, Node *lst2)
{
    Node *result = NULL;

    // Base Cases
    if (lst1 == NULL)
        return (lst2);
    else if (lst2 == NULL)
        return (lst1);
    // recursively merging two lists
    if (lst1->val > lst2->val)
    {
        result = lst1;
        result->next = MergeDescendingSort(lst1->next, lst2);
    }
    else
    {
        result = lst2;
        result->next = MergeDescendingSort(lst1, lst2->next);
    }
    return result;
}

// Splitting two into halves.
// If the size of the list is odd, then extra element goes in the first list.
void Linked_List::SplitList(Node *source, Node **front, Node **back)
{
    Node *ptr1;
    Node *ptr2;
    ptr2 = source;
    ptr1 = source->next;

    // ptr1 is incrmented twice and ptr2 is icremented once.
    while (ptr1 != NULL)
    {
        ptr1 = ptr1->next;
        if (ptr1 != NULL)
        {
            ptr2 = ptr2->next;
            ptr1 = ptr1->next;
        }
    }

    // ptr2 is at the midpoint.
    *front = source;
    *back = ptr2->next;
    ptr2->next = NULL;
}
void Linked_List::sort_descending()
{
    DescMergeSort(&head);
}

// Merge Sort
void Linked_List::DescMergeSort(Node **thead)
{
    Node *head = *thead;
    Node *ptr1;
    Node *ptr2;

    // Base Case
    if ((head == NULL) || (head->next == NULL))
    {
        return;
    }

    // Splitting list
    SplitList(head, &ptr1, &ptr2);

    // Recursively sorting two lists.
    DescMergeSort(&ptr1);
    DescMergeSort(&ptr2);

    // Sorted List.
    *thead = MergeDescendingSort(ptr1, ptr2);
}

Node *Linked_List::MergeAscendingSort(Node *lst1, Node *lst2)
{
    Node *result = NULL;

    // Base Cases
    if (lst1 == NULL)
        return (lst2);
    else if (lst2 == NULL)
        return (lst1);
    // recursively merging two lists
    if (lst1->val <= lst2->val)
    {
        result = lst1;
        result->next = MergeAscendingSort(lst1->next, lst2);
    }
    else
    {
        result = lst2;
        result->next = MergeAscendingSort(lst1, lst2->next);
    }
    return result;
}

// Splitting two into halves.
// If the size of the list is odd, then extra element goes in the first list.

void Linked_List::sort_ascending()
{
    AscMergeSort(&head);
}

// Merge Sort
void Linked_List::AscMergeSort(Node **thead)
{
    Node *head = *thead;
    Node *ptr1;
    Node *ptr2;

    // Base Case
    if ((head == NULL) || (head->next == NULL))
    {
        return;
    }

    // Splitting list
    SplitList(head, &ptr1, &ptr2);

    // Recursively sorting two lists.
    AscMergeSort(&ptr1);
    AscMergeSort(&ptr2);

    // Sorted List.
    *thead = MergeAscendingSort(ptr1, ptr2);
}

int main()
{
    int num;
    cout << "Please enter a number: ";
    //cin >> num;
    Linked_List li;
    li.push_front(23);
    li.push_front(33);
    li.push_front(24);
    li.sort_ascending();
    li.print();

    // char ch;
    // while (ch == 'Y' || ch == 'y')
    // {
    //     cout << "Enter a number: ";
    //     cin >> num;
    //     li.push_back(num);
    //     cout << "Do you want another num(y or n): ";
    //     cin >> ch;
    // }
    // char order;

    // cout << "Sort ascending or descending (a or d)? ";
    // cin >> order;
    // if (order == 'a')
    // {
    //     li.sort_ascending();
    // }
    // else
    // {
    //     li.sort_descending();
    // }
    // cout << "Your linked list is: ";
    // li.print();

    // cout << "You have " << li.countPrime() << " prime number(s) in you list." << endl;

    return 0;
}
#include "Node.h" //including
#include "Linked_list.h"
#include <iostream>
using namespace std;

int Linked_List::get_length()
{
    // length = 0;
    // Node *temp = head;
    // while (temp != NULL)
    // {
    //     temp = temp->next;
    //     length++;
    // }
    return length;
}
void Linked_List::print()
{
    Node *temp = head; // store head pointer in temp node
    while (temp != NULL)
    {
        cout << temp->val << " "; // print value of node on console
        temp = temp->next;        // point temp to next of temp
    }
    cout << endl;
}
unsigned int Linked_List::push_front(int val)
{
    if (head == NULL) // if list is empty
    {
        length = 1;
        head = new Node(); // allocate new node to head pointer
        head->next = NULL; // point next of head to null
        head->val = val;   // giving value to head node
    }
    else // if list is not empty
    {
        Node *temp = new Node(); // allocate new node to temp pointer
        temp->next = head;       // point next of temp to head
        temp->val = val;         // giving value to temp node
        head = temp;             // make temp node a head node
    }
    return ++length; // increment length and then return
}

void Linked_List::clear()
{
    Node *temp = head;   // allocate new node to temp pointer
    while (temp != NULL) // while not reached at the end of list
    {
        Node *t = temp;    // allocate temp to t pointer
        temp = temp->next; // go to next of temp
        delete t;          // delete previous node
    }
    length = 0;  // reset length of list
    head = NULL; // make head a null;
}
unsigned int Linked_List::push_back(int val)
{
    if (head == NULL) // if list is empty
    {
        length = 1;        // as adding node to empty list so length is 1
        head = new Node(); // allocate new node to head pointer
        head->next = NULL; // point next of head to null
        head->val = val;   // assiging value to head node
    }
    else // if list is not already empty
    {
        Node *temp = new Node(); // allocate new node to temp pointer
        temp->val = val;         // giving value to temp node
        Node *t = head;          // allocate new node to t pointer
        while (t->next != NULL)  // while not reached at the end of list
        {
            t = t->next; // go to next of t
        }
        t->next = temp; // point temp node at last node
    }
    return ++length; // increment length and return it
}
bool isPrime(int n)
{
    bool isPrime = true;
    if (n < 0)
    {
        return false;
    }

    // 0 and 1 are not prime numbers
    if (n == 0 || n == 1)
    {
        isPrime = false;
    }
    else
    {
        for (int i = 2; i <= n - 1; ++i)
        {
            if (n % i == 0)
            {
                isPrime = false;
                break;
            }
        }
    }
    return isPrime;
}

int Linked_List::countPrime()
{
    Node *temp = head; // store head pointer in temp node
    int count = 0;     // for counting prime initialized counter
    while (temp != NULL)
    {
        if (isPrime(temp->val)) // check is value is prime
        {
            count++; // increment count if value
        }
        temp = temp->next; // point temp to next of temp
    }
    return count; // return counter
}

unsigned int Linked_List::insert(int val, unsigned int index)
{
    if (head == NULL) // if list is empty
    {
        return 0; // return 0
    }
    Node *temp = head;                  // point temp to  head
    for (int i = 0; i < index - 1; i++) // loop for given index
    {
        temp = temp->next; // point temp to next node of temp
    }
    // here we get temp node which is node on specific index
    if (temp == head) // if temp node is a head node
    {
        Node *n = new Node(); // allocate new memory to that node
        n->val = val;         // assign value to val of node
        n->next = head;       // point next of a node to head
        head = n;             // make that new node head
    }
    else if (temp->next == NULL) // if next of temp is null
    {
        Node *htemp = head;         // allocate a new node from head node
        while (htemp->next != NULL) // while reach at thr end
        {
            htemp = htemp->next; // go to next node
        }
        Node *add = new Node(); // allocate new node which we have to add
        add->val = val;         // giving value to node
        add->next = NULL;       // point next of add node to null
        htemp->next = add;
    }
    else // if node is in mid between of the list
    {

        Node *t = new Node();     // allocate a new node
        t->val = val;             // giving value to node
        t->next = NULL;           // making next of that node null
        Node *tnext = temp->next; // making a new node to save next of temp, becuase we are going to point next to new node
        temp->next = t;           // point next of temp to new node
        t->next = tnext;          // and then next of t to previous node
    }
    return ++length; // first increment the length and then return it.
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

// extra credit for selection sort

void Linked_List::swapNodes(Node **head_ref, Node *currX,
                            Node *currY, Node *prevY)
{
    // make 'currY' as new head
    *head_ref = currY;

    // adjust links
    prevY->next = currX;

    // Swap next pointers
    Node *temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
}

// function to sort the linked list using
// recursive selection sort technique
Node *Linked_List::recurSelectionSort(Node *head)
{
    // if there is only a single node
    if (head->next == NULL)
        return head;

    // 'min' - pointer to store the node having
    // minimum data value
    Node *min = head;

    // 'beforeMin' - pointer to store node previous
    // to 'min' node
    Node *beforeMin = NULL;
    Node *ptr;

    // traverse the list till the last node
    for (ptr = head; ptr->next != NULL; ptr = ptr->next)
    {

        // if true, then update 'min' and 'beforeMin'
        if (ptr->next->val > min->val)
        {
            min = ptr->next;
            beforeMin = ptr;
        }
    }

    // if 'min' and 'head' are not same,
    // swap the head node with the 'min' node
    if (min != head)
        swapNodes(&head, head, min, beforeMin);

    // recursively sort the remaining list
    head->next = recurSelectionSort(head->next);

    return head;
}

// function to sort the given linked list
void Linked_List::sort(Node **head_ref)
{
    // if list is empty
    if ((*head_ref) == NULL)
        return;

    // sort the list using recursive selection
    // sort technique
    *head_ref = recurSelectionSort(*head_ref);
}
void Linked_List::SelectionDescendingSort()
{
    Node *temp = head;
    sort(&temp);
}

Linked_List::~Linked_List()
{
    Node *temp = head;
    while (temp != NULL)
    {
        Node *t = temp;
        temp = temp->next;
        delete t;
    }
    head = NULL;
}
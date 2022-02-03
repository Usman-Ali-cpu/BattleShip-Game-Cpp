#include <iostream>
#include "IntList.h"
using namespace std;

IntNode::IntNode()
{
    next = NULL;
}
IntNode::IntNode(int x)
{
    this->x = x;
    next = NULL;
}

IntList::IntList()
{
    head = NULL;
    tail = NULL;
}
IntList::~IntList()
{
    IntNode *t = head;
    while (t != NULL)
    {
        IntNode *d = t;
        t = t->next;
        delete d;
    }
    head = NULL;
    tail = NULL;
}
void IntList::display() const
{
    IntNode *t = head;
    if (t != NULL)
    {
        cout << t->x;
        t = t->next;
    }

    while (t != NULL)
    {
        cout << " " << t->x;
        t = t->next;
    }
} //  Displays to a single line all of the int values stored in the list, each separated by a space. This function does NOT output a newline or space at the end.
void IntList::push_front(int value)
{
    if (head == NULL)
    {
        head = new IntNode(value);
        tail = head;
    }
    else
    {
        IntNode *temp = new IntNode(value);
        temp->next = head;
        head = temp;
    }
} //  Inserts a data value (within a new node) at the front end of the list.
void IntList::pop_front()
{
    if (head == NULL)
    {
        return;
    }
    else
    {
        IntNode *d = head;
        IntNode *t = head->next;
        head = t;
        delete d;
    }
} // Removes the value (actually removes the node that contains the value) at the front end of the list. Does nothing if the list is already empty.
bool IntList::empty() const
{
    if (head == NULL || tail == NULL)
    {
        return true;
    }
    return false;
} // Returns true if the list does not store any data values (does not have any nodes), otherwise returns false.
void IntList::push_back(int value)
{
    if (head == NULL)
    {
        head = new IntNode(value);
        tail = head;
    }
    else
    {
        IntNode *temp = new IntNode(value);
        IntNode *t = head;
        while (t->next != NULL)
        {
            t = t->next;
        }
        t->next = temp;
    }

} // Inserts a data value (within a new node) at the back end of the list.
void IntList::clear()
{
    IntNode *t = head;
    while (t != NULL)
    {
        IntNode *d = t;
        t = t->next;
        delete d;
    }
    head = NULL;
    tail = NULL;

} //  Removes (deallocates) all IntNodes in the IntList. Don't forget to set both head and tail to appropriate values for an empty list.
IntList::IntList(const IntList &cpy)
{
    if (cpy.head == NULL)
    {
        head = NULL;
    }
    else
    {
        head = new IntNode(cpy.head->x);
        IntNode *current = head;
        IntNode *objHead = cpy.head;
        IntNode *currentObj = objHead;
        while (currentObj->next != NULL)
        {
            current->next = new IntNode(currentObj->next->x);
            currentObj = currentObj->next;
            current = current->next;
        }
    }
} // the copy constructor. Make sure this performs deep copy.
IntList &IntList::operator=(const IntList &rhs)
{

    if (this == &rhs)
    {
        return *this;
    }
    if (rhs.head == NULL)
    {
        head = NULL;
    }
    else
    {

        head = new IntNode(rhs.head->x);
        IntNode *current = head;
        IntNode *objHead = rhs.head;
        IntNode *currentObj = objHead;
        while (currentObj->next != NULL)
        {
            current->next = new IntNode(currentObj->next->x);
            currentObj = currentObj->next;
            current = current->next;
        }
    }
    return *this;
} // the overloaded assignment operator. Make sure this performs deep copy.
void IntList::insert_ordered(int value)
{

    IntNode *current;
    /* Special case for the head end */
    if (head == NULL || head->x >= value)
    {
        IntNode *newNode = new IntNode(value);
        newNode->next = head;
        head = newNode;
    }
    else
    {
        /* Locate the node before the
 point of insertion */
        current = head;
        IntNode *newNode = new IntNode(value);
        while (current->next != NULL && current->next->x < newNode->x)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    // ************* ??
}
// Inserts a data value (within a new node) in an ordered list. Assumes the list is already sorted in ascending order (i.e., Do not sort the list first, assume the list is already is sorted.) This function loops through the list until if finds the correct position for the new data value and then inserts the new IntNode in that location. This function may NOT ever sort the list.
void IntList::remove_duplicates()
{
    IntNode *ptr1, *ptr2, *dup;
    ptr1 = head;
    /* Pick elements one by one */
    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;

        while (ptr2->next != NULL)
        {
            /* If duplicate then delete it */
            if (ptr1->x == ptr2->next->x)
            {
                /* sequence of steps is important here */
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete (dup);
            }
            else /* This is tricky */
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }

} //  Removes all duplicate data values (actually removes the nodes that contain the values) within the list. Always remove just the later value within the list when a duplicate is found. This function may NOT ever sort the list

ostream &operator<<(ostream &out, const IntList &rhs)
{
    IntNode *t = rhs.head;
    if (t != NULL)
    {
        out << t->x;
        t = t->next;
    }

    while (t != NULL)
    {
        out << " " << t->x;
        t = t->next;
    }

    return out;
}
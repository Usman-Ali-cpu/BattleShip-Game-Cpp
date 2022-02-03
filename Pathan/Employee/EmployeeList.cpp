#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
    T x;
    Node *next;
    Node(T n)
    {
        x = n;
        next = NULL;
    }
    Node()
    {
        x = 0;
        next = NULL;
    }
};

template <class T>

class EmployeeList
{
private:
    Node<T> *head;

public:
    EmployeeList()
    {
        head = NULL;
    }
    // EmployeeList(EmployeeList<T> &copy)
    // {
    //     head = new Node(copy.head->x);
    //     Node *<T> current = head;
    //     Node *<T> copyCurrent = copy.head;
    //     while (copyCurrent->next != NULL)
    //     {
    //         current->next = new Node(copyCurrent->next->x);
    //         copyCurrent = copyCurrent->next;
    //         current = current->next;
    //     }
    // }
    // EmployeeList &operator=(EmployeeList &copy)
    // {
    //     head = new Node(copy.head->x);
    //     Node *current = head;
    //     Node *currentCopy = copy.head;
    //     while (currentCopy->next != NULL)
    //     {
    //         current->next = new Node(currentCopy->next->x);
    //         current = current->next;
    //         currentCopy = currentCopy->next;
    //     }
    //     return *this;
    // }

    void insertEnd(T val)
    {
        if (head == NULL)
        {
            head = new Node<T>(val);
        }
        else
        {
            Node<T> *temp = new Node<T>(val);
            Node<T> *t = head;
            while (t->next != NULL)
            {
                t = t->next;
            }
            t->next = temp;
        }
    }
    void insertHead(T val)
    {
        if (head == NULL)
        {
            head = new Node<T>(val);
        }
        else
        {
            Node<T> *temp = new Node<T>(val);
            temp->next = head;
            head = temp;
        }
    }
    void insertAt(int n, int val)
    {
        if (head == NULL)
        {
            return;
        }
        Node<T> *temp = head;
        for (int i = 0; i < n - 1; i++)
        {
            temp = temp->next;
        }
        if (temp == head)
        {
            // insertHead(val);
            Node<T> *n = new Node<T>(val);
            n->next = head;
            head = n;
        }
        else if (temp->next == NULL)
        {
            // insertEnd(val);
            Node<T> *htemp = head;
            while (htemp->next != NULL)
            {
                htemp = htemp->next;
            }
            htemp->next = new Node<T>(val);
        }
        else
        {
            Node<T> *t = new Node<T>(val);
            Node<T> *tnext = temp->next;
            temp->next = t;
            t->next = tnext;
        }
    }
    void getIndex(int id)
    {
        Node<T> *temp = head;
        if (temp != NULL)
        {
            cout << endl;
            temp->x.print();
        }
        int count = 0;
        while (temp->next != NULL)
        {
            cout << temp->x.ID << endl;
            if (temp->x.ID == id)
            {
                temp->x.print();
                return;
            }
            temp = temp->next;
            count++;
        }
        cout << "Employee ID does not found " << endl;
        return;
    }
    void swap(int &a, int &b)
    {
        int t = a;
        a = b;
        b = t;
    }
    int getsize()
    {
        Node<T> *t = head;
        int s = 0;
        while (t != NULL)
        {
            t = t->next;
            s++;
        }
        return s;
    }
    void sort()
    {
        Node<T> *out = head;
        for (int i = 0; i < getsize(); i++)
        {
            Node<T> *in = out;
            for (int j = i; j < getsize(); j++)
            {
                if (in->x < out->x)
                {
                    swap(in->x, out->x);
                }
                in = in->next;
            }
            out = out->next;
        }
    }
    void removeAt(int n)
    {
        if (head == NULL)
        {
            return;
        }
        else
        {
            Node<T> *temp = head;
            Node<T> *previous = NULL;
            for (int i = 0; i < n - 1; i++)
            {
                previous = temp;
                temp = temp->next;
            }
            if (temp == head)
            {
                Node<T> *d = head;
                Node<T> *t = head->next;
                head = t;
                delete d;
            }
            else if (temp->next == NULL)
            {
                temp = NULL;
            }
            else
            {
                previous->next = temp->next;
                delete temp;
            }
        }
    }
    void removeEnd()
    {
        if (head == NULL)
        {
            return;
        }
        else if (head->next == NULL)
        {
            head = NULL;
        }
        else
        {
            Node<T> *t = head;
            while (t->next->next != NULL)
            {
                t = t->next;
            }
            t->next = NULL;
        }
    }
    void removeHead()
    {
        if (head == NULL)
        {
            return;
        }
        else
        {
            Node<T> *d = head;
            Node<T> *t = head->next;
            head = t;
            delete d;
        }
    }
    void print()
    {
        Node<T> *t = head;
        cout << "Data: ";
        int i = 1;
        while (t != NULL)
        {
            cout << i << " ";
            t->x.print();
            t = t->next;
        }
        cout << endl;
    }
    ~EmployeeList()
    {
        Node<T> *t = head;
        while (t != NULL)
        {
            Node<T> *d = t;
            t = t->next;
            delete d;
        }
        head = NULL;
    }
};

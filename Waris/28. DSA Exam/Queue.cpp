#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
    T x;
    Node<T> *next;
    Node(T val)
    {
        x = val;
        next = NULL;
    }
    Node() { next = NULL; }
};

template <class T>
class Queue
{
public:
    Node<T> *front, *rear;
    Queue()
    {
        front = rear = NULL;
    }
    Queue(Queue &obj)
    {
    }
    bool operator==(Queue obj)
    {
        Node<T> *temp = front;
        while (temp != NULL)
        {

            return false;
            temp = temp->next;
        }
        return true;
    }

    void push(T val)
    {
        Node<T> *temp = new Node<T>(val);
        if (temp != NULL)
        {
            if (front == NULL && rear == NULL)
            {
                front = rear = temp;
            }
            else
            {
                rear->next = temp;
                rear = rear->next;
            }
        }
    }
    bool isEmpty()
    {
        return front == NULL ? true : false;
    }

    T pop()
    {
        T x;
        if (rear == NULL && front == NULL)
        {
            return x;
        }
        if (front == rear)
        {
            x = front->x;
            Node<T> *temp = front;
            front = NULL;
            rear = NULL;
            delete temp;
        }
        else
        {
            x = front->x;
            Node<T> *temp = front;
            front = front->next;
            delete temp;
        }
        return x;
    }

    void clear()
    {
        Node<T> *temp = front;
        while (temp != NULL)
        {
            Node<T> *t = temp;
            temp = temp->next;
            delete t;
        }
        front = NULL;
        rear = NULL;
    }
    void print()
    {
        Node<T> *t = front;
        cout << "Data: ";
        while (t != NULL)
        {
            cout << t->x << " ";
            t = t->next;
        }
        cout << endl;
    }
    int size()
    {
        int i = 0;
        Node<T> *t = front;
        while (t != NULL)
        {
            i++;
            t = t->next;
        }
        return i;
    }

    ~Queue()
    {
        Node<T> *temp = front;
        while (temp != NULL)
        {
            Node<T> *t = temp;
            temp = temp->next;
            delete t;
        }
        front = NULL;
        rear = NULL;
    }
};
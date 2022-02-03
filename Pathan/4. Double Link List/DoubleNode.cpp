
template <typename T>
class Node
{
private:
    T data;
    Node<T> *next;
    Node<T> *prev;
    template <typename U>
    friend class LinkedList;

public:
    Node()
    {
        this->next = NULL;
        this->prev = NULL;
    }
};
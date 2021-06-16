#include <iostream>
using namespace std;

/*
An operation that displays the contents of a stack can be useful during program debugging. Add a display
method to the ADT stack such that
a. The method uses only ADT stack operations; that is, it is independent of the stack’s implementation.
b. The method assumes and uses the link-based implementation of the ADT stack.
c. The method assumes and uses the array-based implementation of the ADT stack.


(b):
    At line 115- 121
    void display(){
        Node *temp = head;
        while(temp != NULL){
            cout << temp->x << endl;
            temp = temp->next;
        }
    }


*/
template <class T>
class Node {
public:
    T x;  // data of node 
    Node *next; // pointer to point next node 
    Node(T x){ // parameterize constructor 
        this->x = x;
        next = NULL;
    }
    Node (){ // defualt constructor 
        next = NULL;
    }
};

template <class T>
class Stack{
    Node<T> *head; // Node to point first node 
    int top;  // top of stack 
public:
    Stack(){    // defualt constructor 
        top = -1;
        head = NULL;
    }
    void push(int val){ // insert value in stack
        if(head== NULL){ // if stack has no entry before 
            head = new Node<T>(val);   // made a new node as head node 
            top = 0;
        }
        else {  // if stack has already entries in it 
            Node<T> *temp = head;  // get head pointer in temp node
            while(temp->next != NULL){  // while don't reach last node 
                temp = temp->next;  // temp point to next node 
            }
            temp->next = new Node<T>(val); // add node at the last
            ++top; 
        }
    }
    int pop(){
        Node<T> *temp = head; //  get head pointer in temp node
        int x;
        if(temp== NULL){ // if stack has no entry 
            return -2234;
        }
        if(head->next == NULL){ // if stack has only one entry 
            x = temp->x;  // get value of that node in x 
            head = NULL;  // empty the stack
            top = -1;
            return x;
        }
            while(temp->next->next != NULL){ // while reach last entry 
                temp = temp->next; //  temp point to next node 
            }
            x = temp->next->x; // get value of last node 
            temp->next = NULL; // by this we lost one last node 
            return x;
        top--;
    }
    int peek(){
        Node<T> *temp = head;  // point head node to temp 
        int x;
        if(head== NULL){  // if stack is empty (even does not has one entry)
            throw "Stack has no peek1";  // throw exception 
        }
        while (temp->next != NULL)  //  while reach last node entry 
        {
            temp = temp->next; //  temp point to next node 
        }
        x = temp->x; // get value of last node 
        return x;
    }
    int peek2(){
        Node <T>*temp = head; // point head node to temp 
        int x;
        if(head== NULL){  // if stack is empty (even does not has one entry)
            throw "Stack has no peek2";  // throw exception 
        }
        else if(head->next == NULL){  // if stack has one (even does not has one entry)
            throw "Stack has no peek2";   // throw exception 
        }
        while (temp->next->next != NULL) // while reach second last node 
        {
            temp = temp->next;   //  temp point to next node 
        }
        x = temp->x; 
        return x;
    }
    bool isEmpty(){
        return head == NULL;  // return true if head is not NULL 
    }

    // b. The method assumes and uses the link-based implementation of the ADT stack.
    void display(){
        Node<T> *temp = head;  // point to first node 
        while(temp != NULL){  // loop while reach last node 
            cout << temp->x << endl;  // print value of node 
            temp = temp->next;  // point to next node 
        }
    }
    ~Stack(){
        Node<T> *temp = head;   // point head node to temp 
        while(temp!= NULL){   //  while reach last node entry 
            Node<T> *t = temp;  // get current temp node in t
            temp = temp->next;  // point to next node 
            delete t;  // delete previous node 
        }
        head = NULL; // empty the stack 
    }

};


int main(){
    Stack <int> st;
    st.push(2);
    st.push(1);
    st.push(5);
    st.push(4);
    // Here you can check it is working with linked based stack and it is dependent of 
    // type of stack.
    st.display();

    return 0;
}

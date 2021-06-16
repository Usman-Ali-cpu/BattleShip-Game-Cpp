#include <iostream>
using namespace std;


/*

EXERSICE-11:
Although we do not usually throw our own exception when a method or constructor in LinkedStack fails to
allocate a new node, you could do so. Defi ne the exception MemoryAllocationException , and revise the copy
constructor of LinkedStack so that it throws a MemoryAllocationException when the new operator fails to
allocate memory. Throwing exceptions from constructors requires great care, since you must be sure to properly
deallocate any memory allocated by the constructor before throwing the exception

ANSWER: 
    Line 75- 103
    Stack& copy(const Stack<T> copy){    // copy constructor 
        if(copy.head== NULL){ // if given stack is empty 
            head = NULL;
        }
        else {
            // memory allocation exception 
            try{
                this->head = new Node <T>(copy.head->x);  // new allocation to head
            }
            catch(const std::bad_alloc& e){
                std::cerr<< "Memory Allocation error occured "<< e.what() << '\n';
            }
            Node<T> *current = head;    // current node of this
            Node<T> *copyHead = copy.head; // to store head of copy 
            Node<T> *currentCopy = copyHead; // currentCopy node 
            while(currentCopy->next != NULL){ // while current node don't reach to last node 
                // memory allocation execption 
                try{
                    current->next = new Node <T>(currentCopy->next->value); // give new node to next of current 
                }
                catch(const std::bad_alloc& e){
                    std::cerr <<"Memory Allocation error occured "<< e.what() << '\n';
                }
                currentCopy = currentCopy->next;  // point to next node currentCopy
                current = current->next;    // point to next node current copy
            }
        }
        return *this;
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
    Stack& copy(const Stack<T> copy){    // copy constructor 
        if(copy.head== NULL){ // if given stack is empty 
            head = NULL;
        }
        else {
            // memory allocation exception 
            try{
                this->head = new Node <T>(copy.head->x);  // new allocation to head
            }
            catch(const std::bad_alloc& e){
                std::cerr<< "Memory Allocation error occured "<< e.what() << '\n';
            }
            Node<T> *current = head;    // current node of this
            Node<T> *copyHead = copy.head; // to store head of copy 
            Node<T> *currentCopy = copyHead; // currentCopy node 
            while(currentCopy->next != NULL){ // while current node don't reach to last node 
                // memory allocation execption 
                try{
                    current->next = new Node <T>(currentCopy->next->value); // give new node to next of current 
                }
                catch(const std::bad_alloc& e){
                    std::cerr <<"Memory Allocation error occured "<< e.what() << '\n';
                }
                currentCopy = currentCopy->next;  // point to next node currentCopy
                current = current->next;    // point to next node current copy
            }
        }
        return *this;
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
    void show(){
        Node <T>*temp = head;   // point head node to temp 
        while(temp != NULL){   // loop through all node 
            cout << temp->x << endl; // print value of node 
            temp = temp->next;  //   temp point to next node 
        }
    }
    void removeEnteries(int n){
        // we will pop n time, it will remove last n entries from stack 
        for (int i = 0; i < n; i++){
            this->pop(); 
        }
    }


    
    // The destructor given for the link-based implementation of the ADT stack calls pop .
    //  Although easy to write, this destructor can be ineffi cient due to repeated method calls. 
    // Write another implementation for the destructor that
    // deallocates the linked nodes directly without calling pop ?
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
    Stack<int> st;
    st.push(2);
    st.push(1);
    st.push(5);
    st.push(4);
    Stack<int> s = st;
    s.show();
    // cout << st.pop() << endl;
    // cout << st.pop()<< endl;
    // cout << st.pop()<< endl;
    // cout << st.peek()<< endl;
    // cout << st.pop()<< endl;

    return 0;
}

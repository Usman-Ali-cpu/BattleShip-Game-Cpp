#ifndef VECTOR_CPP  // check if vector is not define 
#define VECTOR_CPP  // define vector 
 
#include <fstream> // for file handling 
#include <iostream> // for input and output 
#include <string> 
#include <cmath>// library for mathematical functions
using namespace std;




template <class T> // templating class 
struct Node {
public:
Node(T value) {
    m_value = value;
    next = NULL;
}
Node(T value, Node* _next) {
    m_value = value;
    next = _next;
}
T getValue() {
    return m_value;
}
void setValue(T x) {
    m_value  = x;
}
T* getrefValue() {
    return &m_value;
}
Node* getNextNode() {
    return next;
}
void setNextNode(Node* newNode) {
    next = newNode;
}
private:
    T m_value;
    Node<T>* next;
};



template <class T> // templating class vector 
class Vector {
      
private:
    Node<T>* m_head; // private member Node to pointing head 

public:
  // Name: Default Constructor
  // Precondition: None (Must be templated)
  // Postcondition: Creates a vector using a linked list
Vector(){
    m_head = NULL;
}
   
  // Name: Destructor
  // Desc: Frees memory
  // Precondition: Existing Vector
  // Postcondition: Destructs existing Vector
~Vector(){
    Node<T> *temp = this->m_head;
    while(temp != NULL){ // while end of list 
        Node<T> *t = temp; // create node to delete 
        temp = temp->getNextNode(); // point to next node 
        free(t);  // delete node 
    }
    m_head = NULL; 
    delete m_head; // delete head 
} 

  // Name: Copy Constructor
  // Desc: Copies an existing vector
  // Precondition: Existing Vector
  // Postcondition: Two identical vectors (in separate memory spaces)
  // Hint: Utilize overloaded [] operator
Vector (Vector<T>& source){
    if(source.m_head == NULL){ // if source is empty 
        this->m_head = NULL; // null the head 
    }
    else 
    {
        m_head = new Node<T>(source.m_head->getValue()); // assigning sourceHead to this head 
        Node<T> *current = m_head; // Node for traversal
        Node<T> *sourceHead = source.m_head;
        Node<T> *currentSource = sourceHead;
        while(currentSource->getNextNode() != NULL){ // while not reach end of source list 
            Node<T>*t = new Node<T>(currentSource->getNextNode()->getValue());  // getting value from source 
            current->setNextNode(t);
            currentSource = currentSource->getNextNode();
            current = current->getNextNode();
        }
    }
}
  
  // Name: Overloaded Assignment operator
  // Desc: Assingns a vector
  // Precondition: Existing Vector
  // Postcondition: Assigns a vector
  // Hint: Utilize overloaded [] operator
Vector<T>* operator=(Vector<T>* source){
    if(source->m_head == NULL){ // if source is empty 
        this->m_head = NULL; // null the head
    }
    else 
    {
        m_head = new Node<T>(source->m_head->getValue()); // assigning sourceHead to this head 
        Node<T> *current = m_head;  // Node for traversal
        Node<T> *sourceHead = source->m_head;
        Node<T> *currentSource = sourceHead;
        while(currentSource->getNextNode() != NULL){ // while not reach end of source list 
            Node<T> *t = new Node<T>(currentSource->getNextNode()->getValue()); // getting value from source 
            current->setNextNode(t);
            currentSource = currentSource->getNextNode();
            current = current->getNextNode();
        }
    }
    return this;
} 
  
  // Name: Overloaded [] operator
  // Desc: to retrive use [indx]
  // Precondition: Existing Vector
  // Postcondition: Returns the value of the element at the given index
T operator[](int indx){
    Node<T> *temp = m_head; // getting head node in temp
    Node<T> *previous = NULL; // for travesal 
    for (int i = 0; i < indx; i++){
        previous = temp;
        temp = temp->getNextNode(); // pointing to next node 
    }
    return temp->getrefValue(); // returning value of node 
}
    
  // Name: Insert
  // Desc: insert a node to the end of the vector
  // Precondition: Existing Vector
  // Postcondition: A vector with the newly added value
void Insert(T x){
    if(m_head == NULL){ // if vector is empty 
       m_head = new Node<T>(x); // add node to head 
    }
    else {
        Node<T> *temp = m_head; // node pointing to head 
        while(temp->getNextNode() != NULL){ // while reaching next node 
            temp = temp->getNextNode(); // point to next node 
        }
        Node<T>*t = new Node<T>(x); 
        temp->setNextNode(t); // add node to last 
    }
}
    
  // Name: SortedInsert
  // Desc: Inserts a node into the vector at it's correct position (sorted ascendingly)
  // Precondition: Existing Vector
  // Postcondition: sorted vector (low to high)
void SortedInsert(T x){
    Node<T>*insertNode = new Node<T>(x);
    Node <T>*temp;
    if(m_head == NULL || m_head->getValue() >= insertNode->getValue()){
        insertNode->setNextNode(m_head);
        m_head = insertNode;
    }
    else 
    {
        temp = m_head;
        while(temp->getNextNode() != NULL && temp->getNextNode()->getValue() < insertNode->getValue()){
            temp = temp->getNextNode();
        }
        insertNode->setNextNode(temp->getNextNode());
        temp->setNextNode(insertNode);
    }
}
      
  // Name: Remove
  // Desc: removes a node from the vector
  // Precondition: Existing Vector
  // Postcondition: A vector that holds the results of the vectors added
void Remove(int indx){
    Node<T>*temp = m_head;
    Node<T>*previous = NULL;
    for (int i = 0; i < indx; i++){
        previous = temp;
        temp = temp->getNextNode();
    }
    if(temp== m_head){
        Node<T>*temp = m_head;
        m_head = m_head->getNextNode();
        delete temp;
    }else {
        int x = temp->getValue();
        previous->setNextNode(temp->getNextNode());
        delete temp;
    }
}
    
  // Name: Overloaded + operator | Vector Addition
  // Desc: Adds two vectors and returns the result
  // Precondition: Existing Vector, vectors can be of different size
  // Postcondition: A vector that holds the results of the vectors added
Vector<T>* operator+(Vector<T>& source){
    Node<T> *thistemp = m_head;
    Node <T>*sourcetemp = source.m_head;
    while(thistemp != NULL && sourcetemp != NULL){
        int i = 0,j = 0;
        if(thistemp != NULL){
            i = thistemp->getValue();
        }
        if(sourcetemp != NULL){
            j = sourcetemp->getValue();
        }
        thistemp->setValue(i + j);

        thistemp = thistemp->getNextNode();
        sourcetemp = sourcetemp->getNextNode();
    }  
    return this;
}
    
  // Name: Overloaded * operator | Vector Multiplication
  // Desc: Multiplys two vectors and returns the result
  // Precondition: Existing Vector, vectors can be of different size
  // Postcondition: returns a vector that holds the results of the vectors multiplied
Vector<T>* operator*(Vector<T>& other){
    Node<T> *thistemp = m_head;
    Node<T> *othertemp = other.m_head;
    while(thistemp != NULL && othertemp != NULL){
        int i = 1,j = 1;
        if(thistemp != NULL){
            i = thistemp->getValue();
        }
        if(othertemp != NULL){
            j = othertemp->getValue();
        }
        thistemp->setValue(i * j);

        thistemp = thistemp->getNextNode();
        othertemp = othertemp->getNextNode();
    }  
    return this;
}
    
  // Name: Overloaded < operator | Vector Comparision
  // Desc: Compares two vectors [using the < operator] and returns the result
  // Precondition: Existing Vector -> vectors need to be of the same size
  // Postcondition: returns a vector that holds the boolean char (T or F) value of each node comparison
Vector<char>* operator<(Vector<T>& other){
    Vector<char> v;
    if(this->Size() == other.Size())
    {
        Node<T> *temp = m_head;
        Node<T> *t = other.m_head;
        while(temp != NULL){
            if(t->getValue() < temp->getValue()){
                v.Insert('T');
            }
            else {
                v.Insert('F');
            }
            temp = temp->getNextNode();
            t = t->getNextNode();
        }
    }
    return v;
}
      
  // Name: Overloaded == operator | Vector Comparision
  // Desc: Compares two vectors [using the == operator] and returns the result
  // Precondition: Existing Vector, vectors need to be of the same size
  // Postcondition: returns a vector that holds the boolean char (T or F) value of each node comparison
Vector<char>* operator==(Vector<T>& other){
    Vector<char> v;
    if(this->Size() == other.Size())
    {
        Node <T>*temp = m_head;
        Node<T> *t = other.m_head;
        while(temp != NULL){
            if(t->getValue() == temp->getValue()){
                v.Insert('T');
            }
            else {
                v.Insert('F');
            }
            temp = temp->getNextNode();
            t = t->getNextNode();
        }
    }
    return v;
}
    
  // Name: Size
  // Desc: number of nodes in Vector
  // Precondition: Existing Vector
  // Postcondition: returns the size of the vector
int Size(){
    int count = 0;
    Node <T>*temp = m_head;
    while(temp != NULL){
        temp = temp->getNextNode();
        count++;
    }
    return count;
}
    
  // Name: Display
  // Desc: displays the contents of the vector
  // Precondition: Existing Vector
  // Postcondition: prints to console the contents of Vector
void Display(){
    Node <T>*temp = m_head;
    while(temp != NULL){
        cout << temp->getValue()<< ", " ;
        temp = temp->getNextNode();
    }
    cout << endl;
}

void sort(){
    Node<T> *temp = m_head;
    while(temp != NULL){
        Node<T> *t = temp;
        while(t != NULL){
            if(t->getValue() < temp->getValue()){
                int te = t->getValue();
                t->setValue(temp->getValue());
                temp->setValue(te);
            }
            t = t->getNextNode();
        }
        temp = temp->getNextNode();
    }
}  



  // Name: median
  // Desc: Computes the median of the vector
  // Precondition: Existing Vector
  // Postcondition: returns the median value
float Median(){
    this->sort();
    int s = this->Size();
    int arr[s];
    Node<T> *temp = m_head;
    int i = 0;
    while(temp != NULL){
        arr[i] = temp->getValue();
        temp = temp->getNextNode();
        i++;
    }
    if(s%2!=0){
        return (float)arr[s / 2];
    }
    else {
        return (float)arr[(s-1)/2];
    }
}


    
  // Name: Mean
  // Desc: Computes the mean of the vector
  // Precondition: Existing Vector
  // Postcondition: returns the mean value
float Mean(){
    float sum = 0;
    int s = this->Size();
    Node<T> *temp = m_head;
    while(temp != NULL){
        // cout << "Value: " << temp->getValue() << endl;
        sum += temp->getValue();
        temp = temp->getNextNode();
    }
    return (float)sum / s;
}
    
  // Name: StDev
  // Desc: Computes the standard derivation of the vector
  // Precondition: Existing Vector
  // Postcondition: returns the standard derivation
float StDev(){
    float mean = this->Mean();
    float stdd = 0.0;
    int s = this->Size();
    int arr[s];
    Node <T>*temp = m_head;
    int i = 0;
    while(temp != NULL){
        arr[i] = temp->getValue();
        temp = temp->getNextNode();
        i++;
    }
    i = 0;
    for (i = 0; i < s; i++){
        stdd += pow(arr[i] - mean, 2);
    }
    return sqrt(stdd / s);
}

};

#endif
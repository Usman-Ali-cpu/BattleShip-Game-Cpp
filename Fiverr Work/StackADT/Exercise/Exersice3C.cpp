#include <iostream>
using namespace std;

/*
An operation that displays the contents of a stack can be useful during program debugging. Add a display
method to the ADT stack such that
a. The method uses only ADT stack operations; that is, it is independent of the stack’s implementation.
b. The method assumes and uses the link-based implementation of the ADT stack.
c. The method assumes and uses the array-based implementation of the ADT stack.


(c):
    At line 44- 49
    void display(){
        for (int i = 0; i < size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }


*/

template <class T>

class Stack{
    int top; // top(current index of stack)
    int size;  // size of array
    T *arr;  // pointer point to array
public:
    Stack(){  // default constructor 
        size = 8; // size of array 
        top = -1;  // at start top will be -1
        arr = new T[size];   // pointer point to array(array allocation )
    }
    Stack(int s){ // parameterize constructor 
        size = s; // size of array 
        top = -1;  // at start top will be -1
        arr = new T[size];   // pointer point to array(array allocation )
    }
    

    // c. The method assumes and uses the array-based implementation of the ADT stack.
    void display(){
        for (int i = 0; i < top; i++){ // loop through size of array
            cout << arr[i] << " ";  // print entry
        }
        cout << endl;
    }
    void push(T x){ // insert into stack 
        if(!isFull()){ // check if array is full
            arr[++top] = x; // increment the top and then assign value 
        }
    }
    T pop(){ // get top value 
        if(!isEmpty()){ // check if stack is not empty 
            return arr[top--];  // return array and decrement top 
        }
    }
    T getTop(){ 
        return arr[top];  // just return top entry 
    }
    bool isEmpty(){
        return top == -1;  // if size is equal to -1 return true else false 
    }
    bool isFull(){
        return top == size - 1;  // if size is equal to size-1 return true else false 
    }
    ~Stack(){
        delete[] arr;  // array deallocation 
        arr = NULL;  // NULL the array
    }
};


int main(){
    Stack <int> s;
    s.push(2);
    s.push(3);
    s.push(5);
    s.push(8);
    s.push(9);
    // Here you can check it is working with array based stack and it is dependent of 
    // type of stack.
    s.display();

    return 0;
} 
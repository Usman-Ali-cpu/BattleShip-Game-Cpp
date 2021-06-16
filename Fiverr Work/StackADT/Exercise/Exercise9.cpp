#include <iostream>
using namespace std;

// Imagine an array-based implementation of the ADT stack 
// that stores the stack’s entries beginning at the end of an array. 
// Describe how you can define the stack operations,
// so that the push and pop operations do not require you to move existing entries in the array.
/*
ANSWER: 
1.  we will define top equal to size 
2.  Array will be full if top is equal to zero
3.  Array will be empty if top is equal to size
4.  In push() we decrement top before assigning 
5.  In pop() we increment top. 
*/
template <class T>

class Stack{ 
    int top; // top(current index of stack)
    int size;  // size of array
    T *arr;  // pointer point to array
public:
    Stack(){  // defualt constructor 
        size = 4; // size of array 
        top = size;   // top will be size because pushing will be at end of array
        arr = new T[size];  // nake an array allocation of given size
    }
    Stack(int s){ //  parameterize constructor 
        size = s; // size of array 
        top = size;   // top will be size because pushing will be at end of array
        arr = new T[size];    // nake an array allocation of given size
    }
    void push(T x){  // insert into stack 
        if(!isFull()){
            arr[--top] = x;  // first decrement top and then assign(it will start inserting at end)
        }
    }
    T pop(){  // get top entry
        if(!isEmpty()){  
            return arr[top++]; // return top entry and then increment 
        }
    }
    T getTop(){
        return arr[top];   // just return top entry 
    }
    bool isEmpty(){
        return top == size; // if size is equal to top return true else false 
    }
    bool isFull(){
        return top == 0;  // if size is equal to zero return true else false 
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
    s.push(7);
    s.push(9);
    s.push(1);
    s.push(5);
    s.push(0);
    cout << s.pop();
    cout << s.pop();

    return 0;
} 
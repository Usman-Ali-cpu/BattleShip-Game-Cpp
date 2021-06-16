#include <iostream>
using namespace std;


/*
Problem-1: 
Write an implementation of the ADT stack that uses a resizable array to represent the stack items. 
Anytime the stack becomes full, double the size of the array. 
Maintain the stack’s bottom entry at the beginning of the array

ANSWER:  Code of Resize is At LINE 31 - 47

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
    void resize(){
        int s = size; // get current size 
        T *tempArr = new T[size];  // allocate an temp array of current size
        for (int i = 0; i < size; i++){  // loop through current size 
            tempArr[i] = arr[i];  // assign values of array to temporary array
        }
        size = size * 2; // double size of array
        delete[] arr; // deallocate array
        arr = NULL;  
        arr = new T[size]; // allocate array of double size 
        for (int i = 0; i < s; i++){ // lopp through previous size 
            arr[i] = tempArr[i];  // giving temp array value to this 
        }
        cout << endl;

    }

    void push(T x){ // insert value
        if(!isFull()){  // check is array is not full
            arr[++top] = x; // assign the value 
        }
        else 
        if(isFull()){ // check if array is full
            resize(); // resize the array
            arr[++top] = x;  // the assign the value 
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
    s.push(7);
    s.push(9);
    s.push(1);
    s.push(5);
    s.push(0);
    cout << s.pop();
    cout << s.pop();

    return 0;
} 
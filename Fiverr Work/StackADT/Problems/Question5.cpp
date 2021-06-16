#include <iostream>
using namespace std;


/*

Problem-5: 
Repeat any of the previous four programming problems,
but after the first doubling of the array, halve the size of
the array if fewer than half of the array’s locations are occupied by current stack entries.

ANSWER:
Code of function of halve is At line 50 - 67
i used this function in pop()


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
    void doubling(){
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
    void halve(){
        if(top < size/2){ // if top is less the half 
            int s = size/2; // get half size of array
            
            T *tempArr = new T[s]; // allocate new array of half size 
            for (int i = 0; i < s; i++){
                tempArr[i] = arr[i];  // assigning value to temporary array
            }
            size = s; // giving half size to this->size 
            delete[] arr; // deallocate array 
            arr = NULL;
            arr = new T[size]; // allocate array of half size 
            for (int i = 0; i < s; i++){
                arr[i] = tempArr[i]; // assigning values to this array
            }
        }
        cout << endl;
    }
    void show(){
        for (int i = 0; i < size; i++){
            cout << arr[i] << " "; // printing stack 
        }
        cout << endl;
    }
    void push(T x){ // inserting value 
        if(!isFull()){ // check if stack is not full 
            arr[++top] = x; // push entry 
        }
        else 
        if(isFull()){ //  check if stack is full 
            doubling(); // double the size of array
            arr[++top] = x;
        }
    }
    T pop(){
        if(!isEmpty()){ // check if stack is not empty
            if(top < size/2){   // if top is less than half of size of array
                halve(); // half the size 
            } 
            return arr[top--]; // return top 
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
    cout << "Before half :" << endl;
    cout << "show: ";
    s.show();
    cout << "Poping " << endl;
    cout << s.pop()<< endl;
    cout << s.pop()<< endl;
    cout << s.pop()<< endl;
    cout << "After half" << endl;
    cout << "show: ";
    s.show();
    cout << "Poping " << endl;
    cout << s.pop()<< endl;

    return 0;
} 
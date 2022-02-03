#include <iostream>
using namespace std;

class Mark;

template <typename T>
T findMax(int SIZE, const T array[])
{
    T max = -2434;
    for (int i = 0; i < SIZE; i++)
    {
        if (max < array[i])
        {
            max = array[i];
        }
    }
    return max;
}

int main()
{
    int Is[] = {10, 5, 15, 12};       // array of ints
    double Ds[] = {1.6, 3.33, 0.5};   // array of doubles
    Mark Ms[] = {70, 50, 25, 90, 65}; // array of marks

    // passing array name and the array size
    cout << "Highest int: " << findMax(4, Is) << endl;
    cout << "Highest double: " << findMax(3, Ds) << endl;
    cout << "Highest Mark: " << findMax(5, Ms) << endl;
    return 0;
}
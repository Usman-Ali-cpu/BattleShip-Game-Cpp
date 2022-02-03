#include <iostream>
using namespace std;

class Mark;

template <typename T>
T findMin(int SIZE, const T array[])
{
    T min = 2434;
    for (int i = 0; i < SIZE; i++)
    {
        if (min > array[i])
        {
            min = array[i];
        }
    }
    return min;
}
int main()
{
    int Is[] = {10, 5, 15, 12};     // array of ints
    double Ds[] = {1.6, 3.33, 0.5}; // array of doubles
    // Mark Ms[] = {70, 50, 25, 90, 65}; // array of marks

    // passing array name and the array size
    cout << "Lowest int: " << findMin(4, Is) << endl;
    cout << "Lowest double: " << findMin(3, Ds) << endl;
    // cout << "Lowest Mark: " << findMin(5, Ms) << endl;
    return 0;
}

/* expected output:
Lowest int: 5
Lowest double: 0.5
Lowest Mark: %25[F]
*/
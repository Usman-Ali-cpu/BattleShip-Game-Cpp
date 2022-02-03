#include <iostream>
#include <stdlib.h> //to use rand(), this library is included....
using namespace std;

// this function creates a new array of greater size and copies data to that array...
void create_new_array(int *arr_, int size)
{
    // creating new array
    int *arr = new int[size + 2000];

    // copying data
    for (int i = 0; i < size; i++)
        arr[i] = arr_[i];

    // assigning pointer to new array...
    arr_ = arr;
}

int main()
{
    // to store sum....
    int sum = 0;

    // best case is we can have all the random numbers = 2...
    int *rand_num_arr = new int[2000];

    // to store the space available in the newly created size
    int iter = 0;

    // store the current number of element in the array
    int count = 0;

    // it will keep iterating untill the sum is 1000;
    while (true)
    {
        // generating the random number...
        rand_num_arr[count] = rand() % 2 + 1;

        // incrementing the sum, count and iteration...
        sum += rand_num_arr[count];
        iter++;
        count++;

        // if condition is met, break is loop
        if (sum >= 1000)
            break;
        // if iteration is 2000, mean no free space in data structure, assign new space using function call...
        else if (iter == 2000)
        {
            // creating new space for adding more numbers
            create_new_array(rand_num_arr, count);
            // set current elements in newly generated space to 0;
            iter = 0;
        }
    }

    cout << "Sum : " << sum << endl;
    cout << "Total iteration Count : " << count << endl;

    return 0;
}

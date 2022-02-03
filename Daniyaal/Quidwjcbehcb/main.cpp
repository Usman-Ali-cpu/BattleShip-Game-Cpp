#include <iostream>
using namespace std;

void clear(int **a)
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
            *((a + i * 4) + j) = 0; // accessing the element at index [i][j] using pointer notation as mentioned in question
    }
}
int main()
{
    int **array;
    array = new int *[3];
    for (int i = 0; i < 3; i++)
        *array = new int[4]; // clear array
    clear(array);

    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
            cout << *((array + i * 4) + j) << " "; // printing value at index [i][j]
        cout << endl;
    }

    return 0;
}
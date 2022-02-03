#include <iostream>
using namespace std;

char ***elCastillo(int levels)
{
    int x = 10, y = 0, z = 0;
    int count = 0;

    // Allocate memory blocks of size
    // x i.e., no of 2D Arrays
    char ***a = new char **[x];

    for (int i = 0; i < x; i++)
    {

        // Allocate memory blocks for
        // rows of each 2D array
        y = i + 1;
        a[i] = new char *[y];
        for (int j = 0; j < y; j++)
        {

            // Allocate memory blocks for
            // columns of each 2D array
            z = i + 1;
            a[i][j] = new char[z];
        }
    }

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            for (int k = 0; k < i + 1; k++)
            {

                // Assign value.s to the
                // memory blocks created
                a[i][j][k] = 'A' + i;
            }
        }
    }
    return a;
}
void print1DArray(char *array, int size);
void print2DArray(char **array, int rows);
void print3DArray(char ***array, int numLevels);
int main()
{
    print3DArray(elCastillo(10), 10);
    cout << endl;
    return 0;
}
void print1DArray(char *array, int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i];
    cout << endl;
}
void print2DArray(char **array, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        print1DArray(array[i], rows);
    }
}
void print3DArray(char ***array, int numLevels)
{
    for (int l = 0; l < numLevels; l++)
        print2DArray(array[l], l + 1);
    cout << endl;
}

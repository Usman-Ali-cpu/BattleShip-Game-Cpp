#include <iostream>
using namespace std;

int main()
{
    int row = 3;
    int cols = 3;
    char **a = new char *[row];
    for (int i = 0; i < row; i++)
    {
        a[i] = new char[cols];
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            a[i][j] = 'A' + (i + j);
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << a[i][j];
        }
        cout << endl;
    }

    char **b = new char *[6];
    for (int i = 0; i < 6; i++)
    {
        b[i] = new char[6];
    }
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {

            b[i][j] = 'A';
        }
        cout << endl;
    }

    // int k = 0, l = 0;
    // for (int i = 0; i < 6; i++)
    // {
    //     for (int j = 0; j < 6; j++)
    //     {
    //         if (j % 3 == 0)
    //         {
    //             if (l > 2)
    //             {
    //                 l = 0;
    //             }
    //             l++;
    //         }
    //         b[i][j] = a[k][l];
    //     }
    //     if (i % 3 == 0)
    //     {
    //         if (k > 2)
    //         {
    //             k = 0;
    //         }
    //         k++;
    //     }
    //     cout << endl;
    // }
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {

            cout << b[i][j];
        }
        cout << endl;
    }
    /*

    for (int i = 0; i < row; i++)
    {
        cout << "Allocated " << endl;
        for (int l = 0; l < 2; l++)
        {
            for (int j = 0; j < cols; j++)
            {
                for (int k = 0; k < 2; k++)
                {
                    b[i + l][j + k] = 'A';
                    cout << "Allocated " << endl;
                }
            }
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << a[i][j];
        }
        cout << endl;
    }
    cout << "Second" << endl;

    for (int i = 0; i < row * 2; i++)
    {

        for (int j = 0; j < cols * 2; j++)
        {

            cout << b[i][j];
        }
        cout << endl;
    }*/

    for (int i = 0; i < 3; i++)
    {
        delete[] a[i];
    }
    delete[] a;
    for (int i = 0; i < 6; i++)
    {
        delete[] b[i];
    }
    delete[] b;

    return 0;
}
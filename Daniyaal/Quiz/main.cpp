#include <iostream>
using namespace std;

void exchange(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
    return;
}
exchange(&a[i], &a[j]);
int main()
{
    const int MAX = 5;
    int a[MAX] = {2, 4, 6, 8, 10};
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            exchange(&a[i], &a[j]);
        }
    }
    for (int i = 0; i < MAX; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}
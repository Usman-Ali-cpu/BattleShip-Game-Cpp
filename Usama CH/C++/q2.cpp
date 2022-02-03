#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 7, 7, 7, 1, 9, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    if (n < 3)
    {
        cout << "Size of the array too small.";
        return 0;
    }
    int sum = 0;
    int n1, n2;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] + arr[i + 1] > sum)
        {
            sum = arr[i] + arr[i + 1];
            n1 = arr[i];
            n2 = arr[i + 1];
        }
    }
    int sum3 = 0;
    int s1, s2, s3;
    for (int i = 0; i < n - 2; i++)
    {
        if (arr[i] + arr[i + 1] + arr[i + 2] > sum3)
        {
            sum3 = arr[i] + arr[i + 1] + arr[i + 2];
            s1 = arr[i];
            s2 = arr[i + 1];
            s3 = arr[i + 2];
        }
    }
    int same = 0;
    if (s1 == n1 || s1 == n2)
    {
        same++;
    }
    if (s2 == n2 || s2 == n1)
    {
        same++;
    }
    if (s3 == n1 || s3 == n2)
    {
        same++;
    }

    if (same > 2)
    {
        same = 2;
    }
    if (same == 2)
    {
        cout << "Sums are " << sum << " and " << sum3 << ", and the two are part of the three.";
    }
    else if (same < 2)
    {
        cout << "Sums are " << sum << " and " << sum3 << ", and the two are not fully part of the three.";
    }

    return 0;
}
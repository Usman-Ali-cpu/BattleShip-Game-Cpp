#include <iostream>
using namespace std;

int find_min(int arr[], int n, int x, int y)
{
    int min = INT16_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (((arr[i] == x && arr[j] == y) || (arr[j] == x && arr[i] == y)) && abs(i - j) < min)
            {
                min = abs(i - j);
            }
        }
    }
    return min;
}
int main()
{
    int arr[] = {2, 3, 5, 7, 8, 4, 2, 5, 8, 4};
    int min = find_min(arr, 10, 5, 8);
    int x = 5;
    int y = 8;
    if (min == 1)
    {
        cout << "Both " << x << " and " << y << " are present and the closest ones are are adjacent." << endl;
    }
    else if (min == 2)
    {
        cout << "Both " << x << " and " << y << " are present and the closestones are of distance 2." << endl;
    }
    else if (min == INT_MAX)
    {
        cout << "Some of the values lacking." << endl;
    }
    else
    {
        cout << "Both " << x << " and " << y << " are present, but they are distant" << endl;
    }
    return 0;
}
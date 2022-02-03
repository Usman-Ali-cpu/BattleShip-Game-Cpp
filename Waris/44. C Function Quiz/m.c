#include <stdio.h>

int findPosition(int x, int y, int r)
{
    if (x - y < r)
    {
        return 2; // inside
    }
    else if (x - y == r)
    {
        return 1; // on boundry
    }
    else if (x - y > r)
    {
        return 0; // outside
    }
}

int main()
{
    printf("%d\n", findPosition(5, 4, 2));   // inside
    printf("%d\n", findPosition(4, 2, 2));   // on boundry
    printf("%d\n", findPosition(15, 10, 3)); // outside

    return 0;
}
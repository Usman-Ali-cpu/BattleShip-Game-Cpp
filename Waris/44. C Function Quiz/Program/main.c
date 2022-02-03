#include <stdio.h>

int count(int n, int t)
{
    static int i = 0;
    if (n < 2)
    {
        return i;
    }
    if (n < t)
    {
        return 0;
    }
    else
    {
        if (n % t == 0)
        {
            i++;
            count(--n, t);
        }
        else
        {
            count(--n, t);
        }
    }
    return i;
}
int main()
{
    printf("%d ", count(99, 5));
    return 0;
}
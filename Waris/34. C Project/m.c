

// Iterative C program to implement pow(x, n)
#include <stdio.h>
#include <time.h>

/* Iterative Function to calculate (x^y) in O(logy) */
int power(int x, unsigned int y)
{
    int res = 1; // Initialize result

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = res * x;

        // y must be even now
        y = y >> 1; // y = y/2
        x = x * x;  // Change x to x^2
    }
    return res;
}

// Driver program to test above functions
int main()
{
    int x = 1.45458;
    unsigned int y = 100000000;
    clock_t tic = clock();

    printf("Power is %d", power(x, y));

    clock_t toc = clock();

    printf("Elapsed: %f seconds\n", (double)(toc - tic));

    return 0;
}

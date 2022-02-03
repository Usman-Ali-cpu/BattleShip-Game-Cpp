# The function accepts INTEGER N as parameter.
#

import os


def printEven(N):
    s = 0
    for i in range(0, N):
        if i % 2 == 0:
            s += i
    return s

    # Write your code here
if __name__ == '__main__':

    N = int(input().strip())

    result = printEven(N)

    print(str(result) + '\n')

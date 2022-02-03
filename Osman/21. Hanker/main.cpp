#include <iostream>
using namespace std;

int aggregateNumbers(int val1, int val2)
{
    return val1 + val2;
}

int charInString(string phrase, char look)
{
    int n = 0;
    for (int i = 0; i < phrase.length(); i++)
    {
        if (phrase.at(i) == look)
        {
            n++;
        }
    }
    return n;
}

int printEven(int N)
{
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        if (i % 2 == 0)
        {
            sum += i;
        }
    }
    return sum;
}

int main()
{

    return 0;
}
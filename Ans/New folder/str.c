#include <stdio.h>

void processString(char str[], char ch, int len)
{
    for (int i = 0; i < len; i++)
    {
        if (str[i] == ch)
        {
            str[i] = ch - 32;
        }
    }
}
int main()
{
    char str[50] = "C Programming is Cool";
    processString(str, 'i', 50);
    printf("%s", str);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void substring(char s[], char sub[], int p, int l)
{
    int c = 0;

    while (c < l)
    {
        sub[c] = s[p + c - 1];
        c++;
    }
    sub[c] = '\0';
}
int string_length(char s[])
{
    int c = 0;
    while (s[c] != '\0')
        c++;

    return c;
}

char *sub(char *string, int position, int length)
{
    char *p;
    int c;

    p = malloc(length + 1);

    if (p == NULL)
    {
        printf("Unable to allocate memory.\n");
        exit(1);
    }

    for (c = 0; c < length; c++)
    {
        *(p + c) = *(string + position - 1);
        string++;
    }

    *(p + c) = '\0';

    return p;
}
int compare_strings(char a[], char b[])
{
    int c = 0;

    while (a[c] == b[c])
    {
        if (a[c] == '\0' || b[c] == '\0')
            break;
        c++;
    }

    if (a[c] == '\0' && b[c] == '\0')
        return 0;
    else
        return -1;
}

char concate(char s1[50], char s2[10])
{
    int length = 0;
    while (s1[length] != '\0')
    {
        ++length;
    }

    // concatenate s2 to s1
    for (int j = 0; s2[j] != '\0'; ++j, ++length)
    {
        s1[length] = s2[j];
    }

    // terminating the s1 string
    s1[length] = '\0';
}
int main()
{

    char word[50];
    printf("Enter a Word : ");
    scanf("%s", &word);
    int length = string_length(word);
    char *out;

    char end[6];
    substring(word, end, length - 2, length);
    if (compare_strings(end, "ion") == 0)
    {
        char new[10];
        substring(word, new, 0, length - 3);
        printf("%s%s", new, "ed");
    }

    return 0;
}

#include <stdio.h>
#include <string.h>


void swapChars(char *ptr)
{
    int i = 0;
    int len = strlen(ptr);
    int f = len / 3;
    int l = len / 3;
    int j = len - 1;
    for (i = 0; i <f; i++){
        char t = *(ptr + i);
        *(ptr + i) = *(ptr + j);
        *(ptr + j) = t;
        j--;
    }
    printf("The String is : %s", ptr);
}


int main() {
   

    char str[40];
    printf("Enter string : ");
    scanf("%s", str);
    swapChars(str);

    return 0;

}
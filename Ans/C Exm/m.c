#include <stdio.h>

/*
To Find most frequent and second most frequent char in a file and also occurance of these characters. 
Five arguments will be pass to function. first is name of file, sencond and third will be char by reference.
Fourth and fifth will be int by refernece. We will declare char array having all alphabets. Then loop through
all characters of alphabets one by one then file occurance of each character. If occurance of that character is greater than previously
store character then most frequent character will be changed. And number of occurance will also be changed. While reading file, we also increment 
total to get total characters in file. Then return total characters. 


*/
int mostFrequent(char *fname, char *p1, char *p2, int *pn1, int *pn2)
{
    int n = 0;  // count number of specific char in a string
    int n2 = 0; // count frequency  char in a string
    char c1;    // to store most frequent char
    char c2;    // to store second most frequent char
    *p1 = c1;
    *p2 = c2;

    int total; // count total number of char in a string

    char alpha[] = "abcdefghijklmnopqrstuvwxyz"; // string of containing all alphabet

    for (int i = 0; i < 26; i++) // looping through all alphabets
    {
        int nn1 = 0, nn2 = 0;
        total = 0;         // initializing total count to 0
        FILE *filePointer; // file pointer to open file
        char ch;

        //2
        filePointer = fopen(fname, "r"); // open file to read

        //3
        if (filePointer == NULL) // if error occur in opening file
        {
            printf("File is not available \n");
        }
        else
        {
            //4
            while ((ch = fgetc(filePointer)) != EOF) // read file while read end of file
            {
                if (ch == alpha[i]) // if char in file is character of alphabet at index
                {
                    nn1++; // increment counter of frequency
                }
                total++; // increment for number of char in file
            }
            if (nn1 > n) // if frequency of char of alphabet is greater than most frequent char
            {
                n = nn1;        // change value of frequent variable
                *p1 = alpha[i]; // change char
            }
            else if (nn1 > n2) // if frequency of char of alphabet is greater than second most frequent char
            {
                n2 = nn1;       // change value of frequent variable
                *p2 = alpha[i]; // change char
            }
        }
        fclose(filePointer); // close the file
    }

    *pn1 = n;
    *pn2 = n2;
    return total; // return total number of char
}

int main()
{
    char a, b;
    int n1 = 0, n2 = 0;
    int ntot = mostFrequent("text.txt", &a, &b, &n1, &n2); // calling function get total number of char in ntot
    printf("\nntot = %d ", ntot);                          // prints total char
    printf("\nc1 = %c ", a);                               // print most frequent char
    printf("\nc2 = %c ", b);                               // print second most frequent
    printf("\nn1 = %d ", n1);                              // number of occurance of most frequent
    printf("\nn2 = %d ", n2);                              // number of occurance of second most frequent

    return 0;
}
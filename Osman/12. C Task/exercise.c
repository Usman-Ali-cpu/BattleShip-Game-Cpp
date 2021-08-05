#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isVowel(char str) // check is char is vowel or not
{
    char vowels[50] = "aeiouAEIOU";          // all the vowel letter
    for (int i = 0; i < strlen(vowels); i++) // iterating over vowel letters
    {
        if (str == vowels[i]) // if char is vowel
        {
            return true; // telling it is vowel
        }
    }
    return false; // telling it is not a vowel
}

int main()
{
    char str1[400];         // string for input a String from user
    char newString[20][20]; // array of string to split words of string
    int i, j, ctr;
    char AUMID[10] = "36087"; // user AUM-ID

    printf(" Input  a string : ");
    fgets(str1, sizeof str1, stdin); // getting string from user from console

    j = 0;
    ctr = 0;
    for (i = 0; i <= (strlen(str1)); i++) // iterate over each character of string
    {
        // if space or NULL found, assign NULL into newString[ctr]
        if (str1[i] == ' ' || str1[i] == '\0')
        {
            newString[ctr][j] = '\0'; // assinging null to the end of string
            ctr++;                    //for next word
            j = 0;                    //for next word, init index to 0
        }
        else // if charcter is not null and not space
        {
            newString[ctr][j] = str1[i];
            j++;
        }
    }
    for (i = 0; i < ctr; i++) // iterate over words in the string
    {
        char out[50];              // declare a word for output
        strcpy(out, newString[i]); // get a word from the string
        if (isVowel(out[0]))       // checking if first letter of word is vowel
        {
            if (i == ctr - 1) // if it is last word of input string
            {
                char s[30];
                // to remove last null character from the word
                for (int a = 0; a < strlen(out) - 1; a++) // iterate over the lenth less one of the out word
                {
                    s[a] = out[a];
                }
                strcpy(out, s); // assigning word string s to out
                strcpy(s, "");
            }
        }
        else
        {
            char new[20]; // string to set value if first character is consonent
            strcpy(new, "");
            int k;
            for (k = 1; out[k] != '\0'; k++) // iterate over out string
            {
                new[k - 1] = out[k];
            }
            if (i == ctr - 1) // check if it is last word of string
            {
                new[k - 2] = out[0];
                char neww[20];
                for (int a = 0; a < strlen(new) - 2; a++) // iterating to removing last character
                {
                    neww[a] = new[a];
                }
                strcpy(new, neww); // fetting string neww in new
            }
            else
            {
                new[k - 1] = out[0];
            }
            k = 1;

            strcpy(out, new);
            strcpy(new, "");
            for (int b = 0; b < 20; b++) // iterate over the new string
            {
                new[b] = '\0'; // assigning null to each character
            }
        }
        strcat(out, "36087"); // concatenating AUM-ID in the word
        printf("%s ", out);   // print word on the console
        strcpy(out, "");
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//function for extracting beginning part
//of the string
char *substring(char *p, int n)
{

    char *str = (char *)malloc(n * sizeof(char));
    int i;
    for (i = 0; i <= n - 1; i++)
    {
        str[i] = p[i];
    }
    str[i] = '\0';
    return str;
}

//function for checking whether the string is
//keyword or not
int isKeyword(char *w)
{

    if (strcmp(w, "define") == 0 || strcmp(w, "set") == 0 ||
        strcmp(w, "print") == 0 || strcmp(w, "true") == 0 ||
        strcmp(w, "false") == 0 || strcmp(w, "read") == 0)
        return 1;
    else
        return 0;
}

//function for checking whether the string is
//operator or not
int isOperator(char *w)
{

    if (strcmp(w, "=") == 0 || strcmp(w, "not") == 0 ||
        strcmp(w, ";") == 0 || strcmp(w, "or") == 0)
        return 1;
    else
        return 0;
}

//function for checking whether the character is
//operator or not

int isOperator_char(char ch)
{

    if (ch == ';')
        return 1;
    else
        return 0;
}
//function for checking whether the string is
//identifier or not
int isIdentifier(char *w)
{

    if (strcmp(w, "a") == 0 || strcmp(w, "b") == 0 ||
        strcmp(w, "c") == 0 || strcmp(w, "d") == 0 || strcmp(w, "e") == 0 || strcmp(w, "f") == 0 || strcmp(w, "g") == 0 || strcmp(w, "h") == 0 || strcmp(w, "i") == 0 || strcmp(w, "j") == 0 || strcmp(w, "k") == 0 || strcmp(w, "l") == 0 || strcmp(w, "m") == 0 || strcmp(w, "n") == 0 || strcmp(w, "o") == 0 || strcmp(w, "p") == 0 || strcmp(w, "q") == 0 || strcmp(w, "r") == 0 || strcmp(w, "s") == 0 || strcmp(w, "t") == 0 || strcmp(w, "u") == 0 || strcmp(w, "v") == 0 || strcmp(w, "w") == 0 || strcmp(w, "x") == 0 || strcmp(w, "y") == 0 || strcmp(w, "z") == 0)
        return 1;
    else
        return 0;
}

int main()
{
    //opening file input.txt for reading
    FILE *fp = fopen("input.txt", "r");
    char word[20];

    // int c = 0;
    int line = 0;
    bool a, b, c, p, d, e;
    char *token2;

    //reading file line by line and store the line in
    //word array
    while (fgets(word, 19, fp) != NULL)
    {

        // printf("%s", word);
        char newString[20][20]; // array of string to split words of string
        int i, j = 0, ctr = 0;
        for (i = 0; i <= (strlen(word)); i++) // iterate over each character of string
        {
            // if space or NULL found, assign NULL into newString[ctr]
            if (word[i] == ' ' || word[i] == '\0' || word[i] == '\n')
            {
                newString[ctr][j] = '\0'; // assinging null to the end of string
                ctr++;                    //for next word
                j = 0;                    //for next word, init index to 0
            }
            else // if charcter is not null and not space
            {
                newString[ctr][j] = word[i];
                j++;
            }
        }

        // printf(":%s:", newString[4]);

        for (i = 0; i < ctr; i++) // iterate over words in the string
        {
            //  printf(":%s:\n", newString[i]);

            char symbol[50];
            strcpy(symbol, newString[i]);
            if (isKeyword(newString[0]))
            {
                if (strcmp(newString[0], "define"))
                {
                    a = true;
                }
                if (strcmp(newString[0], "set"))
                {
                    if (ctr >= 4)
                    {
                        if (strcmp(newString[1], "e"))
                        {
                            if (c || p)
                            {
                                e = true;
                            }
                            else
                            {
                                e = false;
                            }
                        }
                        if (strcmp(newString[1], "d"))
                        {
                            if (a)
                            {
                                d = false;
                            }
                            else
                            {
                                d = true;
                            }
                        }
                    }
                    if (strcmp(newString[1], "a"))
                    {
                        if (ctr > 3)
                        {
                            if (strcmp(newString[3], "false;"))
                            {
                                a = false;
                            }
                            if (strcmp(newString[3], "true;"))
                            {
                                a = true;
                            }
                        }
                    }
                    if (strcmp(newString[1], "b"))
                    {
                        if (ctr > 3)
                        {
                            if (strcmp(newString[3], "false;"))
                            {
                                b = false;
                            }
                            if (strcmp(newString[3], "true;"))
                            {
                                b = true;
                            }
                        }
                    }
                    if (strcmp(newString[1], "e"))
                    {
                        if (ctr > 3)
                        {
                            if (strcmp(newString[3], "false;"))
                            {
                                e = false;
                            }
                            if (strcmp(newString[3], "true;"))
                            {
                                e = true;
                            }
                        }
                    }
                    if (strcmp(newString[1], "d"))
                    {
                        if (ctr > 3)
                        {
                            if (strcmp(newString[3], "false;"))
                            {
                                d = false;
                            }
                            if (strcmp(newString[3], "true;"))
                            {
                                d = true;
                            }
                        }
                    }
                }
                if (strcmp(newString[0], "read"))
                {
                    if (strcmp(newString[1], "c"))
                    {
                        char input[20];
                        printf("Enter true or false for c : ");
                        scanf("%s", &input);
                        if (strcmp(input, "false") || strcmp(input, "False") || strcmp(input, "FALSE"))
                        {
                            c = false;
                        }
                        if (strcmp(input, "true") || strcmp(input, "True") || strcmp(input, "TRUE"))
                        {
                            c = true;
                        }
                    }
                    if (strcmp(newString[1], "p"))
                    {
                        char input[20];
                        printf("Enter true or false for p : ");
                        scanf("%s", &input);
                        if (strcmp(input, "false") || strcmp(input, "False") || strcmp(input, "FALSE"))
                        {
                            p = false;
                        }
                        if (strcmp(input, "true") || strcmp(input, "True") || strcmp(input, "TRUE"))
                        {
                            p = true;
                        }
                    }
                }
                if (strcmp(newString[0], "print"))
                {
                    if (strcmp(newString[1], "d"))
                    {
                        if (d == true)
                        {
                            printf("d = true\n");
                        }
                        else
                        {
                            printf("d = false\n");
                        }
                    }
                    if (strcmp(newString[1], "e"))
                    {
                        if (e == true)
                        {
                            printf("e = true\n");
                        }
                        else
                        {
                            printf("e = false\n");
                        }
                    }
                    return 0;
                }
            }
        }
        // Extract the first token

        // char *token = strtok(word, " ");
        // // loop through the string to extract all other tokens
        // while (token != NULL)
        // {

        //     if (isKeyword(token))
        //         printf("\nID %d line %d in the program %s keyword", c, line, token);

        //     else if (isIdentifier(token))
        //         printf("\nID %d line %d in the program %s identifier", c, line, token);
        //     else if (isOperator(token))
        //         printf("\nID %d line %d in the program %s operator", c, line, token);

        //     token2 = token;            //previous token
        //     token = strtok(NULL, " "); //next token
        //     c++;                       //increment count
        // }
        // c--; //decrement the extra count
        // int len = strlen(token2);

        // char ch = token2[len - 2]; //getting the last character

        // if (isOperator_char(ch))
        //     printf("\nID %d line %d in the program %c operator", c, line, ch);

        // //getting the portion of token2 except the last
        // //character
        // char *lastword = substring(token2, len - 2);
        // c++;

        // //checking whether the portion of token2 except the last
        // //character is identifier or keyword
        // if (isIdentifier(lastword))
        //     printf("\nID %d line %d in the program %s identifier", c, line, lastword);

        // else if (isKeyword(lastword))
        //     printf("\nID %d line %d in the program %s keyword", c, line, lastword);

        // c++; //increment count
        // printf("\n");
        // line++; //increment line number
    }
}

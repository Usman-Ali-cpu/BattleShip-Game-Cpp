#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count = 7;

struct Person
{
    char name[20];
    char wages[10];
};


void checkName(struct Person *p, char *name )
{
    for (int i = 0; i < count; i++){

        if(strcmp(p[i].name, name) == 0){
            printf("\nName: %s\n", name);
            printf("Wages %s\n", p[i].wages);
            return;
        }
    }
    printf("Name: %s", name);
    printf("Not Found");
    return;
}

int main()
{
    struct Person data[10];
    FILE *fp; // declaration of file pointer
    char con[1000]; // variable to read the content

    fp = fopen("test.txt","r");// opening of file
    if (!fp)// checking for error
        return 1;
    int count = 0;
    while (fgets(con,1000, fp)!=NULL){
        char n[20] = "";
        
        int i = 0;
        while (con[i] != ' ')
        {
            n[i] = con[i];
            i++; 
        }
        char m[20] = "";
        int j = 0;
        i++;
        
        while (con[i] != '\n')
        {
            m[j] = con[i];
            i++;
            j++;
        }
        

        
        strcpy(data[count].name, n);
        strcpy(data[count].wages, m);
        // printf("wages: %s", data[count].wages);
        // data[count].wages = m;

        count++;
    }
    






    fclose(fp); // closing file

    int choice;
    while(1)
    {
        
        printf("\n1. Enter name.\n");
        printf("2. Exit\n");
        scanf("%d", &choice);
        getch();
        char name[30] = "";
        switch (choice)
        {
        case 1:
            getchar();
            printf("NAme : ");
            scanf(" %[^\n]",name);
            checkName(data, name);
            break;
        case 2:
            exit(0);
            break;

        default:
            printf("Invalid input! ");
            break;
        }
    }
      // faalsay le aayo 


    return 0;
}
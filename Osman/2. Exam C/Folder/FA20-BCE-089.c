#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Product_ID, Product_Name, Quantity, Price, Product_Type
struct Product
{
    char product_name[50];
    int product_ID;
    int quantity;
    float price;
    char product_type[50];
};

void addProduct(){
    char name[50];
    char ID[10];
    char quantity[10];
    char price[10];
    char type[50];

    printf("Enter product name : ");
    scanf("%s", &name);

    printf("Enter product ID : ");
    scanf("%s", &ID);

    printf("Enter product Quantity : ");
    scanf("%s", &quantity);

    printf("Enter product Price : ");
    scanf("%s", &price);

    printf("Enter product type : ");
    scanf("%s", &type);

    FILE * fptr;
    fptr = fopen("Product.txt", "a");
    char result[20];
    char dataToAppend[50] = "\n";
    strcat(dataToAppend,name);
    strcat(dataToAppend," ");

    strcat(dataToAppend,ID);
    strcat(dataToAppend," ");
    strcat(dataToAppend,quantity);
    strcat(dataToAppend," ");
    // sprintf(result, "%f", price);
    strcat(dataToAppend,price);
    strcat(dataToAppend," ");
    strcat(dataToAppend,type);

    // printf("%s", dataToAppend);
 
    fprintf(fptr,dataToAppend);
    printf("\n Your Product has been added Successfully ");
    fclose(fptr);

    // fputs(dataToAppend, fptr);

}
void UpdateProduct(){
    char name[50];
    char ID[10];
    char quantity[10];
    char price[10];
    char type[50];

    printf("Enter product ID to Update : ");
    scanf("%s", &ID);

    printf("Enter new name of product : ");
    scanf("%s", &name);

    printf("Enter new  Quantity of product : ");
    scanf("%s", &quantity);

    printf("Enter new Price product : ");
    scanf("%s", &price);

    printf("Enter new type product  : ");
    scanf("%s", &type);

    printf("Product has been updated \n");

}
void displayProducts(){
    FILE * fptr;
    fptr = fopen("Product.txt", "r");
    if (fptr == NULL){
        printf("Error! opening file");
        return;
    }

    int c;
    char getter[20];
    int i =0;
    int pcount =0;
    printf("Product_ID   Product_Name   Quantity   Price   Product_Type\n");
    while (1)
    { 
        if (feof(fptr)){
            return;
        } 
        if(i % 5==0){
            pcount++;
            printf("\n");
        }
        fscanf(fptr,"%s", &getter);
        printf("    %s      ",getter);
        i++;
    }
    fclose(fptr);
}

int get_index(char* string, char c, int n) {
    char *e = strchr(string, c);
    if (e == NULL) {
        return -1;
    }
    if ((int)(e - string) == n){
        return (int)(e - string);
    }
    return (int)(e - string);
}



// *************   Second Question  **************
int * getPolarity(int array[], int s){
    static int retArr[10];
    int i;
    for(i=0; i< 10; i++){
        if(array[i]< 0){
            retArr[i] = -1;
        }
        else if(array[i]> 0){
            retArr[i] = 1;
        }
        else {
            retArr[i] = 0;
        }
    }
    return retArr;
}

// ************  END Second Question *************


int main(){


    printf("********************************** \n");
    printf("Enter A to Run First Question \n");
    printf("Enter B to run Second Question \n");
    printf("********************************** \n");

    char ch;
    printf("Enter character (A or B): ");
    scanf("%c", &ch);

    switch (ch)
    {
    case 'B':
    {
        printf("You Pressed B, This is second Question  \n");
            int values[10];
            int i;
            for(i=0; i< 10; i++){
                printf("Enter value %d of 9: ", i);
                scanf("%d", &values[i]);
            }
            printf("Data Analysis \n");
            int * p;
            p = getPolarity(values, 10);
            for(i=0; i< 10; i++){
                printf("%d     %d\n",values[i] , p[i]);
            }
             return 0;
    }
    break;
    case 'A':
    {
    	printf("You Pressed A, This is First Question  \n");
        FILE * fptr;
        fptr = fopen("Product.txt", "r");
        if (fptr == NULL){
            printf("Error! opening file");
            return 0;
        }
        char name[50];
        int ID;
        int quantity;
        float price;
        char type[50];
        while(1)
        {
            printf("\n********************************** \n");
            printf("Press 1 to Add New Product\n");
            printf("Press 2 to Update Product\n");
            printf("Press 3 to Display Product\n");
            printf("Press 4 to Exit\n");
            printf("********************************** \n");
            int num;
            printf("Enter choice : ");
            scanf("%d", &num);
            switch (num)
            {
            case 1:
                addProduct();
                break;
            case 2:
                UpdateProduct();
                break;
            case 3:
                displayProducts();
                break;
            case 4:
                printf("You Quit this program");
                exit(0);
                break;
            default:
                printf("Invalid Input \n");
                break;
            }
        }


    }
        /* code */
        break;
    default:
        printf("Invalid Input \n");
        break;
    }

    return 0;
}

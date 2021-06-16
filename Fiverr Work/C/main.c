#include <stdio.h>
#include <stdbool.h>
#include <string.h>

    // Your Name 
    // Your Roll no 
    // Your Section ID
    // Your University

int main(){


    int books;
    int choice;
    int stdtype;
    printf("Enter your type : \n1.For Student   \n2. For Teacher   \n3.For Adminstrator\n");
    scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter your level: \n1.For elementry   \n2.For high school\n ");
            scanf("%d", &stdtype);

            switch (stdtype)
            {
            case 1:
                printf("You can borrow %d books\n",3);
                break;
            case 2:
                printf("You can borrow %d books\n", 4);
                break;
            default:
                printf("Invalid Choice\n");
                break;
            }
            break;
        case 2:
            printf("You can borrow %d books\n",8);
        break;
        case 3:
            printf("You can borrow %d books\n", 5);
        break;
        default:
            printf("Invalid Input ! \n");
            break;
        }
    return 0;
}
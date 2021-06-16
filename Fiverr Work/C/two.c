#include <stdio.h>
#include <stdbool.h>
#include <string.h>





int main(){
    char password[100];
    int strength = 0;
    printf("Enter password: ");
    scanf("%s", password);
    char ingnore = getchar();


    int passlength = strlen(password);
    if(passlength >= 8){
        strength =  strength + 2;
    }

    int i = 0;
    int uppercase = 0;
    while (password[i] != '\0')
    {
        if (password[i] >= 'A' && password[i] <= 'Z'){
            uppercase++;
            
        }
        i++;
    }
    if(uppercase>= 2 ){
        strength += 3;
    }

    int k = 0;
    int numCount = 0;
    while (password[k] != '\0') {
        if (password[k] >= '0' && password[k] <= '9')
        {
            numCount = numCount +1;
           
        }
         k++;
    }
    if(numCount>= 3 ){
        strength += 3;
    }

    int j = 0;
    int specialCh = 0;
    while (password[j] != '\0') {
        if (password[j] == '+' || password[j] == '-' || password[j] == '/' || password[j] == '*' || password[j] == '%'){
            specialCh = specialCh + 1;
            
        }
        j++;
    }
    if(specialCh>= 2 ){
        strength += 3;
    }
    
    
    

    printf("Strength is %d ", strength);

    return 0;
}
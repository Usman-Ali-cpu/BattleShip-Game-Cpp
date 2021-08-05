#include <stdio.h>


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


int main() {

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

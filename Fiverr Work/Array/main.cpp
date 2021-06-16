#include <iostream>
using namespace std;

// ***********  PART 1 ************
int sumArray(int arr[], int len){
    int sum = 0;  // to store sum of array elements 
    for (int i = 0; i < len; i++){
        sum += arr[i]; // add item to sum 
    }
    return sum; //  returning sum to main function
}

float convertToDecimal(int arr[], int len, int base){
    int count10 = len-1; // initailize loop counter 
    float value =0.0;   // to store decimal value 
    for (int i = 0; i < len; i++){
        int j = arr[i]; // get digit 
        for (int k = 0; k < count10; k++){
            j *= base; // multiply digit with 10
        }
        value += j; // add to returning value 
        count10--; // decrement counter 
    }
    return value; // return value to main 
}

void printAccending(int arr[], int len){
    int prev = arr[0]; // get starting element 
    for (int i = 0; i < len; i++){ 
        if(arr[i]< prev){ // check if number is less than previous 
            cout << "\n"; 
        }   
        cout << arr[i] << ", ";
        prev = arr[i]; // assigning previous to current 
    }
    cout << endl;
}
void reverseArrayEven(int arr[], int len){
    // printing before reversing
    cout << "Before Reversing " << endl;
    for (int i = 0; i < len; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

        for (int i = 0; i < len/2; i++){ 
            // check if one of them number from start and correnponding number from end is even 
            if(arr[i]%2 == 0 && arr[len-1-i]%2 != 0  || arr[i]%2 != 0 && arr[len-1-i]%2 == 0){ 
                // it will swap these two elements of array 
                int temp = arr[i];
                arr[i] = arr[len - 1 - i];
                arr[len - 1 - i] = temp;

            }
        }
    // printing After reversing
    cout << "After Reversing " << endl;
    for (int i = 0; i < len; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}


// *************** PART 2 *****************

void insertInArray(string arr[], const int position, const string newItem){
    if(position < 0 || position > 19){ // check if position is valid 
        cout << "Position is inValid" << endl; 
        return; // return the function 
    }
    arr[position] = newItem; // assign value to that given position 
}

void eraseInArray(string arr[], const int startingPosition, const int howMany){
    if(startingPosition<0){ // check if position is valid 
        cout << "Position is inValid you can't erase" << endl;
        return;
    }
    else {
        for (int i = startingPosition; i < howMany; i++){
            arr[i] = ""; // empty string in a given range starting to given numbers
        }
    }
}
void DisplayStrings(string arr[], const int len){
    for (int i = 0; i < len; i++){
        cout <<i<< ". " <<arr[i] << ".\n"; // print strings in array 
    }
}

// ************** PART 3 *****************
void swap2D(int arr[][8] , int x1, int y1, int x2, int y2)
{
    cout << arr[x1][y1] << ", " << arr[x2][y2] << endl; // print numbers before swaping 

    arr[x1][y1] = arr[x1][y1] + arr[x2][y2];   // sum both elements in one 
    arr[x2][y2] = arr[x1][y1] - arr[x2][y2];    // subtrating second one from sum and assigning to second 
    arr[x1][y1] = arr[x1][y1] - arr[x2][y2];    //subtrating second one from sum and assigning to first

    cout << arr[x1][y1] << ", " << arr[x2][y2] << endl;  // print after swap 
}


void checkMatches(int arr[][8], int len)
{
    // printing array before
    cout << "Printing Array Before Checking" << endl;
    for (int i = 0; i < len; i++){
        for (int j = 0; j < len; j++){
            cout<< arr[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < len; i++){ // looping through rows 
        for (int j = 0; j < len; j++){  // looping through coloumns 
            if(j==0){ // check if coloumn is first 
                if(arr[i][j+2] == arr[i][j] && arr[i][j+1] == arr[i][j]){ // check if three consective elements in row is same  
                    if(arr[i][j +2] == arr[i][j +3]){ // check if have anymore element is same 
                        arr[i][j + 3] = 0; // assigning zero to that 
                    }
                    arr[i][j +2] = 0; // assigning zero
                    arr[i][j] = 0; // assigning zero
                    arr[i][j + 1] = 0; // assigning zero
                }
            }
            if(i==0){
                if(arr[i+2][j] == arr[i][j] && arr[i+1][j] == arr[i][j]){ // check if three consective elements in coloumn is same
                    if(arr[i+2][j] == arr[i+3][j]){ // check if have anymore element is same
                        arr[i+3][j] = 0; // assigning zero
                    }
                    arr[i+2][j] = 0; // assigning zero
                    arr[i][j] = 0; // assigning zero
                    arr[i+1][j] = 0; // assigning zero
                }
            }
            else {
                if(arr[i][j-1] == arr[i][j+1] && arr[i][j-1] == arr[i][j]){ // check if three consective elements in row is same
                    if(arr[i][j] == arr[i][j+2]){ // check if have anymore element is same 
                        arr[i][j + 2] = 0; // assigning zero
                    }
                    arr[i][j - 1] = 0; // assigning zero
                    arr[i][j + 1] = 0; // assigning zero
                    arr[i][j] = 0; // assigning zero
                }
                if(arr[i-1][j] == arr[i+1][j] && arr[i-1][j] == arr[i][j]){ // check if three consective elements in cloumn is same
                    if(arr[i][j] == arr[i+2][j]){ // check if have anymore element is same 
                        arr[i+2][j] = 0; // assigning zero
                    }    
                    arr[i - 1][j] = 0; // assigning zero
                    arr[i + 1][j] = 0; // assigning zero
                    arr[i][j] = 0; // assigning zero
                } 
            }
        }         
    }

    // printing array After 
    cout << "Printing Array After Checking " << endl;
    for (int i = 0; i < len; i++){
        for (int j = 0; j < len; j++){
            cout<< arr[i][j] << " ";
        }
        cout << endl;
    }
}
int main(){
    cout << "******** PART 1 *********\n";
    int arr[4] = {1, 2, 3, 4};
    cout <<"Sum Array : " << sumArray(arr, 3) << endl; // print sum of first 3 elements of array 

    cout <<"Array to decimal : " << convertToDecimal(arr, 4,10 )<< endl;
    int ar[4] = {1, 0, 1, 1};
    cout <<"Base 2 Array to decimal : " << convertToDecimal(ar, 4,2 )<< endl;

    int array[7] = {2, 5, 8, 3, 9, 9, 7};
    cout << "Printing Accending : \n";
    printAccending(array, 7); // Printing Accending 

    int a[7] = {1, 2, 4, 5, 6, 9, 10};
    reverseArrayEven(a, 7); // even reversing of array 



    // *********** PART 2 *************
    cout << "\n******** PART 2 *********\n";
    string strArr[20];
    for (int i = 0; i < 20; i++){
        strArr[i] = "";
    }
    // Inserting to array 
    insertInArray(strArr, 3, "Hello 1");
    insertInArray(strArr, 7, "Hello 2");
    insertInArray(strArr, 11, "Hello 3");
    insertInArray(strArr, 15, "Hello 4");
    insertInArray(strArr, 18, "Hello 5");
    cout << "Display String After inserting : " << endl;
    DisplayStrings(strArr, 20);
    // Erasing from array 
    cout << "Display String After erasing : " << endl;
    eraseInArray(strArr, 2, 8);
    DisplayStrings(strArr, 20);


    // *********** PART 3 **********
    cout << "\n******** PART 3 *********\n";
    int arr2D[8][8];
    cout << "Swaping :-> \n";
    arr2D[1][3] = 45;
    arr2D[2][2] = 34;

    swap2D(arr2D, 1, 3, 2, 2); // it will swap elements at these two postions 

    int test[8][8] = { 
                     {1, 1, 2, 3, 3, 1, 3, 2},
                     {1, 2, 3, 3, 3, 1, 1, 1}, 
                     {1, 2, 3, 3, 1, 2, 1, 2}, 
                     {3, 1, 2, 1, 3, 1, 2, 2}, 
                     {3, 2, 2, 1, 1, 1, 1, 1}, 
                     {1, 2, 3, 2, 1, 2, 2, 3}, 
                     {3, 2, 1, 3, 2, 1, 2, 1}, 
                     {1, 2, 3, 1, 1, 2, 3, 3}
                    };

    checkMatches(test, 8); // it will check matches and place zero 




    return 0;
}


// 2. References                          (10 points)
//
// In the program below, there are two arrays defined, in which the expenditure over 12 months of two years are stored.
// Swap the values of the arrays by doing the following:
//
// 2.1 Create a for-loop to output the stored data expenditures1 and expenditures2.
//
// 2.2 Call the function "swapNums" inside of this loop and pass the values of the array expenditure1 and expenditure2.
//
// 2.3 Output the stored data of expenditures1 and expenditures2 after calling the function.
//     Why are the values not being swapped?
//     Answer:
//
// 2.4 Correct the function swapNums so that it's referencing and swapping the actual values of the arrays.

#include <iostream>
using namespace std;

void swapNums(int& x, int& y) {
  int z = x;
  x = y;
  y = z;
}

int main()
{
    int expenditure1[12] = {10,15,20,36,15,45,20,35,24,64,52,12};
    int expenditure2[12] = {100,150,200,360,150,450,200,350,240,640,520,120};

    for(int i=0; i< 12; i++){
      cout<< "Expenditure1["<< i<< "]: "<< expenditure1[i] << "   "<< "Expenditure2["<< i<< "]: "<< expenditure2[i] <<endl;
      swapNums(expenditure1[i], expenditure2[i]);
    }
    cout<< "After Swaping -> \n";
    for(int i=0; i< 12; i++){
      cout<< "Expenditure1["<< i<< "]: "<< expenditure1[i] << "   "<< "Expenditure2["<< i<< "]: "<< expenditure2[i] <<endl;
    }



    return 0;
}

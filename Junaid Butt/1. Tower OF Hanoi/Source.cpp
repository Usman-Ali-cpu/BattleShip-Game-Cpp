#include <iostream> 
#include <math.h>
#include <string>
using namespace std; 

int getMoves(int n){
    return pow(2, n)-1;
}
// recusive call to this function
void TowerOfHanoi(int n, string A, string B, string C)  
{ 

    if (n == 1)  
    {  
        // cout << "Move disk 1 from rod " << A <<  " to rod " << B <<endl;  
        return;  
    }  
    TowerOfHanoi(n - 1, A, C, B);  
    // cout << "Move disk " << n << " from rod " << A << " to rod " << B << endl;  
    TowerOfHanoi(n - 1, C, B, A);  
}  

int main()  
{  
    cout<< "Number of disks  |  Number of moves" << endl; 
    for(int i=0; i< 10 ; i++){
        cout<< i+1<< "\t         | \t";
        TowerOfHanoi(i+1, "A", "B", "C");  //names of the towers
        cout <<getMoves(i+1)<< endl;
    }
    return 0;  
} 

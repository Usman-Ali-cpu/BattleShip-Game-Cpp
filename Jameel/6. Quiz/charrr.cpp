#include <iostream>
using namespace std;
template <typename T>
T Max(T a, T b)
{
    return a > b ? a : b;
}
int main()
{
    int num1 = 10, num2 = 5;
    double num3 = 10.1, num4 = 10.2;
    char char1 = 'e', char2 = 102;
    cout << "The larger value between" << num1 << " and " << num2 << " is " << Max(num1, num2) << endl;
    cout << "The larger value between" << num3 << " and " << num4 << " is " << Max(num3, num4) << endl;
    cout << "The larger value between" << char1 << " and " << char2 << " is " << Max(char1, char2) << endl;
    return 0;
}

/*
line 4
 no matching return type
 void can not be resolved to int
 change void to T

 line 13
 no matching operator with void to <<
 void type can not be output
 change void at line 4 to T

 line 14
 no matching operator with void to <<
 void type can not be output
 change void at line 4 to T

 line 15
 no matching operator with void to <<
 void type can not be output
 change void at line 4 to int

 line 15
 char1 is not declared
  char1 is  not define in scope
 change chari to char1 at line 12

*/

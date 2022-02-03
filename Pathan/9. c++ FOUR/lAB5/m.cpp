#include <iostream>
#include <string>

using namespace std;

// function with default parameter
void defaultParameterFunction(char ch = 'A', float fvar = 10.21, int ivar = 25)
{
    cout << "ch = " << ch << " fvar = " << fvar << " ivar= " << ivar << endl;
}

// Which of the following 5 function calls is correct ? If it is correct, what is the output ?

int main()
{
    // 1.
    defaultParameterFunction('F', 11.45, 11);
    // 2.
    defaultParameterFunction('A', 14.36);
    // 3.
    defaultParameterFunction();
    // 4.
    defaultParameterFunction('L');
    // 5.
    defaultParameterFunction('L', 10.29, 42);

    system("pause");
    return 0;
}

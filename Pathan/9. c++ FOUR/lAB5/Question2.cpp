#include <iostream>
using namespace std;

int main()
{

    int count = 0;
    int intVar = 1, temp = 1, product = 1;
    while (product <= 2021)
    {
        cout << "Enter number for intVar: ";
        cin >> intVar;
        temp = product;
        product = intVar * product;
        count++;
    }
    cout << "At count : " << count << endl;
    cout << "Last product : "
         << temp << endl;
    cout << "intVar = " << intVar << endl;
    cout << "product = " << product << endl;
    return 0;
}
// if product = 3000, then loop will not iterate anytime
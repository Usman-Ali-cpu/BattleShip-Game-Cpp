#include <iostream>
using namespace std;

int main()
{

    int count = 0;
    int intVar = 1, temp = 1, product = 1;
    do
    {
        cout << "Enter and integer intVar: ";
        cin >> intVar;
        temp = product;
        product = intVar * product;
        count++;
    } while (product <= 2021);
    cout
        << "At count : " << count << endl;
    cout << "Last product : "
         << temp << endl;
    cout << "intVar = " << intVar << endl;
    cout << "product = " << product << endl;
    return 0;
}
// if product = 3000 then loop will iterate one time
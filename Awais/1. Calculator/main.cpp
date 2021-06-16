#include <iostream>
using namespace std;

int main(){

int first, second;
for (int i = 0; i < 10; i++)
{
    cout << "Enter first operand : ";
    cin >> first;
    char c;
    cout << "Enter operator ( + * - / ) : ";
    cin >> c;
    cout << "Enter second operand : ";
    cin >> second;
    switch (c)
    {
    case '+':
        cout << first << " + " << second << " = " << first + second << endl;
        break;
    case '-':
        cout << first << " - " << second << " = " << first - second << endl;
        break;
    case '*':
        cout << first << " * " << second << " = " << first * second << endl;
        break;
    case '/':
        cout << first << " / " << second << " = " << first / second << endl;
        break;
    default:
        cout << "Invalid input " << endl;
        break;
    }
}
    return 0;
}
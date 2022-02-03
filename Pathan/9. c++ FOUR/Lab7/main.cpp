#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char aString1[] = "HELLO";
    char aString2[] = {'H', 'E', 'L', 'L', 'O', '\0'};
    char aString3[6];
    char aString4[6];

    // A.
    cout << "aString1: " << aString1 << endl;

    // B.
    strcpy_s(aString3, aString2);
    cout << "aString3: " << aString3 << endl;

    // C.
    cout << "Enter a string: ";
    cin.getline(aString4, 80); // Users type "This is the test"
    cout << "aString4: " << aString4 << endl;

    // D.
    aString2[1] = 'e';
    cout << "aString2: " << aString2 << endl;

    // E.
    aString4 = aString2;
    cout << "aString4: " << aString4 << endl;

    return 0;
}

#include <iostream>
#include <string>
using namespace std;
int main()
{
    string scores = "2 5 78";
    int i = scores.find_last_of(" ");

    do
    {
        int index = scores.find_first_of(" ");
        // cout << index << endl;
        string s = scores.substr(0, index);
        cout << s << endl;
        scores.erase(0, index + 1);
        // cout << scores << endl;
    } while (scores != scores.substr(i + 1, scores.length()));

    return 0;
}
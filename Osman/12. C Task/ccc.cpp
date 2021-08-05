#include <iostream>
#include <vector>
using namespace std;

class B
{
public:
    B()
    {
        cout << "Clled \n";
    }
};
int main()
{
    vector<B> b(7);

    return 0;
}
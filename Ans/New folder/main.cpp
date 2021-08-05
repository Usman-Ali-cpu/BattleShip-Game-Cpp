#include <iostream>
using namespace std;

enum MM
{
    stw,
    rt,
    ty
};

int main()
{
    MM m = MM::stw;
    MM mm[6];

    for (int i = 0; i < 6; i++)
    {
        mm[i] = MM::rt;
    }
    if (mm[6 - 6] == MM::rt)
    {
        cout << "bdbd" << endl;
    }

    return 0;
}
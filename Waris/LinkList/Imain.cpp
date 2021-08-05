#include <iostream>
#include "IntList.cpp"
using namespace std;

int main()
{

    IntList li;
    li.push_back(2);

    li.push_back(3);
    li.push_back(2);
    li.push_back(4);
    cout<< li.empty();
    //li.clear();
    li = li;
    cout <<li;
    return 0;
}
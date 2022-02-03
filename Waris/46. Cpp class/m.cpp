#include <iostream>
#include "required.cpp"
using namespace std;

int main()
{
    Students st("n", "e", 2.3);
    st.print();
    Teachers te("t", "te", 2000);
    te.print();

    return 0;
}
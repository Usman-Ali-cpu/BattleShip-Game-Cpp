#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void printVector(std::vector<T> const &vec)
{
    for (int i = 0; i < vec.size(); i += 2)
    {
        cout << vec.at(i) << "\t" << vec.at(i + 1) << endl;
    }
}

int main()
{
    vector<int> v1 = {1, 2, 3, 4, 5, 6};
    vector<double> v2 = {1.2, 3.4, 5.6, 4.7, 6, 7};
    vector<char> v3 = {'a', 'b', 'c', 'd', 'e', 'f'};
    cout << "int:\n";
    printVector(v1);
    cout << "\nDoubles:\n";
    printVector(v2);
    cout << "\nChar:\n";
    printVector(v3);

    return 0;
}
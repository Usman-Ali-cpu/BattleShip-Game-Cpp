

#include <iostream> // input output header file
#include <vector>   // include vector to program
using namespace std;

void removeDuplicate(vector<int> &v) // passing vector of int by reference to function
{
    vector<int> n; // vector to store non duplicate values
    bool check = true;
    for (int i = 0; i < v.size(); i++) // loop through orignal vector
    {
        for (int j = 0; j < n.size(); j++) // loop through new vector of non duplicate values
        {

            if (n.at(j) == v.at(i)) // check if value is already present in new vector
            {
                check = false; // then make bool to false mean not to add.
            }
        }
        if (check) // if it is true
        {
            n.push_back(v.at(i)); // pushing in new vector if not present in it
        }
        check = true;
    }
    v.clear(); // empty the vector
    for (int i = 0; i < n.size(); i++)
    {
        v.push_back(n.at(i)); // push all values from new vector to orignal vector
    }
}

int main()
{
    vector<int> v; // empty vector
    cout << "Enter the vector elements:\n";
    int input;
    while ((cin >> input)) // input value while it is valid integer
    {
        if (!isdigit(input)) // check if this is digit
        {
            v.push_back(input); // add to vector
        }
        else
        {
            break; // stop input if it is not int
        }
    }

    removeDuplicate(v); // calling function to remove duplicates
    cout << "The deduplicated vector is: [";
    for (int i = 0; i < v.size(); i++)
    {
        if (i < v.size() - 1)
        {
            cout << v.at(i) << ","; // printing vector after removing
        }
        else
        {
            cout << v.at(i) << ""; // printing vector after removing
        }
    }
    cout << "]";
    return 0;
}
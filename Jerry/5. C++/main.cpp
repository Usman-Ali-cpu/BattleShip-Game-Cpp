#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

void fillVector(vector<int> &vect);
void addToEnd(vector<int> &vect);
void findHighLowSum(vector<int> vect);

int findIndex(vector<int> vect, int number);
void insertAtIndex(vector<int> vect, int idx, int number);
void removeAtIndex(vector<int> vect, int idx);

void removeNumber(vector<int> vect, int number);

int main()
{

    vector<int> vect;

    int choice;

    while (true)
    {
        cout << "\n\n0. Fill Vector" << endl;
        cout << "1. Find high, low, sum average" << endl;
        cout << "2. Add a number to the end" << endl;
        cout << "3. Find index of a number" << endl;
        cout << "4. Insert number at index" << endl;
        cout << "5. Remove number at index" << endl;
        cout << "6. Remove number" << endl;
        cout << "7. Quit" << endl;
        cout << "Enter : ";
        cin >> choice;
        switch (choice)
        {
        case 0:
            fillVector(vect);
            cout << endl;
            break;
        case 1:
        {
            if (vect.size() <= 0)
            {
                cout << "Vector is not yet created\n";
            }
            else
            {
                findHighLowSum(vect);
            }
        }

        break;
        case 2:
        {
            addToEnd(vect);
        }

        break;
        case 3:
        {
            if (vect.size() <= 0)
            {
                cout << "Vector is not yet created\n";
            }
            else
            {
                int n;
                cout << "Enter number to find: ";
                cin >> n;
                int idx = findIndex(vect, n);
                if (idx == -1)
                {
                    cout << n << " does not exist" << endl;
                }
                else
                {
                    cout << n << " is at index " << idx << endl;
                }
                for (int i = 0; i < vect.size(); i++)
                {
                    cout << vect.at(i) << " ";
                }
            }
        }
        break;
        case 4:
        {
            if (vect.size() <= 0)
            {
                cout << "Vector is not yet created\n";
            }
            else
            {
                int inum;
                cout << "Enter the number to insert: ";
                cin >> inum;
                cout << "Enter the index to insert : ";
                int indx;
                cin >> indx;
                insertAtIndex(vect, indx, inum);
            }
        }
        break;
        case 5:
        {
            if (vect.size() <= 0)
            {
                cout << "Vector is not yet created\n";
            }
            else
            {
                cout << "Enter the index to remove : ";
                int rindx;
                cin >> rindx;
                removeAtIndex(vect, rindx);
            }
        }
        /* code */
        break;
        case 6:
        {
            if (vect.size() <= 0)
            {
                cout << "Vector is not yet created\n";
            }
            else
            {
                cout << "Enter number to remove : ";
                int rnum;
                cin >> rnum;
                removeNumber(vect, rnum);
            }
        }
        /* code */
        break;
        case 7:
            cout << "Goodby.";
            exit(0);
            break;
        default:
            break;
        }
    }

    return 0;
}

void fillVector(vector<int> &vect)
{
    vect.clear();
    int num;
    cout << "Enter the length of the Vector: ";
    cin >> num;
    srand(time(NULL));
    for (int i = 0; i < num; i++)
    {
        int random_x;
        random_x = rand() % 99;
        cout << random_x << " ";
        vect.push_back(random_x);
    }
    cout << endl;
}
void addToEnd(vector<int> &vect)
{
    int random_x;
    random_x = rand() % 99;
    vect.push_back(random_x);
    for (int i = 0; i < vect.size(); i++)
    {
        cout << vect.at(i) << " ";
    }
}
void findHighLowSum(vector<int> vect)
{
    if (vect.size() <= 0)
    {
        cout << "Vector not yet created" << endl;
        return;
    }
    int sum = 0;
    for (int i = 0; i < vect.size(); i++)
    {
        sum += vect.at(i);
    }
    cout << "Sum is : " << sum << endl;
    cout << "Average is : " << sum / vect.size() << endl;
    int high = vect.at(0);
    for (int i = 0; i < vect.size(); i++)
    {
        if (vect.at(i) > high)
        {
            high = vect.at(i);
        }
    }
    cout << "Highest is : " << high << endl;
    int low = vect.at(0);
    for (int i = 0; i < vect.size(); i++)
    {
        if (vect.at(i) < low)
        {
            low = vect.at(i);
        }
    }
    cout << "Lowest is : " << low << endl;
}

int findIndex(vector<int> vect, int number)
{
    for (int i = 0; i < vect.size(); i++)
    {
        if (vect.at(i) == number)
        {

            return i;
            break;
        }
    }
    return -1;
}
void insertAtIndex(vector<int> vect, int idx, int number)
{
    if (idx < 0 || idx >= vect.size())
    {
        cout << "The specified index is outside the vector" << endl;
    }
    else
    {
        vect.insert(vect.begin() + idx, number);
        cout << endl;
        for (int i = 0; i < vect.size(); i++)
        {
            cout << vect.at(i) << " ";
        }
    }
}

void removeAtIndex(vector<int> vect, int idx)
{
    if (idx < 0 || idx >= vect.size())
    {
        cout << idx << " is outside the vector" << endl;
        return;
    }

    vector<int>::iterator it;

    it = vect.begin();
    int i = 0;

    for (auto it = vect.begin(); it != vect.end(); ++it)
    {
        if (i == idx)
        {
            vect.erase(it);
            return;
        }
        i++;
    }
}

void removeNumber(vector<int> vect, int number)
{

    vector<int>::iterator it;

    it = vect.begin();
    int i = 0;
    bool check = false;

    for (auto it = vect.begin(); it != vect.end(); ++it)
    {
        if (*it == number)
        {
            vect.erase(it);
            check = true;
        }
    }
    if (check == false)
    {
        cout << number << " does not exist\n"
             << endl;
    }
    for (int i = 0; i < vect.size(); i++)
    {
        cout << vect.at(i) << " ";
    }
}

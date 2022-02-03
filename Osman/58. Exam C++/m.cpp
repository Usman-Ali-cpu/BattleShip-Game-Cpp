#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Map_Type
{
    vector<string> vect;
};

Map_Type read_map()
{
    Map_Type t;
    string str;
    int count = 0;
    while (str != "DONE")
    {
        cin >> str;
        t.vect.push_back(str);
    }
    return t;
}

int find_treasures(Map_Type mapss, int range)
{
    int count = 0;
    if (range == 0)
    {
        return 0;
    }
    int x, y;
    for (int i = 0; i < mapss.vect.size(); i++)
    {
        string str = mapss.vect.at(i);
        for (int j = 0; j < str.length(); j++)
        {
            if (mapss.vect.at(i)[j] == 's')
            {
                x = i;
                y = j;
            }
        }
    }
    int left = y - range;
    int right = y + range;
    int top = x - range;
    int bottom = x + range;
    if (bottom > mapss.vect.size() - 1)
    {
        bottom = mapss.vect.size() - 1;
    }
    if (top < 0)
    {
        top = 0;
    }
    if (right > mapss.vect.at(x).length() - 1)
    {
        right = mapss.vect.at(x).length() - 1;
    }
    if (left < 0)
    {
        left = 0;
    }

    for (int i = 0; i < mapss.vect.size(); i++)
    {
        string str = mapss.vect.at(i);
        if (i >= top && i <= bottom)
        {
            for (int j = 0; j < str.length(); j++)
            {
                if (j >= left && j <= right)
                {
                    if (mapss.vect.at(i)[j] == 't')
                    {
                        count++;
                    }
                }
            }
        }
    }
    return count;
}
int main()
{
    Map_Type map;
    int range;

    cout << "Enter map:" << endl;
    map = read_map();

    cout << "Enter range: ";
    cin >> range;

    cout << "Found treasures: " << find_treasures(map, range);
    return 0;
}
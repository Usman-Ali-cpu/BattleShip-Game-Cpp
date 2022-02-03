#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
using namespace std;

int main()
{
    // fstream file;
    // string word;
    // string filename = "student7_Datafile.txt";

    // // opening file
    // file.open(filename.c_str());

    // // extracting words from the file
    // while (file >> word)
    // {
    //     // displaying content
    //     cout << word << endl;
    // }

    // ifstream file("student7_Datafile.txt");
    // string line;

    // while (getline(file, line))
    // {
    //     stringstream linestream(line);
    //     string data;
    //     int val1;
    //     int val2;

    //     // If you have truly tab delimited data use getline() with third parameter.
    //     // If your data is just white space separated data
    //     // then the operator >> will do (it reads a space separated word into a string).
    //     std::getline(linestream, data, '\t'); // read up-to the first tab (discard tab).

    //     // Read the integers using the operator >>
    //     linestream >> val1 >> val2;
    //     cout << val1;
    //     cout << val2;
    // }
    map<string, string> listMap;

    ifstream file("student7_Datafile.txt");
    string data = "";
    int i = 0;
    while (getline(file, data, '\n'))
    {
        if (i > 0)
        {
            int index = data.find_first_of(" ");
            string artist = data.substr(0, index);
            string num = data.substr(index + 1, data.length() - 1);
            cout << artist << "  " << num << endl;
            listMap.insert(pair<string, string>(artist, num));
        }
        i++;
    }
    file.close();

    map<string, string>::iterator itr;
    for (itr = listMap.begin(); itr != listMap.end(); ++itr)
    {
        cout << '\t' << itr->first
             << '\t' << itr->second << '\n';
    }
    cout << endl;
    cout << "Enter name of Artist : ";
    string name;
    getline(cin, name);
    for (itr = listMap.begin(); itr != listMap.end(); ++itr)
    {
        if (itr->first == name)
        {
            cout << '\t' << itr->first
                 << '\t' << itr->second << '\n';
        }
    }

    return 0;
}
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class File
{
protected:
    vector<string> reader(const string &fileName)
    {
        ifstream file;
        file.open(fileName);
        string data;
        vector<string> result;
        while (file.is_open() && !file.eof())
        {
            getline(file, data);
            if (!data.empty())
            {
                result.push_back(data);
            }
        }
        if (file.is_open())
            file.close();
        return result;
    }
    void writer(const string &fileName, const vector<string> &data)
    {
        ofstream file;
        file.open(fileName, ios::app);
        if (file.is_open())
        {
            for (string s : data)
            {
                file << s + "\n";
            }
            file.close();
        }
    }
    void clearwriter(const string &fileName, const vector<string> &data)
    {
        ofstream file;
        file.open(fileName);
        if (file.is_open())
        {
            for (string s : data)
            {
                file << s + "\n";
            }
            file.close();
        }
    }
};

#ifndef PLANET_H
#define PLANET_H

class Planet
{
private:
    string name;
    string system;
    string method;
    int year;
    string facility;
    double radius;
    double mass;
    int temperature;
    double habitability;

public:
    // default contructor
    Planet();

    // parameterized constructor
    Planet(string name, string system, string method, int year, string facility, double radius, double mass, int temperature, double habitability);

    // accessors
    string getName();
    string getSystem();
    string getYethod();
    int getYear();
    string getFacility();
    double getRadius();
    double getMass();
    int getTemperature();
    double getHabitability();

    // used to set the value of the habitability for the exoplanet,
    void setHabitability(double habitability);

    // relational operators
    bool operator<(const Planet &planet);
    bool operator>(const Planet &planet);

    // out & in sttream operators
    ostream &operator<<(ostream &out);
    istream &operator<<(istream &in);

    // destructor
    ~Planet();
};

Planet::Planet(/* args */)
{
}

Planet::~Planet()
{
}

#endif

void rewriter(const string &fileName, const vector<string> &data)
{
    ofstream file;       // file stream object to write data in it
    file.open(fileName); // open given file
    if (file.is_open())  // check if file is open or not
    {
        for (string s : data) // if file is open, loop through all strings in vector
        {
            file << s + "\n"; // write each string one by one
        }
        file.close(); // close file after writing
    }
}

void writer(const string &fileName, const vector<string> &data)
{
    ofstream file;                 // file stream object to write data
    file.open(fileName, ios::app); // open file to write data in append mode
    if (file.is_open())            // check if file is open or not
    {
        for (string s : data) // loop through all string in the vector
        {
            file << s + "\n"; // write each line
        }
        file.close(); // close the opened file
    }
}
vector<string> reader(const string &fileName)
{
    ifstream file;       // file stream object to read data
    file.open(fileName); // open file to read data
    string data;
    vector<string> result;
    while (file.is_open() && !file.eof()) // check while  file is open or not
    {
        getline(file, data); // read line  by line
        if (!data.empty())
        {
            result.push_back(data); // if data is not empty put this in a vector
        }
    }
    if (file.is_open()) // check if file is open
        file.close();   // then close the file
    return result;      // return read vector
}

void showAllPlanet(vector<string> planets)
{
    string name;
    string system;
    string method;
    int year;
    string facility;
    double radius;
    double mass;
    int temperature;
    double habitability;
    cout << "\t ==================================================================\n\n";
    cout << "\t ------------------------------------------------------------------\n";
    cout << "\t ||\t\t1.  All Planets \t\t\t ||\n\n";
    cout << "Name \t SYSTEM \t\tMethod \t\t Year \t   Facility \t   Radius \t Mass \t temperature  \n";
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";

    vector<string> get = planets; // store given vector through argument to new vector named get
    for (string s : get)          // loop through all strings in the vector
    {
        for (int i = 0; i < 8; i++) // loop how many entries are in a string separated by comma
        {
            bool checkstr = false;
            int index = s.find_first_of(','); // get index of first comma in the string
            switch (i)                        //   switch through entries
            {
            case 0: // if it is first entry
            {
                name = s.substr(2, index - 3); // store it in a name
                checkstr = true;
            }

            break;
            case 1: // if it is second  entry
            {
                system = s.substr(2, index - 3); // store that entry in model
                checkstr = true;
            }

            break;
            case 2:
            {
                checkstr = true;
                method = s.substr(2, index - 3); // store that entry in color

            } // if it is third  entry

            break;
            case 3:                              // if it is fourth entry
                year = stoi(s.substr(1, index)); // store that entry in price after converting that string to double
                break;
            case 4: // if it is fifth entry
            {
                checkstr = true;
                facility = s.substr(2, index - 3);
            }

            break;
            case 5:                                // if it is sixth entry
                radius = stod(s.substr(1, index)); // store that entry in display after converting that string to double
                break;
            case 6:                              // if it is seventh entry
                mass = stod(s.substr(1, index)); // store that entry in sim
                break;
            case 7:                                     // if it is eight entry
                temperature = stoi(s.substr(1, index)); // store that entry in noPhones after converting that string to int
                break;
            }
            // erase entries one by one
            if (checkstr == true)
            {
                s.erase(0, index + 1);
            }
            else
            {
                s.erase(0, index + 1);
            }
        }
        for (int i = 0; i < 8; i++)
        {
            switch (i) // switch through entries
            {
            case 0:                                         // if it is first entry
                cout << setw(10) << left << name << " \t "; // display brand
                break;
            case 1:                                          // if it is second entry
                cout << setw(6) << left << system << " \t "; // display model
                break;
            case 2:                                          // if it is thrid entry
                cout << setw(6) << left << method << " \t "; // display color
                break;
            case 3:                                         // if it is fourth entry
                cout << setw(5) << left << year << " \t\t"; // display price
                break;
            case 4:                                             // if it is fifth entry
                cout << setw(3) << left << facility << "\t   "; // display size of memory
                break;
            case 5:                                            // if it is sixth entry
                cout << setw(4) << left << radius << " \t   "; // display display size
                break;
            case 6: // if it is seventh entry

                cout << setw(4) << left << mass << " \t\t   "; // display if two sims

                break;
            case 7:                                                       // if it is eight entry
                cout << setw(3) << left << temperature << " \t " << endl; // display number of phones
                break;
            }
        }
    }
}

int main()
{
    vector<string> listPlanet;
    listPlanet = reader("exoplanets.txt");
    showAllPlanet(listPlanet);

    return 0;
}
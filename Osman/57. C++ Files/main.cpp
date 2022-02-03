#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

// function to write data in a text file
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
// function to get least memory from all mobile phones
int getLeastMemory(vector<string> get)
{
    int leastmemory = 345534; // store bigger number
    int memory;
    for (string s : get) // loop through all strings in the vector
    {
        // each string has 8 entries like brand model etc..
        for (int i = 0; i < 8; i++) // to get all comma separated entries
        {
            int index = s.find_first_of(','); // get index of first comma in the string
            switch (i)                        // switch through entries
            {
            case 4:                                // if it is 5th entry
                memory = stoi(s.substr(0, index)); // get memory with is 5th entry, and convert it to integer
                if (memory < leastmemory)          // check if memory is less than least memory we have
                {
                    leastmemory = memory; // update least memory if memory is less than previous one
                }
                break;
            default:
                break;
            }
            s.erase(0, index + 1); // remove entry from string from given index
        }
    }
    return leastmemory; // return least memory from all phones
}
vector<string> addingPhone(int num)
{
    vector<string> mobile;        // create vector of string
    for (int i = 0; i < num; i++) // loop how many mobile phones user want to add
    {
        string brand, model, color, sim; // to store different properties of phone
        double price, display;           // to store price price and display of phone
        int noPhones, memorysize;        // to store number of phones and memory size
        cout << "Enter Mobile Brand: ";
        getline(cin, brand); // input mobile brand
        cout << "Enter Mobile Model: ";
        getline(cin, model); // input mobile model
        cout << "Enter Mobile Color: ";
        getline(cin, color); // input color of mobile
        cout << "Enter Mobile Price: ";
        cin >> price; // input price of mobile phone
        cout << "Enter memory size: ";
        cin >> memorysize; // input memory size of phone
        cout << "Enter Display Diagonal : ";
        cin >> display; // input display diagonal size
        cout << "Mobile has two sim (Y/N): ";
        cin >> sim; // input whether it has two sims or not
        cout << "Enter number of phones this model has : ";
        cin >> noPhones; // enter number of phones of this model
        cin.clear();
        cin.ignore(); // remove input buffer
        if (sim == "Y")
        {
            sim = "T";
        }
        else
        {
            sim = "F";
        }
        string str = "";
        // create string to store each property
        str = brand + "," + model + "," + color + "," + to_string(price) + "," + to_string(memorysize) + "," + to_string(display) + "," + sim + "," + to_string(noPhones);
        mobile.push_back(str); // add string to vector
    }
    return mobile; // return vector containing detail of phones
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
void showAllMobile(vector<string> mobile)
{
    string brand, model, color, sim; // string variables to store data of phone
    double price, display;           // double type variable to store display size and price
    int noPhones, memorysize;        // int type variable to store no of phones  size and memory size
    cout << "\t ==================================================================\n\n";
    cout << "\t ------------------------------------------------------------------\n";
    cout << "\t ||\t\t1.  All Mobile Phones \t\t\t ||\n\n";
    cout << "Brand \t\tModel \t\tColor \t\t Price \t   Memory Size \t   Display \t Two Sims \t No. of Phones\n";
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";

    vector<string> get = mobile; // store given vector through argument to new vector named get
    for (string s : get)         // loop through all strings in the vector
    {
        for (int i = 0; i < 8; i++) // loop how many entries are in a string separated by comma
        {
            int index = s.find_first_of(','); // get index of first comma in the string
            switch (i)                        //   switch through entries
            {
            case 0:                         // if it is first entry
                brand = s.substr(0, index); // store it in a brand
                break;
            case 1:                         // if it is second  entry
                model = s.substr(0, index); // store that entry in model
                break;
            case 2:                         // if it is third  entry
                color = s.substr(0, index); // store that entry in color
                break;
            case 3:                               // if it is fourth entry
                price = stod(s.substr(0, index)); // store that entry in price after converting that string to double
                break;
            case 4: // if it is fifth entry
                memorysize = stoi(s.substr(0, index));
                break;
            case 5:                                 // if it is sixth entry
                display = stod(s.substr(0, index)); // store that entry in display after converting that string to double
                break;
            case 6:                       // if it is seventh entry
                sim = s.substr(0, index); // store that entry in sim
                break;
            case 7:                                  // if it is eight entry
                noPhones = stoi(s.substr(0, index)); // store that entry in noPhones after converting that string to int
                break;
            }
            s.erase(0, index + 1); // erase entries one by one
        }
        for (int i = 0; i < 8; i++)
        {
            switch (i) // switch through entries
            {
            case 0:                                          // if it is first entry
                cout << setw(10) << left << brand << " \t "; // display brand
                break;
            case 1:                                         // if it is second entry
                cout << setw(6) << left << model << " \t "; // display model
                break;
            case 2:                                         // if it is thrid entry
                cout << setw(6) << left << color << " \t "; // display color
                break;
            case 3:                                          // if it is fourth entry
                cout << setw(5) << left << price << " \t\t"; // display price
                break;
            case 4:                                                  // if it is fifth entry
                cout << setw(3) << left << memorysize << "GB \t   "; // display size of memory
                break;
            case 5:                                               // if it is sixth entry
                cout << setw(4) << left << display << "in \t   "; // display display size
                break;
            case 6: // if it is seventh entry
                if (sim == "T")
                {
                    cout << setw(4) << left << "YES \t\t   "; // display if two sims
                }
                else
                {
                    cout << setw(4) << left << "NO \t\t   "; // display if one sim
                }

                break;
            case 7:                                                    // if it is eight entry
                cout << setw(3) << left << noPhones << " \t " << endl; // display number of phones
                break;
            }
        }
    }
}
void showLeastMemory(vector<string> mobile, int leastmemory)
{
    string brand, model, color, sim; // string variables to store data of phone
    double price, display;           // double type variable to store display size and price
    int noPhones, memorysize;        // int type variable to store no of phones  size and memory size
    cout << "\t ==================================================================\n\n";
    cout << "\t ------------------------------------------------------------------\n";
    cout << "\t ||\t\t1.  Least Memory Sized Mobile Phones \t\t\t ||\n\n";
    cout << "Brand \t\tModel \t\tColor \t\t Price \t   Memory Size \t   Display \t Two Sims \t No. of Phones\n";
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
    vector<string> get = mobile; // store given vector through argument to new vector named get
    for (string s : get)         // loop through all strings in the vector
    {
        for (int i = 0; i < 8; i++) // loop how many entries are in a string separated by comma
        {
            int index = s.find_first_of(','); // get index of first comma in the string
            switch (i)                        //   switch through entries
            {
            case 0:                         // if it is first entry
                brand = s.substr(0, index); // store it in a brand
                break;
            case 1:                         // if it is second  entry
                model = s.substr(0, index); // store that entry in model
                break;
            case 2:                         // if it is third  entry
                color = s.substr(0, index); // store that entry in color
                break;
            case 3:                               // if it is fourth entry
                price = stod(s.substr(0, index)); // store that entry in price after converting that string to double
                break;
            case 4:                                    // if it is fifth entry
                memorysize = stoi(s.substr(0, index)); // store that entry in memory size after converting that string to int
                break;
            case 5:                                 // if it is sixth entry
                display = stod(s.substr(0, index)); // store that entry in display after converting that string to double
                break;
            case 6:                       // if it is seventh entry
                sim = s.substr(0, index); // store that entry in sim
                break;
            case 7:
                noPhones = stoi(s.substr(0, index));
                break;
            }
            s.erase(0, index + 1);
        }
        if (memorysize == leastmemory) // check if memory is equal to least memory
        {
            for (int i = 0; i < 8; i++)
            {
                switch (i) // switch through entries
                {
                case 0:                                          // if it is first entry
                    cout << setw(10) << left << brand << " \t "; // display brand
                    break;
                case 1:                                         // if it is second entry
                    cout << setw(6) << left << model << " \t "; // display model
                    break;
                case 2:                                         // if it is thrid entry
                    cout << setw(6) << left << color << " \t "; // display color
                    break;
                case 3:                                          // if it is fourth entry
                    cout << setw(5) << left << price << " \t\t"; // display price
                    break;
                case 4:                                                  // if it is fifth entry
                    cout << setw(3) << left << memorysize << "GB \t   "; // display memory size
                    break;
                case 5:                                               // if it is sixth entry
                    cout << setw(4) << left << display << "in \t   "; // display display size
                    break;
                case 6:
                    if (sim == "T")
                    {
                        cout << setw(4) << left << "YES \t\t   "; // display if two sims
                    }
                    else
                    {
                        cout << setw(4) << left << "NO \t\t   ";
                    }

                    break;
                case 7:                                                    // if it is eight entry
                    cout << setw(3) << left << noPhones << " \t " << endl; // display number of phones
                    break;
                }
            }
        }
    }
}
void showMobileTwoSim(vector<string> mobile)
{
    string brand, model, color, sim; // string variables to store data of phone
    double price, display;           // double type variable to store display size and price
    int noPhones, memorysize;        // int type variable to store no of phones  size and memory size
    cout << "\t ==================================================================\n\n";
    cout << "\t ------------------------------------------------------------------\n";
    cout << "\t ||\t\t1.  Mobile Phones With Two Sims Cards \t\t\t ||\n\n";
    cout << "Brand \t\tModel \t\tColor \t\t Price \t   Memory Size \t   Display \t Two Sims \t No. of Phones\n";
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
    vector<string> get = mobile;
    for (string s : get)
    {
        for (int i = 0; i < 8; i++) // loop how many entries are in a string separated by comma
        {
            int index = s.find_first_of(','); // get index of first comma in the string
            switch (i)                        //   switch through entries
            {
            case 0:                         // if it is first entry
                brand = s.substr(0, index); // store it in a brand
                break;
            case 1:                         // if it is second  entry
                model = s.substr(0, index); // store that entry in model
                break;
            case 2:                         // if it is third  entry
                color = s.substr(0, index); // store that entry in color
                break;
            case 3:                               // if it is fourth entry
                price = stod(s.substr(0, index)); // store that entry in price after converting that string to double
                break;
            case 4: // if it is fifth entry
                memorysize = stoi(s.substr(0, index));
                break;
            case 5:                                 // if it is sixth entry
                display = stod(s.substr(0, index)); // store that entry in display after converting that string to double
                break;
            case 6:                       // if it is seventh entry
                sim = s.substr(0, index); // store that entry in sim
                break;
            case 7:                                  // if it is eight entry
                noPhones = stoi(s.substr(0, index)); // store that entry in noPhones after converting that string to double
                break;
            }
            s.erase(0, index + 1); // erase entries one by one
        }
        if (sim == "T") // check if two sims are there
        {
            for (int i = 0; i < 8; i++)
            {
                switch (i) // switch through entries
                {
                case 0:                                          // if it is first entry
                    cout << setw(10) << left << brand << " \t "; // display brand
                    break;
                case 1:                                         // if it is second entry
                    cout << setw(6) << left << model << " \t "; // display model
                    break;
                case 2:                                         // if it is thrid entry
                    cout << setw(6) << left << color << " \t "; // display color
                    break;
                case 3:                                          // if it is fourth entry
                    cout << setw(5) << left << price << " \t\t"; // display price
                    break;
                case 4:                                                  // if it is fifth entry
                    cout << setw(3) << left << memorysize << "GB \t   "; // display memory size
                    break;
                case 5:                                               // if it is sixth entry
                    cout << setw(4) << left << display << "in \t   "; // display display size
                    break;
                case 6:
                    if (sim == "T")
                    {
                        cout << setw(4) << left << "YES \t\t   "; // display if two sims
                    }
                    else
                    {
                        cout << setw(4) << left << "NO \t\t   ";
                    }

                    break;
                case 7:                                                    // if it is eight entry
                    cout << setw(3) << left << noPhones << " \t " << endl; // display number of phones
                    break;
                }
            }
        }
    }
}

bool checkPhone(vector<string> mobile, string a_brand, string a_model)
{
    string brand, model;
    for (string s : mobile) // loop through all strings in the vector
    {
        // each string has 8 entries like brand model etc..
        for (int i = 0; i < 8; i++) // to get all comma separated entries
        {
            int index = s.find_first_of(','); // get index of first comma in the string
            switch (i)                        // switch through entries
            {
            case 0:                         // if it is first entry
                brand = s.substr(0, index); // get brand name
                break;
            case 1:                         // if it is 2nd entry
                model = s.substr(0, index); // get model name
                break;
            default:
                break;
            }
            s.erase(0, index + 1); // remove entry from string from given index
        }
        if (a_brand == brand && a_model == model) // if model and brand found
        {
            return true; // return good sign for it's existance
        }
    }
    return false;
}
vector<string> updatedetail(vector<string> mobile, string a_brand, string a_model)
{
    vector<string> updatemobiles;
    string brand, model, color, sim;
    double price, display;
    int noPhones, memorysize;
    string a_color, a_sim;
    double a_price, a_display;
    int a_noPhones, a_memorysize;
    cout << "Enter Mobile new Color: ";
    getline(cin, a_color); // input new color of mobile
    cout << "Enter Mobile new Price: ";
    cin >> a_price; // input new price  of mobile
    cout << "Enter new memory size: ";
    cin >> a_memorysize; // input new memory size of mobile
    cout << "Enter new Display Diagonal : ";
    cin >> a_display; // input new display size  of mobile
    cout << "Mobile has two sim (Y/N): ";
    cin >> a_sim; // input two sims or not  of mobile
    cout << "Enter new number of phones this model has : ";
    cin >> a_noPhones; // input number of phones  of model
    cin.ignore();
    bool bcheck = false, mcheck = false;
    vector<string> get = mobile; // store given vector through argument to new vector named get
    for (string s : get)         // loop through all strings in the vector
    {
        mcheck = false;
        bcheck = false;
        for (int i = 0; i < 8; i++) // loop how many entries are in a string separated by comma
        {
            int index = s.find_first_of(','); // get index of first comma in the string
            switch (i)                        //   switch through entries
            {
            case 0:                         // if it is first entry
                brand = s.substr(0, index); // store it in a brand
                if (brand == a_brand)       // if brand is same which is passed in argument to be updated
                {
                    bcheck = true;
                }
                break;
            case 1:
                model = s.substr(0, index);
                if (model == a_model) // if model is same which is passed in argument to be updated
                {
                    mcheck = true;
                }
                break;
            case 2:
                color = s.substr(0, index); // store that entry in color
                break;
            case 3:
                price = stod(s.substr(0, index)); // store that entry in price after converting that string to double
                break;
            case 4:
                memorysize = stoi(s.substr(0, index));
                break;
            case 5:
                display = stod(s.substr(0, index)); // store that entry in display after converting that string to double
                break;
            case 6:
                sim = s.substr(0, index);
                break;
            case 7:
                noPhones = stoi(s.substr(0, index)); // store that entry in noPhones after converting that string to int
                break;
            }
            s.erase(0, index + 1); // erase entries one by one
        }

        for (int i = 0; i < 8; i++)
        {
            switch (i) // switch through entries
            {
            case 0:
                if (bcheck == true && mcheck == true) // if brand and model are same to given to be updated
                    brand = a_brand;
                break;
            case 1:
                if (bcheck == true && mcheck == true) // if brand and model are same to given to be updated
                    model = a_model;                  // update model
                break;
            case 2:
                if (bcheck == true && mcheck == true) // if brand and model are same to given to be updated
                    color = a_color;                  // update color
                break;
            case 3:
                if (bcheck == true && mcheck == true) // if brand and model are same to given to be updated
                    price = a_price;                  // update price
                break;
            case 4:
                if (bcheck == true && mcheck == true) // if brand and model are same to given to be updated
                    memorysize = a_memorysize;        // update memory size
                break;
            case 5:
                if (bcheck == true && mcheck == true) // if brand and model are same to given to be updated
                    display = a_display;              // update display size
                break;
            case 6:
                if (bcheck == true && mcheck == true) // if brand and model are same to given to be updated
                    sim = a_sim;

                break;
            case 7:
                if (bcheck == true && mcheck == true) // if brand and model are same to given to be updated
                    noPhones = a_noPhones;            // update number of hpnes
                break;
            }
        }
        string str = "";
        str = brand + "," + model + "," + color + "," + to_string(price) + "," + to_string(memorysize) + "," + to_string(display) + "," + sim + "," + to_string(noPhones); // create updated string
        updatemobiles.push_back(str);                                                                                                                                      // push in vector
    }
    return updatemobiles;
}
int getNumberOfPhones(vector<string> mobile, string a_brand, string a_model)
{
    string brand, model;
    int noPhones;
    for (string s : mobile) // loop through all strings in the vector
    {
        for (int i = 0; i < 8; i++) // loop how many entries are in a string separated by comma
        {
            int index = s.find_first_of(','); // get index of first comma in the string
            switch (i)                        //   switch through entries
            {
            case 0: // if it is first entry
                brand = s.substr(0, index);
                break;
            case 1: // if it is second entry
                model = s.substr(0, index);
                break;
            case 7: // if it is eight entry
                noPhones = stoi(s.substr(0, index));
                break;
            default:
                break;
            }
            s.erase(0, index + 1);
        }
        if (a_brand == brand && a_model == model) // if brand and model are same to given
        {
            return noPhones; // return number of phones
        }
    }
    return -1;
}
vector<string> saleMobile(vector<string> mobile, string a_brand, string a_model)
{
    int totalphone = getNumberOfPhones(mobile, a_brand, a_model);
    int salephone;
    cout << "Enter number of phone to sale : ";
    cin >> salephone;
    cout << "Mobile sale : " << salephone << endl;
    cout << "Total Phoen: " << totalphone << endl;

    while (salephone > totalphone)
    {
        cout << "You don't have enough phones!" << endl;
        cout << "You have " << totalphone << " to sale " << endl;
        cout << "Enter number of phone to sale : ";
        cin >> salephone;
    }
    // cin.ignore();
    vector<string> updatemobiles;
    string brand, model, color, sim;
    double price, display;
    int noPhones, memorysize;

    bool bcheck = false, mcheck = false;
    vector<string> get = mobile;
    for (string s : get)
    {
        mcheck = false;
        bcheck = false;
        for (int i = 0; i < 8; i++)
        {
            int index = s.find_first_of(',');
            switch (i)
            {
            case 0:
                brand = s.substr(0, index);
                if (brand == a_brand)
                {
                    bcheck = true;
                }
                break;
            case 1:
                model = s.substr(0, index);
                if (model == a_model)
                {
                    mcheck = true;
                }
                break;
            case 2:
                color = s.substr(0, index);
                break;
            case 3:
                price = stod(s.substr(0, index));
                break;
            case 4:
                memorysize = stoi(s.substr(0, index));
                break;
            case 5:
                display = stod(s.substr(0, index));
                break;
            case 6:
                sim = s.substr(0, index);
                break;
            case 7:
                noPhones = stoi(s.substr(0, index));
                break;
            }
            s.erase(0, index + 1);
        }

        for (int i = 0; i < 8; i++)
        {
            switch (i)
            {
            case 7:
                if (bcheck == true && mcheck == true)
                {
                    cout << "Decrease" << endl;
                    noPhones = noPhones - salephone;
                }
                break;
            default:
                break;
            }
        }
        string str = "";
        str = brand + "," + model + "," + color + "," + to_string(price) + "," + to_string(memorysize) + "," + to_string(display) + "," + sim + "," + to_string(noPhones);
        updatemobiles.push_back(str);
    }
    return updatemobiles;
}
void reviewByBrand(vector<string> mobile, string a_brand)
{
    string brand, model, color, sim;
    double price, display;
    int noPhones, memorysize;
    cout << "\t ==================================================================\n\n";
    cout << "\t ------------------------------------------------------------------\n";
    cout << "\t ||\t\t1.  Review Mobile By Brand \t\t\t ||\n\n";
    cout << "Brand \t\tModel \t\tColor \t\t Price \t   Memory Size \t   Display \t Two Sims \t No. of Phones\n";
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";

    vector<string> get = mobile;
    for (string s : get)
    {
        for (int i = 0; i < 8; i++) // loop how many entries are in a string separated by comma
        {
            int index = s.find_first_of(','); // get index of first comma in the string
            switch (i)                        //   switch through entries
            {
            case 0:                         // if it is first entry
                brand = s.substr(0, index); // store it in a brand
                break;
            case 1:                         // if it is second  entry
                model = s.substr(0, index); // store that entry in model
                break;
            case 2:                         // if it is third  entry
                color = s.substr(0, index); // store that entry in color
                break;
            case 3:                               // if it is fourth entry
                price = stod(s.substr(0, index)); // store that entry in price after converting that string to double
                break;
            case 4: // if it is fifth entry
                memorysize = stoi(s.substr(0, index));
                break;
            case 5:                                 // if it is sixth entry
                display = stod(s.substr(0, index)); // store that entry in display after converting that string to double
                break;
            case 6:                       // if it is seventh entry
                sim = s.substr(0, index); // store that entry in sim
                break;
            case 7:                                  // if it is eight entry
                noPhones = stoi(s.substr(0, index)); // store that entry in noPhones after converting that string to int
                break;
            }
            s.erase(0, index + 1); // erase entries one by one
        }

        if (brand == a_brand)
        {
            for (int i = 0; i < 8; i++)
            {
                switch (i)
                {
                case 0:
                    cout << setw(10) << left << brand << " \t ";
                    break;
                case 1:
                    cout << setw(6) << left << model << " \t ";
                    break;
                case 2:
                    cout << setw(6) << left << color << " \t ";
                    break;
                case 3:
                    cout << setw(5) << left << price << " \t\t";
                    break;
                case 4:
                    cout << setw(3) << left << memorysize << "GB \t   ";
                    break;
                case 5:
                    cout << setw(4) << left << display << "in \t   ";
                    break;
                case 6:
                    if (sim == "T")
                    {
                        cout << setw(4) << left << "YES \t\t   ";
                    }
                    else
                    {
                        cout << setw(4) << left << "NO \t\t   ";
                    }

                    break;
                case 7:
                    cout << setw(3) << left << noPhones << " \t " << endl;
                    break;
                }
            }
        }
    }
}
void reviewBydisplay(vector<string> mobile, double a_display)
{
    string brand, model, color, sim;
    double price, display;
    int noPhones, memorysize;
    cout << "\t ==================================================================\n\n";
    cout << "\t ------------------------------------------------------------------\n";
    cout << "\t ||\t\t1.  Review Mobile By Brand \t\t\t ||\n\n";
    cout << "Brand \t\tModel \t\tColor \t\t Price \t   Memory Size \t   Display \t Two Sims \t No. of Phones\n";
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";

    vector<string> get = mobile;
    for (string s : get)
    {
        for (int i = 0; i < 8; i++) // loop how many entries are in a string separated by comma
        {
            int index = s.find_first_of(','); // get index of first comma in the string
            switch (i)                        //   switch through entries
            {
            case 0:                         // if it is first entry
                brand = s.substr(0, index); // store it in a brand
                break;
            case 1:                         // if it is second  entry
                model = s.substr(0, index); // store that entry in model
                break;
            case 2:                         // if it is third  entry
                color = s.substr(0, index); // store that entry in color
                break;
            case 3:                               // if it is fourth entry
                price = stod(s.substr(0, index)); // store that entry in price after converting that string to double
                break;
            case 4: // if it is fifth entry
                memorysize = stoi(s.substr(0, index));
                break;
            case 5:                                 // if it is sixth entry
                display = stod(s.substr(0, index)); // store that entry in display after converting that string to double
                break;
            case 6:                       // if it is seventh entry
                sim = s.substr(0, index); // store that entry in sim
                break;
            case 7:                                  // if it is eight entry
                noPhones = stoi(s.substr(0, index)); // store that entry in noPhones after converting that string to int
                break;
            }
            s.erase(0, index + 1); // erase entries one by one
        }

        if (display == a_display)
        {
            for (int i = 0; i < 8; i++)
            {
                switch (i)
                {
                case 0:
                    cout << setw(10) << left << brand << " \t ";
                    break;
                case 1:
                    cout << setw(6) << left << model << " \t ";
                    break;
                case 2:
                    cout << setw(6) << left << color << " \t ";
                    break;
                case 3:
                    cout << setw(5) << left << price << " \t\t";
                    break;
                case 4:
                    cout << setw(3) << left << memorysize << "GB \t   ";
                    break;
                case 5:
                    cout << setw(4) << left << display << "in \t   ";
                    break;
                case 6:
                    if (sim == "T")
                    {
                        cout << setw(4) << left << "YES \t\t   ";
                    }
                    else
                    {
                        cout << setw(4) << left << "NO \t\t   ";
                    }

                    break;
                case 7:
                    cout << setw(3) << left << noPhones << " \t " << endl;
                    break;
                }
            }
        }
    }
}
void reviewNewToOld(vector<string> mobile)
{
    string brand, model, color, sim;
    double price, display;
    int noPhones, memorysize;
    cout << "\t ==================================================================\n\n";
    cout << "\t ------------------------------------------------------------------\n";
    cout << "\t ||\t\t1.  Review Newest To Oldest \t\t\t ||\n\n";
    cout << "Brand \t\tModel \t\tColor \t\t Price \t   Memory Size \t   Display \t Two Sims \t No. of Phones\n";
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";

    reverse(mobile.begin(), mobile.end());
    vector<string> get = mobile;
    for (string s : get)
    {
        for (int i = 0; i < 8; i++) // loop how many entries are in a string separated by comma
        {
            int index = s.find_first_of(','); // get index of first comma in the string
            switch (i)                        //   switch through entries
            {
            case 0:                         // if it is first entry
                brand = s.substr(0, index); // store it in a brand
                break;
            case 1:                         // if it is second  entry
                model = s.substr(0, index); // store that entry in model
                break;
            case 2:                         // if it is third  entry
                color = s.substr(0, index); // store that entry in color
                break;
            case 3:                               // if it is fourth entry
                price = stod(s.substr(0, index)); // store that entry in price after converting that string to double
                break;
            case 4: // if it is fifth entry
                memorysize = stoi(s.substr(0, index));
                break;
            case 5:                                 // if it is sixth entry
                display = stod(s.substr(0, index)); // store that entry in display after converting that string to double
                break;
            case 6:                       // if it is seventh entry
                sim = s.substr(0, index); // store that entry in sim
                break;
            case 7:                                  // if it is eight entry
                noPhones = stoi(s.substr(0, index)); // store that entry in noPhones after converting that string to int
                break;
            }
            s.erase(0, index + 1); // erase entries one by one
        }
        for (int i = 0; i < 8; i++)
        {
            switch (i)
            {
            case 0:
                cout << setw(10) << left << brand << " \t ";
                break;
            case 1:
                cout << setw(6) << left << model << " \t ";
                break;
            case 2:
                cout << setw(6) << left << color << " \t ";
                break;
            case 3:
                cout << setw(5) << left << price << " \t\t";
                break;
            case 4:
                cout << setw(3) << left << memorysize << "GB \t   ";
                break;
            case 5:
                cout << setw(4) << left << display << "in \t   ";
                break;
            case 6:
                if (sim == "T")
                {
                    cout << setw(4) << left << "YES \t\t   ";
                }
                else
                {
                    cout << setw(4) << left << "NO \t\t   ";
                }

                break;
            case 7:
                cout << setw(3) << left << noPhones << " \t " << endl;
                break;
            }
        }
    }
}
int main()
{
    vector<string> mobiles = reader("file.txt"); // read data from file and store in vector
    vector<string> addedmobiles;
    while (true) // loop infinite times
    {
        int choice; // int variable to take choice
        // All menu options
        cout << "\n******************************************" << endl;
        cout << "******************************************" << endl;
        cout << "Enter 1. Add new Phone" << endl;
        cout << "Enter 2. Add list of Phones" << endl;
        cout << "Enter 3. Show All Phones on screen" << endl;
        cout << "Enter 4. Show Phones with least memory" << endl;
        cout << "Enter 5. Show Phones with two sim cards" << endl;
        cout << "Enter 6. Adjust Data of Phone" << endl;
        cout << "Enter 7. Sale Mobile Phone" << endl;
        cout << "Enter 8. Review By Brand" << endl;
        cout << "Enter 9. Review Display Size" << endl;
        cout << "Enter 10. Review Newest To Oldest" << endl;
        cout << "Enter 11. To Quit" << endl;
        cout << "******************************************" << endl;
        cout << "******************************************" << endl;
        cout << "Enter choice: ";
        cin >> choice; // input to take choice
        switch (choice)
        {
        case 1: // if choice is one
        {
            cin.ignore();
            addedmobiles = addingPhone(1);    // call function to add a phone
            writer("file.txt", addedmobiles); // update text file by writing
            mobiles = reader("file.txt");     // take data from file
        }

        break;
        case 2:
        {

            int num;
            cout << "How many mobiles in the list : ";
            cin >> num; // input how many phones user want to enter
            cin.ignore();
            addedmobiles = addingPhone(num);  // call function to add phones
            writer("file.txt", addedmobiles); // update text file by writing
            mobiles = reader("file.txt");     // take data from file
        }
        break;
        case 3:
        {

            mobiles = reader("file.txt"); // read data from file
            showAllMobile(mobiles);       // display all phones in the file
        }
        break;
        case 4:
        {

            mobiles = reader("file.txt"); // read data from file
            int leastmem = getLeastMemory(mobiles);
            showLeastMemory(mobiles, leastmem); // display all phones in the file with least memory
        }
        /* code */
        break;
        case 5:
        {
            mobiles = reader("file.txt"); // read data from file
            showMobileTwoSim(mobiles);    // display all phones in the file with two sim cards
        }

        /* code */
        break;
        case 6:
        {
            mobiles = reader("file.txt"); // read data from file
            string ubrand, umodel;
            cin.ignore();
            cout << "Enter Mobile Brand to adjust: ";
            getline(cin, ubrand); // take input brand name

            cout << "Enter Mobile Model to adjust: ";
            getline(cin, umodel);                  // take input model name
            updatedetail(mobiles, ubrand, umodel); // call the fuction to update details
        }
        /* code */
        break;
        case 7:
        {
            mobiles = reader("file.txt"); // read data from file
            cin.ignore();
            string sbrand, smodel;
            cout << "Enter Mobile Brand to adjust: ";
            getline(cin, sbrand); // take input brand name
            cout << "Enter Mobile Model to adjust: ";
            getline(cin, smodel);                                               // take input model name
            vector<string> updatedphones = saleMobile(mobiles, sbrand, smodel); //  call sale model function
            rewriter("file.txt", updatedphones);                                // store updated result
        }
        /* code */
        break;
        case 8:
        {

            mobiles = reader("file.txt"); // read data from file
            cin.ignore();
            string rbrand;
            cout << "Enter Mobile Brand to review: ";
            getline(cin, rbrand); // input brand name
            cin.ignore();
            reviewByBrand(mobiles, rbrand); // review brand
        }
        /* code */
        break;
        case 9:
        {

            mobiles = reader("file.txt"); // read data from file
            double rdisplay;
            cout << "Enter Mobile display to review: ";
            cin >> rdisplay; // input display size of mobiles
            cin.ignore();
            reviewBydisplay(mobiles, rdisplay); // review display size
        }
        /* code */
        break;
        case 10:
        {

            mobiles = reader("file.txt"); // read data from file
            reviewNewToOld(mobiles);      // display the review phones from new to old
        }
        /* code */
        break;
        case 11:
            exit(0); // To Quit or terminate the program

            break;

        default:
            cout << "Invalid choice! " << endl; // show invlaid input to user
            break;
        }
    }

    return 0;
}
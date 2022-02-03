#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    fstream file;
    file.open("input.txt", ios::in); //open a file to perform read operation using file object
    string name, type, num;

    if (file.is_open())
    { //checking whether the file is open
        getline(file, name);
        getline(file, type);
        getline(file, num);
    }
    int free;
    float rate;

    int n = stoi(num);
    if (type == "R" || type == "r")
    {
        float r = 1.5;
        if (n > 50)
        {
            string first = "Regular Servive";
            string second = "50 minutes are free for 40 AED";
            int firstnum = 50;
            n -= 50;
            rate = n * 1.5;
            string third = n + " minutes as extra for " + to_string(n) + " * " + to_string(r) + " = " + to_string(rate) + " AED";
            string fourth = "Total Bill = " + to_string((firstnum + rate)) + " AED";
            cout << first << endl;
            cout << second << endl;
            cout << third << endl;
            cout << fourth << endl;
            string filename = name + ".txt";
            cout << first << endl;
            ofstream wfile;

            wfile.open(filename);

            if (!wfile)
            {
                cout << "Error in creating file!!!" << endl;
                return 0;
            }

            cout << "File created successfully." << endl;
            //write text into file
            wfile << first << "\n";
            wfile << second << "\n";
            wfile << third << "\n";
            wfile << fourth << "\n";
            //closing the file
            wfile.close();
        }
        else
        {
            string first = "Regular Servive";
            string second = "50 minutes are free for 40 AED";
            int firstnum = 50;
            n -= 50;
            if (n < 0)
            {
                n = 0;
            }
            rate = n * 1.5;
            string third = n + " minutes as extra for " + to_string(n) + " * " + to_string(r) + " = " + to_string(rate) + " AED";
            string fourth = "Total Bill = " + to_string((firstnum + rate)) + " AED";
            cout << first << endl;
            cout << second << endl;
            cout << third << endl;
            cout << fourth << endl;
            string filename = name + ".txt";
            cout << first << endl;
            ofstream wfile;

            wfile.open(filename);

            if (!wfile)
            {
                cout << "Error in creating file!!!" << endl;
                return 0;
            }

            cout << "File created successfully." << endl;
            //write text into file
            wfile << first << "\n";
            wfile << second << "\n";
            wfile << third << "\n";
            wfile << fourth << "\n";
            cout << first << "\n";
            cout << second << "\n";
            cout << third << "\n";
            cout << fourth << "\n";
            //closing the file
            wfile.close();
        }
    }
    if (type == "p" || type == "P")
    {
        string snum2;
        getline(file, snum2);
        int num2 = stoi(snum2);
        int num1 = stoi(num);
        string first = "Premium Service";
        if (num1 > 75)
        {
            string second = "75 morning minutes & 100 evening minutes for free for 100 AED";
            string third, fourth;
            float rate1 = 0.75;
            float n1 = num1 - 75;
            float r1 = n1 * 0.75;
            float r2;
            third = to_string(n1) + " morning minutes extra as for " + to_string(1) + " * " + to_string(rate1) + " = " + to_string(r1) + "AED";
            float rate2 = 0.25;
            if (num2 > 100)
            {
                fourth = "0 evening minutes as extra for 0  * " + to_string(rate2) + " = " + to_string(rate2 * 0) + " AED";
            }
            else if (num2 < 100)
            {
                float rate2 = 0.25;
                float n2 = num2 - 100;
                if (n2 < 0)
                {
                    n2 = 0;
                }
                r2 = n2 * rate2;
                fourth = to_string(n2) + " evening minutes as extra for " + to_string(n2) + " * " + to_string(rate2) + " = " + to_string(rate2 * 0) + " AED";
            }
            string fifth = "Total Bill = " + to_string(r1 + r2 + 100) + " AED";
            ofstream wfile;
            string filename = name + ".txt";
            wfile.open(filename);

            if (!wfile)
            {
                cout << "Error in creating file!!!" << endl;
                return 0;
            }

            cout << "File created successfully." << endl;
            //write text into file
            wfile << first << "\n";
            wfile << second << "\n";
            wfile << third << "\n";
            wfile << fourth << "\n";
            wfile << fifth;
            cout << first << "\n";
            cout << second << "\n";
            cout << third << "\n";
            cout << fourth << "\n";
            cout << fifth;
            //closing the file
            wfile.close();
        }
        else if (num1 < 75)
        {
            string second = "75 morning minutes & 100 evening minutes for free for 100 AED";
            string third, fourth;
            float rate1 = 0.75;
            float n1 = num1 - 75;
            float r1 = n1 * 0.75;
            if (n1 < 0)
            {
                n1 = 0;
            }
            float r2;
            third = to_string(n1) + " morning minutes extra as for " + to_string(1) + " * " + to_string(rate1) + " = " + to_string(r1) + "AED";
            float rate2 = 0.25;
            if (num2 > 100)
            {
                fourth = "0 evening minutes as extra for 0  * " + to_string(rate2) + " = " + to_string(rate2 * 0) + " AED";
            }
            else if (num2 < 100)
            {
                float rate2 = 0.25;
                float n2 = num2 - 100;
                if (n2 < 0)
                {
                    n2 = 0;
                }
                r2 = n2 * rate2;
                fourth = to_string(n2) + " evening minutes as extra for " + to_string(n2) + " * " + to_string(rate2) + " = " + to_string(rate2 * 0) + " AED";
            }
            string fifth = "Total Bill = " + to_string(r1 + r2 + 100) + " AED";
            ofstream wfile;
            string filename = name + ".txt";
            wfile.open(filename);

            if (!wfile)
            {
                cout << "Error in creating file!!!" << endl;
                return 0;
            }

            cout << "File created successfully." << endl;
            //write text into file
            wfile << first << "\n";
            wfile << second << "\n";
            wfile << third << "\n";
            wfile << fourth << "\n";
            wfile << fifth;
            //closing the file
            wfile.close();
        }
    }

    return 0;
}
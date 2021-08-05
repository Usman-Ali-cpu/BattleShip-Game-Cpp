#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main(){
    string pqr;
    cout<< "Enter your full name : ";
    getline(cin, pqr);

    ifstream sal_file;
    sal_file.open("input_file.txt");

    if(!sal_file)
    {
        cout<< "Salary File Read Error! "<< endl;
    }
    ofstream foofile;
    foofile.open("gains_file.html");

    int id = 1;
    cout<< "id" << "\t"<< "salary" << "\t" << "salary_12%"<< endl;
    foofile<< "id" << "&nbsp; &nbsp; &nbsp;" << "salary"<< "&nbsp; &nbsp; &nbsp;"<< "&nbsp; &nbsp; &nbsp;"<< "sal12"<< "<br>";

    if (sal_file.is_open()){   //checking whether the file is open
      string tp;
      while(getline(sal_file, tp)){ //read data from file object and put it into string.
        // cout << tp << "\n"; //print the data of the string
        double salary = stod(tp);
        double sal12 = salary * 12 * 0.01;
        cout<< id<< "\t" << salary<< "\t " << sal12<< endl;
        id++;
        foofile<< id << " &nbsp; &nbsp; &nbsp;" << salary<<  " &nbsp; &nbsp; &nbsp;"<<"&nbsp;"<< sal12<< "<br>";
      }
      sal_file.close(); //close the file object.
      
   }
    foofile<< "<br>"<< "<br>"<< "<br>Name:  "<<pqr;

    foofile.close();



    return 0;
}
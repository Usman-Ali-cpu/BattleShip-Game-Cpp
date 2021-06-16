#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>  // to use string vector 
#include <fstream> // to file handling include it
using namespace std;

class File{
protected:
    vector<string> reader(const string & fileName) {
		ifstream file; // to read file 
		file.open(fileName); // open the file 
		string data;
		vector<string> result;  // vector to string to place data after reading 
		while (file.is_open() && !file.eof()) {  // read while file end and file is open 
			getline(file, data);  // get each line and store in string 
			if (!data.empty()) {  
				result.push_back(data);  // push string in vector 
			}
		}
		if(file.is_open())
			file.close();  // close the file 
		return result;  // return vector 
	}
	void writer(const string & fileName, const vector<string>& data) {
		ofstream file;   // to write into file 
		file.open(fileName,ios::in | ios::out |ios::app);  // open the file to write 
		if (file.is_open()) {
			for (string s : data) {  // take string in each loop while data has any string 
				file << s + "\n";  // write into file
			}
			file.close();  // close the file 
		}
	}
};

class Employee{
public:
    int * hours;  // pointer to int for pointing array
    string name; // to store name of employee
    string catagory;  // to store catagory w
    float rate;  // to store rate for especially F3
    int amount;   // to store amount for especially F3
    int size;       // to declare size of hours array
    double totalSalary;  // total salary 

// default constructor 
    Employee(){ 
        hours = new int [5];
        name = " ";
        catagory = " ";
        amount = 0;
        rate = 0;
    }
    // assignment operator 
    Employee & operator=(Employee &oper){
        this->hours = oper.hours;
        this->name = oper.name;
        this->catagory = oper.catagory;
        this->rate = oper.rate;
        this->amount = oper.amount;
        this->size = oper.size;
        this->totalSalary = oper.totalSalary;
        return *this;
    }
    // parameterize constructor 
    Employee(int a_size, string a_name, string cata, int arr[]){
        size = a_size;
        hours = new int [size];
        for (int i = 0; i < size; i++){
            hours[i] = arr[i];
        }
        name = a_name;
        catagory = cata;
        rate = 11.25;
        amount = 0;
    }
    // get total salary of employee
    double getSalary(){
        // if else is appllied 
        if(catagory== "F1"){
            return totalSalary = gethours() * 11.25;  // by multiplying total hours by 11.25
        }else 
        if(catagory== "F2"){
            return totalSalary = (gethours() - 35) * 18.95 + 400; // first get total hours and then calculate total salary 
        }else
        if(catagory== "F3"){
            return totalSalary = amount * rate; // by mulltiplying amount with rate 
        }else
        if(catagory== "F4"){
            return totalSalary = getfivehour() * 22.55 + getLastTwoHour() * 48.75; //  get first 5 seperate and last 2 separate and then calculate total salary 
        }
        return 0;
    }
    // paramterize constructor 
    Employee(string a_name,int a_amount , float a_rate, string cata){
        name = a_name;
        catagory = cata;
        rate = a_rate;
        amount = a_amount;
    }
    // get total hours of employee 
    int gethours(){
        int sum = 0;
        for (int i = 0; i < size; i++){
            sum += hours[i];
        }
        return sum;
    }

    // get first five hours of employee like F4
    int getfivehour(){
        int sum = 0;
        for (int i = 0; i < 5; i++){
            sum += hours[i];
        }
        return sum;
    }
    // get last two hours of employee like F4
    int getLastTwoHour(){
        int sum = 0;
        for (int i = 5; i < size; i++){
            sum += hours[i];
        }
        return sum;
    }
    // get total employee hours on define catagory 
    int getEmphour(){
        if(catagory== "F1"){
            return getfivehour();
        }else 
        if(catagory== "F2"){
            return getfivehour();
        }else
        if(catagory== "F3"){
            if(rate<= 10){
                return 30;
            }
            if(rate> 10){
                return 40;
            }
        }else
        if(catagory== "F4"){
            return getfivehour() + getLastTwoHour();
        }
        return 0;
    }

    

    
    
};

// inheriting class File 
class Department: public File{
    string catagory;  
    Employee *ITEmp; // pointer to Employee to point array  for First depart
    Employee *saleEmp; // pointer to Employee to point array for second depart
    int num1;  // number of employee in a department first
    int num2; // number of employee in a department second

public:
    string filename; // store file name 
    // defualt constructor
    Department(string f){
        filename = f;
        num1 = checkITEmp();
        num2 = checkSaleEmp();
        ITEmp = new Employee[num1];
        saleEmp = new Employee[num2];
    }
    // to get data 
    vector<string>readData(){
        return reader(filename);
    }
    // check number of employees in depart // read from file 
    int checkITEmp(){
        int emp = -1;
        vector<string> get = readData();
        int i = 0;
        for(string s : get){
            char e = s[s.length() - 1];           
            if(e != '1' && e != '2' && e != '3' && e != '4'){  // check whether string is data or heading 
            // it would check if at the end of line there would be catagory 
                if(i!=0){ // check for first line 
                    num1 = emp;
                    return emp;
                }
            }
            emp++;
            i++;   
        }
        num1 = emp;
        return emp;
    }
    // check number of employees in sencond depart // read from file 
    int checkSaleEmp(){
        int emp = -2;
        vector<string> get = readData();
        for(string s : get){
            if(s == "EOF"){ // at the EOF it would break
                break;
            }
            emp++;
        }
        num2 = emp - num1;
        return num2;
    }

    // process First depart 
    void ITdepart(){
        int ch = checkITEmp();
        int count = 0;
        int t = 0;

        vector<string> get = readData(); // geting data in get vector
        for(string s : get){   // while get has any string 
            int e = s[s.length() - 1]-48; 
            if(count>=num1){
                break;
            }
            else 
            if(e != 1 &&  e != 2 && e != 3 && e != 4 ){ // if it is heading / not data it would skip 
                continue; // to skip iteration
            }
            else {

                int c = s[s.length() - 1]-48;  // to get catagory of employee
                switch (c)
                {
                    case 1: // if catagory id F1
                    {
                        int hours[5];   // for storing 5 hour data 
                        string name;

                        for (int i = 0; i < 7; i++){  // total data is 7 separated by space, So looping 7 time  
                            int index = s.find_first_of(' '); // index of first space 
                            switch (i)
                            {
                                case 0: // if first space is found 
                                {
                                    name = s.substr(0, index);  // store name 
                                    break;
                                }
                                case 1: // if second  space is found 
                                {
                                    hours[0] = atoi(s.substr(0, index).cstr()); // store first day hours, convert to int 
                                    break;
                                }
                                case 2: // if third space is found 
                                {
                                    hours[1] = stoi(s.substr(0, index)); // store second day hours , convert to int
                                    break;
                                }
                                case 3: // if fourth space is found 
                                {
                                    hours[2] = stoi(s.substr(0, index)); // store third day hours , convert to int
                                    break;
                                }
                                case 4: // if fifth space is found 
                                {
                                    hours[3] = stoi(s.substr(0, index)); // store fourth day hours , convert to int
                                    break;
                                }
                                case 5: // if sixth space is found 
                                {                       
                                    hours[4] = stoi(s.substr(0, index)); // store fifth day hours , convert to int
                                    break;
                                }
                                case 6: // if seventh space is found 
                                {
                                    catagory = s.substr(0, index); // store catagory
                                    break;
                                }
                            }
                            s.erase(0, index + 1); // for each  case remove previous string 
                        }
                        Employee e(5, name, catagory, hours); // make object 
                        ITEmp[t] = e;  // assign data of employee
                        t++;
                        break;
                    }

                    case 2: // if catagory id F2
                    {
                        int hours[5];  // for storing 5 hour data 
                        string name;
                        for (int i = 0; i < 7; i++){   // total data is 7 separated by space, So looping 7 time  
                            int index = s.find_first_of(' ');  // index of first space each time 
                            switch (i)  
                            {
                                case 0:  // if first space is found 
                                {
                                    name = s.substr(0, index);
                                    break;
                                }
                                case 1:  // if second  space is found 
                                {
                                    hours[0] = stoi(s.substr(0, index)); // store first day hours, convert to int 
                                    break;
                                }
                                case 2:  // if third space is found 
                                {
                                    hours[1] = stoi(s.substr(0, index)); // store second day hours, convert to int 
                                    break;
                                }
                                case 3:  // if fifth space is found 
                                {
                                    hours[2] = stoi(s.substr(0, index)); // store third day hours, convert to int 
                                    break;
                                }
                                case 4:  // if sixth space is found 
                                {
                                    hours[3] = stoi(s.substr(0, index)); // store fourth day hours, convert to int 
                                    break;
                                }
                                case 5:  // if seventh space is found 
                                {
                                    hours[4] = stoi(s.substr(0, index)); // store fifth day hours, convert to int 
                                    break;
                                }
                                case 6:  // if first space is found 
                                {
                                    catagory = s.substr(0, index); // catagory of employee 
                                    break;
                                }
                            }
                            s.erase(0, index + 1); // for each  case remove previous string 
                        }
                        Employee e(5, name, catagory, hours);
                        ITEmp[t] = e;
                        t++;
                        break;
                    }
                    
                    case 4: // if catagory id F4
                    {
                        int hours[7]; // for storing 7 hour data 
                        string name;
                        for (int i = 0; i < 9; i++){  // total data is 9 separated by space, So looping 9 time  
                            int index = s.find_first_of(' ');  // index of first space each time 
                            switch (i)
                            {
                                case 0:   // if first space is found 
                                {
                                    name = s.substr(0, index);   // store name 
                                    break;
                                }
                                case 1: // if second space is found 
                                {
                                    hours[0] = stoi(s.substr(0, index));  // store first day hours, convert to int
                                    break;
                                }
                                case 2: // if third space is found 
                                {
                                    hours[1] = stoi(s.substr(0, index)); // store second day hours, convert to int
                                    break;
                                }
                                case 3:  // if fourth space is found 
                                {
                                    hours[2] = stoi(s.substr(0, index)); // store third day hours, convert to int
                                    break;
                                }
                                case 4:     // if fifth space is found 
                                {
                                    hours[3] = stoi(s.substr(0, index)); // store fourth day hours, convert to int
                                    break;
                                }
                                case 5: // if sixth space is found 
                                {
                                    hours[4] = stoi(s.substr(0, index)); // store fifth day hours, convert to int
                                    break;
                                }
                                case 6: // if seventh space is found 
                                {
                                    hours[5] = stoi(s.substr(0, index)); // store sixth day hours, convert to int
                                    break;
                                }
                                case 7: // if eight space is found 
                                {
                                    hours[6] = stoi(s.substr(0, index)); // store seventh day hours, convert to int
                                    break;
                                }
                                case 8: // if ninth space is found 
                                {
                                    catagory = s.substr(0, index); // catagory og employee 
                                    break;
                                }
                                    
                            }
                            s.erase(0, index + 1);  // for each  case remove previous string 
                        }
                        Employee e(7, name, catagory, hours);
                        ITEmp[t] = e;
                        t++;
                        break;
                    }
                    
                    case 3: // if catagory id F3
                    {
                        int amounts;  // store amount 
                        float rates; // store rate 
                        string name; // name of employee 

                        for (int i = 0; i < 4; i++){   // total data is 4 separated by space, So looping 4 time 
                            int index = s.find_first_of(' '); // index of first space each time 
                            switch (i)
                            {
                                case 0:  // if first space is found
                                {
                                    name = s.substr(0, index); // sotre name 
                                    break;
                                }
                                case 1: // if second space is found
                                {
                                    amounts = stoi(s.substr(0, index)); // store amount , convert to int 
                                    break;
                                }
                                case 2: // if third space is found
                                {
                                    rates = stof(s.substr(0, index));  // store rate  , convert to float
                                    break;
                                }
                                case 3: // if fourth space is found
                                {
                                    catagory = s.substr(0, index); // store catagory of employee 
                                    break;
                                }
                            }
                            s.erase(0, index + 1);// for each  case remove previous string 
                        }
                        
                        Employee e(name, amounts, rates, catagory);
                        ITEmp[t] = e;
                        t++;
                        break;
                    }
        
                    default:
                        break;
                }
                count++;
            }       
        }
    }
    // check if catagory is exist in first department 
    bool checkExistCataSale(string f){
        for (int i = 0; i < num2; i++){
            if(saleEmp[i].catagory == f){
                return true;
            }
        }
        return false;
    }
    // check if catagory is exist in second department 
    bool checkExistCataIT(string f){
        for (int i = 0; i < num2; i++){
            if(ITEmp[i].catagory == f){
                return true;
            }
        }
        return false;
    }

    void saledepart(){
        /// function is most same as ITdpart() So, i am not commenting 
        int s = checkSaleEmp();
        int count = 0;
        int t = 0;
        vector<string> get = readData();
        for(string s : get){
            int e = s[s.length() - 1]-48;
            
            if(count<=num2){
                count++;
                continue;
            }
            else 
            if(e != 1 &&  e != 2 && e != 3 && e != 4 ){

                continue;
            }
            else {

                int c = s[s.length() - 1]-48;
                switch (c)
                {


                    case 1:
                    {
                        int hours[5];
                        string name;

                        for (int i = 0; i < 7; i++){
                            int index = s.find_first_of(' ');
                            switch (i)
                            {
                                case 0:
                                {
                                    name = s.substr(0, index);
                                    break;
                                }
                                case 1:
                                {
                                    hours[0] = stoi(s.substr(0, index));
                                    break;
                                }
                                case 2:
                                {
                                    hours[1] = stoi(s.substr(0, index));
                                    break;
                                }
                                case 3:
                                {
                                    hours[2] = stoi(s.substr(0, index));
                                    break;
                                }
                                case 4:
                                {
                                    hours[3] = stoi(s.substr(0, index));
                                    break;
                                }
                                case 5:
                                {                        
                                    hours[4] = stoi(s.substr(0, index));
                                    break;
                                }
                                case 6:
                                {
                                    catagory = s.substr(0, index);
                                    break;
                                }
                            }
                            s.erase(0, index + 1);
                        }

                        Employee e(5, name, catagory, hours);
                        saleEmp[t] = e;
                        t++;
                        break;
                    }

                    case 2:
                    {
                        int hours[5];
                        string name;
                        for (int i = 0; i < 7; i++){
                            int index = s.find_first_of(' ');
                            switch (i)
                            {
                                case 0:
                                {
                                    name = s.substr(0, index);
                                    break;
                                }
                                case 1:
                                {
                                    hours[0] = stoi(s.substr(0, index));
                                    break;
                                }
                                case 2:
                                {
                                    hours[1] = stoi(s.substr(0, index));
                                    break;
                                }
                                case 3:
                                {
                                    hours[2] = stoi(s.substr(0, index));
                                    break;
                                }
                                case 4:
                                {
                                    hours[3] = stoi(s.substr(0, index));
                                    break;
                                }
                                case 5:
                                {
                                    hours[4] = stoi(s.substr(0, index));
                                    break;
                                }
                                case 6:
                                {
                                    catagory = s.substr(0, index);
                                    break;
                                }
                            }
                            s.erase(0, index + 1);
                        }
                        Employee e(5, name, catagory, hours);
                        saleEmp[t] = e;
                        t++;
                        break;
                    }
                    case 4:
                    {
                        int hours[7];
                        string name;
                        for (int i = 0; i < 9; i++){
                            int index = s.find_first_of(' ');
                            switch (i)
                            {
                                case 0:
                                {
                                    name = s.substr(0, index);
                                    break;
                                }
                                case 1:
                                {
                                    hours[0] = stoi(s.substr(0, index));
                                    break;
                                }
                                case 2:
                                {
                                    hours[1] = stoi(s.substr(0, index));
                                    break;
                                }
                                case 3:
                                {
                                    hours[2] = stoi(s.substr(0, index));
                                    break;
                                }
                                case 4:
                                {
                                    hours[3] = stoi(s.substr(0, index));
                                    break;
                                }
                                case 5:
                                {
                                    hours[4] = stoi(s.substr(0, index));
                                    break;
                                }
                                case 6:
                                {
                                    hours[5] = stoi(s.substr(0, index));
                                    break;
                                }
                                case 7:
                                {
                                    hours[6] = stoi(s.substr(0, index));
                                    break;
                                }
                                case 8:
                                {
                                    catagory = s.substr(0, index);
                                    break;
                                }
                                    
                            }
                            s.erase(0, index + 1);
                        }
                        Employee e(7, name, catagory, hours);
                        saleEmp[t] = e;
                        t++;
                        break;
                    }
                    
                    case 3:
                    {
                        int amounts;
                        float rates;
                        string name;

                        for (int i = 0; i < 4; i++){
                            int index = s.find_first_of(' ');
                            switch (i)
                            {
                                case 0:
                                {
                                    name = s.substr(0, index);
                                    break;
                                }
                                case 1:
                                {
                                    amounts = stoi(s.substr(0, index));
                                    break;
                                }
                                case 2:
                                {
                                    rates = stof(s.substr(0, index));
                                    break;
                                }
                                case 3:
                                {
                                    catagory = s.substr(0, index);
                                    break;
                                }
                            }
                            s.erase(0, index + 1);
                        }
                        Employee e(name, amounts, rates, catagory);
                        saleEmp[t] = e;
                        t++;
                        break;
                        
                    }
        
                    default:
                        break;
                }
                count++;
            }       
        }
    }
    // 5% order the employees in the roster according to their F status, 
    // F1’s first, then F2’s and so on.
    // it will sort employee by catagory 
    void sortOrderFIT(){
        for (int i = 0; i < num1; i++){
            int c = ITEmp[i].catagory[1]-48;
            for (int j = i; j < num1; j++){
                int a = ITEmp[j].catagory[1]-48;
                if(c>a)
                {
                    Employee e = ITEmp[i];
                    ITEmp[i] = ITEmp[j];
                    ITEmp[j] = e;
                }
            }
        }
        cout << "Name   Catagory" << endl;

        for (int i = 0; i < num1; i++){
            cout <<  ITEmp[i].catagory << "     " <<ITEmp[i].name << endl;
        }
    }

    // 5% order the employees in the roster according to their F status, 
    // F1’s first, then F2’s and so on.
    // it will sort employee by catagory 
    void sortOrderFSales(){
        for (int i = 0; i < num1; i++){
            int c = saleEmp[i].catagory[1]-48;
            for (int j = i; j < num1; j++){
                int a = saleEmp[j].catagory[1]-48;
                if(c>a)
                {
                    Employee e = saleEmp[i];
                    saleEmp[i] = saleEmp[j];
                    saleEmp[j] = e;
                }
            }
        }
        cout << "Name   Catagory" << endl;

        for (int i = 0; i < num1; i++){
            cout <<  saleEmp[i].catagory << "     " <<saleEmp[i].name << endl;
        }
    }

    // display Total of first department 
    void displayTotalDetailIT(){
        ITdepart(); // process and get data from file 
        double displayTotalSal = 0.0;
        int displayTotalhour = 0;
        for (int i = 0; i < num1; i++){
            displayTotalSal += ITEmp[i].getSalary(); // getting total sallary of each employee 
            displayTotalhour += ITEmp[i].getEmphour(); // getting total hours of each employee 
        }
        cout << "Total Salary: $" << displayTotalSal << endl;
        cout << "Total Hours: " << displayTotalhour << endl;
        cout << "Total Number of Employees: " << num1 << endl;
        cout << "Roster: ";
        for (int i = 0; i < num1; i++){
            cout << ITEmp[i].name<< " ";
        }
        cout << endl;
    }
    void displayTotalDetailSales(){
        saledepart(); // process and get data from file 
        
        double displayTotalSal = 0.0;
        int displayTotalhour = 0;
        for (int i = 0; i < num2; i++){
            displayTotalSal += saleEmp[i].getSalary(); // getting total sallary of each employee 
            displayTotalhour += saleEmp[i].getEmphour(); // getting total hours of each employee 
        }
        cout << "Total Salary: $" << displayTotalSal << endl;
        cout << "Total Hours: " << displayTotalhour << endl;
        cout << "Total Number of Employees: " << num2 << endl;
        cout << "Roster: ";
        for (int i = 0; i < num2; i++){
            cout << saleEmp[i].name<< " ";
        }
        cout << endl;
    }
    // display total of salary and hours for given catagory 
    void DisplayDetailCatagoryIT(string f){
        cout << f <<" : "<< endl;
        if(!checkExistCataIT(f)){ // if that catagoory is not present 
            cout << "Catagory does not exist in IT department " << endl<< endl;
        }
        else{
            double displayTotalSal = 0.0;
            int displayTotalhour = 0;
            int numEmp = 0;
            for (int i = 0; i < num1; i++){
                if(ITEmp[i].catagory == f){
                    displayTotalSal += ITEmp[i].getSalary();   // getting total sallary of employees of given catagory 
                    displayTotalhour += ITEmp[i].getEmphour(); // getting total hours  of employees of given catagory 
                    numEmp++;
                }
            }
            cout << "Total Salary: $" << displayTotalSal << endl;
            cout << "Total Hours: " << displayTotalhour << endl;
            cout << "Total Number of Employees: " << numEmp << endl<< endl;
        }
    }
    // display total of salary and hours for given catagory 
    void DisplayDetailCatagorySales(string f){
        cout  << f <<" : "<< endl;
        if(!checkExistCataSale(f)){  // if that catagoory is not present 
            cout << "Catagory does not exist in Sale department " << endl<< endl;
        }
        else 
        {
            double displayTotalSal = 0.0;
            int displayTotalhour = 0;
            int numEmp = 0;
            for (int i = 0; i < num2; i++){
                if(saleEmp[i].catagory == f){
                    displayTotalSal += saleEmp[i].getSalary();  // getting total sallary of employees of given catagory
                    displayTotalhour += saleEmp[i].getEmphour();  // getting total hours  of employees of given catagory
                    numEmp++;
                }
            }
            cout << "Total Salary: $" << displayTotalSal << endl;
            cout << "Total Hours: " << displayTotalhour << endl;
            cout << "Total Number of Employees: " << numEmp << endl << endl;
        }
    }

};


int main(){

    // HERE I READ FIRST GIVEN FILE 
    cout << "**************  FIRST FILE ************" << endl;
    Department d("Payroll.txt");

    cout << "The IT Department" << endl;
    d.displayTotalDetailIT();
    cout << endl;
    d.DisplayDetailCatagoryIT("F1");
    d.DisplayDetailCatagoryIT("F2");
    d.DisplayDetailCatagoryIT("F3");
    d.DisplayDetailCatagoryIT("F4");


    cout << "The Sales Department" << endl;
    d.displayTotalDetailSales();
    cout << endl;
    d.DisplayDetailCatagorySales("F1");
    d.DisplayDetailCatagorySales("F2");
    d.DisplayDetailCatagorySales("F3");
    d.DisplayDetailCatagorySales("F4");





    // HERE I READ SECOND GIVEN EXAMPLE FILE 
    cout << "**************  SECOND FILE ************" << endl;
    Department d2("Payroll2.txt");

    cout << "The SALES Department" << endl;
    d2.displayTotalDetailIT();
    cout << endl;
    d2.DisplayDetailCatagoryIT("F1");
    d2.DisplayDetailCatagoryIT("F2");
    d2.DisplayDetailCatagoryIT("F3");
    d2.DisplayDetailCatagoryIT("F4");


    cout << "The RECORD Department" << endl;
    d2.displayTotalDetailSales();
    cout << endl;
    d2.DisplayDetailCatagorySales("F1");
    d2.DisplayDetailCatagorySales("F2");
    d2.DisplayDetailCatagorySales("F3");
    d2.DisplayDetailCatagorySales("F4");


    // 5% order the employees in the roster according to their F status,
    // F1’s first, then F2’s and so on.
    // IT WILL SORT AND DISPLAY EMPLOYEES
    cout << " Department Sales : " << endl;
    d2.sortOrderFIT();

    cout << " Department Record  : " << endl;
    d.sortOrderFSales();

    return 0;
}

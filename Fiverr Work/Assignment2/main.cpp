#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

string reader(const string & fileName) {
		ifstream file; // to read file 
		file.open(fileName); // open the file 
		string data;
		string result;  // string to place data after reading 
		while (file.is_open() && !file.eof()) {  // read while file end and file is open 
			getline(file, data);  // get each line and store in string 
			if (!data.empty()) {  
				result += data + "\n";  // push string in  
			}
		}
		if(file.is_open())
			file.close();  // close the file 
		return result;  // return  
}

void writer(const string & fileName, const string& data) {
	ofstream file;   // to write into file 
	file.open(fileName, ios::out | ios::app);  // open the file to write 
	if (file.is_open()) {  // take string in each loop while data has any string 
		file << data + "\n";  // write into file
    }
		file.close();  // close the file 
}

int studentGradeA( string fileName){

    int students = 0; // to store count of students

    ifstream file; // to read file 
		file.open(fileName); // open the file 
		string data;
		while (file.is_open() && !file.eof()) {  // read while file end and file is open 
			getline(file, data);  // get each line and store in string 
			if (!data.empty()) { 
                char a = data[data.length() - 1]; //get last charactor of string
                if(a== 'A'){  // check if it has A grade 
                    students++; // increment student count 
                }
			}
		}
		if(file.is_open()) //  
			file.close();  // close the file
    return students; // return students 
}

double getTotalMarks(string fileName, string student){
    string roll,marks; // to store roll number and marks 
    ifstream file; // to read file 
	file.open(fileName); // open the file 
	string data;
	while (file.is_open() && !file.eof()) { // read while file end and file is open 
		getline(file, data);  // get line and store in string 
		if (!data.empty()) {  
            int index = data.find_first_of(' '); // find index where firt , exist 
            roll = data.substr(0, index); // subtring from 0 to index,
            cout << roll << endl;
            if(student == roll){ // check if roll number match 
                data.erase(0, index + 1);  // erase substring 
                index = data.find_first_of(' '); // get index of fist , 
                marks = data.substr(0, index);  // get marks string 
                return stod(marks); // covert to double and return 
            } 
        }
    }
	if(file.is_open())
		file.close();  // close the file
    return 0; // else return 0;
}



int Gracing(string fileName){
    int count = 0; // for counter 
    char grade;
    int index;
    double marks;
    string full, roll;

        ifstream file; // to read file 
		file.open(fileName); // open the file 
		string s;
		while (file.is_open() && !file.eof()) {  // read while file end and file is open 
			getline(file, s);  // get line and store in string 
			if (!s.empty()) {  
                grade = s[s.length() - 1]; // get last char of string 
                if(grade == 'F'){ // check if grade is F
                    index = s.find_first_of(' '); // index of first , 
                    marks = stod(s.substr(index+1,4)); // sub string
                    cout << marks << endl;
                    if(marks<50){ // check if marks are less than 50 
                        count++;
                        cout << count << endl;
                        while(marks<50){ // increment marks while it will be 50 
                            marks++;
                        }
                        index = s.find_first_of(' ');
                        roll = s.substr(0, index);
                        full += roll + " " + to_string(marks) + " " + "D\n"; // made a string
                    }
                }
			}
        }
        cout << full << endl;
        ofstream ofile;                 // to write into file
        ofile.open("fails.txt", ios::out); // open the file to write
        if (ofile.is_open())
        {                  // take string in each loop while data has any string
            ofile << full; // write into file
    }
    file.close();  // close the file

	if(file.is_open())
		file.close();  // close the file 
    return count;
}

void update(string fileName){
    int count = 0; // for counter 
    char grade;
    int index;
    double marks;
    string full, roll;

    ifstream file; // to read file 
		file.open(fileName); // open the file 
		string s;
		string result;  //  to string to place data after reading 
		while (file.is_open() && !file.eof()) {  // read while file end and file is open 
			getline(file, s);  // get  line and store in string 
			if (!s.empty()) {  
                grade = s[s.length() - 1]; // get last char of string 
                if(grade == 'F'){ // check if grade is F
                    index = s.find_first_of(' ');
                    marks = stod(s.substr(index+1,4));
                    if(marks<50){ // check if marks are less than 50 
                        while(marks<50){   // increment marks while it will be 50 
                            marks++;
                        }
                        index = s.find_first_of(' ');
                        roll = s.substr(0,  index);
                        full += roll + " " + to_string(marks) + " " + "D\n"; // insert string at the end of same string
                    }
                }	
                else {
                    full += s+ "\n";
                }	             // push string in  
			}
		}
        ofstream ofile;   // to write into file 
        ofile.open(fileName, ios::out);  // open the file to write 
        if (ofile.is_open()) {  // take string in each loop while data has any string 
            ofile << full;  // write into file
        }
        file.close();  // close the file
		if(file.is_open())
		    file.close();  // close the file 
}

int main(){
    string data = reader("output.txt"); // read data from file 
    int c = -1;
    while(c!= 5)
    {
        cout << "1. Check how many Students has A grade " << endl;
        cout << "2. Check marks of a Student " << endl;
        cout << "3. Gracing the fail Students " << endl;
        cout << "4. Update orignal data after gracing " << endl;
        cout << "5. Quit " << endl;
        cout << "Enter choice : ";
        cin >> c;
        switch (c)
        {
        case 1:
            cout<< studentGradeA("output.txt")<< endl; //  number of students with A grade 
            break;
        case 2:
        {
            string r;
            cout << "Enter roll number of Student : ";
            cin >> r;
            cout << getTotalMarks("output.txt", r); // get total marks of passing roll number  
            break;
        }
        case 3:
            cout<<"Gracing Students are : " << Gracing("output.txt")<< endl; // gracing data who are going to fail in subjects  
            break;
        case 4:
            update("output.txt");  // update file with gracing data who are going to fail in subjects 
            break;
        case 5:
            cout << "Quiting " << endl;  // terminate the program 
            exit(0);
            break;
        default:
            cout << "Invalid entry  " << endl; // non choice 
            break;
        }
    }
    return 0;
}
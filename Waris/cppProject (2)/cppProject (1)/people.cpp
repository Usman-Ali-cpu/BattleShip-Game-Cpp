#include <iostream>
#include <fstream> // header file library to do file functional 
#include <algorithm> // header file library to dget alogorithm
#include <vector>
using namespace std;

struct People{ // Structure for storing file data 
    string name; // name of person 
    int startTime; // starttime of enterance
    int endTime; // endtime from video
    People(string name, int stime, int etime){ // parameterize constructor 
        this->name = name;
        this->startTime = stime;
        this->endTime = etime;
    }
};

bool checkVisit(string name, vector<People> pList){ // check if visitor already visited 
    for(int i=0; i<pList.size(); i++){ // iterate over all hear
        if(pList[i].name == name ){
            return true; // return true if name are smae 
        }
    }
    return false;
}
void printMessage(vector<People> List){ // printing message from start time end tile . 
    
        for (int i = 0; i < List.size(); i++)
        {
            cout << List[i].name << " (entered at " << List[i].startTime << ", left at" << List[i].endTime << ")\n"; // printing message 
        }
        cout<< endl;
}

int getMaxTime(vector<int> tList){ ///  get maximum sixe from files 
    int max =0;
    for(int i=0; i< tList.size(); i++){
        if(tList[i] > max){ // if current is greater that 
            max = tList[i]; // assign value to maximum
        }
    }
    return max; // return matr
}


int main(){

    int stime;
    int ltime;
    string name;
    vector<People> pList;
    ifstream infile("visits.txt"); // open file 
    if(!infile.is_open()){ // try to open txt file
        cout<< "Error in Opening file ";//ig not open vm ,
        return 0;
    }
    while (infile >> stime >> ltime >> name)
    {
        People person = People(name, stime, ltime);
        pList.push_back(person); // add data of each line to vector if persons
    }

    int times;
    vector<int> tList; // list of times
    ifstream timefile("times.txt"); // open that txt fulw
    if(!timefile.is_open()){
        cout<< "Error in Opening file ";
        return 0;
    }
    while (timefile >>times)
    {  
        tList.push_back(times); // . add time to vector 
    }

    cout<< "*********** PART-1 People at the Time *************"<< endl;

    for(int i=0; i < tList.size(); i++){ // loop throgh all times list
        int count =0;
        vector<People> temp;
        for(int j=0; j < pList.size(); j++){ // loop through list of all people who visited 
            if(tList[i] >= pList[j].startTime && tList[i] <= pList[j].endTime){
                if(!checkVisit(pList[j].name, temp )){
                    temp.push_back(pList[j]);
                    count++;
                }
            }
        }
        cout<< "There were "<< count<< " people at the time " << tList[i]<< endl; // print number if visitor and time viisted 
        if(temp.size() > 0){
            printMessage(temp);
        }
        else {
            cout << "There were no people present at time " << tList[i] << endl<< endl;
        }
    }


    cout<< "*********** PART-2 Largest Time Visited *************"<< endl;
    int largeCount =0;
    int largeTime =0;
    for(int i=0; i < getMaxTime(tList); i++){ // loop through all indexes from zero to largest time 
        int count =0;
        for(int j=0; j < pList.size(); j++){ // loop through list of all people 
            if(i >= pList[j].startTime && i <= pList[j].endTime){
                count++;
            }  
        }
        if(count> largeCount){ // if number of people visited in a time is greater than largest 
            largeCount = count;
            largeTime = i;
        }
    }
    cout << " There were "<< largeCount <<" people present at time " <<  largeTime << ".\n";



    cout<< "*********** PART-2  Total Time in the Each Visited *************"<< endl;
    vector<People> uniqueVisits;
    for (int i = 0; i < pList.size(); i++) // loop through all people in the list who visited 
    {
        if (!checkVisit(pList[i].name, uniqueVisits)) // if person does not visited before 
        {
            pList[i].startTime = pList[i].endTime - pList[i].startTime; // get time duration remain in building 
            uniqueVisits.push_back(pList[i]); // add visitor 
        }
        else
        {
            for (int j = 0; j < uniqueVisits.size(); j++) // loop through all unique people in the list who visited
            {
                if (uniqueVisits[j].name == pList[i].name)
                {
                    uniqueVisits[j].startTime += pList[i].endTime - pList[i].startTime;
                }
            }
        }
    }
    sort(uniqueVisits.begin(), uniqueVisits.end(), [](People a, People b)
              { return a.name < b.name; }); // sort People by their names 
    for (int i = 0; i < uniqueVisits.size(); i++)
    {
        cout << uniqueVisits[i].name<< "  " << uniqueVisits[i].startTime  << endl; // print Visitor  and Time duration 
    }

    return 0;
}

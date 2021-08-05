#include <iostream>
#include <string>
using namespace std;

class Island{
private:
    string name;
    float area;
public:
    Island(){
        name = "unknown";
        area = 0.0;
    }
    Island(string n, float a){
        name = n;
        area = a;
    }
    void setValues(string n, float f){
        name = n;
        area = f;
    }
    void display(){
        cout<< name <<  area<< " km2" <<endl;
    }
};

class Archipelago{
public:
    string name;
    float area;
    string location;
    Island * series;
    int size;
    Archipelago(){
        name = "Unkown";
        area = 0.0;
        size = 5;
        series = new Island[5];
    }
    Archipelago(string n, float a, string l, string o, int s){
        name = n;
        area = a;
        size = s;
        ocean = o;
        location = l;
        series = new Island[size];
    }
    void setValues(string n, float a, string l,string o, int s){
        name = n;
        area = a;
        size = s;
        ocean = o;
        location = l;
        series = new Island[size];
    }
    void display(){
        cout<< name << " " << area << " km2"<< endl;
        cout<< location << "(" << ocean << ")" << endl;
        for(int i=0; i<size; i++){
            series[i].display();
        }
    }
};

int main(){
    int numRow;
    cin>> numRow;
    Archipelago * row = new Archipelago[numRow]; // row of Archipelago


    for(int i=0; i<numRow; i++){
        string oc, loc, na;
        float ar;
        cin.ignore();
        getline(cin, na);
        cin >> ar;
        cin.ignore();
        getline(cin, loc);
        cin.ignore();
        getline(cin, oc);
        cin>> num;
        Archipelago arc(na, ar,loc, oc, num);
        for(int i=0; i< num; i++){
            float iarea;
            string iname;
            cin.ignore();
            getline(cin,iname);   
            cin >> iarea;
            arc.series[i].setValues(iname, iarea);
        }
        row[i] = arc;
    }

    string na;
    string loc;
    int large = 0;
    for(int i=0; i< numRow; i++){
        if(row[i].size > large){
            large = row[i].size;
            name = row[i].name;
            loc = row[i].location;
        }
    }
    cout<< "Ocean with most islands in a row : "<< name<< endl;
    cout<< "Location Ocean with most islands in a row : "<< loc << endl;




    





    return 0;
}
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
    string ocean;
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
    string name;
    float area;
    int num;
    string location, ocean;
    cin.ignore();
    getline(cin, name);
    cin >> area;
    cin.ignore();
    getline(cin, location);
    cin.ignore();
    getline(cin, ocean);
    cin>> num;
    Archipelago arc(name, area,location, ocean, num);
    for(int i=0; i< num; i++){
        float iarea;
        string iname;
        cin.ignore();
        getline(cin,iname);   
        cin >> iarea;
        arc.series[i].setValues(iname, iarea);
    }
    arc.display();


    


    





    return 0;
}
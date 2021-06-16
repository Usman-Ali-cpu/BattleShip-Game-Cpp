#include <iostream>
#include <cmath>
#include "Shape.h" // a base class
#include "Rectangle.h" // drived class from Shape
#include "Sphere.h" // drived class from Shape
using namespace std;

int main(){
    cout << "For 3D Sphere ->" << endl;
    Sphere <int> s(1); // calling template object to int of Sphere class
    int r;  // declare radius 
    cout << "Enter radius : ";
    cin >> r; // input to radius
    s.setRadius(r); //  set radius for sphere 

    // Execption handling block
    try 
    {
        // it will check whether area circumference and volume thorwing any error
        cout << "Sphere Area is " << s.calArea() << endl;
        cout << "Sphere Circumference is " << s.calcircum() << endl;
        cout << "Sphere Volume is " << s.calVolume() << endl;
    }
    catch (const char* msg) {
        // it will catch an error 
        cerr << msg << endl; // it will print error thrown 
        int r;
        do{
            cout << "Enter radius : ";
            cin >> r; 
        } while (r < 0); // it will ask to input value of radius while use does not enter positive value
        s.setRadius(r);  // then it will set radius 
        // Here printing 
        // Area of Sphere 
        cout << "Sphere Area is " << s.calArea() << endl;
        // Circumference of Sphere 
        cout << "Sphere Circumference is " << s.calcircum() << endl;
        // Volume of sphere 
        cout << "Sphere Volume is " << s.calVolume() << endl;
    }

    system("pause"); 
    // Here, calculation for Rectangle 
    cout << "/nFor Rectangle -> " << endl;
    int len, wid, hei;
    cout << "Enter Height: ";
    cin >> hei; // input height
    cout << "Enter length: ";
    cin >> len; // input length
    cout << "Enter width: ";
    cin >> wid; // input width

    Rectangle <int> rect(len, wid,hei); // calling template object to int of Rectangle class
    try{
         // it will check whether area circumference and volume thorwing any error
        cout << "Rectangle Area is " << rect.calArea() << endl;
        cout << "Rectangle Circumference is " << rect.calCircum() << endl;
        cout << "Rectangle Volume is " << rect.calVolume() << endl;
    }
    catch (const char* msg) {
        cerr << msg << endl; // it will print error thrown 
        int l,w,h;
        do{
            cout << "Enter Height : ";
            cin >> h;  // input height
        } while (h < 0); // it will input height while h is not positive  
        rect.setheight(h);

        do{
            cout << "Enter Width : ";
            cin >> w;
        } while (w < 0);  // it will input width while h is not positive  
        rect.setwidth(w);

        do{
            cout << "Enter length : ";
            cin >> l; // input length
        } while (l < 0);  // it will input length while h is not positive  
        rect.setheight(l);
        // Here printing 
        // Area of Sphere 
        cout << "Rectangle Area is " << rect.calArea() << endl;
        //  Rectangle Circumference Sphere 
        cout << "Rectangle Circumference is " << rect.calCircum() << endl;
        // Rectangle Volume Sphere 
        cout << "Rectangle Volume is " << rect.calVolume() << endl;
    }

    return 0;
}
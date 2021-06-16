#pragma once
#ifndef SHAPE_H // check if class is define or not 
#define SHAPE_H // define that class 
#include <iostream>
using namespace std;


 
template <class T> // make template of class 
class Shape{
    T height;  // heigth data member  
    T width;   // width data member 
    T length;  // length data member 
public:  // making all the methods public  
    // Default constructor 
    Shape(){
        height = 0;
        width = 0;
        length = 0;
    }
    // parameterize costructor 
    Shape(T l, T w, T h){
        height = h;
        length = l;
        width = w;
    }
    // set values to all data members
    void setValue(T l, T w, T h){
        height = h;
        length = l;
        width = w;
    }
    
    void setHeight(T h) { height = h; }  // height setter 
    void setWidth(T w) { width = w; }    // width setter 
    void setLength(T l) { length = l; }  // length setter 

    T getHeight() { return height; } // heigth getter 
    T getWidth() { return width; } // width getter  
    T getLength() { return length; } // length getter 

};


#endif
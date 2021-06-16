#pragma once
#ifndef SPHERE_H // check if class is define or not  
#define SPHERE_H // define that class 
#include <iostream>
#include "Shape.h" // including base class 
using namespace std;



template <class T> // making tenplate of class 
class Sphere: public Shape<T>{  // inheritance : inherting base class Shape
public:
    // default constructor 
    Sphere(){
        this->setHeight(0);
    }
    // parameterize constructor
    Sphere(T r){
        this->setHeight(r);
    }
    // radius getter 
    T getRadius(){
        return this->getHeight();
    }
    // radius setter 
    T setRadius(T x){
        this->setHeight(x);
    }
    // it will calcuate and return area 
    T calArea(){
        if(this->getHeight()< 0){
            // if height is negative it will throw exception
            throw "Error due to Negative value \n";
        }
    
        return 4 * 3.14 * this->getHeight() * this->getHeight();
    }
    // it will calcuate and return volume 
    T calVolume(){
        if(this->getHeight()< 0){
            // if height is negative it will throw exception
            throw "Error due to Negative value \n";
        }
        return 4.0 / 3.0 * (3.14 * this->getHeight() * this->getHeight() * this->getHeight());
    }
    // it will calcuate and return circumference
    T calcircum(){
        // if height is negative it will throw exception
        if(this->getHeight()< 0){
            throw "Error due to Negative value \n";
        }
        return 4 / 3 * (3.14 * this->getHeight() * this->getHeight() * this->getHeight());
    }
};
#endif
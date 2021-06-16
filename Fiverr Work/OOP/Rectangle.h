#pragma once
#ifndef RECTANGLE_H // it will check if class is not define 
#define RECTANGLE_H // it will define class 
#include <iostream>
#include "Shape.h" // including base class 
using namespace std;


template <class T> // make template of class 
class Rectangle: public Shape<T>{
    public:
    // defualt constructor
    Rectangle(){ 
        this->setHeight(0);
        this->setLength(0);
        this->setWidth(0);  
    }
    // parameterize constructor 
    Rectangle(T l, T h, T w){
        this->setHeight(h);
        this->setLength(l);
        this->setWidth(w);
    }
    // it will set height
    void setheight(T x){
        this->setHeight(x);
    }
    // width setter
    void setwidth(T x){
        this->setWidth(x);
    }
    // length setter
    void setlength(T x){
        this->setLength(x);
    }
    // it will calculate area and then return it
    T calArea(){
        T area;
        if(this->getHeight()< 0){
            // if height is negative it will throw exception
            throw "Error due to Negative value of Height ";
        }
        if(this->getWidth()<0){
            // if width is negative it will throw exception
            throw "Error due to Negative value of width";
        }
        if( this->getLength()<0){
            // if length is negative it will throw exception
            throw "Error due to Negative value of length";
        }
        area = 2 * ((this->getHeight() * this->getLength()) + (this->getHeight() * this->getWidth()) + (this->getWidth() * this->getLength()));
        return area;
    }
    // it will calculate volume and return it 
    T calVolume(){

        if(this->getHeight()< 0.0){
            // if height is negative it will throw exception
            throw "Error due to Negative value of Height ";
        }
        if(this->getWidth()<0){
            // if width is negative it will throw exception
            throw "Error due to Negative value of width";
        }
        if(this->getLength()<0){
            // if length is negative it will throw exception
            throw "Error due to Negative value of length";
        }
        T volume = this->getHeight() * this->getWidth() * this->getLength();
        return volume;
    }
    // it will calculate circumference and return it 
    T calCircum(){
        if(this->getHeight()< 0){
            // if height is negative it will throw exception
            throw "Error due to Negative value of Height ";
        }
        if(this->getWidth()<0){
            // if width is negative it will throw exception
            throw "Error due to Negative value of width";
        }
        if( this->getLength()<0){
            // if length is negative it will throw exception
            throw "Error due to Negative value of length";
        }
        T circum;
        circum = 2 * this->getHeight() * ( this->getWidth() + this->getLength() );
        return circum;
    }
};




#endif
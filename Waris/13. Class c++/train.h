#include "car.h"
using namespace std;

#ifndef TRAIN_H
#define TRAIN_H

class Train
{
private:
    Car *tHead;
    Car *tTail;

public:
    Train();
    ~Train();
    void addCarBack(Car *);
    void deleteFirstCar();
    void removeFirstCarOfType(const string &);
    void display() const;
};
#endif
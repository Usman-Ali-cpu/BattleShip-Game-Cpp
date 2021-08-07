#include <iostream>
#include "train.h"
using namespace std;

void Train::addCarBack(Car *car)
{
    if (tHead == NULL)
    {
        tHead = car;
        tTail = car;
    }
    else
    {
        tTail->nextCar = car;
        tTail = tTail->nextCar;
    }
}

void Train::deleteFirstCar()
{
    if (tHead == NULL)
    {
        return;
    }
    else
    {
        Car *d = tHead;
        Car *t = tHead->nextCar;
        tHead = t;
        delete d;
    }
}

void Train::removeFirstCarOfType(const string &s)
{
    Car *temp = tHead;
    Car *previous = NULL;
    while (temp != NULL)
    {
        if (temp->getName() == s)
        {
            break;
        }
        previous = temp;
        temp = temp->nextCar;
    }

    if (temp == tHead)
    {
        if (tHead == NULL)
        {
            return;
        }
        if (tHead->nextCar == NULL)
        {
            tHead = NULL;
        }
        else
        {
            Car *temp = tHead;
            tHead = tHead->nextCar;
            delete temp;
        }
    }
    else
    {
        previous->nextCar = temp->nextCar;
        delete temp;
    }
}

void Train::display() const
{
    Car *temp = tHead;
    cout << "Car Name\t  " << endl;
    cout << "*****************************\n";
    while (temp != NULL)
    {
        cout << temp->getName() << endl;
        temp = temp->nextCar;
    }
    cout << "*****************************\n";
}

Train::Train()
{
    tHead = NULL;
    tTail = NULL;
}
Train::~Train()
{
    Car *t = tHead;
    while (t != NULL)
    {
        Car *d = t;
        t = t->nextCar;
        delete d;
    }
    tHead = NULL;
}

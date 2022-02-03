#pragma once
#ifndef EVENT_H
#define EVENT_H

#include <iostream>
using namespace std;

class Event
{
private:
    int time;
    string eventName;

public:
    Event()
    {
        time = 0;
        eventName = "Defualt";
    }
    Event(int t, string name)
    {
        time = t;
        eventName = name;
    }
    int getTime()
    {
        return time;
    }
    string getEventName()
    {
        return eventName;
    }
    void print()
    {
        cout << "Event : " << eventName << endl;
        cout << "Time : " << time << endl;
    }
    friend bool operator==(Event &, Event &);
};

bool operator==(Event &e1, Event &e2)
{
    return (e1.getTime() == e2.getTime() && e1.getEventName() == e2.getEventName());
}
#endif
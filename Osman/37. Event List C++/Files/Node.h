#pragma once
#ifndef NODE_H
#define NODE_H

#include <iostream>
#include "Event.h"
using namespace std;

class Node
{
public:
    Event x;
    Node *next;
    Node *previous;
    Node(Event x)
    {
        this->x = x;
        next = NULL;
        previous = NULL;
    }
    Node()
    {
        next = NULL;
        previous = NULL;
    }
};
#endif
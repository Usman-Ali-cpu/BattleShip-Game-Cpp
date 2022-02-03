

#pragma once
#ifndef NODE_H // if node class is not define
#define NODE_H // then define this class

class Node
{
public:
    int val;    // the value that this node stores
    Node *next; // a pointer to the next node in the list
                // you can add constructors or other functionality if you find it useful or necessary
};

#endif
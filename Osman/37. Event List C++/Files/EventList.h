#pragma once
#ifndef EVENTLIST_H
#define EVENTLIST_H

#include <iostream>
#include <string>
#include "Tokenizer.cpp"
#include "Event.h"
#include "Node.h"
#include <fstream>
using namespace std;

class EventList
{
    Node *head;
    Node *tail;

public:
    EventList()
    {
        head = NULL;
        tail = NULL;
    }
    void append(Event val)
    {
        if (head == NULL)
        {
            head = new Node(val);
            tail = head;
        }
        else
        {
            Node *temp = new Node(val);
            tail->next = temp;
            temp->previous = tail;
            tail = temp;
        }
    }
    void loadFile()
    {
        fstream newfile;
        newfile.open("event.txt", ios::in); //open a file to perform read operation using file object
        if (newfile.is_open())
        { //checking whether the file is open
            string tp;
            while (getline(newfile, tp))
            { //read data from file object and put it into string.
                Tokenizer t(tp);
                vector<int> readInteger = t.readIntegers();
                vector<string> readstr = t.readString();
                Event e(readInteger[0], readstr[0]);
                append(e);
            }
            newfile.close(); //close the file object.
        }
    }
    void insert_After(Node *prev_node, Event e)
    {
        //check if prev node is null
        if (prev_node == NULL)
        {
            cout << "Location Does not exists" << endl;
            return;
        }
        //allocate memory for new node
        Node *newNode = new Node;

        //assign data to new node
        newNode->x = e;

        //set next of newnode to next of prev node
        newNode->next = prev_node->next;

        //set next of prev node to newnode
        prev_node->next = newNode;

        //now set prev of newnode to prev node
        newNode->previous = prev_node;

        //set prev of new node's next to newnode
        if (newNode->next != NULL)
            newNode->next->previous = newNode;
    }
    void insert_before(Node *next_node, Event e)
    {
        //check if prev node is null
        if (next_node == NULL)
        {
            cout << "Location Does not exists" << endl;
            return;
        }
        //allocate memory for new node
        Node *newNode = new Node;

        //assign data to new node
        newNode->x = e;

        //set next of newnode to prev of next node
        newNode->previous = next_node->previous;

        //set prev of next node to newnode
        next_node->previous = newNode;

        //now set next of newnode to next node
        newNode->next = next_node;

        //set next of new node's prev to newnode
        if (newNode->previous != NULL)
            newNode->previous->next = newNode;
    }

    void preappend(Event val)
    {
        if (head == NULL)
        {
            head = new Node(val);
            tail = head;
        }
        else
        {
            Node *temp = new Node(val);
            temp->next = head;
            head->previous = temp;
            head = temp;
        }
    }
    void insertBefore(string loc, Event val)
    {
        Node *t = head;
        while (t != NULL)
        {
            cout << loc << " == " << t->x.getEventName() << endl;
            if (t->x.getEventName() == loc)
            {
                cout << "macth" << endl;
                break;
            }
            t = t->next;
        }
        if (t == head)
        {
            preappend(val);
            return;
        }
        insert_before(t, val);
    }
    void insertAfter(string loc, Event val)
    {
        Node *t = head;

        while (t != NULL)
        {
            if (t->x.getEventName() == loc)
            {
                break;
                break;
            }
            t = t->next;
        }
        insert_After(t, val);
    }
    void remove(Event e)
    {
        Node *temp = head;
        while (temp != NULL)
        {

            if (temp->x == e)
            {
                if (temp == head)
                {
                    Node *t = head;
                    head = head->next;
                    head->previous = NULL;
                    delete t;
                    return;
                }
                else if (temp == tail)
                {
                    Node *t = tail;
                    tail->previous->next = NULL;
                    tail = tail->previous;
                    delete t;
                    return;
                }
                Node *t = temp;
                temp->previous->next = temp->next;
                temp->next->previous = temp->previous;
                delete t;
                return;
            }
            temp = temp->next;
        }
        cout << "Specific Event Does not Find!" << endl;
    }
    void removeStart()
    {
        if (head == NULL)
        {
            return;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            head->previous = NULL;
            Event x = temp->x;
            delete temp;
        }
    }
    void display()
    {
        Node *temp = head;
        cout << "********** DISPLAY ********** \n";
        while (temp != NULL)
        {
            temp->x.print();
            temp = temp->next;
            cout << endl;
        }
        cout << "********** ******** ********** \n";
    }
    void displayUntil(int time)
    {

        Node *temp = head;
        cout << "********** DISPLAY UNTILL TIME ELASPED " << time << " ********** \n";
        while (temp != NULL)
        {
            if (temp->x.getTime() == time)
            {
                return;
            }
            temp->x.print();
            temp = temp->next;
            cout << endl;
        }
        cout << "********** ******** ********** \n";
    }
    void find(Event e)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->x == e)
            {
                cout << "******* EVENT FIND *********\n";
                temp->x.print();
                cout << "******* ********* *********\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Specific Event Does not Find ! " << endl;
    }
    int getLength()
    {
        int length = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            length++;
            temp = temp->next;
        }
        return length;
    }
    void clear()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            Node *t = temp;
            temp = temp->next;
            delete t;
        }
        head = tail = NULL;
    }
    ~EventList()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            Node *t = temp;
            temp = temp->next;
            delete t;
        }
        head = tail = NULL;
    }
};

#endif

#include "Node.h"
#include <iostream>
#pragma once
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

class Linked_List
{
private:
    unsigned int length;                                     // the number of nodes contained in the list
    Node *head = NULL;                                       // a pointer to the first node in the list
    Node *MergeDescendingSort(Node *lst1, Node *lst2);       // helper method for sorting used by sort_descending
    void SplitList(Node *source, Node **front, Node **back); //
    void DescMergeSort(Node **thead);
    void AscMergeSort(Node **thead);
    Node *MergeAscendingSort(Node *lst1, Node *lst2); // helper method for sorting used by sort_ascending

    // extra credit (SELECCTION SORT)
    void swapNodes(Node **head_ref, Node *currX,
                   Node *currY, Node *prevY);
    // function to sort the linked list using
    // recursive selection sort technique
    Node *recurSelectionSort(Node *head);

    // helper function to sort the given linked list
    void sort(Node **head_ref);

public:
    // anything else you need...
    int get_length();
    // note: there is no set_length(unsigned int) (the reasoning should be intuitive)
    void print();                                     // output a list of all integers contained within the list
    void clear();                                     // delete the entire list (remove all nodes and reset length to 0)
    unsigned int push_front(int);                     // insert a new value at the front of the list (returns the new length of the list)
    unsigned int push_back(int);                      // insert a new value at the back of the list (returns the new length of the list)
    unsigned int insert(int val, unsigned int index); // insert a new value in the list at the specified index (returns the new length of the list)
    void sort_ascending();                            // sort the nodes in ascending order. You must implement the recursive Merge Sort algorithm
                                                      // Note: it's okay if sort_ascending() calls a recursive private function to perform the sorting.
    void sort_descending();                           // sort the nodes in descending order
    int countPrime();

    void SelectionDescendingSort();
    ~Linked_List();
};

#endif
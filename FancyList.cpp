// Brij Malhotra
// Purpose: Create a program that lets user make a list and modify it with different functions
// Example: 
// $ ./hw3.out
// ********* FancyList Menu *********
// 1. Create a list
// 2. Display the list
// 3. Reverse the list
// 4. Delete the n-th node from the end of the list
// 5. Exit the program

// Enter your choice: 1
// Type a number for appending (type x to stop): 1
// Type a number for appending (type x to stop): 2
// Type a number for appending (type x to stop): 3
// Type a number for appending (type x to stop): 4
// Type a number for appending (type x to stop): 5
// Type a number for appending (type x to stop): 6
// Type a number for appending (type x to stop): 7
// Type a number for appending (type x to stop): x

// ********* FancyList Menu *********
// 1. Create a list
// 2. Display the list
// 3. Reverse the list
// 4. Delete the n-th node from the end of the list
// 5. Exit the program

// Enter your choice: 2
// Current list is: 1  2  3  4  5  6  7  

#include <iostream>
#include "FancyList.h"

using namespace std;

// Defining member variables 

FancyList::FancyList()
{
    head = nullptr;
}

FancyList::~FancyList()
{
    Node * curr;
    Node * next;

    curr = head;

    cout << " Deallocating... " << endl << endl;
    
    while (curr != nullptr)
    {
        cout << " Deleting " << " " << curr->value << endl;

        next = curr->next;

        delete curr;

        curr = next;
    }

    head = nullptr;
    cout << endl << endl;
}

void FancyList::append(int num)
{
    Node * newNode;
    Node * nodePtr;

    newNode = new Node;
    newNode->value = num;
    newNode->next = nullptr;

    if(!head)
        head = newNode;
    else {
        nodePtr = head;

        while (nodePtr->next){
            nodePtr = nodePtr->next;
        }

        nodePtr->next = newNode;
    }
}

void FancyList::display()
{
    Node *nodePtr;
    nodePtr = head;

    while (nodePtr)
    {
        cout << nodePtr->value << " ";

        nodePtr = nodePtr->next;
    }
}

void FancyList::reverse()
{
    Node * curr = head;
    Node * prev = nullptr;
    Node * next = nullptr;

    if (curr != nullptr){
        next = curr->next;

        while (next != nullptr){
            curr->next = prev;

            prev = curr;
            curr = next;
            next = next->next;
        }

        curr->next = prev;
        head = curr;
    }

    cout << " Current list after reversing is: ";
    display();
}

void FancyList::deleteNth()
{
    int pos;
    int count = 0;

    cout << " Delete n-th node from the end of the list, your n is: ";
    cin >> pos;

    Node * curr = head; // Set curr to the head pointer to count from the start 
    while (curr)        // Transverse the list to find how many nodes are present and set the n values to counter
    {
        count++;
        curr = curr->next;
    }

    curr = head; // This code segment makes your curr pointer take the value of the  n-th node from the end of the list
    Node * prev = nullptr;
    for (int i = 0; i < count - pos; i++)
    {
        prev = curr;
        curr = curr->next;
    }

    if(!prev) // This code segment connects the nodes to the next ones when the deletion takes place
        head = curr->next;
    else    
        prev->next  = curr->next;
    delete curr;

    cout << " Current list after deleting the " << pos << "-th node from the end is: ";
    display();
}


// I looked online to learn how to do the delete function and everywhere it said to find the count of the list
// and then connect the pointers to the ones around the node being deleted but they used fast and slow pointers as 
// well as dummy pointers? I would like to understand if that would be easier, since I have not learnt it. 
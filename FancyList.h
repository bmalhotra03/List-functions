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

#ifndef FANCYLIST_H
#define FANCYLIST_H
#include <iostream>

using namespace std;

class FancyList
{

    private: 

        struct Node
        {
            int value;
            Node * next;
        };

        Node * head;

    public:

    FancyList();
    ~FancyList();
    void append(int);
    void display();
    void reverse();
    void deleteNth();

};

#endif


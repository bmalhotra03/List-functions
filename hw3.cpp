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
#include <cstdlib>
#include <string>
#include "FancyList.h"

using namespace std;

// Function prototype

int mainMenu();

int main()
{
    string str = "x";
    int num;
    int option;
    bool done = false;

    FancyList mainList;

    while (option != 5)
    {
        option = mainMenu();
        if (option == 1)
        {
            while (!done)
            {
                cout << " Type a number for appending (type x to stop): ";
                cin >> str;
                cout << endl;

                if (str == "x")
                {
                    done = true;
                    break;
                } else{
                    mainList.append(stoi(str));
                }  
            }
            done = false;
        }else if (option ==2)
        {
            cout << " Current list is: ";
            mainList.display();
        } else if (option ==  3)
        {
            mainList.reverse();
        } else if (option == 4)
        {
            mainList.deleteNth();
        }
    }

    return 0;
}

// Function declaration

int mainMenu()
{
    int menuChoice;
    
    cout << endl << endl;

    cout << " ********* FancyList Menu ********* " << endl;
    cout << " 1. Create a list" << endl;
    cout << " 2. Display the list" << endl;
    cout << " 3. Reverse the list" << endl;
    cout << " 4. Delete the n-th node from the end of the list" << endl;
    cout << " 5. Exit the program" << endl;

    cout << " Enter your choice: ";
    cin >> menuChoice;
    cout << endl << endl;

    return menuChoice;
}
#include <windows.h>

#include <chrono>
#include <ctime>
#include <iostream>
#include "User.h"
#include "Admin.h"

using namespace std;

// Function to log in the user
// Prompt user for login credentials and user type
void display(struct User* userHead)
{
    while (userHead != NULL)
    {
        cout << userHead->lastLoginDate << " ";
        userHead = userHead->nextNode;
    }
}

string endProgram() {
    system("cls");
    cout << "System Terminating..." << endl;
    Sleep(1000);
    cout << "....." << endl;
    Sleep(1000);
    cout << "..." << endl;
    Sleep(1000);
    cout << "." << endl;
    Sleep(1000);
    cout << "---Goodbye!---" << endl;
    return nullptr;
}
User* login(User* userHead) {

    string username, password;
    int userType;

    while (true) {
        cout << "\n+--------------------------------------------+\n";
        cout << "| *  Top Univeristy Recommendation System  * |\n";
        cout << "+--------------------------------------------+\n\n";

        cout << "\n\n=====  Login User Type Selection: =====\t\n";
        cout << "[ 1 ] - Guest\n";
        cout << "[ 2 ] - Registered Customer\n";
        cout << "[ 3 ] - MoHE Admin\n";
        cout << "[ 4 ] - Exit the Program\n\n";
        cout << "Please Enter Your User Type:\t";
        cin >> userType;

        if (userType == 4) {
            endProgram();
            //return nullptr; // User chooses to exit the program instantly
        }
        else {

            cout << "Please Enter Your Username:\t";
            cin >> username;
            cout << "Please Enter Your Password:\t";
            cin >> password;

            // Transverse singly linked list and check user credentials
            User* current = userHead;
            while (current) {
                if (current->username == username && current->password == password) {
                    cout << "Login successful!" << endl;
                    displayMenu(userHead, current);
                    return current; // Return pointer to user object
                }
                current = current->nextNode;
            }

            // If user not found or credentials don't match, return nullptr
            cout << "Invalid username or password. Please try again." << endl;
        }

    }

}


void displayMenu(User* userHead, User* current) {
    cout << "\n+---------------------------------------------+\n";
    cout << "          Welcome, " << current->name << "!      \n";
    cout << "+---------------------------------------------+\n\n";
    int userType = 3;

    switch (userType) {

    case 1: // Guest Menu
        cout << "\n\n===== User Type: Guest  =====\t\n\n";
        cout << "[ 1 ] - Sort University in Order\n";
        cout << "[ 2 ] - Search University Details\n";
        cout << "[ 3 ] - Feedback Mailbox\n";
        cout << "[ 4 ] - Logout\n\n";
        cout << "Please Select Your Option:\t";
        break;

    case 2: // Registered Customer Menu
        cout << "\n===== User Type: Registered Customer  =====\t\n\n";
        cout << "[ 1 ] - Sort University in Order\n";
        cout << "[ 2 ] - Search University Details\n";
        cout << "[ 3 ] - Feedback Mailbox\n";
        cout << "[ 4 ] - Logout\n\n";
        cout << "Please Select Your Option:\t";
        break;

    case 3:
        adminMenu(userHead, current);
        break;

    default:
        cout << endl << "Please Try Again." << endl << endl;
        break;
    }
}


// Function to calculate the time difference in ms



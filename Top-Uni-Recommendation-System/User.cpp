#include "User.h"

void User::login() {

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

        switch (userType) {
        case 1
            showGuestMenu();
        case 2: 
        case 3:
        case 4:
        default:
        }

        cout << "Please Enter Your Username:\t";
        cin >> username;
        cout << "Please Enter Your Password:\t";
        cin >> password;

        // Transverse singly linked list and check user credentials
        User* current = userHead;
        while (current) {
            if (current->username == username && current->password == password) {
                cout << "Login successful!" << endl;
                displayMenu(current);
                return current; // Return pointer to user object
            }
            current = current->next;
        }

        // If user not found or credentials don't match, return nullptr
        cout << "Invalid username or password. Please try again." << endl;


    }

}


User::User() :currentUser{ "U0001", "john" } {}
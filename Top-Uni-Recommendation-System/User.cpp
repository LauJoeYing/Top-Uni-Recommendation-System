#include "User.h"

//void showMenu(UserList* userHead, int userType) {
//    Admin admin;
//    switch (userType) {
//    case 1:
//        cout << "Hello";
//        break;
//    case 2:
//        showRegisteredCustomerMenu();
//        break;
//    case 3:
//        admin.showAdminMenu(userHead);
//        break;
//    case 4:
//        cout << "Bye";
//        break;
//        return;
//    default:
//        cout << "Wrong";
//        break;
//    }
//}
//
//UserList* login(UserList* userHead) {
//    //while (userHead != nullptr) {
//    //    cout << userHead->userId << endl;
//    //    userHead = userHead->nextNode;
//    //}
//
//    string username, password;
//    int userType;
//
//    while (true) {
//        cout << "\n+--------------------------------------------+\n";
//        cout << "| *  Top Univeristy Recommendation System  * |\n";
//        cout << "+--------------------------------------------+\n\n";
//
//        cout << "\n\n=====  Login User Type Selection: =====\t\n";
//        cout << "[ 1 ] - Guest\n";
//        cout << "[ 2 ] - Registered Customer\n";
//        cout << "[ 3 ] - MoHE Admin\n";
//        cout << "[ 4 ] - Exit the Program\n\n";
//        cout << "Please Enter Your User Type:\t";
//        cin >> userType;
//
//        cout << "Please Enter Your Username:\t" << endl;
//        cin >> username;
//        cout << "Please Enter Your Password:\t" << endl;
//        cin >> password;
//
//        while (userHead != NULL) {
//            if (userHead->username == username && userHead->password == password) {
//                cout << "Login successful!" << endl;
//                showMenu(userHead, userType);
//                return nullptr; // Return pointer to user object
//
//            }
//            userHead = userHead->nextNode;
//        }
//
//        // If user not found or credentials don't match, return nullptr
//        cout << "Invalid username or password. Please try again." << endl;
//
//    }
//}

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

        cout << "Please Enter Your Username:\t";
        cin >> username;
        cout << "Please Enter Your Password:\t";
        cin >> password;

        // Transverse singly linked list and check user credentials
        UserList* current = userHead;
        while (current) {
            if (current->username == username && current->password == password) {
                cout << "Login successful!" << endl;
                switch (userType) {
                case 1:
                    showRegisteredCustomerMenu();
                case 2:
                case 3:
                    //showAdminMenu(userHead);
                case 4:
                default:
                }
                //displayMenu(current);
                return; // Return pointer to user object

            }
            current = current->nextNode;
        }

        // If user not found or credentials don't match, return nullptr
        cout << "Invalid username or password. Please try again." << endl;


    }

}


User::User() :currentUser{ "U0001", "john" } {}
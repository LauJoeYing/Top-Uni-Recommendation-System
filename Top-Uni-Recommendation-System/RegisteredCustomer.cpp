#include "RegisteredCustomer.h"
#include "University.h"

void showRegisteredCustomerMenu() {
    University myUniversity; // Create a University object
    myUniversity.importUni(); // Call the importUni function using the University object

    int option;
    bool invalidOption = true;
    while (invalidOption) {
        cout << "===============================" << endl;
        cout << setw(2) << "        " << "CUSTOMER MENU" << endl;
        cout << "===============================" << endl;
        cout << setw(2) << " " << "1. View University" << endl;
        cout << setw(2) << " " << "2. Sort University" << endl;
        cout << setw(2) << " " << "3. Search University" << endl;
        cout << setw(2) << " " << "4. View Top 10 Favourite University" << endl;
        cout << setw(2) << " " << "5. Manage Feedback" << endl;
        cout << setw(2) << " " << "6. Manage Favourite" << endl;
        cout << setw(2) << " " << "7. Logout" << endl;
        cout << "===============================" << endl;
        cout << "Input:" << "\t";
        cin >> option;

        switch (option) {
        case 1:
            myUniversity.printTable(); // Call the printTable function using the University object
            invalidOption = false; // set flag to exit loop
            break;
        case 2:
            sortForRegisterCustomerPanel();
            invalidOption = false;
            break;
        case 3:
            //searchUniversity();
            invalidOption = false;
            break;
        case 4:
            myUniversity.printTopPickUniTable();
            invalidOption = false;
            break;
        case 5:
            //manageFeedback();
            invalidOption = false;
            break;
        case 6:
            //manage favourite();
            invalidOption = false;
            break;
        case 7:
            //manage favourite();
            logout();
            invalidOption = false;
            break;
        default:
            cout << "Invalid Option. Please enter a valid option." << endl;
            break;
        }
    }
}

void logout() {
    cout << "Logout Successful" << endl;
}
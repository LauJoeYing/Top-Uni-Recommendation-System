#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>
#include <ctime>

#include "File.h"
#include "University.h"
#include "Feedback.h"
#include "User.h"

using namespace std;

//struct declaration

struct FeedbackList;
struct UniList;
struct UserList;
struct CurrentUser;
struct Favourited;

//Declaration of functions

void showBootMenu();

void showGuestMenu();
void showGuestDisplayUniversityOptions();        //choose Sort or Search
void showSortOptions();
void showSearchOptions();

void showRegisteredUserMenu();
void showRegisteredUserDisplayUniversityOptionMenu();
void showChooseVariablesMenu();
void showRegViewFeedbackMenu();

void showAdminMenu();
void showAdminFeedbackMenu();
void showModifyUserMenu();
void showInactiveUserMenu();
void showSummary();


//Functions for testing//
void skipLogin();
void dummyCurrentUser();


//Struct Initialization

//struct FeedbackList {
//    string feedbackId;
//    string userName;
//    string adminName;
//    string subject;
//    string feedbackMessage;
//    string replyMessage;
//    string date;
//
//    FeedbackList* nextNode;
//    FeedbackList* prevNode;
//}*feedbackHead, *feedbackTail;
//
//struct Favourited {
//    string userId;
//    int userFavRankArr[10];  //Assume maximum of 10 favourite Uni each user, or else I will die
//    int counter;
//
//    Favourited* nextNode;
//}*favouritedHead;
//
//struct UniList {
//    int Rank;
//    string Institution;
//    string LocationCode;
//    string Location;
//    double ArScore;
//    int ArRank;
//    double ErScore;
//    int ErRank;
//    double FsrScore;
//    int FsrRank;
//    double CpfScore;
//    int CpfRank;
//    double IfrScore;
//    int IfrRank;
//    double IsrScore;
//    int IsrRank;
//    double IrnScore;
//    int IrnRank;
//    double GerScore;
//    int GerRank;
//    double ScoreScaled;
//    string Region;
//    int TotalPick;
//    UniList* nextNode;
//    UniList* prevNode;
//}*universityHead,*universityTail;
//
//struct CurrentUser {    //Just to be safe CurrentUser use "extern"
//    string userId;
//    string username;
//    string password;
//    string name;
//    string email;
//    string phoneNumber;
//    string gender;
//    string lastLoginDate;
//}currentUser;
//
//struct UserList {
//    string userId;
//    string username;
//    string password;
//    string name;
//    string email;
//    string phoneNumber;
//    string gender;
//    string lastLoginDate;
//    UserList* nextNode;
//}*userHead;

//Testing Functions   //DELETE AFTER DEPLOY
void skipLogin() {
    dummyCurrentUser();
    //showRegisteredUserMenu();
    showAdminMenu();
}

void dummyCurrentUser() {
    currentUser.userId = "A1234";
    currentUser.username = "Michelle Farrow";
    currentUser.password = "123";
    cout << "Passed" << endl;
    currentUser.email = "dummy123@gmail.com";
    currentUser.phoneNumber = "0182865952";
    currentUser.gender = "Male";
    currentUser.lastLoginDate = "04-05-2023";
}


// Function Initialization


void showBootMenu() {
    int userType;
    while (true) {
        cout << "\n+--------------------------------------------+\n";
        cout << "| *  Top Univeristy Recommendation System  * |\n";
        cout << "+--------------------------------------------+\n\n";

        cout << "\n\n===== System Boot Menu: =====\t\n";
        cout << "[ 1 ] - Proceed as Guest\n";
        cout << "[ 2 ] - Login\n";
        cout << "[ 3 ] - Set Login\n";           //Temporary for testing
        cout << "[ 4 ] - Exit the Program\n\n";
        cout << "Please Enter Your User Type:\t";
        cin >> userType;

        switch (userType) {
        case 1:
             showGuestMenu();
            break;
        case 2:
            //Login();
            break;
        case 3:
            skipLogin();
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid input. Please try again." << endl;
        }
    }
}

void showGuestMenu() {
    int choice;
    cout << "\n+--------------------------------------------+\n";
    cout << "          Welcome, " << "Guest" << "!      \n";
    cout << "+--------------------------------------------+\n\n";

    cout << "\n\n===== Guest Menu: =====\t\n";
    cout << "[ 1 ] - Display University\n";
    cout << "[ 2 ] - Register\n";
    cout << "[ 3 ] - Back\n";
    cout << "[ 4 ] - Exit the Program\n\n";
    cout << "Please Enter Your Choice:\t";
    cin >> choice;

    switch (choice) {
    case 1:
        showGuestDisplayUniversityOptions();
        break;
    case 2:
        callRegister();
        break;
    case 3:
        break;
    case 4:
        exit(0);
        break; 
    default:
        cout << "Invalid input. Please try again." << endl;
    }
}

void showRegisteredUserMenu() {
    int choice;
    cout << "\n+--------------------------------------------+\n";
    cout << "          Welcome, " << currentUser.username << "!      \n";
    cout << "+--------------------------------------------+\n\n";

    cout << "\n\n===== Guest Menu: =====\t\n";
    cout << "[ 1 ] - Display University\n";
    cout << "[ 2 ] - View Feedback\n";
    cout << "[ 3 ] - Send Feedback\n";
    cout << "[ 4 ] - Favourited University\n";
    cout << "[ 5 ] - Exit the Program\n\n";
    cout << "Please Enter Your Choice:\t";
    cin >> choice;

    switch (choice) {
    case 1:
        showRegisteredUserDisplayUniversityOptionMenu();
        break;
    case 2:
        showRegViewFeedbackMenu();
        break;
    case 3:
        //UserSendFeedback();
        break;
    case 4:
        //showUserFavourited
    case 5:
        exit(0);
    default:
        cout << "Invalid input. Please try again." << endl;
    }
}

void showAdminMenu() {
    int choice;
    cout << "\n+--------------------------------------------+\n";
    cout << "          Welcome, " << currentUser.username << "!      \n";
    cout << "+--------------------------------------------+\n\n";

    cout << "\n\n===== Admin Menu: =====\t\n";
    cout << "[ 1 ] - Display Existing Users\n";
    cout << "[ 2 ] - View and Reply Feedback\n";
    cout << "[ 3 ] - Modify User Account\n";
    cout << "[ 4 ] - Delete Account\n";
    cout << "[ 5 ] - Show Summary\n";
    cout << "[ 6 ] - Exit the Program\n\n";
    cout << "Please Enter Your Choice:\t";
    cin >> choice;

    switch (choice) {
    case 1:
        displayAllUsers();
        break;
    case 2:
        adminViewFeedbackList();
        break;
    case 3:
        
        break;
    case 4:

        break;
    case 5:

        break;
    case 6:
        exit(0);
        break;
    default:
        cout << "Invalid input. Please try again." << endl;
    }
}

void showGuestDisplayUniversityOptions(){
    int choice;
    displayUniversity();
    cout << "\n\n===== Sort or Search: =====\t\n";
    cout << "[ 1 ] - Sort By Name\n";
    cout << "[ 2 ] - Search By Name\n";
    cout << "[ 3 ] - Exit\n";
    cout << "Please Enter Your Choice:\t" << endl;
    cin >> choice;

    switch (choice) {
    case 1:
        showSortOptions();
        break;
    case 2:
        callBinarySearch();
        break;
    case 3:

        break;
    default:
        cout << "Invalid input. Please try again." << endl;
    }
    
}

void showSortOptions() {
    int choice;
    cout << "\n\n===== Choose Sort Algorithm: =====\t\n";
    cout << "[ 1 ] - Sort By Quick Sort\n";
    cout << "[ 2 ] - Sort using Tim Sort\n";
    cin >> choice;

    switch (choice) {
    case 1:
        quicksortForGuest();
        break;
    case 2:
        timsortForGuest();
        break;
    case 3:

        break;
    default:
        cout << "Invalid input. Please try again." << endl;
    }
}

void showSearchOptions() {
    int choice;
    cout << "\n\n===== Sort or Search: =====\t\n";
    cout << "[ 1 ] - Search By Binary\n";
    cout << "[ 2 ] - Search By Hash Search\n";
    cin >> choice;

    switch (choice) {
    case 1:
        callBinarySearch();
        break;
    case 2:
        break;
    case 3:

        break;
    default:
        cout << "Invalid input. Please try again." << endl;
    }
}

void showRegisteredUserDisplayUniversityOptionMenu() {
    int choice;
    displayUniversity();
    cout << "\n\n===== Modify Display: =====\t\n";
    cout << "[ 1 ] - Sort\n";
    cout << "[ 2 ] - Search\n";
    cout << "[ 3 ] - Exit\n";
    cin >> choice;

    switch (choice) {
    case 1:
        quicksortForRegisteredCustomer();
        break;
    case 2:

        break;
    case 3:

        break;
    default:
        cout << "invalid input";
    }
}

void showRegViewFeedbackMenu(){
    int choice;
    userViewFeedbackList();
    cout << "===== Actions ===== " << endl;
    cout << "[ 1 ] View Other Feedback" << endl;
    cout << "[ 2 ] Back To Main Menu" << endl;
    cout << "Please Enter Your Choice:\t";
    cin >> choice;

    switch (choice) {
    case 1:
        return showRegViewFeedbackMenu();
        break;
    case 2:
        return;
        break;
    case 3:

        break;
    default:
        cout << "Invalid input. Please try again." << endl;
    }

}




//Main

int main() {
    fileRelay();
    //displayAllUsers();
    showBootMenu();

}
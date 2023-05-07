#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <ctime>

#include "User.h"
#include "Admin.h"
using namespace std;
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
void srchFeedback() {
    cout << "This is Search Feedback Page";
}

void mdfyFeedback() {
    cout << "This is Modify Feedback Page";
}

void feedbackChoice(int choice) {
    switch (choice) {
    case 1: //search feedback
        srchFeedback();
        break;

    case 2: //modify feedback
        mdfyFeedback();
        break;

    case 3: //return to MoHE Admin main page
        cout << endl << "Will return to Main Page" << endl << endl;
        break;

    default:
        cout << endl << "Please Try Again." << endl << endl;
        break;
    }

}

void viewFeedback() {

    int adminType;

    while (true) {
        cout << "\n===== Manage User Feedback Menu =====\t\n\n";
        cout << "[ 1 ] - Search User Feedback\n";
        cout << "[ 2 ] - Modify User Feedback\n";
        cout << "[ 3 ] - Back\n\n";
        cout << "Please Select Your Option:\t";
        cin >> adminType;

        feedbackChoice(adminType);
        if (adminType == 3) {
            break;
        }
    }
}

void srchAccount(User* slctUser) {
    cout << "\nThis is Search User Account Page\n";
    cout << slctUser->username << "\n";
}

void chngName(User* slctUser) {
    string newName;
    cout << "\nThis is Change Username Page\n";
    cout << "Old Name\t:\t" << slctUser->name << "\n";
    cout << "New Name\t:\t";
    cin >> newName;
    slctUser->name = newName;
    cout << slctUser->name;
    cout << "Name successfully changed.";
}

void chngUsername(User* slctUser) {
    string newUsername;
    cout << "\nThis is Change Username Page\n";
    cout << "Old Username\t:\t" << slctUser->username << "\n";
    cout << "New Username\t:\t";
    cin >> newUsername;
    slctUser->username = newUsername;
    cout << slctUser->username;
    cout << "Username successfully changed.";
}

void chngPassword(User* slctUser) {
    string newPassword;
    cout << "\nThis is Change Password Page\n";
    cout << "Old Password\t:\t" << slctUser->password << "\n";
    cout << "New Password\t:\t";
    cin >> newPassword;
    slctUser->password = newPassword;
    cout << slctUser->password;
    cout << "Password successfully changed.";
}

void chngEmail(User* slctUser) {
    string newEmail;
    cout << "\nThis is Change Email Address Page\n";
    cout << "Old Email Address\t:\t" << slctUser->email << "\n";
    cout << "New Email Address\t:\t";
    cin >> newEmail;
    slctUser->email = newEmail;
    cout << slctUser->email;
    cout << "Email Address successfully changed.";
}

void chngPhoneNum(User* slctUser) {
    string newPhoneNum;
    cout << "\nThis is Change Phone Number Page\n";
    cout << "Old Phone Number\t:\t" << slctUser->phoneNumber << "\n";
    cout << "New Phone Number\t:\t";
    cin >> newPhoneNum;
    slctUser->phoneNumber = newPhoneNum;
    cout << slctUser->phoneNumber;
    cout << "Phone Number successfully changed.";
}

void mdfyChoice(User* slctUser, int choice) {
    switch (choice) {
    case 1: //Change Name
        chngName(slctUser);
        break;

    case 2: //Change Username
        chngUsername(slctUser);
        break;

    case 3: //Change Password
        chngPassword(slctUser);
        break;

    case 4: //Change Email Address
        chngEmail(slctUser);
        break;

    case 5: //Change Phone Number
        chngPhoneNum(slctUser);
        break;

    case 6: //return to Previous Page
        cout << endl << "Will return to Previous Page" << endl << endl;
        break;

    default:
        cout << endl << "Please Try Again." << endl << endl;
        break;
    }

}

User* profile(User* userHead) {
    int adminType;
    string checkId;
    User* current = userHead;
    cout << "\nPlease Select Customer ID\t:\t";
    cin >> checkId;
    while (current) {
        if (current->userId == checkId) {
            cout << "\n";
            cout << "\n================ USER PROFILE ==================\n";
            cout << "| Username \t\t|\t" << current->username << "\n";
            cout << "| Real Name\t\t|\t" << current->name << "\n";
            cout << "| Email Address\t\t|\t" << current->email << "\n";
            cout << "| Phone Number\t\t|\t" << current->phoneNumber << "\n";
            cout << "==================================================\n";
            cout << "\n===== Modify Menu =====\t\n\n";
            cout << "[ 1 ] - Name\n";
            cout << "[ 2 ] - Username\n";
            cout << "[ 3 ] - Password\n";
            cout << "[ 4 ] - Email Address\n";
            cout << "[ 5 ] - Phone Number\n";
            cout << "[ 6 ] - Back\n\n";
            cout << "Please Select Your Option:\t";
            cin >> adminType;

            mdfyChoice(current, adminType);
            if (adminType == 6) {
                break;
            }
            return current;

        }
        current = current->nextNode;
    }
}

void showAccount(User* userHead) {
    cout << "\n";
    cout << "User ID\t|\tName\t|\tLast Login Date\n";
    cout << "---------------------------------------\n";
    while (userHead != NULL)
    {
        cout << userHead->userId << "\t|\t" << userHead->name << "\t|\t"  << userHead->lastLoginDate << "\n";
        userHead = userHead->nextNode;
    }
    cout << "---------------------------------------\n";
}
string getCurrentDateString() {
    auto t = time(nullptr);
    auto tm = *localtime(&t);

    ostringstream oss;
    oss << put_time(&tm, "%d/%m/%Y");
    auto str = oss.str();

    return str;
}

bool checkDate(User* userHead) {
    string dateArray[3];
    string date, currentDate, currentMonth, currentYear, currentDay;
    string check;
    currentDate = getCurrentDateString();
    stringstream ss(currentDate);
    getline(ss, currentDay, '/');//get current day
    getline(ss, currentMonth, '/');//get current month
    getline(ss, currentYear);//get current year



    User* temp = userHead;
    while (temp != nullptr) {
        date = temp->lastLoginDate;
        try {
            stringstream ss(date);
            while (getline(ss, check)) {
                stringstream ss(check);
                getline(ss, dateArray[0], '/');//get last active day
                getline(ss, dateArray[1], '/');//get last active month
                getline(ss, dateArray[2]);//get last active year
            }
        }
        catch (exception& err)
        {
            cout << "Conversion failure" << endl;
        }

        //IF ELSE STATEMENT to check active inactive
        if (stoi(currentMonth) - stoi(dateArray[1]) > 3) {
            return true;
        }
        else if (stoi(currentYear) - stoi(dateArray[2]) > 0) {
            return true;
        }
        else {
            return false;
        }

        temp = temp->nextNode;

    }
}

void showInactive(User* userHead) {
    cout << userHead->userId;
    cout << "This is Show Inactive User Account Page\n\n";
    cout << "User ID\t|\tName\t\t\t|\tLast Login Date\n";
    cout << "------------------------------------------------------------------\n";
    while (userHead != NULL)
    {
        bool status = checkDate(userHead);
        if (status) {
            cout << userHead->userId << "\t|\t" << userHead->name << "\t\t|\t" << userHead->lastLoginDate << "\n";
            userHead = userHead->nextNode;
        }
        else {
            userHead = userHead->nextNode;
        }
    }
    cout << "------------------------------------------------------------------\n";
}

static void display(User* head)
{
    if (head == NULL)
    {
        cout << "NULL" << endl;
    }
    else
    {
        cout << head->userId << endl;
    }
}

//havent done witht eh delete inactive function
void dltSelect(User* userHead) {
    string dltType;
    string adminType;
    User* current = userHead;
    cout << "\nThis is delete selected inactive user page\n";
    cout << "\nEnter the Inactive User ID\t:\t";
    cin >> dltType;

    while (current) {
        if (current->userId == dltType) {
            cout << "\n";
            cout << "\n================ USER PROFILE ==================\n";
            cout << "| Username \t\t|\t" << current->username << "\n";
            cout << "| Real Name\t\t|\t" << current->name << "\n";
            cout << "| Email Address\t\t|\t" << current->email << "\n";
            cout << "| Phone Number\t\t|\t" << current->phoneNumber << "\n";
            cout << "| Last Login Date\t\t|\t" << current->lastLoginDate << "\n";
            cout << "==================================================\n";
            cout << "\nAre you sure you want to delete this user? [Yes/No]\t";
            cin >> adminType;
            if (adminType == "Yes") {
                User* check = userHead;

                cout << check->userId << "\n\n";
                display(check);
                cout << "\n\n";
                cout << "Run before here\n\n";
                if (check->prevNode == NULL) {
                    User* temp;
                    temp = check->nextNode;
                    cout << temp;
                    delete check;
                    delete temp;
                    cout << "\n\n";
                }
                else {
                    User* temp = check->prevNode;
                    temp->nextNode = check->nextNode;
                    delete check;
                    delete temp;
                    cout << "\n\n";
                }
                cout << "Run until here\n\n";
                //cout << temp->userId << "\n\n";
                cout << "Run end\n\n";
                //temp->nextNode = current->nextNode;

                cout << "\nYou have deleted\t:" << current->userId << "\t" << current->name << "\n\n";
                //showInactive(current);
                break;
            }
        }
        current = current->nextNode;
    }
}


void dltAll(User* userHead) {
    cout << "This is delete all inactive user page\n\n";
    while (userHead != NULL)
    {
        bool status = checkDate(userHead);
        if (status) {

            //temp = userHead->prevNode;
            //temp->nextNode = userHead->nextNode;
            cout << userHead->userId << "\t|\t" << userHead->name << "\t\t|\t" << userHead->lastLoginDate << "\n Deleted";
            userHead = userHead->nextNode;
        }
        else {
            userHead = userHead->nextNode;
        }
    }
}

void dltChoice(User* slctUser, int choice) {
    switch (choice) {
    case 1: //delete selected inactive user
        dltSelect(slctUser);
        break;

    case 2: //delete all inactive user
        dltAll(slctUser);
        break;

    case 3: //return to previous page
        cout << endl << "Will return to Previous Page" << endl << endl;
        break;

    default:
        cout << endl << "Please Try Again." << endl << endl;
        break;
    }
}



void mngDlt(User* userHead) {
    int adminType;
    while (true) {
        showInactive(userHead);
        cout << "\n===== Delete Inactive User Menu =====\t\n\n";
        cout << "[ 1 ] - Select Inactive User\n";
        cout << "[ 2 ] - Delete All\n";
        cout << "[ 3 ] - Back\n\n";
        cout << "Please Select Your Option:\t";
        cin >> adminType;

        dltChoice(userHead, adminType);
        if (adminType == 3) {
            break;
        }
    }
}

void mdfyAccount(User* userHead) {
    while (true) {
        //Profile form
        showAccount(userHead);
        profile(userHead);

        break;
    }

}

void mngChoice(User* userHead, int choice) {
    switch (choice) {
    case 1: //search User Account
        srchAccount(userHead);
        break;

    case 2: //modify User Account
        mdfyAccount(userHead);
        break;

    case 3: //show Inactive User Account
        mngDlt(userHead);
        break;

    case 4: //return to MoHE Admin main page
        cout << endl << "Will return to Main Page" << endl << endl;
        break;

    default:
        cout << endl << "Please Try Again." << endl << endl;
        break;
    }

}

void mngAct(User* userHead) {

    int adminType;

    while (true) {
        cout << "\n===== Manage User Account Menu =====\t\n\n";
        cout << "[ 1 ] - Search User Account Details\n";
        cout << "[ 2 ] - Modify User Account Details\n";
        cout << "[ 3 ] - Show Inactive User Account\n";
        cout << "[ 4 ] - Back\n\n";
        cout << "Please Select Your Option:\t";
        cin >> adminType;

        mngChoice(userHead, adminType);
        if (adminType == 4) {
            break;
        }
    }
}

void byCountry() {
    cout << "This is Show by Country Page";
}

void byOverall() {
    cout << "This is Show by Overall Performance Page";
}

void favUni() {
    cout << "This is Summary of Most Favourite University Page";
}

void sumChoice(int choice) {
    switch (choice) {
    case 1: //Summary by Country
        byCountry();
        break;

    case 2: //Summary by Overall
        byOverall();
        break;

    case 3: //summary of Most Favourite University
        favUni();
        break;

    case 4: //return to MoHE Admin main page
        cout << endl << "Will return to Main Page" << endl << endl;
        break;

    default:
        cout << endl << "Please Try Again." << endl << endl;
        break;
    }

}

void sumTop() {

    int adminType;

    while (true) {
        cout << "\n===== University Summary Menu =====\t\n\n";
        cout << "[ 1 ] - By Country\n";
        cout << "[ 2 ] - By Overall\n";
        cout << "[ 3 ] - Show Most Favourite Unversity\n";
        cout << "[ 4 ] - Back\n\n";
        cout << "Please Select Your Option:\t";
        cin >> adminType;

        sumChoice(adminType);
        if (adminType == 4) {
            break;
        }
    }
}

void adminChoice(User* userHead, int choice) {
    switch (choice) {
    case 1: //search feedback
        mngAct(userHead);
        break;

    case 2: //modify feedback
        viewFeedback();
        break;

    case 3:
        sumTop();
        break;

    case 4: //return to MoHE Admin main page
        cout << endl << "Will logout this page." << endl << endl;
        break;
    default:
        cout << endl << "Please Try Again." << endl << endl;
        break;
    }
}

void adminMenu(User* userHead, User* current) {
    int adminType;

    while (true) {
        cout << "\n===== User Type: MoHE Admin  =====\t\n\n";
        cout << "[ 1 ] - Manage Registered Customer Account\n";
        cout << "[ 2 ] - Manage Registered Customer Feedback\n";
        cout << "[ 3 ] - Top 10 Most Preferred Universities Summary\n";
        cout << "[ 4 ] - Logout\n\n";
        cout << "Please Select Your Option:\t";
        cin >> adminType;

        adminChoice(userHead, adminType);
        if (adminType == 4) {
            break;
        }
    }
}
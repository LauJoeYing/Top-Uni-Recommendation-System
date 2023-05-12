#include "Admin.h"
#include "University.h"
#include "RegisteredCustomer.h"

#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

Admin admin;

void readUserData(UserList*& userHead) {

    const string fileName = "User.csv";

    ifstream file(fileName);
    //Case 1: File is not accessible
    if (!file) {
        cerr << "Error: File Cannot Be Opened! " << fileName << endl;
        return;
    }

    //Case 2: File is accessible
    //Read data line by line from user.csv and create User objects
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string userId, username, password, name, email, phoneNumber, gender, lastLoginDate;

        if (getline(ss, userId, ',') &&
            getline(ss, username, ',') &&
            getline(ss, password, ',') &&
            getline(ss, name, ',') &&
            getline(ss, email, ',') &&
            getline(ss, phoneNumber, ',') &&
            getline(ss, gender, ',') &&
            getline(ss, lastLoginDate)) {

            //Create new User object and add it to singly linked list
            UserList* newUser = new UserList{ userId, username, password, name, email, phoneNumber, gender, lastLoginDate };

            if (userHead == nullptr) {
                userHead = newUser;
                cout << "Made it here" << endl;
            }

            else {
                UserList* current = userHead;

                while (current->nextNode != nullptr) {
                    current = current->nextNode;
                }

                current->nextNode = newUser;
            }
        }
    }

    //Close the file
    file.close();
}

void writeUserFile(UserList* userHead) {
    ofstream file;
    file.open("User.csv");
    UserList* temp = userHead;
    while (temp != NULL) {
        file << temp->userId << "," << temp->username << "," << temp->password << "," << temp->name << "," << temp->email << "," << temp->phoneNumber << "," << temp->gender << "," << temp->lastLoginDate << endl;
        temp = temp->nextNode;
    }
    file.close();
}

void modifyName(UserList* selectUser) {
    string newName;
    cout << "This is Modify Real Name." << endl << endl;
    cout << "Old Name\t:\t" << selectUser->name << endl;
    cout << "New Name\t:\t";
    cin >> newName;
    selectUser->name = newName;
    cout << selectUser->name << endl;
    cout << "Name successfully changed.";
    return;
};

void modifyUsername(UserList* selectUser) {
    string newUsername;
	cout << "This is Modify Username." << endl << endl;
    cout << "Old Username\t:\t" << selectUser->username << endl;
    cout << "New Username\t:\t";
    cin >> newUsername;
    selectUser->username = newUsername;
    cout << selectUser->username << endl;
    cout << "Username successfully changed.";
    return;
};

void modifyPassword(UserList* selectUser) {
    string newPassword;
    cout << "This is Change Password Page" << endl;
    cout << "Old Password\t:\t" << selectUser->password << endl;
    cout << "New Password\t:\t";
    cin >> newPassword;
    selectUser->password = newPassword;
    cout << selectUser->password << endl;
    cout << "Password successfully changed.";
    return;
};

void modifyEmail(UserList* selectUser) {
    string newEmail;
    cout << "This is Change Email Address Page" << endl;
    cout << "Old Email Address\t:\t" << selectUser->email << endl;
    cout << "New Email Address\t:\t";
    cin >> newEmail;
    selectUser->email = newEmail;
    cout << selectUser->email << endl;
    cout << "Email Address successfully changed.";
    return;
};

void modifyPhoneNumber(UserList* selectUser) {
    string newPhoneNum;
    cout << "This is Change Phone Number Page" << endl;
    cout << "Old Phone Number\t:\t" << selectUser->phoneNumber << endl;
    cout << "New Phone Number\t:\t";
    cin >> newPhoneNum;
    selectUser->phoneNumber = newPhoneNum;
    cout << selectUser->phoneNumber << endl;
    cout << "Phone Number successfully changed.";
    return;
};

void modifyGender(UserList* selectUser) {
    string newGender;
    cout << "This is Change Phone Number Page" << endl;
    cout << "Old Phone Number\t:\t" << selectUser->gender << endl;
    cout << "New Phone Number\t:\t";
    cin >> newGender;
    selectUser->gender = newGender;
    cout << selectUser->gender << endl;
    cout << "Gender successfully changed.";
    return;
};


bool modifyLoop = true;

void modifyChoice(UserList* selectUser, int choice) {
    switch (choice) {
    case 1: //Change Name
        modifyName(selectUser);
        break;

    case 2: //Change Username
        modifyUsername(selectUser);
        break;

    case 3: //Change Password
        modifyPassword(selectUser);
        break;

    case 4: //Change Email Address
        modifyEmail(selectUser);
        break;

    case 5: //Change Phone Number
        modifyPhoneNumber(selectUser);
        break;

    case 6: //return to Previous Page
        modifyGender(selectUser);
        break;

    case 7: //return to Previous Page
        cout << endl << "Will return to Previous Page" << endl << endl;
        modifyLoop = false;
        break;

    default:
        cout << endl << "Please Try Again." << endl << endl;
        break;
    }
    return;
}

void showAccount(UserList* userHead) {
    cout << "\n";
    cout << "----------------------------------------------------------------" << endl;
    cout << "|" << setw(10) << left << "User ID" << "|" << setw(30) << left << "Name" << "|" << setw(20) << left << "Last Login Date" << "|" << endl;
    cout << "----------------------------------------------------------------" << endl;
    while (userHead != NULL)
    {
        cout << "|" << setw(10) << left << userHead->userId << "|" << setw(30) << left << userHead->name << "|" << setw(20) << left << userHead->lastLoginDate << "|" << endl;
        userHead = userHead->nextNode;
    }
    cout << "----------------------------------------------------------------" << endl;
    return;
}

void showModifyMenu(UserList* selectUser) {
    showAccount(selectUser);
    int adminType;
    string checkId;
    UserList* current = selectUser;
    cout << "\nPlease Select Customer ID\t:\t";
    cin >> checkId;
    while (modifyLoop) {
        if (current->userId == checkId) {
            cout << endl << "================== USER PROFILE =====================" << endl;
            cout << "|" << setw(20) << left << "Username"<< "|" << setw(30) << left << current->username << "|" << endl;
            cout << "|" << setw(20) << left << "Real Name" << "|" << setw(30) << left << current->name << "|" << endl;
            cout << "|" << setw(20) << left << "Email Address" << "|" << setw(30) << left << current->email << "|" << endl;
            cout << "|" << setw(20) << left << "Phone Number" << "|" << setw(30) << left << current->phoneNumber << "|" << endl;
            cout << "|" << setw(20) << left << "Gender" << "|" << setw(30) << left << current->gender << "|" << endl;
            cout << "=====================================================" << endl;
            cout << endl << "===== Modify Menu =====" << endl;
            cout << "[ 1 ] - Name" << endl;
            cout << "[ 2 ] - Username" << endl;
            cout << "[ 3 ] - Password" << endl;
            cout << "[ 4 ] - Email Address" << endl;
            cout << "[ 5 ] - Phone Number" << endl;
            cout << "[ 6 ] - Gender" << endl;
            cout << "[ 7 ] - Back" << endl;
            cout << "Please Select Your Option:\t";
            cin >> adminType;
            modifyChoice(current, adminType);
            return;
        }
        current = current->nextNode;
    }
}



void Admin::modifyRegisteredCustomerDetail(UserList* userHead) {
    cout << "This is Modify Registered Customer Detail." << endl << endl;
    showModifyMenu(userHead);
};

string getCurrentDateString() {
    auto t = time(nullptr);
    auto tm = *localtime(&t);

    ostringstream oss;
    oss << put_time(&tm, "%d/%m/%Y");
    auto str = oss.str();

    return str;
}

bool checkDate(UserList* userHead) {
    string dateArray[3];
    string date, currentDate, currentMonth, currentYear, currentDay;
    string check;
    currentDate = getCurrentDateString();
    stringstream ss(currentDate);
    getline(ss, currentDay, '/');//get current day
    getline(ss, currentMonth, '/');//get current month
    getline(ss, currentYear);//get current year



    UserList* temp = userHead;
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

void Admin::deleteRegisteredCustomerAccount(UserList* userHead, string deleteUser) {
    UserList* temp = userHead;
    UserList* prev = nullptr;

    string choice;

    while (temp != nullptr) {
        if (temp->userId == deleteUser) {
            cout << endl << "================== USER PROFILE =====================" << endl;
            cout << "|" << setw(20) << left << "Username" << "|" << setw(30) << left << temp->username << "|" << endl;
            cout << "|" << setw(20) << left << "Real Name" << "|" << setw(30) << left << temp->name << "|" << endl;
            cout << "|" << setw(20) << left << "Email Address" << "|" << setw(30) << left << temp->email << "|" << endl;
            cout << "|" << setw(20) << left << "Phone Number" << "|" << setw(30) << left << temp->phoneNumber << "|" << endl;
            cout << "|" << setw(20) << left << "Gender" << "|" << setw(30) << left << temp->gender << "|" << endl;
            cout << "=====================================================" << endl;
            cout << "Are you sure you want to delete this account?[Yes/No] : " << endl;

            cin >> choice;
            if (choice == "Yes") {
                if (prev == nullptr) {
                    userHead = temp->nextNode;
                }
                else {
                    prev->nextNode = temp->nextNode;
                }
                cout << temp->name << " (Registered Customer) has been deleted from the system." << endl;
                delete temp;
                break;
            }
            else {
                return;
            }
        }
        prev = temp;
        temp = temp->nextNode;
    }
    return;
    //successfully delete message
};

void Admin::checkInactiveUser(UserList* userHead) {
    UserList* temp = userHead;
    string inactiveUserArray[250];
    int k = 0;
    while (temp != nullptr) {
        if (checkDate(temp) == true) {
            inactiveUserArray[k] = temp->userId;
            k++;
        }
        temp = temp->nextNode;
    }

    temp = userHead;
    for (int i = 0; i < k; i++) {
        while (temp != nullptr) {
            //cout << "[" << i << "]\t" << temp->userId << "\t" << temp->lastLoginDate << endl;
            if (inactiveUserArray[i] == temp->userId) {
                cout << "[" << i << "]\t" << temp->userId << "\t" << temp->lastLoginDate << endl;
            }
            temp = temp->nextNode;
        }
        temp = userHead;
    }
    cout << "Please enter the user you want to delete: " << endl;
    int choice;
    cin >> choice;
    temp = userHead;

    deleteRegisteredCustomerAccount(userHead, inactiveUserArray[choice]);
    return;
}

bool manageMenuLoop = true;

void manageChoice(UserList* userHead, int choice) {
    switch (choice) {
    case 1: //search customer
        cout << "This is the Search User Account Page." << endl << endl;

        break;

    case 2: //modify customer details
        cout << "This is the Modify User Account Page." << endl << endl;
        admin.modifyRegisteredCustomerDetail(userHead);
        break;

    case 3: //show and delete inactive customer.
        cout << "This is the Show Inactive User Account Page." << endl << endl;
        admin.checkInactiveUser(userHead);
        break;

    case 4: //return to MoHE Admin main page
        cout << endl << "Will Return to Admin Main Page." << endl << endl;
        manageMenuLoop = false;
        break;
    default:
        cout << endl << "Please Try Again." << endl << endl;
        break;
    }
    return;
}

void showManageMenu(UserList* userHead) {
    cout << "This is Manage User Menu." << endl << endl;
    int adminType;

    while (manageMenuLoop) {
        cout << "\n===== Manage User Account Menu =====\t\n\n";
        cout << "[ 1 ] - Search User Account Details\n";
        cout << "[ 2 ] - Modify User Account Details\n";
        cout << "[ 3 ] - Show Inactive User Account\n";
        cout << "[ 4 ] - Back\n\n";
        cout << "Please Select Your Option:\t";
        cin >> adminType;

        manageChoice(userHead, adminType);
    }
    return;

};

bool feedbackMenuLoop = true;
Feedback feedback;
void feedbackChoice(int choice) {

    switch (choice) {
    case 1: //search feedback
        cout << "This is the Search User Feedback Page." << endl << endl;
        feedback.adminViewFeedbackList();
        break;

    case 2: //modify customer
        cout << "This is the Modify User Feedback Page."  << endl << endl;
        break;

    case 3:
        cout << endl << "Will Return to Admin Main Page." << endl << endl;
        feedbackMenuLoop = false;
        break;
    default:
        cout << endl << "Please Try Again." << endl << endl;
        break;
    }
    return;
}
string feedbackID;
string userName;
string adminName;
string subject;
string feedbackMessage;
string replyMessage;
string date;
void showFeedbackMenu() {
    cout << "This is Manage Feedback Menu." << endl << endl;
    int adminType;

    while (feedbackMenuLoop) {
        cout << "\n===== Manage User Feedback Menu =====\t\n\n";
        cout << "[ 1 ] - View User Feedback\n";
        cout << "[ 2 ] - Modify User Feedback\n";
        cout << "[ 3 ] - Back\n\n";
        cout << "Please Select Your Option:\t";
        cin >> adminType;

        feedbackChoice(adminType);
    }
    return;
};

bool topMenuLoop = true;

void topChoice(int choice) {
    switch (choice) {
    case 1: //search feedback
        cout << "This is the Show By Country Page."<< endl << endl;
        break;

    case 2: //modify customer
        cout << "This is the Show By Overall Page." << endl << endl;
        break;

    case 3:
        cout << "This is the Show By Most Favourite Page." << endl << endl;
        break;

    case 4: //return to MoHE Admin main page
        cout << endl << "Will Return to Admin Main Page." << endl << endl;
        topMenuLoop = false;
        break;
    default:
        cout << endl << "Please Try Again." << endl << endl;
        break;
    }
    return;
}

void showTopMenu() {
    cout << "This is Top 10 Universities Summary Menu." << endl << endl;
    int adminType;

    while (topMenuLoop) {
        cout << "\n===== University Summary Menu =====\t\n\n";
        cout << "[ 1 ] - By Country\n";
        cout << "[ 2 ] - By Overall\n";
        cout << "[ 3 ] - Show Most Favourite Unversity\n";
        cout << "[ 4 ] - Back\n\n";
        cout << "Please Select Your Option:\t";
        cin >> adminType;

        topChoice(adminType);
    }
    return;
};

bool adminMenuLoop = true;

void adminChoice(UserList* userHead, int choice) {
    Admin admin;
    switch (choice) {
    case 1: //search feedback
        cout << "This is the manage choice: " << endl << endl;
        showManageMenu(userHead);
        break;

    case 2: //modify customer
        cout << "This is the feedback choice: " << endl << endl;
        showFeedbackMenu();
        break;

    case 3:
        cout << "This is the top 10 choice: " << endl << endl;
        showTopMenu();
        break;

    case 4: //return to MoHE Admin main page
        cout << endl << "Will logout this page." << endl << endl;
        adminMenuLoop = false;
        break;
    default:
        cout << endl << "Please Try Again." << endl << endl;
        break;
    }
    return;
}

void Admin::showAdminMenu(UserList* userHead) {
    cout << "This is Show Admin Menu." << endl << endl;
    int adminType;
    while (adminMenuLoop) {
        cout << "\n===== User Type: MoHE Admin  =====\t\n\n";
        cout << "[ 1 ] - Manage Registered Customer Account\n";
        cout << "[ 2 ] - Manage Registered Customer Feedback\n";
        cout << "[ 3 ] - Top 10 Most Preferred Universities Summary\n";
        cout << "[ 4 ] - Logout\n\n";
        cout << "Please Select Your Option:\t";
        cin >> adminType;

        adminChoice(userHead, adminType);
    }
    return;

};

void showMenu(UserList* userHead, int userType) {
    switch (userType) {
    case 1:
        cout << "Hello";
        break;
    case 2:
        showRegisteredCustomerMenu();
        break;
    case 3:
        admin.showAdminMenu(userHead);
        break;
    case 4:
        cout << "Bye";
        /*readUserData(userHead);*/
        writeUserFile(userHead);
        feedback.writeFeedbackFile();
        break;
        return;
    default:
        cout << "Wrong";
        break;
    }
}

void Admin::login() {

    UserList* userHead = nullptr;
    readUserData(userHead);
    feedback.importFeedbackFile();
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

        cout << "Please Enter Your Username:\t" << endl;
        cin >> username;
        cout << "Please Enter Your Password:\t" << endl;
        cin >> password;

        while (userHead != NULL) {
            if (userHead->username == username && userHead->password == password) {
                cout << "Login successful!" << endl;
                showMenu(userHead, userType);
                // Return pointer to user object

            }
            userHead = userHead->nextNode;
        }

        // If user not found or credentials don't match, return nullptr
        cout << "Invalid username or password. Please try again." << endl;

        }
}


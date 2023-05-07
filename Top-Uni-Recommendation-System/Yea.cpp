#include <string>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>

using namespace std;

struct User {
    string userId;
    string username;
    string password;
    string name;
    string email;
    string phoneNumber;
    string gender;
    string lastLoginDate;

    User* nextNode;
};


void readUserData(User*& userHead) {

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
            User* newUser = new User{ userId, username, password, name, email, phoneNumber, gender, lastLoginDate };

            if (userHead == nullptr) {
                userHead = newUser;
                cout << "Made it here" << endl;
            }

            else {
                User* current = userHead;

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

void adminMenu(User* userHead);

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
            // endProgram();
            return nullptr; // User chooses to exit the program instantly
        }
        else {

            cout << "Please Enter Your Username:\t" << endl;
            cin >> username;
            cout << "Please Enter Your Password:\t" << endl;
            cin >> password;

            // Transverse singly linked list and check user credentials
            User* temp = userHead;
            while (temp != nullptr) {
                if (temp->username == username) {
                    cout << "Login successful!" << endl;
                    adminMenu(userHead);
                    return temp; // Return pointer to user object
                }
                temp = temp->nextNode;
            }

            // If user not found or credentials don't match, return nullptr
            cout << "Invalid username or password. Please try again." << endl;
        }

    }

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

void deleteUser(User* userHead, string byebye) {
    User* temp = userHead;
    User* prev = nullptr;
    while (temp != nullptr) {
        if (temp->userId == byebye) {
            if (prev == nullptr) {
                userHead = temp->nextNode;
            }
            else {
                prev->nextNode = temp->nextNode;
            }
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->nextNode;
    }
}

void checkInactiveUser(User* userHead) {
    User* temp = userHead;
    string inactiveUserArray[10];
    int k = 0;
    while (temp != nullptr) {
        if (checkDate(userHead) == true) {
            inactiveUserArray[k] = temp->userId;
            k++;
        }
        temp = temp->nextNode;
    }
    temp = userHead;
    for (int i = 0; i < k; i++) {
        while (temp != nullptr) {
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
    deleteUser(userHead, inactiveUserArray[choice]);
}

void adminMenu(User* userHead) {
    int choice;
    cout << "Welcome to the admin menu!" << endl;
    cout << "Please select an option: " << endl;
    cout << "[1] - Check inactive users" << endl;
    cout << "[2] - Exit" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        checkInactiveUser(userHead);
        break;
    case 2:
        break;
    default:
        break;
    }
}

int main() {
    User* userHead = nullptr;
    readUserData(userHead);
    User* currentUser = login(userHead);
    return 0;
}
#include <windows.h>

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>

using namespace std;

//Read User File store into Linked List
//Search user file using username
//If username found, check password
//If password correct, login
//If password incorrect, prompt user to re-enter password
//If username not found, prompt user to re-enter username
//If possible try to create modify function to change password

//Global Variables
string tmpLogonUserDetails[7]; //Very bad for security, but for my own convenience

struct User {
    string accType;
    string username;
    string password;
    string realName;
    string email;
    string phoneNo;
    string gender;

    User* nextNode;
    User* prevNode;
}*head, * tail;

void insertAtEnd(string accType, string username, string password, string realName, string email, string phoneNo, string gender) {
    User* newNode = new User;
    newNode->accType = accType;
    newNode->username = username;
    newNode->password = password;
    newNode->realName = realName;
    newNode->email = email;
    newNode->phoneNo = phoneNo;
    newNode->gender = gender;
    newNode->nextNode = NULL;
    newNode->prevNode = NULL;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->nextNode = newNode;
        newNode->prevNode = tail;
        tail = newNode;
    }
}

void importUserFile() {
    ifstream file;
    file.open("UserData.csv");
    if (!file) {
        cout << "Error opening file" << endl;
        return;
    }
    string line;
    getline(file, line);
    while (getline(file, line)) {
        stringstream ss(line);
        string accType, username, password, realName, email, phoneNo, gender;
        getline(ss, accType, ',');
        getline(ss, username, ',');
        getline(ss, password, ',');
        getline(ss, realName, ',');
        getline(ss, email, ',');
        getline(ss, phoneNo, ',');
        getline(ss, gender, ',');
        insertAtEnd(accType, username, password, realName, email, phoneNo, gender);
    }
    file.close();
    return;
}

void login() {
    string tmpLoginUsernameInput, tmpLoginPasswordInput;
    cout << "Username: ";
    cin >> tmpLoginUsernameInput;
    cout << "Password: ";
    cin >> tmpLoginPasswordInput;
    User* temp = head;
    while (temp != NULL) {
        if (temp->username == tmpLoginUsernameInput) {
            if (temp->password == tmpLoginPasswordInput) {
                cout << "Login Successful" << endl;
                return;
            }
            else {
                cout << "Incorrect Password" << endl;
                return;
            }
        }
        temp = temp->nextNode;
    }

}

void showMenu() {
    int choice;
    cout << "Welcome to the Top Uni Recommendation System" << endl;
    cout << "============================================" << endl;
    cout << "1. Login" << endl;
    cout << "2. Register" << endl;
    cout << "3. Proceed as Guest" << endl;
    cout << "4. Exit" << endl;
    cout << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
    case 1:
        login();
        break;
    case 2:
        cout << "Register" << endl;
        break;
    case 3:
        cout << "Proceed as Guest" << endl;
        break;
    case 4:
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
        return;
        break;
    default:
        cout << "Invalid choice" << endl;
        break;
    }
    showMenu();
}



int main() {
    importUserFile();
    showMenu();
    // displayList();
}



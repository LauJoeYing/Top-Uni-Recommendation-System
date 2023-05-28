#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <regex>

using namespace std;

//Register
void callRegister();
bool isValidEmail(const std::string& email);
bool isValidPassword(const std::string& password);
bool isValidPhoneNumber(const std::string& phone_number);
bool isValidUsername(const std::string& username);
void callRegister();
void displayAllUsers();
void modifyOptions(UserList*);
void displayInactiveUsers();
void deleteInactiveUsers();
void deleteTargetUser(UserList*);
extern void showGuestMenu();


bool isValidEmail(const std::string& email) {          //Email format
    std::regex email_regex("^\\S+@\\S+\\.\\S+$");
    return std::regex_match(email, email_regex);
}


bool isValidPassword(const std::string& password) {             //Aphanumerical Only, one Upper one Lower One digit atleast
    std::regex password_regex("^(?=.*[a-zA-Z])(?=.*\\d)[a-zA-Z\\d]{6,20}$");
    return std::regex_match(password, password_regex);
}


bool isValidPhoneNumber(const std::string& phone_number) {                      //10 or 11 digits, starting with 01
    std::regex phone_regex("^01\\d{8,9}$");
    return std::regex_match(phone_number, phone_regex);
}

bool isValidUsername(const std::string& username) {                    //alphanumerical  4-20 char
    std::regex username_regex("^[a-zA-Z0-9]{4,20}$");
    return std::regex_match(username, username_regex);
}

void modifyPassword(UserList* user) {
    string oldPass, newPass, confirmNewPass;
    cout << "\n\n===== Modify Password: =====\t\n" << endl;
    cout << "Input Old Password: \t" << endl;
    cin >> oldPass;
    if (oldPass == user->password) {
        while (true) {
            cout << "Input New Password: \t" << endl;
            cin >> newPass;
            cout << "Confirm New Password: \t" << endl;
            cin >> confirmNewPass;
            if (newPass == confirmNewPass) {
                if (isValidPassword(newPass)) {
                    break;
                }
                else {
                    cout << "\Invalid Password Format." << endl;
                }
            }
            else {
                cout << "\nPassword Does Not Match." << endl;
            }
        }
        user->password = newPass;
        cout << "Password successfully modified" << endl;
    }
}

void modifyEmail(UserList* user) {
    string oldEmail, newEmail, confirmNewEmail;
    cout << "\n\n===== Modify Email: =====\t\n" << endl;
    cout << "Input Old Email: \t" << endl;
    cin >> oldEmail;
    if (oldEmail == user->email) {
        while (true) {
            cout << "Input New Email: \t" << endl;
            cin >> newEmail;
            cout << "Confirm New Email: \t" << endl;
            cin >> confirmNewEmail;
            if (newEmail == confirmNewEmail) {
                if (isValidEmail(newEmail)) {
                    break;
                }
                else {
                    cout << "\nInvalid Email Format." << endl;
                }
            }
            else {
                cout << "\nEmail Does Not Match." << endl;
            }
        }
        user->email = newEmail;
        cout << "Email successfully modified" << endl;
    }
}

void modifyPhoneNumber(UserList* user) {
    string oldPhoneNumber, newPhoneNumber, confirmNewPhoneNumber;
    cout << "\n\n===== Modify Phone Number: =====\t\n" << endl;
    cout << "Input Old Phone Number: \t" << endl;
    cin >> oldPhoneNumber;
    if (oldPhoneNumber == user->phoneNumber) {
        while (true) {
            cout << "Input New Phone Number: \t" << endl;
            cin >> newPhoneNumber;
            cout << "Confirm New Phone Number: \t" << endl;
            cin >> confirmNewPhoneNumber;
            if (newPhoneNumber == confirmNewPhoneNumber) {
                if (isValidPhoneNumber(newPhoneNumber)) {
                    break;
                }
                else {
                    cout << "\nInvalid Phone Number Format." << endl;
                }
            }
            else {
                cout << "\nPhoneNumber Does Not Match." << endl;
            }
        }
        user->phoneNumber = newPhoneNumber;
        cout << "Password successfully modified" << endl;
    }
}

void modifyUsername(UserList* user) {
    string oldUsername, newUsername, confirmNewUsername;
    cout << "\n\n===== Modify Username: =====\t\n" << endl;
    cout << "Input Old Username: \t" << endl;
    cin >> oldUsername;
    if (oldUsername == user->username) {
        while (true) {
            cout << "\nInput New Username: \t" << endl;
            cin >> newUsername;
            cout << "Confirm New Username: \t" << endl;
            cin >> confirmNewUsername;
            if (newUsername == confirmNewUsername){
                if (isValidUsername(newUsername)) {
                    break;
                }
                else {
                    cout << "\nInvalid Username Format." << endl;
                }
            }
            else {
                cout << "\nUsername Does Not Match." << endl;
            }
        }
        user->username = newUsername;
        cout << "Username successfully modified" << endl;
    }
}

string getNewRegisteredUserId() {
    UserList* temp = userHead;
    while (temp->nextNode != NULL) {
        temp = temp->nextNode;
    }
    ostringstream oss;
    string id = temp->userId;
    int num = stoi(id.substr(1,5));
    num++;
    oss << setw(4) << setfill('0') << num;
    id = "C" + oss.str();
    return id;
}

std::string getCurrentDateString() {
    std::time_t t = std::time(nullptr);
    std::tm tm;
    localtime_s(&tm, &t);

    std::ostringstream oss;
    oss << std::put_time(&tm, "%d-%m-%Y");
    auto str = oss.str();

    return str;
}

void showRegDetails(string new_Username, string new_Password, string new_realName, string new_Email, string new_PhoneNo, string new_Gender) {
    cout << "==================================================" << endl;
    cout << setw(15) << left << "Username" << "\t" << new_Username << endl;
    cout << setw(15) << left << "Password" << "\t" << new_Password << endl;
    cout << setw(15) << left << "Real Name" << "\t" << new_realName << endl;
    cout << setw(15) << left << "Email" << "\t" << new_Email << endl;
    cout << setw(15) << left << "Phone Number" << "\t" << new_PhoneNo << endl;
    cout << setw(15) << left << "Gender" << "\t" << new_Gender << endl;

    cout << "\n\n==================================================\n" << endl;
    cout << "Are you sure you want to register?\n[ 1 ]\tYes\n[ 2 ]\tNo" << endl;
    int choice;
    cin >> choice;
    switch (choice) {
    case 1:
        break;
    case 2:
        return showGuestMenu();
    default:
        cout << "Invalid Input" << endl;
    }
}


void callRegister() {
    string inputUsername, inputPassword, inputName, inputEmail, inputPhoneNumber, inputGender;
    int genderChoice, choice;
    system("cls");
    cout << "\n\n===== New User Register =====\t\n" << endl;

    cout << "\nInput Real Name: \t";
    cin.clear();
    cin.ignore(1000, '\n');
    getline(cin, inputName);
    cout << "Input Email: \t";
    cin >> inputEmail;
    cout << "Input Phone Number: \t";
    cin >> inputPhoneNumber;
    while (true) {
        cout << "\nChoose Gender: \t" << endl;
        cout << "[ 1 ] Male" << endl;
        cout << "[ 2 ] Female" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            inputGender = "Male";
            break;
        case 2:
            inputGender = "Female";
            break;
        default:
            cout << "Invalid Input..." << endl;
        }
        break;
    }
    while (isValidEmail(inputEmail) && isValidPhoneNumber(inputPhoneNumber)) {
        cout << "Input Username: \t";
        cin >> inputUsername;
        cout << "Input Password: \t";
        cin >> inputPassword;
        if (isValidUsername(inputUsername) && isValidPassword(inputPassword)) {
            showRegDetails(inputUsername, inputPassword, inputName, inputEmail, inputPhoneNumber, inputGender);
            UserList* newUser = new UserList{ getNewRegisteredUserId(), inputUsername, inputPassword, inputName, inputEmail, inputPhoneNumber, inputGender, getCurrentDateString(), nullptr };
            insertUserAtTail(getNewRegisteredUserId(), inputUsername, inputPassword, inputName, inputEmail, inputPhoneNumber, inputGender, getCurrentDateString());
            cout << "Passed" << endl;
            return showGuestMenu();
        }
    }
    cout << "Something went wrong" << endl;
}


void displayAllUsers() {
    UserList* userTemp = userHead;
    cout << "+===========================================================================================================================================================+" << endl;
    cout << "|" << setw(7) << left << "ID" << "|" << setw(25) << left << "Username" << "|" << setw(25) << left << "Password" << "|" << setw(25) << left << "Name" << "|" << setw(35) << left << "Email" << "|" << setw(12) << left << "Phone Number" << "|" << setw(7) << left << "Gender" << "|" << setw(12) << left << "Last Active" << "|" << endl;
    cout << "+===========================================================================================================================================================+" << endl;
    while (userTemp != NULL) {
        cout << "|" << setw(7) << left << userTemp->userId << "|" << setw(25) << left << userTemp->username << "|" << setw(25) << left << userTemp->password << "|" << setw(25) << left << userTemp->name << "|" << setw(35) << left << userTemp->email << "|" << setw(12) << left << userTemp->phoneNumber << "|" << setw(7) << left << userTemp->gender << "|" << setw(12) << left << userTemp->lastLoginDate << "|" << endl;
        userTemp = userTemp->nextNode;
    }
    cout << "+===========================================================================================================================================================+" << endl;

}

void displayInactiveUsers() {

}

void deleteInactiveUsers() {

}

void deleteTargetUser(UserList*current) {

}
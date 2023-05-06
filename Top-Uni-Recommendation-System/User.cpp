#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>

#include "UserFH.h"

using namespace std;

void insertUser(string userId, string username, string password, string realName, string email, string phoneNo, string gender, string lastLoginDate) {
    User* newNode = new User;
    newNode->userId = userId;
    newNode->username = username;
    newNode->password = password;
    newNode->realName = realName;
    newNode->email = email;
    newNode->phoneNo = phoneNo;
    newNode->gender = gender;
    newNode->lastLoginDate = lastLoginDate;
    newNode->nextNode = NULL;
    newNode->prevNode = NULL;

    if (userHead == NULL) {
        userHead = newNode;
        userTail = newNode;
    }
    else {
        userTail->nextNode = newNode;
        newNode->prevNode = userTail;
        userTail = newNode;
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
        string userId, username, password, realName, email, phoneNo, gender, lastLoginDate;
        getline(ss, userId, ',');
        getline(ss, username, ',');
        getline(ss, password, ',');
        getline(ss, realName, ',');
        getline(ss, email, ',');
        getline(ss, phoneNo, ',');
        getline(ss, gender, ',');
        getline(ss, lastLoginDate, ',');
        insertUser(userId, username, password, realName, email, phoneNo, gender, lastLoginDate);
    }
    file.close();
    return;
}
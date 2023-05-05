#ifndef USERFH_H
#define USERFH_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>

using namespace std;

struct User;

void importUserFile();
void writeUserFile();

struct User{
    string userId;
    string username;
    string password;
    string realName;
    string email;
    string phoneNo;
    string gender;
    string lastLoginDate;

    User *nextNode;
    User *prevNode;
}*userHead, *userTail;

void insertUser(string userId, string username, string password, string realName, string email, string phoneNo, string gender, string lastLoginDate) {
    User *newNode = new User{userId, username, password, realName, email, phoneNo, gender, lastLoginDate};
    newNode->nextNode = NULL;
    newNode->prevNode = NULL;

    if(userHead == NULL){
        userHead = newNode;
        userTail = newNode;
    }else{
        userTail->nextNode = newNode;
        newNode->prevNode = userTail;
        userTail = newNode;
    }
}

void importUserFile(){
    ifstream file;
    file.open("UserData.csv");
    if(!file){
        cout << "Error opening file" << endl;
        return;
    }
    string line;
    getline(file, line);
    while (getline(file, line)){
        stringstream ss(line); 
        string userId, username, password, realName, email, phoneNo, gender, lastLoginDate;
        getline(ss, userId, ',');
        getline(ss, username, ',');
        getline(ss, password, ',');
        getline(ss, realName, ',');
        getline(ss, email, ',');
        getline(ss, phoneNo, ',');
        getline(ss, gender, ',');

        insertUser(userId, username, password, realName, email, phoneNo, gender, lastLoginDate);
    }
    file.close();
    return;
}

//Write to file
void writeUserFile(){
    ofstream file;
    file.open("User.csv");
    User *temp = userHead;
    while(temp != NULL){
        file << temp->userId << "," << temp->username << "," << temp->password << "," << temp->realName << "," << temp->email << "," << temp->phoneNo << "," << temp->gender << "," << temp->lastLoginDate << endl;
        temp = temp->nextNode;
    }
    file.close();
}


#endif
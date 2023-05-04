#pragma once
#ifndef FILEHANDLER_H
#define FILEHANDLER_H


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void readUserData(User*& head);

//Function: To read user data from CSV and save it into singly linked list
void readUserData(User*& head) {

    const string fileName = "User.csv";

    ifstream userFile(fileName);

    //Case 1: File is not accessible
    if (!userFile) {
        cerr << "Error: File Cannot Be Opened!" << fileName << endl;
        return;
    }

    //Case 2: File is accessible
    //Read data line by line from user.csv and create User objects
    string line;
    while (getline(userFile, line)) {
        stringstream ss(line);
        string userId, username, password, name, email, phoneNumber, gender;

        if (getline(ss, userId, ',') &&
            getline(ss, username, ',') &&
            getline(ss, password, ',') &&
            getline(ss, name, ',') &&
            getline(ss, email, ',') &&
            getline(ss, phoneNumber, ',') &&
            getline(ss, gender)) {

            //Create new User object and add it to singly linked list
            User* newUser = new User{ userId, username, password, name, email, phoneNumber, gender };

            if (head == nullptr) {
                head = newUser;
            }

            else {
                User* current = head;

                while (current->next != nullptr) {
                    current = current->next;
                }

                current->next = newUser;
            }
        }
    }

    //Close the file
    userFile.close();
}








#endif

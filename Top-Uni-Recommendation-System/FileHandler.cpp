#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "User.h"
#include "FileHandler.h"

using namespace std;



//Function: To read user data from CSV and save it into singly linked list
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




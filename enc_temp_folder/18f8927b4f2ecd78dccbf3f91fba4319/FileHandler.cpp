#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "User.h"
#include "FileHandler.h"

using namespace std;



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
        istringstream iss(line);
        string userId, username, password, name, email, phoneNumber, gender;

        if (getline(iss, userId, ',') &&
            getline(iss, username, ',') &&
            getline(iss, password, ',') &&
            getline(iss, name, ',') &&
            getline(iss, email, ',') &&
            getline(iss, phoneNumber, ',') &&
            getline(iss, gender)) {

            //Create new User object and add it to singly linked list
            User* newUser = new User{ userId, username, password, name, email, phoneNumber, gender };

            if (!head) {
                head = newUser;
            }

            else {
                User* current = head;
                while (current->next) {
                    current = current->next;
                }

                current->next = newUser;
            }
        }
    }

    //Close the file
    userFile.close();
}




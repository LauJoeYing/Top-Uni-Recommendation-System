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
void insertUser(string userId, string username, string password, string realName, string email, string phoneNo, string gender);


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


#endif
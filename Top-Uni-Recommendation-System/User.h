#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>
#include <ctime>

#include "SavedFavourite.h"
#include "Admin.h"
#include "Guest.h"
#include "RegisteredCustomer.h"

using namespace std;

struct CurrentUser {    //Just to be safe CurrentUser use "extern"
    string userId;
    string username;
    string password;
    string name;
    string email;
    string phoneNumber;
    string gender;
    string lastLoginDate;
};

struct UserList {
    string userId;
    string username;
    string password;
    string name;
    string email;
    string phoneNumber;
    string gender;
    string lastLoginDate;
    UserList* nextNode;
};

class User {
private:
    UserList* userHead;
    UserList* userTemp; //This is supposed to be declared in method but I dont know

public:
    CurrentUser currentUser; //Define the currentUser like this User():currentUser{"U0001", "john".....}{} or ("U0001", "john".....){}   More convenient if this is public, but tak tahu if it will work.
    //CurrentUser getCurrentUser(); //Shouldnt need this unless CurrentUser is in Private
    UserList* getUserHead();
    //constructor
    User();
    ~User();

    //File IO
    void insertUser(string userId, string username, string password, string name, string email, string phoneNumber, string gender, string lastLoginDate);    
    void importUserFile();
    void writeUserFile();

    //LoginLogout
    void login();
    void logout();

    //LoginInformation of CurrentUser
    void saveCurrentLoginUser();       //In CPP, User::User(parameters){currentUser.userId = ...............}

    //PrintUserFile
};
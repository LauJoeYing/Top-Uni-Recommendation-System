#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>
#include <ctime>

//#include "User.h"
//#include "University.h"
#include "Feedback.h"
//#include "SavedFavourite.h"

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

//Only UI functions

class Admin {
private:

public:
	void login();
	void showAdminMenu(UserList* userHead);
	//void readUserData(UserList*& userHead);
	void modifyRegisteredCustomerDetail(UserList* userHead);
	void deleteRegisteredCustomerAccount(UserList* userHead, string deleteUser);
	//Other methods, such as inactive validation
	void checkInactiveUser(UserList* userHead);
	//Decide to use override function or declare printTable in University sahaja
};
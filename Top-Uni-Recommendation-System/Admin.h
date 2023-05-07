#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>
#include <ctime>

#include "User.h"
#include "University.h"
#include "Feedback.h"
#include "SavedFavourite.h"

using namespace std;

//Only UI functions

class Admin {
private:
	void modifyUsername();
	void modifyPassword();
	void modifyEmail();
	void modifyPhoneNumber();
	void modifyGender();

public:
	void showAdminMenu();
	void ModifyRegisteredCustomerDetail();
	void DeleteRegisteredCustomerAccount();
	//Other methods, such as inactive validation

	//Decide to use override function or declare printTable in University sahaja
};
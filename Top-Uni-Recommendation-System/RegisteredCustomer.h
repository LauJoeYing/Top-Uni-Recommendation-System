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

class RegisteredCustomer {
private:
	//??? MinOn please fill in the functions

public:
	void showRegisteredCustomerMenu();
	void logout(); //Override
	//??? MinOn please fill in the functions


	//Decide to use override function or declare printTable in University sahaja
};
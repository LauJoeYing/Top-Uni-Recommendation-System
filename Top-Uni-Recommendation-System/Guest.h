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

using namespace std::chrono;
using namespace std;

class Guest {
private:
	string regUsername();
	string regPassword();
	string regRealName();
	string regEmail();
	string regPhoneNo();
	string regGender();
	void showRegDetails();


public:
	void showGuestMenu(); //1. printtable() 2. Sort->Choose algorithm 3.Search->Choose Algorithm 4.Register 5. Exit Program
	void registerNewUser();
	string getCurrentDateString(); //Personally I suggest to declare this in Main.cpp or make this function universal - Jun Xian

	//Decide to use override function or declare printTable in University sahaja
};
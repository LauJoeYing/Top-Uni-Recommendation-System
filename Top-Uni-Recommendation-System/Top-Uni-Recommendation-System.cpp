// Top-Uni-Recommendation-System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <sstream>
#include <fstream>

#include <chrono>

//#include "mngFdbck.h"
#include "User.h"
#include "FileHandler.h"
#include "Admin.h"

using namespace std;


int main()
{

    User* userHead = nullptr;
    readUserData(userHead);
    User* current = login(userHead);
}






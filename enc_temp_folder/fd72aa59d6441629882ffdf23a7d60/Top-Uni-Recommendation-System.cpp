// Top-Uni-Recommendation-System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "User.h"
#include "FileHandler.h"

#include <iostream>
using namespace std;



int main()
{
	User *userHead;
	readUserData(userHead);
	cout << userHead->name << "\n";
}



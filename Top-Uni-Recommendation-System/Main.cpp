#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>
#include <ctime>

//#include "User.h"
#include "University.h"
#include "Feedback.h"
//#include "SavedFavourite.h"
//#include "HashTable.h"
#include "Admin.h"
//#include "Guest.h"
#include "RegisteredCustomer.h"

using namespace std;

void exitProgram() {

}


int main() {
	cout << "Start" << endl << endl;
	cout << "Running" << endl << endl;
	Admin admin;
	admin.login();
	cout << "Return" << endl << endl;
	return 0;
}
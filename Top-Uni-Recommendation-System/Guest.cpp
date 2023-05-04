

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;



struct user {
    string username;
    string password;
};

void login(const string& username, const string& password) {
    bool foundFlag = false;
    string userPassword;


    // Read user data from csv file
    ifstream user_file("user.csv");


   
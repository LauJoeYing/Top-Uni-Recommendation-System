// Top-Uni-Recommendation-System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <sstream>
#include <fstream>

#include <chrono>

//#include "mngFdbck.h"
#include "User.h"
#include "FileHandler.h"

using namespace std;


int main()
{

    User* userHead = nullptr;
    readUserData(userHead);
    User* current = login(userHead);
}

//int main()
//{   
//    int option;
//    importUni();
//    /*printTable();*/
//    cout << "Welcome";
  /* cout << "1.Sort by Location? 2. Sort by ArScore ? 3.Sort by FrcScore?";
    cin >> option;
    if (option == 1) {
        quickSort(getHeadRef(), compareLocation);
    }
    else if (option == 2) {
        quickSort(getHeadRef(), compareArScore);
    }
    else if (option == 3) {
        quickSort(getHeadRef(), compareFrcScore);
    }
    else {
        cout << "Invalid Option";
    }
    printTable();*/
//
//
//}

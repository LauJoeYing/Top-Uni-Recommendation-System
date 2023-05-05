#pragma once

#include <windows.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <limits>



using namespace std;

struct Feedback {
    string feedbackID;
    string userName;
    string adminName;
    string subject;
    string feedbackMessage;
    string replyMessage;
    string date;

    Feedback* nextNode;
    Feedback* prevNode;
}*fbHead, * fbTail;

Feedback* tmpArr = new Feedback[100];


struct CurrentUser {  //Global variable to store current user data
    string accType;
    string username;
    string password;
    string realName;
    string email;
    string phoneNo;
    string gender;
}currentUser;

void userViewFeedbackList();
void userCreateFeedback();
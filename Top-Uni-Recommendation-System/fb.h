#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>

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



void insertFb();
void importFeedbackFile();
void writeFeedbackFile();
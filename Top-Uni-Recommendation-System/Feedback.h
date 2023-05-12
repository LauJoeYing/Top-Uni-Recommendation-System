#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>
#include <ctime>

//#include "User.h"
//#include "SavedFavourite.h"

using namespace std;

struct FeedbackList {
    string feedbackID;
    string userName;
    string adminName;
    string subject;
    string feedbackMessage;
    string replyMessage;
    string date;

    FeedbackList* nextNode;
    FeedbackList* prevNode; //actually FeedbackList dont need to be doubly, but why not, do to show variety
};


class Feedback {
    private:
        FeedbackList* feedbackHead;
        FeedbackList* feedbackTail;
        int feedbackTableWidth[7];
        FeedbackList* currentUserFeedbackArr[50];
        void theThreeLines(); //Border + Headers
    
    public :
        //constructor
        //Feedback();
        //~Feedback();

        //File I/O
        void insertFeedback(string feedbackID, string userName, string adminName, string subject, string feedbackMessage, string replyMessage, string date); //Change to singly linked list insert
        void importFeedbackFile();
        void writeFeedbackFile();

        //Admin
        int adminReplyFeedback(FeedbackList* temp);
        void adminViewFeedbackList();

        //User
        void userCreateFeedback();
        void userViewFeedbackList();

        

};
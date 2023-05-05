#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>

#include "FeedbackFH.h"

using namespace std;

void insertFb(string feedbackID, string userName, string adminName, string subject, string feedbackMessage, string replyMessage, string date){
    Feedback*newNode = new Feedback{feedbackID, userName, adminName, subject, feedbackMessage, replyMessage, date};
    newNode->nextNode = NULL;
    newNode->prevNode = NULL;

    if(fbHead == NULL){
        fbHead = newNode;
        fbTail = newNode;
    }else{
        fbTail->nextNode = newNode;
        newNode->prevNode = fbTail;
        fbTail = newNode;
    }
}

void importFeedbackFile(){
    ifstream feedbackFile;
    feedbackFile.open("Feedback.csv");
    string line;
    string feedbackID, userName, adminName, subject, feedbackMessage, replyMessage, date;
    // getline(feedbackFile, line);
    while(getline(feedbackFile, line)){
        stringstream ss(line); 
        getline(ss, feedbackID, ',');
        getline(ss, userName, ',');
        getline(ss, adminName, ',');
        getline(ss, subject, ',');
        getline(ss, feedbackMessage, ',');
        getline(ss, replyMessage, ',');
        getline(ss, date, ',');
        insertFb(feedbackID, userName, adminName, subject, feedbackMessage, replyMessage, date);
    }
    feedbackFile.close();
}

//write linkedlist back to file
void writeFeedbackFile(){
    ofstream feedbackFile;
    feedbackFile.open("Feedback.csv");
    Feedback *temp = fbHead;
    while(temp != NULL){
        feedbackFile << temp->feedbackID << "," << temp->userName << "," << temp->adminName << "," << temp->subject << "," << temp->feedbackMessage << "," << temp->replyMessage << "," << temp->date << endl;
        temp = temp->nextNode;
    }
    feedbackFile.close();
}

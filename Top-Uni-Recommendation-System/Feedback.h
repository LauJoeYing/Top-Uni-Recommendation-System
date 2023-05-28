#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>
#include <ctime>


using namespace std;

int adminReplyFeedback(FeedbackList* temp);
void adminViewFeedbackList();
void userViewFeedbackList();
void userCreateFeedback();
void writeFeedbackFile();
extern void insertFeedbackAtHead(string feedbackID, string userName, string adminName, string subject, string feedbackMessage, string replyMessage, string  date);


int adminReplyFeedback(FeedbackList* temp) {
    int i = 0, j = 0, choice;
    cout << "Actions: " << endl;
    cout << "[ 1 ] Reply Feedback" << endl;
    cout << "[ 2 ] View Other Feedback" << endl;
    cout << "[ 3 ] Exit to Main Menu" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
    case 1:
        system("cls");

        cout << "\n+----------------------------------------------+" << endl;
        cout << "            Reply Feedback " << temp->feedbackId << endl;
        cout << "+----------------------------------------------+\n\n";

        cout << "Subject: " << temp->subject << endl;
        cout << "Message: " << temp->feedbackMessage << endl;
        cout << "+==============================================+" << endl;
        cout << "Reply Message: " << endl;
        cin >> temp->replyMessage;
        cout << "+==============================================+" << endl;
        break;
    case 2:
        return 1;
        break;
    case 3:
        return 0;
        break;
    }
    return 0;
}

void adminViewFeedbackList() {
    int i = 0, j = 0, flag_reply;
    FeedbackList* temp = feedbackHead;
    while (temp != NULL) {
        i++;
        cout << "[" << i << "]\t" << "|" << setw(20) << left << temp->feedbackId << "|" << setw(20) << left << temp->userName << "|" << setw(20) << left << temp->date << "|" << setw(20) << left << temp->subject << "|" << endl;
        temp = temp->nextNode;
    }

    cout << "\nWhich feedback would you like to view? (Enter No.)\t:\t";
    int choice;
    cin >> choice; //Need to Check is Integer
    if (choice < i + 1 && choice > 0) {
        FeedbackList* temp = feedbackHead;
        while (temp != NULL) {
            j++;
            if (j == choice) {  //Need to Check If Feedback is replied by another admin
                cout << setw(20) << left << "Feedback ID" << "|" << setw(30) << left << temp->feedbackId << endl;
                cout << setw(20) << left << "User ID" << "|" << setw(30) << left << temp->userName << endl;
                cout << setw(20) << left << "Admin ID" << "|" << setw(30) << left << temp->adminName << endl;
                cout << setw(20) << left << "Subject" << "|" << setw(30) << left << temp->subject << endl;
                cout << setw(20) << left << "Message" << "|" << setw(30) << left << temp->feedbackMessage << endl;
                cout << setw(20) << left << "replyMessage" << "|" << setw(30) << left << temp->replyMessage << endl;
                cout << setw(20) << left << "Date" << "|" << setw(30) << left << temp->date << endl;
                flag_reply = adminReplyFeedback(temp);
                if (flag_reply == 1) {
                    return adminViewFeedbackList();
                }
                else if (flag_reply == 0) {
                    return; //Call MainMenu Function
                }
                return;
            }
            temp = temp->nextNode;
        }
    }
}

void userViewFeedbackList() {
    int i = 1;
    FeedbackList* temp = feedbackHead;
    FeedbackList* tmpArr = new FeedbackList[100];
    while (temp != NULL) {
        if (temp->userName == currentUser.username) {
            cout << "|" << setw(3) << left << i << "|" << setw(10) << left << temp->feedbackId << "|" << setw(10) << left << temp->date << "|" << setw(30) << left << temp->subject << endl;
            tmpArr[i - 1] = *temp;
            temp = temp->nextNode;
            i++;
        }
        else {
            temp = temp->nextNode;
        }
    }
    cout << "\nWhich feedback would you like to view? (Enter No.):";
    int choice;
    cin >> choice;
    if (choice < i + 1 && choice > 0) {
        cout << "Feedback ID: " << tmpArr[choice - 1].feedbackId << endl;
        cout << "Username: " << tmpArr[choice - 1].userName << endl;
        cout << "Admin ID: " << tmpArr[choice - 1].adminName << endl;
        cout << "Subject: " << tmpArr[choice - 1].subject << endl;
        cout << "Message: " << tmpArr[choice - 1].feedbackMessage << endl;
        cout << "replyMessage: " << tmpArr[choice - 1].replyMessage << endl;
        cout << "Date: " << tmpArr[choice - 1].date << endl;
    }
}


void userCreateFeedback() {
    FeedbackList* temp = feedbackHead;
    int i = 0;
    string feedbackID_head = "f0000";
    string feedbackId, userName, adminName, subject, feedbackMessage, replyMessage, date;
    cout << "Enter Subject: ";
    getline(cin, subject);
    cout << "Enter Message: ";
    getline(cin, feedbackMessage);
    while (temp != NULL) {
        i++;
        temp = temp->nextNode;
    }
    if (i < 10000) {
        if (i < 1000) {
            if (i < 100) {
                if (i < 10) {
                    feedbackId = feedbackID_head + "000" + to_string(i);
                }
                else {
                    feedbackId = feedbackID_head + "00" + to_string(i);
                }
            }
            else {
                feedbackId = feedbackID_head + "0" + to_string(i);
            }
        }
        else {
            feedbackId = feedbackID_head + to_string(i);
        }
    }//Either while loop to get end of linkedlist, or slice string then stoi from tail 
    else {
        cout << "Error: Feedback ID Overflow" << endl;
        return;
    }
    userName = currentUser.username;
    adminName = "NULL";
    replyMessage = "NULL";
    insertFeedbackAtHead(feedbackId, userName, adminName, subject, feedbackMessage, replyMessage, date);
    return;
}

void writeFeedbackFile() {
    ofstream feedbackFile;
    feedbackFile.open("Feedback.csv");
    FeedbackList* temp = feedbackHead;
    while (temp != NULL) {
        feedbackFile << temp->feedbackId << "," << temp->userName << "," << temp->adminName << "," << temp->subject << "," << temp->feedbackMessage << "," << temp->replyMessage << "," << temp->date << endl;
        temp = temp->nextNode;
    }
    feedbackFile.close();
}
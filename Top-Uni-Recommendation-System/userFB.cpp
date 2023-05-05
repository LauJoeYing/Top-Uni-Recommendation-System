#include "userFB.h"
#include "FeedbackFH.h"

using namespace std;

void userViewFeedbackList() {
    int i = 1;
    Feedback* temp = fbHead;
    while (temp != NULL) {
        if (temp->userName == currentUser.username) {
            cout << "|" << setw(3) << left << i << "|" << setw(10) << left << temp->feedbackID << "|" << setw(10) << left << temp->date << "|" << setw(30) << left << temp->subject;
            temp = temp->nextNode;
            tmpArr[i - 1] = *temp;
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
        cout << "Feedback ID: " << tmpArr[choice - 1].feedbackID << endl;
        cout << "User ID: " << tmpArr[choice - 1].userName << endl;
        cout << "Admin ID: " << tmpArr[choice - 1].adminName << endl;
        cout << "Subject: " << tmpArr[choice - 1].subject << endl;
        cout << "Message: " << tmpArr[choice - 1].feedbackMessage << endl;
        cout << "replyMessage: " << tmpArr[choice - 1].replyMessage << endl;
        cout << "Date: " << tmpArr[choice - 1].date << endl;
    }
}

void userCreateFeedback() {
    Feedback* temp = fbHead;
    int i = 0;
    string feedbackID_head = "f0000";
    string feedbackID, userName, adminName, subject, feedbackMessage, replyMessage, date;
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
                    feedbackID = feedbackID_head + "000" + to_string(i);
                }
                else {
                    feedbackID = feedbackID_head + "00" + to_string(i);
                }
            }
            else {
                feedbackID = feedbackID_head + "0" + to_string(i);
            }
        }
        else {
            feedbackID = feedbackID_head + to_string(i);
        }
    }//Either while loop to get end of linkedlist, or slice string then stoi from tail 
    else {
        cout << "Error: Feedback ID Overflow" << endl;
        return;
    }
    userName = currentUser.username;
    adminName = "NULL";
    replyMessage = "NULL";
    insertFb(feedbackID, userName, adminName, subject, feedbackMessage, replyMessage, date);
    return;
}
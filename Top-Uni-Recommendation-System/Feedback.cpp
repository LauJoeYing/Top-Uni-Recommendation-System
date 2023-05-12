#include "Feedback.h"


void Feedback::insertFeedback(string feedbackID, string userName, string adminName, string subject, string feedbackMessage, string replyMessage, string date) {
    FeedbackList* newNode = new FeedbackList;
    newNode->feedbackID = feedbackID;
    newNode->userName = userName;
    newNode->adminName = adminName;
    newNode->subject = subject;
    newNode->feedbackMessage = feedbackMessage;
    newNode->replyMessage = replyMessage;
    newNode->date = date;
    newNode->nextNode = NULL;
    newNode->prevNode = NULL;

    if (feedbackHead == NULL) {
        feedbackHead = newNode;
        feedbackTail = newNode;
    }
    else {
        feedbackTail->nextNode = newNode;
        newNode->prevNode = feedbackTail;
        feedbackTail = newNode;
    }
}

void Feedback::importFeedbackFile() {

    const string fileName = "Feedback.csv";

    ifstream feedbackFile;
    feedbackFile.open(fileName);

    if (!feedbackFile) {
        cerr << "Error: File Cannot Be Opened! " << fileName << endl;
        return;
    }
    string line;
    string feedbackID, userName, adminName, subject, feedbackMessage, replyMessage, date;
    // getline(feedbackFile, line);
    while (getline(feedbackFile, feedbackID, ',')) {
        getline(feedbackFile, userName, ',');
        getline(feedbackFile, adminName, ',');
        getline(feedbackFile, subject, ',');
        getline(feedbackFile, feedbackMessage, ',');
        getline(feedbackFile, replyMessage, ',');
        getline(feedbackFile, date);
        insertFeedback(feedbackID, userName, adminName, subject, feedbackMessage, replyMessage, date);
    }
    feedbackFile.close();
}


int Feedback::adminReplyFeedback(FeedbackList* temp) {
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
        cout << "            Reply Feedback " << temp->feedbackID << endl;
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

}

void Feedback::adminViewFeedbackList() {
    cout << "I have reached view feedback"<<endl;
    int i = 0, j = 0, flag_reply;
    FeedbackList* temp = feedbackHead;
    while (temp != NULL) {
        i++;
        cout << "[" << i << "]\t" << "|" << setw(20) << left << temp->feedbackID << "|" << setw(20) << left << temp->userName << "|" << setw(20) << left << temp->date << "|" << setw(20) << left << temp->subject << "|" << endl;
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
                cout << setw(20) << left << "Feedback ID" << "|" << setw(30) << left << temp->feedbackID << endl;
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
};

void Feedback::userViewFeedbackList() {
    /*int i = 1;
    FeedbackList* temp = feedbackHead;
    FeedbackList* tmpArr = new FeedbackList[100];
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
    }*/
}


void Feedback::userCreateFeedback() {
    //FeedbackList* temp = feedbackHead;
    //int i = 0;
    //string feedbackID_head = "f0000";
    //string feedbackID, userName, adminName, subject, feedbackMessage, replyMessage, date;
    //cout << "Enter Subject: ";
    //getline(cin, subject);
    //cout << "Enter Message: ";
    //getline(cin, feedbackMessage);
    //while (temp != NULL) {
    //    i++;
    //    temp = temp->nextNode;
    //}
    //if (i < 10000) {
    //    if (i < 1000) {
    //        if (i < 100) {
    //            if (i < 10) {
    //                feedbackID = feedbackID_head + "000" + to_string(i);
    //            }
    //            else {
    //                feedbackID = feedbackID_head + "00" + to_string(i);
    //            }
    //        }
    //        else {
    //            feedbackID = feedbackID_head + "0" + to_string(i);
    //        }
    //    }
    //    else {
    //        feedbackID = feedbackID_head + to_string(i);
    //    }
    //}//Either while loop to get end of linkedlist, or slice string then stoi from tail 
    //else {
    //    cout << "Error: Feedback ID Overflow" << endl;
    //    return;
    //}
    //userName = currentUser.username;
    //adminName = "NULL";
    //replyMessage = "NULL";
    //insertFeedback(feedbackID, userName, adminName, subject, feedbackMessage, replyMessage, date);
    //return;
}

void Feedback::writeFeedbackFile() {
    ofstream feedbackFile;
    feedbackFile.open("Feedback.csv");
    FeedbackList* temp = feedbackHead;
    while (temp != NULL) {
        feedbackFile << temp->feedbackID << "," << temp->userName << "," << temp->adminName << "," << temp->subject << "," << temp->feedbackMessage << "," << temp->replyMessage << "," << temp->date << endl;
        temp = temp->nextNode;
    }
    feedbackFile.close();
}

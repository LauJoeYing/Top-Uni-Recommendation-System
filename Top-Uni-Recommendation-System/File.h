#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>
#include <ctime>

using namespace std;

//declaration

void insertUniversity(int Rank, std::string Institution, std::string LocationCode, std::string Location, double ArScore, int ArRank, double ErScore, int ErRank, double FsrScore, int FsrRank, double CpfScore, int CpfRank, double IfrScore, int IfrRank, double IsrScore, int IsrRank, double IrnScore, int IrnRank, double GerScore, int GerRank, double ScoreScaled, std::string Region, int TotalPick);
void importUniversity();
void insertFeedbackAtTail(string feedbackID, string userName, string adminName, string subject, string feedbackMessage, string replyMessage, string  date);
void insertFeedbackAtHead(string feedbackID, string userName, string adminName, string subject, string feedbackMessage, string replyMessage, string  date);
void importFeedback();
void insertFavourited(string userId, int userFavRankArr[5], int counter);
void importFavourited();
void insertUser();
void importUser();

struct FeedbackList {
    string feedbackId;
    string userName;
    string adminName;
    string subject;
    string feedbackMessage;
    string replyMessage;
    string date;

    FeedbackList* nextNode;
    FeedbackList* prevNode;
}*feedbackHead, * feedbackTail;

struct Favourited {
    string userId;
    int userFavRankArr[5];  //Assume maximum of 5 favourite Uni each user, or else I will die
    int counter;

    Favourited* nextNode;
}*favouritedHead;

struct UniList {
    int Rank;
    string Institution;
    string LocationCode;
    string Location;
    double ArScore;
    int ArRank;
    double ErScore;
    int ErRank;
    double FsrScore;
    int FsrRank;
    double CpfScore;
    int CpfRank;
    double IfrScore;
    int IfrRank;
    double IsrScore;
    int IsrRank;
    double IrnScore;
    int IrnRank;
    double GerScore;
    int GerRank;
    double ScoreScaled;
    string Region;
    int TotalPick;
    UniList* nextNode;
    UniList* prevNode;
}*universityHead, * universityTail;

struct CurrentUser {    //Just to be safe CurrentUser use "extern"
    string userId;
    string username;
    string password;
    string name;
    string email;
    string phoneNumber;
    string gender;
    string lastLoginDate;
}currentUser;

struct UserList {
    string userId;
    string username;
    string password;
    string name;
    string email;
    string phoneNumber;
    string gender;
    string lastLoginDate;
    UserList* nextNode;
}*userHead;

//Initialization

void importUniversity() {
    ifstream uniFile;
    uniFile.open("University.csv");
    if (!uniFile) {
        cerr << "Error: File Cannot Be Opened! " << endl;
        return;
    }
    string line;
    getline(uniFile, line);
    while (getline(uniFile, line)) {
        stringstream ss(line);
        string Rank, Institution, LocationCode, Location, Region, ArScore, ArRank, ErScore, ErRank, FsrScore, FsrRank, CpfScore, CpfRank, IfrScore, IfrRank, IsrScore, IsrRank, IrnScore, IrnRank, GerScore, GerRank, ScoreScaled, TotalPick;
        getline(ss, Rank, ',');
        getline(ss, Institution, ',');
        getline(ss, LocationCode, ',');
        getline(ss, Location, ',');
        getline(ss, ArScore, ',');
        getline(ss, ArRank, ',');
        getline(ss, ErScore, ',');
        getline(ss, ErRank, ',');
        getline(ss, FsrScore, ',');
        getline(ss, FsrRank, ',');
        getline(ss, CpfScore, ',');
        getline(ss, CpfRank, ',');
        getline(ss, IfrScore, ',');
        getline(ss, IfrRank, ',');
        getline(ss, IsrScore, ',');
        getline(ss, IsrRank, ',');
        getline(ss, IrnScore, ',');
        getline(ss, IrnRank, ',');
        getline(ss, GerScore, ',');
        getline(ss, GerRank, ',');
        getline(ss, ScoreScaled, ',');
        getline(ss, Region, ',');
        getline(ss, TotalPick, ',');
        insertUniversity(std::stoi(Rank), Institution, LocationCode, Location, std::stod(ArScore), std::stoi(ArRank), std::stod(ErScore), std::stoi(ErRank), std::stod(FsrScore), std::stoi(FsrRank), std::stod(CpfScore), std::stoi(CpfRank), std::stod(IfrScore), std::stoi(IfrRank), std::stod(IsrScore), std::stoi(IsrRank), std::stod(IrnScore), std::stoi(IrnRank), std::stod(GerScore), std::stoi(GerRank), std::stod(ScoreScaled), Region, std::stoi(TotalPick));
    }
    uniFile.close();

}

void importUser() {
    const string fileName = "User.csv";
    UserList* current = nullptr;

    ifstream file(fileName);
    //Case 1: File is not accessible
    if (!file) {
        cerr << "Error: File Cannot Be Opened! " << fileName << endl;
        return;
    }
    
    //Case 2: File is accessible
    //Read data line by line from user.csv and create User objects
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string userId, username, password, name, email, phoneNumber, gender, lastLoginDate;
    
        if (getline(ss, userId, ',') &&
            getline(ss, username, ',') &&
            getline(ss, password, ',') &&
            getline(ss, name, ',') &&
            getline(ss, email, ',') &&
            getline(ss, phoneNumber, ',') &&
            getline(ss, gender, ',') &&
            getline(ss, lastLoginDate)) {
    
            //Create new User object and add it to singly linked list
            UserList* newUser = new UserList{ userId, username, password, name, email, phoneNumber, gender, lastLoginDate, nullptr };
    
            if (userHead == nullptr) {
                userHead = newUser;
            }
    
            else {
                current = userHead;
                while (current->nextNode != nullptr) {
                    current = current->nextNode;
                }
    
                current->nextNode = newUser;
            }
        }
    }
    file.close();
}

void importFeedback() {
    const string fileName = "Feedback.csv";
    FeedbackList* current = nullptr;
    ifstream file(fileName);
    //Case 1: File is not accessible
    if (!file) {
        cerr << "Error: File Cannot Be Opened! " << fileName << endl;
        return;
    }

    //Case 2: File is accessible
    //Read data line by line
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string feedbackId, userName, adminName, subject, feedbackMessage, replyMessage, date;

        getline(ss, feedbackId, ',');
        getline(ss, userName, ',');
        getline(ss, adminName, ',');
        getline(ss, subject, ',');
        getline(ss, feedbackMessage, ',');
        getline(ss, replyMessage, ',');
        getline(ss, date);
        
        FeedbackList* newFeedback = new FeedbackList{ feedbackId, userName, adminName, subject, feedbackMessage, replyMessage, date, nullptr};
        //newFeedback->nextNode = nullptr;

        if (feedbackHead == nullptr) {
            feedbackHead = newFeedback;
        }

        else {
            current = feedbackHead;
            while (current->nextNode != nullptr) {
                current = current->nextNode;
            }

            current->nextNode = newFeedback;
        }
    }
    
    file.close();
}

void importFavourited() {
    const string fileName = "Favourited.csv";
    string userId, userFavRank, counter, token;
    int userFavRankArr[10], i;
    ifstream file;
    file.open(fileName);
    if (!file.is_open()) {
        cout << "File not found" << endl;
    }
    else {
        std::string line;
        while (getline(file, line)) {
            stringstream ss(line);
            getline(ss, userId, ',');
            getline(ss, userFavRank, ',');
            getline(ss, counter, ',');
            stringstream sss(userFavRank);
            i = 0;
            while (getline(sss, token, '-')) {
                userFavRankArr[i] = std::stoi(token);
                i++;
            }
            Favourited* newFavourited = new Favourited{ userId, userFavRankArr[5], std::stoi(counter) };

        if (favouritedHead == nullptr) {
            favouritedHead = newFavourited;
        }

        else {
            Favourited* current = favouritedHead;
            while (current->nextNode != nullptr) {
                current = current->nextNode;
            }

            current->nextNode = newFavourited;
        }
        }
    }
    file.close();
}

void insertUniversity(int Rank, std::string Institution, std::string LocationCode, std::string Location, double ArScore, int ArRank, double ErScore, int ErRank, double FsrScore, int FsrRank, double CpfScore, int CpfRank, double IfrScore, int IfrRank, double IsrScore, int IsrRank, double IrnScore, int IrnRank, double GerScore, int GerRank, double ScoreScaled, std::string Region, int TotalPick) {
    UniList* newNode = new UniList{ Rank, Institution, LocationCode, Location, ArScore, ArRank, ErScore, ErRank, FsrScore, FsrRank, CpfScore, CpfRank, IfrScore, IfrRank, IsrScore, IsrRank, IrnScore, IrnRank, GerScore, GerRank, ScoreScaled, Region, TotalPick,nullptr,nullptr};
    if (universityHead == NULL) {
        universityHead = newNode;
        universityTail = newNode;
    }
    else {
        universityTail->nextNode = newNode;
        newNode->prevNode = universityTail;
        universityTail = newNode;
    }
}

void insertFeedbackAtHead(string feedbackId, string userName, string adminName, string subject, string feedbackMessage, string replyMessage, string  date) {
    FeedbackList* newNode = new FeedbackList;
    newNode->feedbackId = feedbackId;
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

void insertUserAtTail(string userId,string username, string password, string name, string email, string phoneNumber, string gender, string lastLoginDate) {
    UserList* newUser = new UserList;
    UserList* current = userHead;
    
    newUser->userId = userId;
    newUser->username = username;
    newUser->password = password;
    newUser->name = name;
    newUser->email = email;
    newUser->phoneNumber = phoneNumber;
    newUser->gender = gender;
    newUser->lastLoginDate = lastLoginDate;
    newUser->nextNode = nullptr;

    while (current->nextNode != NULL) {
        current = current->nextNode;
    }
    current->nextNode = newUser;
    cout << "|" << setw(7) << left << newUser->userId << "|" << setw(25) << left << newUser->username << "|" << setw(25) << left << newUser->password << "|" << setw(25) << left << newUser->name << "|" << setw(35) << left << newUser->email << "|" << setw(12) << left << newUser->phoneNumber << "|" << setw(7) << left << newUser->gender << "|" << setw(12) << left << newUser->lastLoginDate << "|" << endl;
}
//
//void insertFavourited(string userId, int userFavRankArr[10], int counter) {
//
//}

void fileRelay() {
    importUser();
    importFavourited();
    importFeedback();
    importUniversity();
}
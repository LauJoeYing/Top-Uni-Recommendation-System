#include "SavedFavourite.h"

SavedFavourite::SavedFavourite() {
    favouriteHead = NULL;
    arrLength = 0;
}


SavedFavourite::~SavedFavourite() {
    Favourite* temp = favouriteHead;
    while (temp != NULL) {
        favouriteHead = favouriteHead->nextNode;
        delete temp;
        temp = favouriteHead;
    }
}

//File IO import from csv
void SavedFavourite::importFavourite() {
    ifstream file;
    file.open("QSS.csv");
    if (!file.is_open()) {
        cout << "File not found" << endl;
    }
    else {
        std::string line;
        while (getline(file, line)) {
            stringstream ss(line);
            std::string userId;
            std::string userFavRankArr;
            std::string counter;
            getline(ss, userId, ',');
            getline(ss, userFavRankArr, ',');
            getline(ss, counter, ',');
            insertFavourite(userId, userFavRankArr, counter);
        }
    }
    file.close();
}

void SavedFavourite::insertFavourite(std::string userId, std::string userFavRankArr, std::string counter) {
    Favourite* newNode = new Favourite;
    newNode->userId = userId;
    newNode->counter = stoi(counter);
    stringstream ss(userFavRankArr);
    string token;
    int i = 0;
    while (getline(ss, token, '|')) {
        newNode->userFavRankArr[i] = stoi(token);
        i++;
    }
    newNode->nextNode = NULL;
    if (favouriteHead == NULL) {
        favouriteHead = newNode;
    }
    else {
        Favourite* temp = favouriteHead;
        while (temp->nextNode != NULL) {
            temp = temp->nextNode;
        }
        temp->nextNode = newNode;
    }
}


void SavedFavourite::writeFavourite() {
    ofstream file;
    file.open("QSS.csv");
    if (!file.is_open()) {
        cout << "File not found" << endl;
    }
    else {
        Favourite* temp = favouriteHead;
        while (temp != NULL) {
            if (temp->userId != currentUser.userId) {
                file << temp->userId << "," << temp->userFavRankArr[0] << "|" << temp->userFavRankArr[1] << "|" << temp->userFavRankArr[2] << "," << temp->counter << endl;
                temp = temp->nextNode;
            }
            else {
                temp->counter = arrLength;
                file << temp->userId << "," << temp->userFavRankArr[0] << "|" << temp->userFavRankArr[1] << "|" << temp->userFavRankArr[2] << "," << temp->counter << endl;
            }
        }
    }
    file.close();
}

void SavedFavourite::isFavourited(int rankNumber) {
    Favourite* temp = favouriteHead;
    while (temp != NULL) {
        if (temp->userId == currentUser.userId) {
            for (int i = 0; i < 3; i++) {
                if (temp->userFavRankArr[i] == rankNumber) {
                    cout << "You have already favourited this university!" << endl;
                    return;
                }
                else if (temp->userFavRankArr[i] == 0) {
                    temp->userFavRankArr[i] = rankNumber;
                    cout << "University has been favourited!" << endl;
                    return;
                }
            }
        }
    }
}
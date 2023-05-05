#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>

#include "Fav.h"

using namespace std;


void insertFav(string Institution, string userId) {
    Favourite* newNode = new Favourite{ Institution, userId };
    newNode->nextNode = NULL;

    if (favHead == NULL) {
        favHead = newNode;
    }
    else {
        Favourite* temp = favHead;
        while (temp->nextNode != NULL) {
            temp = temp->nextNode;
        }
        temp->nextNode = newNode;
    }
}

void importFavouriteFile() {
    ifstream file;
    file.open("Favourite.csv");
    if (!file) {
        cout << "Error opening file" << endl;
    }
    else {
        string line;
        string Institution, userId;
        getline(file, line);
        while (getline(file, line)) {
            stringstream ss(line);
            getline(ss, Institution, ',');
            getline(ss, userId, ',');
            insertFav(Institution, userId);
        }
    }
}
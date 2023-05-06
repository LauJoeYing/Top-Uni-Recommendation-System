#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>

#include "Univercity.h"

using namespace std;

void insertUni(int rank, string institution, string locationCode, string location, double arScore, int arRank, double erScore, int erRank, double fsrScore, int fsrRank, double cpfScore, int cpfRank, double ifrScore, int ifrRank, double isrScore, int isrRank, double irnScore, int irnRank, double gerScore, int gerRank, double scoreScaled, string region, int totalPick) {
    Uni* newNode = new Uni{ rank, institution, locationCode, location, arScore, arRank, erScore, erRank, fsrScore, fsrRank, cpfScore, cpfRank, ifrScore, ifrRank, isrScore, isrRank, irnScore, irnRank, gerScore, gerRank, scoreScaled, region, totalPick,nullptr,nullptr };
    
    if (uniHead == NULL) {
        uniHead = newNode;
        uniTail = newNode;
    }
    else {
        uniTail->nextNode = newNode;
        newNode->prevNode = uniTail;
        uniTail = newNode;
    }
}

void importUniFile() {
    ifstream uniFile;
    uniFile.open("University.csv");
    string line;
    getline(uniFile, line);
    while (getline(uniFile, line)) {
        stringstream ss(line);
        string rank, institution, locationCode, location, region, arScore, arRank, erScore, erRank, fsrScore, fsrRank, cpfScore, cpfRank, ifrScore, ifrRank, isrScore, isrRank, irnScore, irnRank, gerScore, gerRank, scoreScaled, totalPick;
        getline(ss, rank, ',');
        getline(ss, institution, ',');
        getline(ss, locationCode, ',');
        getline(ss, location, ',');
        getline(ss, arScore, ',');
        getline(ss, arRank, ',');
        getline(ss, erScore, ',');
        getline(ss, erRank, ',');
        getline(ss, fsrScore, ',');
        getline(ss, fsrRank, ',');
        getline(ss, cpfScore, ',');
        getline(ss, cpfRank, ',');
        getline(ss, ifrScore, ',');
        getline(ss, ifrRank, ',');
        getline(ss, isrScore, ',');
        getline(ss, isrRank, ',');
        getline(ss, irnScore, ',');
        getline(ss, irnRank, ',');
        getline(ss, gerScore, ',');
        getline(ss, gerRank, ',');
        getline(ss, scoreScaled, ',');
        getline(ss, region, ',');
        getline(ss, totalPick, ',');
        insertUni(stoi(rank), institution, locationCode, location, stod(arScore), stoi(arRank), stod(arScore), stoi(erRank), stod(fsrScore), stoi(fsrRank), stod(cpfScore), stoi(cpfRank), stod(ifrScore), stoi(ifrRank), stod(isrScore), stoi(isrRank), stod(irnScore), stoi(irnRank), stod(gerScore), stoi(gerRank), stod(scoreScaled), region, stoi(totalPick));
    }
    uniFile.close();
}

Uni* binarySearchUni(string uniName) {

    Uni* start = uniHead;
    Uni* end = uniTail;
    while (start != nullptr && end != nullptr && start != end && end->nextNode != start) {
        Uni* mid = start;
        int count = 0;
        while (mid != nullptr && mid != end && mid != start && end->nextNode != start && count < 100) {
            mid = mid->nextNode;
            count++;
        }
        if (mid == nullptr || mid == end || mid == start || count >= 100) {
            break;
        }
        if (mid->Institution == uniName) {
            return mid;
        }
        else if (mid->Institution > uniName) {
            end = mid->prevNode;
        }
        else {
            start = mid->nextNode;
        }
    }
    if (start != nullptr && start->Institution == uniName) {
        return start;
    }
    else if (end != nullptr && end->Institution == uniName) {
        return end;
    }
    else {
        return nullptr;
    }
}






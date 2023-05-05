#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>

#include "UniFH.h"

using namespace std;

void insertUni(int Rank, string Institution, string LocationCode, string Location, double ArScore, int ArRank, double ErScore, int ErRank, double FsrScore, int FsrRank, double CpfScore, int CpfRank, double IfrScore, int IfrRank, double IsrScore, int IsrRank, double IrnScore, int IrnRank, double GerScore, int GerRank, double ScoreScaled, string Region, int TotalPick) {
    Uni* newNode = new Uni{ Rank, Institution, LocationCode, Location, ArScore, ArRank, ErScore, ErRank, FsrScore, FsrRank, CpfScore, CpfRank, IfrScore, IfrRank, IsrScore, IsrRank, IrnScore, IrnRank, GerScore, GerRank, ScoreScaled, Region, TotalPick,nullptr,nullptr };
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


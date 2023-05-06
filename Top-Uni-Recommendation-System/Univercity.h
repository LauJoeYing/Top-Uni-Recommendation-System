#ifndef UNIFH_H
#define UNIFH_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>

using namespace std;

struct Uni;

void importUniFile();
void insertUni(int rank, string institution, string locationCode, string location, double arScore, int arRank, double erScore, int erRank, double fsrScore, int fsrRank, double cpfScore, int cpfRank, double ifrScore, int ifrRank, double isrScore, int isrRank, double irnScore, int irnRank, double gerScore, int gerRank, double scoreScaled, string region, int totalPick);


struct Uni {
    int rank;
    string institution;
    string locationCode;
    string location;
    double arScore;
    int arRank;
    double erScore;
    int erRank;
    double fsrScore;
    int fsrRank;
    double cpfScore;
    int cpfRank;
    double ifrScore;
    int ifrRank;
    double isrScore;
    int isrRank;
    double irnScore;
    int irnRank;
    double gerScore;
    int gerRank;
    double scoreScaled;
    string region;
    int totalPick;

    Uni* nextNode;
    Uni* prevNode;

}*uniHead, *uniTail;

#endif
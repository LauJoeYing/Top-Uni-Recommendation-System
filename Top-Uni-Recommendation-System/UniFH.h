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
void insertUni(int Rank, string Institution, string LocationCode, string Location, double ArScore, int ArRank, double ErScore, int ErRank, double FsrScore, int FsrRank, double CpfScore, int CpfRank, double IfrScore, int IfrRank, double IsrScore, int IsrRank, double IrnScore, int IrnRank, double GerScore, int GerRank, double ScoreScaled, string Region, int TotalPick);


struct Uni {
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

    Uni* nextNode;
    Uni* prevNode;

}*uniHead, *uniTail;

#endif
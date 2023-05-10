#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>

//#include "HashTable.h"
//#include "SavedFavourite.h"

using namespace std;


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
};

// Add these declarations to University.h (or another header file)
bool compareArScore(UniList* a, UniList* b);
bool compareFsrScore(UniList* a, UniList* b);
bool compareErScore(UniList* a, UniList* b);
bool compareName(UniList* a, UniList* b);
bool compareTotalPicks(UniList* a, UniList* b);
void sortForRegisterCustomerPanel();


class University {
private:
    UniList* uniTail;
    UniList* uniHead;
    int widthArray[23] = { 4,90,12,30,7,6,7,6,8,7,8,7,8,7,8,7,8,7,8,7,11,13,10 };
    int cnt = 0;
    string chgPage = "Type '<' to go to prev page, '>' to go to next page, or 'q' to quit: ";

public:
    //File I/O
    void insertUni(int Rank, string Institution, string LocationCode, string Location, double ArScore, int ArRank, double ErScore, int ErRank, double FsrScore, int FsrRank, double CpfScore, int CpfRank, double IfrScore, int IfrRank, double IsrScore, int 	IsrRank, double IrnScore, int IrnRank, double GerScore, int GerRank, double ScoreScaled, string Region, int TotalPick);
    void importUni();

    //Print Table
    void printTopBorder();
    void printHeader();
    void theTopLines(); //topborder + cout << header + top 
    void printTable();
    void printTopPickUniTable();


    UniList* getUniTail(UniList* uniCur);
    UniList** getHeadRef();
    UniList* partition(UniList* uniHead, UniList* end, UniList** newHead, UniList** newEnd, bool (*compare)(UniList*, UniList*));
    UniList* quickSortRecur(UniList* uniHead, UniList* end, bool (*compare)(UniList*, UniList*));
    void quickSort(UniList** headRef, bool (*compare)(UniList*, UniList*));



};





    //Top10 Fav
    /*
    Sort with TotalPick Descending
    Print 10 lines
    Gao dim

    */


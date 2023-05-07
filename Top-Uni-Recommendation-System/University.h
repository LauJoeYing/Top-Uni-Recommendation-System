#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>

#include "HashTable.h"
#include "SavedFavourite.h"

using namespace std;

struct UniList{
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
};


class University {
private:
    UniList* uniHead;
    int widthArray[23] = { 4,90,12,30,7,6,7,6,8,7,8,7,8,7,8,7,8,7,8,7,11,13,10 };

public:
    //File I/O
    void insertUni(int Rank, string Institution, string LocationCode, string Location, double ArScore, int ArRank, double ErScore, int ErRank, double FsrScore, int FsrRank, double CpfScore, int CpfRank, double IfrScore, int IfrRank, double IsrScore, int 	IsrRank, double IrnScore, int IrnRank, double GerScore, int GerRank, double ScoreScaled, string Region, int TotalPick);
    void importUni();

    //Print Table
    void printTopBorder();
    void theTopLines(); //topborder + cout << header + top 
    void printTable();

    //Sorting
    UniList* merge(UniList* left, UniList* right, bool (*compare)(UniList*, UniList*));
    UniList* split(UniList* uniHead);
    UniList* timsort(UniList* uniHead, bool (*compare)(UniList*, UniList*));
    bool compareArScore(UniList* a, UniList* b);
    bool compareFsrScore(UniList* a, UniList* b);
    bool compareErScore(UniList* a, UniList* b);
    UniList* getUniTail(UniList* uniCur);
    UniList** getHeadRef();
    UniList* partition(UniList* uniHead, UniList* end, UniList** newHead, UniList** newEnd, bool (*compare)(UniList*, UniList*));
    UniList* quickSortRecur(UniList* uniHead, UniList* end, bool (*compare)(UniList*, UniList*));
    UniList* quickSort(UniList** uniHeadRef, bool (*compare)(UniList*, UniList*));
    void timsort();
    void quicksort();


    //Top10 Fav
    /*
    Sort with TotalPick Descending
    Print 10 lines
    Gao dim

    */

};

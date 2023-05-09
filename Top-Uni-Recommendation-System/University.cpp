#include "University.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>

//#include "UniFH.h"

using namespace std;


void University::insertUni(int Rank, std::string Institution, std::string LocationCode, std::string Location, double ArScore, int ArRank, double ErScore, int ErRank, double FsrScore, int FsrRank, double CpfScore, int CpfRank, double IfrScore, int IfrRank, double IsrScore, int IsrRank, double IrnScore, int IrnRank, double GerScore, int GerRank, double ScoreScaled, std::string Region, int TotalPick) {
    UniList* newNode = new UniList{ Rank, Institution, LocationCode, Location, ArScore, ArRank, ErScore, ErRank, FsrScore, FsrRank, CpfScore, CpfRank, IfrScore, IfrRank, IsrScore, IsrRank, IrnScore, IrnRank, GerScore, GerRank, ScoreScaled, Region, TotalPick,nullptr,nullptr };
    if (this->uniHead == NULL) {
        this->uniHead = newNode;
        this->uniTail = newNode;
    }
    else {
        this->uniTail->nextNode = newNode;
        newNode->prevNode = this->uniTail;
        this->uniTail = newNode;
    }
}

void University::importUni() {
    std::ifstream uniFile;
    uniFile.open("UniversityDataset.csv");
    std::string line;
    getline(uniFile, line);
    while (getline(uniFile, line)) {
        std::stringstream ss(line);
        std::string Rank, Institution, LocationCode, Location, Region, ArScore, ArRank, ErScore, ErRank, FsrScore, FsrRank, CpfScore, CpfRank, IfrScore, IfrRank, IsrScore, IsrRank, IrnScore, IrnRank, GerScore, GerRank, ScoreScaled, TotalPick;
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
        insertUni(std::stoi(Rank), Institution, LocationCode, Location, std::stod(ArScore), std::stoi(ArRank), std::stod(ErScore), std::stoi(ErRank), std::stod(FsrScore), std::stoi(FsrRank), std::stod(CpfScore), std::stoi(CpfRank), std::stod(IfrScore), std::stoi(IfrRank), std::stod(IsrScore), std::stoi(IsrRank), std::stod(IrnScore), std::stoi(IrnRank), std::stod(GerScore), std::stoi(GerRank), std::stod(ScoreScaled), Region, std::stoi(TotalPick));
    }
    uniFile.close();
}
void University::printTopBorder() {
    std::cout << "+";
    for (int i = 0; i < 23; i++) {
        for (int j = 0; j < widthArray[i]; j++) {
            std::cout << "=";
        }
        std::cout << "+";
    } std::cout << std::endl;
}
void University::printHeader() {
    std::cout << "|" << std::setw(widthArray[0]) << std::left << "Rank" << "|" << std::setw(widthArray[1]) << std::left << "Institution" << "|" << std::setw(widthArray[2]) << std::left << "LocationCode" << "|" << std::setw(widthArray[3]) << std::left << "Location" << "|" << std::setw(widthArray[4]) << std::left << "ArScore" << "|" << std::setw(widthArray[5]) << std::left << "ArRank" << "|" << std::setw(widthArray[6]) << std::left << "ErScore" << "|" << std::setw(widthArray[7]) << std::left << "ErRank" << "|" << std::setw(widthArray[8]) << std::left << "FsrScore" << "|" << std::setw(widthArray[9]) << std::left << "FsrRank" << "|" << std::setw(widthArray[10]) << std::left << "CpfScore" << "|" << std::setw(widthArray[11]) << std::left << "CpfRank" << "|" << std::setw(widthArray[12]) << std::left << "IfrScore" << "|" << std::setw(widthArray[13]) << std::left << "IfrRank" << "|" << std::setw(widthArray[14]) << std::left << "IsrScore" << "|" << std::setw(widthArray[15]) << std::left << "IsrRank" << "|" << std::setw(widthArray[16]) << std::left << "IrnScore" << "|" << std::setw(widthArray[17]) << std::left << "IrnRank" << "|" << std::setw(widthArray[18]) << std::left << "GerScore" << "|" << std::setw(widthArray[19]) << std::left << "GerRank" << "|" << std::setw(widthArray[20]) << std::left << "ScoreScaled" << "|" << std::setw(widthArray[21]) << std::left << "Region" << "|" << std::setw(widthArray[22]) << std::left << "TotalPick" << "|" << std::endl;
}
void University::theTopLines() {
    printTopBorder();
    printHeader();
    printTopBorder();
    return;
}
//Display Table with width fixed to widthArray position
void University::printTable() {
    theTopLines();
    char choice;
    int currentPage = 1;
    UniList* uniTemp = uniHead;
    while (uniTemp != NULL) {
        if (cnt < 40) {
            std::cout << "|" << std::setw(widthArray[0]) << std::left << uniTemp->Rank << "|" << std::setw(widthArray[1]) << std::left << uniTemp->Institution << "|" << std::setw(widthArray[2]) << std::left << uniTemp->LocationCode << "|" << std::setw(widthArray[3]) << std::left << uniTemp->Location << "|" << std::setw(widthArray[4]) << std::left << uniTemp->ArScore << "|" << std::setw(widthArray[5]) << std::left << uniTemp->ArRank << "|" << std::setw(widthArray[6]) << std::left << uniTemp->ErScore << "|" << std::setw(widthArray[7]) << std::left << uniTemp->ErRank << "|" << std::setw(widthArray[8]) << std::left << uniTemp->FsrScore << "|" << std::setw(widthArray[9]) << std::left << uniTemp->FsrRank << "|" << std::setw(widthArray[10]) << std::left << uniTemp->CpfScore << "|" << std::setw(widthArray[11]) << std::left << uniTemp->CpfRank << "|" << std::setw(widthArray[12]) << std::left << uniTemp->IfrScore << "|" << std::setw(widthArray[13]) << std::left << uniTemp->IfrRank << "|" << std::setw(widthArray[14]) << std::left << uniTemp->IsrScore << "|" << std::setw(widthArray[15]) << std::left << uniTemp->IsrRank << "|" << std::setw(widthArray[16]) << std::left << uniTemp->IrnScore << "|" << std::setw(widthArray[17]) << std::left << uniTemp->IrnRank << "|" << std::setw(widthArray[18]) << std::left << uniTemp->GerScore << "|" << std::setw(widthArray[19]) << std::left << uniTemp->GerRank << "|" << std::setw(widthArray[20]) << std::left << uniTemp->ScoreScaled << "|" << std::setw(widthArray[21]) << std::left << uniTemp->Region << "|" << std::setw(widthArray[22]) << std::left << uniTemp->TotalPick << "|" << std::endl;
            printTopBorder();
            uniTemp = uniTemp->nextNode;
            cnt += 1;
        }
        else {
            std::cout << "\n\n" << chgPage << std::endl;
            std::cout << "Input:" << "\t";
            std::cin >> choice;
            switch (choice) {

            case '<':
                if (currentPage > 1) {
                    currentPage--;
                    int k = 0;
                    int lj = (currentPage - 1) * 20;
                    system("cls");
                    theTopLines();
                    uniTemp = uniHead;
                    while (k < lj) {
                        uniTemp = uniTemp->nextNode;
                        k++;
                    }
                    cnt = 0;
                }
                else {
                    std::cout << "You are already on the first page. Cannot go back further." << std::endl;
                }
                break;
            case '>':
                system("cls");
                theTopLines();
                cnt = 0;
                currentPage++;
                break;
            case 'q':
                system("cls");
                std::cout << "Thank you for using this program!" << std::endl;
                return;
            default:
                system("cls");
                std::cout << "Invalid input!" << std::endl;
                return;
            }

        }
    }

    return;
}

bool compareArScore(UniList* a, UniList* b) {
    return a->ArScore > b->ArScore;
}
bool compareFsrScore(UniList* a, UniList* b) {
    return a->FsrScore > b->FsrScore;
}
bool compareErScore(UniList* a, UniList* b) {
    return a->ErScore > b->ErScore;
}
bool compareName(UniList* a, UniList* b) {
    return a->Institution < b->Institution;
}

UniList* University::getUniTail(UniList* uniCur) {
    while (uniCur != NULL && uniCur->nextNode != NULL)
        uniCur = uniCur->nextNode;
    return uniCur;
}



UniList** University::getHeadRef() {
    return &uniHead;
}
UniList* University::partition(UniList* uniHead, UniList* end, UniList** newHead, UniList** newEnd, bool (*compare)(UniList*, UniList*)) {
    UniList* pivot = end;
    UniList* prev = NULL, * uniCur = uniHead, * uniTail = pivot;

    while (uniCur != pivot) {
        if (compare(uniCur, pivot)) {
            if ((*newHead) == NULL)
                (*newHead) = uniCur;

            prev = uniCur;
            uniCur = uniCur->nextNode;
        }
        else {
            if (prev)
                prev->nextNode = uniCur->nextNode;
            UniList* uniTmp = uniCur->nextNode;
            uniCur->nextNode = NULL;
            uniTail->nextNode = uniCur;
            uniTail = uniCur;
            uniCur = uniTmp;
        }
    }

    if ((*newHead) == NULL)
        (*newHead) = pivot;

    (*newEnd) = uniTail;

    return pivot;
}
UniList* University::quickSortRecur(UniList* uniHead, UniList* end, bool (*compare)(UniList*, UniList*)) {


    if (!uniHead || uniHead == end)
        return uniHead;

    UniList* newHead = NULL, * newEnd = NULL;

    UniList* pivot = partition(uniHead, end, &newHead, &newEnd, compare);

    if (newHead != pivot) {
        UniList* uniTmp = newHead;
        while (uniTmp->nextNode != pivot)
            uniTmp = uniTmp->nextNode;
        uniTmp->nextNode = NULL;

        newHead = quickSortRecur(newHead, uniTmp, compare);

        uniTmp = getUniTail(newHead);
        uniTmp->nextNode = pivot;
    }

    pivot->nextNode = quickSortRecur(pivot->nextNode, newEnd, compare);

    return newHead;
}

//void University::quickSort(UniList** headRef, bool (*compare)(UniList*, UniList*)) {
//    (*headRef) = quickSortRecur(*headRef, getUniTail(*headRef), compare);
//    return;
//}

void University::quickSort(UniList** headRef, bool (*compare)(UniList*, UniList*)) {
    (*headRef) = quickSortRecur(*headRef, getUniTail(*headRef), compare);
    return;
}
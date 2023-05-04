#pragma once
#ifndef UNIVERSITY_H
#define UNIVERSITY_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>

using namespace std;

int widthArray[23] = { 4,83,12,30,7,6,7,6,8,7,8,7,8,7,8,7,8,7,8,7,11,13,10 };
int cnt = 0;
std::string chgPage = "Type '<' to go to prev page, '>' to go to next page, or 'q' to quit: ";



//LinkedList of dataset Rank,Institution,LocationCode,Location,ArScore,ArRank,ErScore,ErRank,FsrScore,FsrRank,CpfScore,CpfRank,IfrScore,IfrRank,IsrScore,IsrRank,IrnScore,IrnRank,GerScore,GerRank,ScoreScaled
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
   
}*tail, *head;

void insertAtEnd(int Rank, std::string Institution, std::string LocationCode, std::string Location, double ArScore, int ArRank, double ErScore, int ErRank, double FsrScore, int FsrRank, double CpfScore, int CpfRank, double IfrScore, int IfrRank, double IsrScore, int IsrRank, double IrnScore, int IrnRank, double GerScore, int GerRank, double ScoreScaled, std::string Region, int TotalPick) {
    Uni* newNode = new Uni{ Rank, Institution, LocationCode, Location, ArScore, ArRank, ErScore, ErRank, FsrScore, FsrRank, CpfScore, CpfRank, IfrScore, IfrRank, IsrScore, IsrRank, IrnScore, IrnRank, GerScore, GerRank, ScoreScaled, Region, TotalPick,nullptr,nullptr };
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->nextNode = newNode;
        newNode->prevNode = tail;
        tail = newNode;
    }
}

void importUni() {
    std::ifstream file;
    file.open("UniversityDataset.csv");
    std::string line;
    getline(file, line);
    while (getline(file, line)) {
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
        insertAtEnd(std::stoi(Rank), Institution, LocationCode, Location, std::stod(ArScore), std::stoi(ArRank), std::stod(ErScore), std::stoi(ErRank), std::stod(FsrScore), std::stoi(FsrRank), std::stod(CpfScore), std::stoi(CpfRank), std::stod(IfrScore), std::stoi(IfrRank), std::stod(IsrScore), std::stoi(IsrRank), std::stod(IrnScore), std::stoi(IrnRank), std::stod(GerScore), std::stoi(GerRank), std::stod(ScoreScaled), Region, std::stoi(TotalPick));
    }
    file.close();
}
void printTopBorder() {
    std::cout << "+";
    for (int i = 0; i < 23; i++) {
        for (int j = 0; j < widthArray[i]; j++) {
            std::cout << "=";
        }
        std::cout << "+";
    } std::cout << std::endl;
}

void printHeader() {
    std::cout << "|" << std::setw(widthArray[0]) << std::left << "Rank" << "|" << std::setw(widthArray[1]) << std::left << "Institution" << "|" << std::setw(widthArray[2]) << std::left << "LocationCode" << "|" << std::setw(widthArray[3]) << std::left << "Location" << "|" << std::setw(widthArray[4]) << std::left << "ArScore" << "|" << std::setw(widthArray[5]) << std::left << "ArRank" << "|" << std::setw(widthArray[6]) << std::left << "ErScore" << "|" << std::setw(widthArray[7]) << std::left << "ErRank" << "|" << std::setw(widthArray[8]) << std::left << "FsrScore" << "|" << std::setw(widthArray[9]) << std::left << "FsrRank" << "|" << std::setw(widthArray[10]) << std::left << "CpfScore" << "|" << std::setw(widthArray[11]) << std::left << "CpfRank" << "|" << std::setw(widthArray[12]) << std::left << "IfrScore" << "|" << std::setw(widthArray[13]) << std::left << "IfrRank" << "|" << std::setw(widthArray[14]) << std::left << "IsrScore" << "|" << std::setw(widthArray[15]) << std::left << "IsrRank" << "|" << std::setw(widthArray[16]) << std::left << "IrnScore" << "|" << std::setw(widthArray[17]) << std::left << "IrnRank" << "|" << std::setw(widthArray[18]) << std::left << "GerScore" << "|" << std::setw(widthArray[19]) << std::left << "GerRank" << "|" << std::setw(widthArray[20]) << std::left << "ScoreScaled" << "|" << std::setw(widthArray[21]) << std::left << "Region" << "|" << std::setw(widthArray[22]) << std::left << "TotalPick" << "|" << std::endl;
}

void theTopLines() {
    printTopBorder();
    printHeader();
    printTopBorder();
    return;
}

void firstPrint() {
    theTopLines();
    int count = 0;
    Uni* temp = head;
    while (temp != NULL) {
        if (count < 20) {
            cout << "|" << setw(widthArray[0]) << left << temp->Rank << "|" << setw(widthArray[1]) << left << temp->Institution << "|" << setw(widthArray[2]) << left << temp->LocationCode << "|" << setw(widthArray[3]) << left << temp->Location << "|" << setw(widthArray[4]) << left << temp->ArScore << "|" << setw(widthArray[5]) << left << temp->ArRank << "|" << setw(widthArray[6]) << left << temp->ErScore << "|" << setw(widthArray[7]) << left << temp->ErRank << "|" << setw(widthArray[8]) << left << temp->FsrScore << "|" << setw(widthArray[9]) << left << temp->FsrRank << "|" << setw(widthArray[10]) << left << temp->CpfScore << "|" << setw(widthArray[11]) << left << temp->CpfRank << "|" << setw(widthArray[12]) << left << temp->IfrScore << "|" << setw(widthArray[13]) << left << temp->IfrRank << "|" << setw(widthArray[14]) << left << temp->IsrScore << "|" << setw(widthArray[15]) << left << temp->IsrRank << "|" << setw(widthArray[16]) << left << temp->IrnScore << "|" << setw(widthArray[17]) << left << temp->IrnRank << "|" << setw(widthArray[18]) << left << temp->GerScore << "|" << setw(widthArray[19]) << left << temp->GerRank << "|" << setw(widthArray[20]) << left << temp->ScoreScaled << "|" << setw(widthArray[21]) << left << temp->Region << "|" << setw(widthArray[22]) << left << temp->TotalPick << "|" << endl;
            printTopBorder();
            temp = temp->nextNode;
            count++;
        }
        else {
            count = 0;
            cout << "Press Enter To Continue" << endl;
            // getchar();
            cin.clear();
            cin.ignore(10000, '\n');
            system("cls");
            return;
        }
    }
}


//Display Table with width fixed to widthArray position
void printTable() {
    theTopLines();
    char choice;
    Uni* temp = head;
    while (temp != NULL) {
        if (cnt < 20) {
            std::cout << "|" << std::setw(widthArray[0]) << std::left << temp->Rank << "|" << std::setw(widthArray[1]) << std::left << temp->Institution << "|" << std::setw(widthArray[2]) << std::left << temp->LocationCode << "|" << std::setw(widthArray[3]) << std::left << temp->Location << "|" << std::setw(widthArray[4]) << std::left << temp->ArScore << "|" << std::setw(widthArray[5]) << std::left << temp->ArRank << "|" << std::setw(widthArray[6]) << std::left << temp->ErScore << "|" << std::setw(widthArray[7]) << std::left << temp->ErRank << "|" << std::setw(widthArray[8]) << std::left << temp->FsrScore << "|" << std::setw(widthArray[9]) << std::left << temp->FsrRank << "|" << std::setw(widthArray[10]) << std::left << temp->CpfScore << "|" << std::setw(widthArray[11]) << std::left << temp->CpfRank << "|" << std::setw(widthArray[12]) << std::left << temp->IfrScore << "|" << std::setw(widthArray[13]) << std::left << temp->IfrRank << "|" << std::setw(widthArray[14]) << std::left << temp->IsrScore << "|" << std::setw(widthArray[15]) << std::left << temp->IsrRank << "|" << std::setw(widthArray[16]) << std::left << temp->IrnScore << "|" << std::setw(widthArray[17]) << std::left << temp->IrnRank << "|" << std::setw(widthArray[18]) << std::left << temp->GerScore << "|" << std::setw(widthArray[19]) << std::left << temp->GerRank << "|" << std::setw(widthArray[20]) << std::left << temp->ScoreScaled << "|" << std::setw(widthArray[21]) << std::left << temp->Region << "|" << std::setw(widthArray[22]) << std::left << temp->TotalPick << "|" << std::endl;
            printTopBorder();
            temp = temp->nextNode;
            cnt += 1;
        }
        else {
            std::cout << "\n\n" << chgPage << std::endl;
            std::cout << "Input:" << "\t";
            std::cin >> choice;
            switch (choice) {

            case '<':
                system("cls");
                theTopLines();
                for (int k = 0; k < 40; k++) {
                    temp = temp->prevNode;
                }
                cnt = 0;
                break;
            case '>':
                system("cls");
                theTopLines();
                cnt = 0;
                break;
            case 's':
                system("cls");
                /*Uni** headRef = &head;
                quickSort(getHeadRef());
                printTable();*/
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


Uni* getTail(Uni* cur) {
    while (cur != NULL && cur->nextNode != NULL)
        cur = cur->nextNode;
    return cur;
}

Uni** getHeadRef() {
    return &head;
}

Uni* partition(Uni* head, Uni* end, Uni** newHead, Uni** newEnd) {
    Uni* pivot = end;
    Uni* prev = NULL, * cur = head, * tail = pivot;

    while (cur != pivot) {
        if (cur->ScoreScaled < pivot->ScoreScaled) {                   //Change the sorting criteria here (e.g. If u want name, change to cur->Institution) (e.g. If u want ArScore, change to cur->ArScore)
            if ((*newHead) == NULL)                                    //Do the ascending Descending choice urself
                (*newHead) = cur;

            prev = cur;
            cur = cur->nextNode;
        }
        else {
            if (prev)
                prev->nextNode = cur->nextNode;
            Uni* tmp = cur->nextNode;
            cur->nextNode = NULL;
            tail->nextNode = cur;
            tail = cur;
            cur = tmp;
        }
    }

    if ((*newHead) == NULL)
        (*newHead) = pivot;

    (*newEnd) = tail;

    return pivot;
}

Uni* quickSortRecur(Uni* head, Uni* end) {
    if (!head || head == end)
        return head;

    Uni* newHead = NULL, * newEnd = NULL;

    Uni* pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot) {
        Uni* tmp = newHead;
        while (tmp->nextNode != pivot)
            tmp = tmp->nextNode;
        tmp->nextNode = NULL;

        newHead = quickSortRecur(newHead, tmp);

        tmp = getTail(newHead);
        tmp->nextNode = pivot;
    }

    pivot->nextNode = quickSortRecur(pivot->nextNode, newEnd);

    return newHead;
}

void quickSort(Uni** headRef) {
    (*headRef) = quickSortRecur(*headRef, getTail(*headRef));
    return;
}
//void importUni();
//Uni* getTail();
//Uni** getHeadRef();
//void printTable();
//void firstPrint();
//void quickSort(Uni** headRef);

#endif

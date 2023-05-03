#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>


#include "sort.h"

using namespace std;


void insertAtEnd(int Rank, string Institution, string LocationCode, string Location, double ArScore, int ArRank, double ErScore, int ErRank, double FsrScore, int FsrRank, double CpfScore, int CpfRank, double IfrScore, int IfrRank, double IsrScore, int IsrRank, double IrnScore, int IrnRank, double GerScore, int GerRank, double ScoreScaled, string Region, int TotalPick) {
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
    ifstream file;
    file.open("UniversityDataset.csv");
    string line;
    getline(file, line);
    while (getline(file, line)) {
        stringstream ss(line);
        string Rank, Institution, LocationCode, Location, Region, ArScore, ArRank, ErScore, ErRank, FsrScore, FsrRank, CpfScore, CpfRank, IfrScore, IfrRank, IsrScore, IsrRank, IrnScore, IrnRank, GerScore, GerRank, ScoreScaled, TotalPick;
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
        insertAtEnd(stoi(Rank), Institution, LocationCode, Location, stod(ArScore), stoi(ArRank), stod(ErScore), stoi(ErRank), stod(FsrScore), stoi(FsrRank), stod(CpfScore), stoi(CpfRank), stod(IfrScore), stoi(IfrRank), stod(IsrScore), stoi(IsrRank), stod(IrnScore), stoi(IrnRank), stod(GerScore), stoi(GerRank), stod(ScoreScaled), Region, stoi(TotalPick));
    }
    file.close();
}

void printTopBorder() {
    cout << "+";
    for (int i = 0; i < 23; i++) {
        for (int j = 0; j < widthArray[i]; j++) {
            cout << "=";
        }
        cout << "+";
    }
    cout << endl;
}

void printHeader() {
    cout << "|" << setw(widthArray[0]) << left << "Rank" << "|" << setw(widthArray[1]) << left << "Institution" << "|" << setw(widthArray[2]) << left << "LocationCode" << "|" << setw(widthArray[3]) << left << "Location" << "|" << setw(widthArray[4]) << left << "ArScore" << "|" << setw(widthArray[5]) << left << "ArRank" << "|" << setw(widthArray[6]) << left << "ErScore" << "|" << setw(widthArray[7]) << left << "ErRank" << "|" << setw(widthArray[8]) << left << "FsrScore" << "|" << setw(widthArray[9]) << left << "FsrRank" << "|" << setw(widthArray[10]) << left << "CpfScore" << "|" << setw(widthArray[11]) << left << "CpfRank" << "|" << setw(widthArray[12]) << left << "IfrScore" << "|" << setw(widthArray[13]) << left << "IfrRank" << "|" << setw(widthArray[14]) << left << "IsrScore" << "|" << setw(widthArray[15]) << left << "IsrRank" << "|" << setw(widthArray[16]) << left << "IrnScore" << "|" << setw(widthArray[17]) << left << "IrnRank" << "|" << setw(widthArray[18]) << left << "GerScore" << "|" << setw(widthArray[19]) << left << "GerRank" << "|" << setw(widthArray[20]) << left << "ScoreScaled" << "|" << setw(widthArray[21]) << left << "Region" << "|" << setw(widthArray[22]) << left << "TotalPick" << "|" << endl;
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
            cout << "|" << setw(widthArray[0]) << left << temp->Rank << "|" << setw(widthArray[1]) << left << temp->Institution << "|" << setw(widthArray[2]) << left << temp->LocationCode << "|" << setw(widthArray[3]) << left << temp->Location << "|" << setw(widthArray[4]) << left << temp->ArScore << "|" << setw(widthArray[5]) << left << temp->ArRank << "|" << setw(widthArray[6]) << left << temp->ErScore << "|" << setw(widthArray[7]) << left << temp->ErRank << "|" << setw(widthArray[8]) << left << temp->FsrScore << "|" << setw(widthArray[9]) << left << temp->FsrRank << "|" << setw(widthArray[10]) << left << temp->CpfScore << "|" << setw(widthArray[11]) << left << temp->CpfRank << "|" << setw(widthArray[12]) << left << temp->IfrScore << "|" << setw(widthArray[13]) << left << temp->IfrRank << "|" << setw(widthArray[14]) << left << temp->IsrScore << "|" << setw(widthArray[15]) << left << temp->IsrRank << "|" << setw(widthArray[16]) << left << temp->IrnScore << "|" << setw(widthArray[17]) << left << temp->IrnRank << "|" << setw(widthArray[18]) << left << temp->GerScore << "|" << setw(widthArray[19]) << left << temp->GerRank << "|" << setw(widthArray[20]) << left << temp->ScoreScaled << "|" << setw(widthArray[21]) << left << temp->Region << "|" << setw(widthArray[22]) << left << temp->TotalPick << "|" << endl;
            printTopBorder();
            temp = temp->nextNode;
            cnt += 1;
        }
        else {
            cout << "\n\n" << chgPage << endl;
            cout << "Input:" << "\t";
            cin >> choice;
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
            case 'q':
                system("cls");
                cout << "Thank you for using this program!" << endl;
                return;
            default:
                system("cls");
                cout << "Invalid input!" << endl;
                return;
            }
        }
    }

    return;
}

int main() {
    importUni();
    firstPrint();
    Uni** headRef = &head;
    quickSort(getHeadRef());
    printTable();

}
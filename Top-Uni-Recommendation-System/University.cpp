#include "University.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>
#include "RegisteredCustomer.h"
//#include "Guest.h"


using namespace std;


void University::insertUni(int Rank, string Institution, string LocationCode, string Location, double ArScore, int ArRank, double ErScore, int ErRank, double FsrScore, int FsrRank, double CpfScore, int CpfRank, double IfrScore, int IfrRank, double IsrScore, int IsrRank, double IrnScore, int IrnRank, double GerScore, int GerRank, double ScoreScaled, string Region, int TotalPick) {
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
    ifstream uniFile;
    uniFile.open("UniversityDataset.csv");
    string line;
    getline(uniFile, line);
    while (getline(uniFile, line)) {
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
        insertUni(stoi(Rank), Institution, LocationCode, Location, stod(ArScore), stoi(ArRank), stod(ErScore), stoi(ErRank), stod(FsrScore), stoi(FsrRank), stod(CpfScore), stoi(CpfRank), stod(IfrScore), stoi(IfrRank), stod(IsrScore), stoi(IsrRank), stod(IrnScore), stoi(IrnRank), stod(GerScore), stoi(GerRank), stod(ScoreScaled), Region, stoi(TotalPick));
    }
    uniFile.close();
}
void University::printTopBorder() {
    cout << "+";
    for (int i = 0; i < 23; i++) {
        for (int j = 0; j < widthArray[i]; j++) {
            cout << "=";
        }
        cout << "+";
    }   cout << endl;
}
void University::printHeader() {
    cout << "|" << setw(widthArray[0]) << left << "Rank" << "|" << setw(widthArray[1]) << left << "Institution" << "|" << setw(widthArray[2]) << left << "LocationCode" << "|" << setw(widthArray[3]) << left << "Location" << "|" << setw(widthArray[4]) << left << "ArScore" << "|" << setw(widthArray[5]) << left << "ArRank" << "|" << setw(widthArray[6]) << left << "ErScore" << "|" << setw(widthArray[7]) << left << "ErRank" << "|" << setw(widthArray[8]) << left << "FsrScore" << "|" << setw(widthArray[9]) << left << "FsrRank" << "|" << setw(widthArray[10]) << left << "CpfScore" << "|" << setw(widthArray[11]) << left << "CpfRank" << "|" << setw(widthArray[12]) << left << "IfrScore" << "|" << setw(widthArray[13]) << left << "IfrRank" << "|" << setw(widthArray[14]) << left << "IsrScore" << "|" << setw(widthArray[15]) << left << "IsrRank" << "|" << setw(widthArray[16]) << left << "IrnScore" << "|" << setw(widthArray[17]) << left << "IrnRank" << "|" << setw(widthArray[18]) << left << "GerScore" << "|" << setw(widthArray[19]) << left << "GerRank" << "|" << setw(widthArray[20]) << left << "ScoreScaled" << "|" << setw(widthArray[21]) << left << "Region" << "|" << setw(widthArray[22]) << left << "TotalPick" << "|" << endl;
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
        if (cnt < 20) {
            cout << "|" << setw(widthArray[0]) << left << uniTemp->Rank << "|" << setw(widthArray[1]) << left << uniTemp->Institution << "|" << setw(widthArray[2]) << left << uniTemp->LocationCode << "|" << setw(widthArray[3]) << left << uniTemp->Location << "|" << setw(widthArray[4]) << left << uniTemp->ArScore << "|" << setw(widthArray[5]) << left << uniTemp->ArRank << "|" << setw(widthArray[6]) << left << uniTemp->ErScore << "|" << setw(widthArray[7]) << left << uniTemp->ErRank << "|" << setw(widthArray[8]) << left << uniTemp->FsrScore << "|" << setw(widthArray[9]) << left << uniTemp->FsrRank << "|" << setw(widthArray[10]) << left << uniTemp->CpfScore << "|" << setw(widthArray[11]) << left << uniTemp->CpfRank << "|" << setw(widthArray[12]) << left << uniTemp->IfrScore << "|" << setw(widthArray[13]) << left << uniTemp->IfrRank << "|" << setw(widthArray[14]) << left << uniTemp->IsrScore << "|" << setw(widthArray[15]) << left << uniTemp->IsrRank << "|" << setw(widthArray[16]) << left << uniTemp->IrnScore << "|" << setw(widthArray[17]) << left << uniTemp->IrnRank << "|" << setw(widthArray[18]) << left << uniTemp->GerScore << "|" << setw(widthArray[19]) << left << uniTemp->GerRank << "|" << setw(widthArray[20]) << left << uniTemp->ScoreScaled << "|" << setw(widthArray[21]) << left << uniTemp->Region << "|" << setw(widthArray[22]) << left << uniTemp->TotalPick << "|" << endl;
            printTopBorder();
            uniTemp = uniTemp->nextNode;
            cnt += 1;
        }
        else {
            cout << "\n\n" << chgPage << endl;
            cout << "Input:" << "\t";
            cin >> choice;
            while (choice != '<' && choice != '>' && choice != 'q') {
                cout << "Invalid input. Please enter a valid option." << endl;
                cout << "Input:" << "\t";
                cin >> choice;
            }
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
                    cout << "You are already on the first page. Cannot go back further." << endl;
                }
                break;
            case '>':
                system("cls");
                theTopLines();
                cnt = 0;
                currentPage++;
                break;
            case 'q':
                // go back to previous menu
               /* if (userType == 1) {
                    showGuestMenu();
                }*/
                /*if (userType == 2) {
                    showRegisteredCustomerMenu();
                }*/
                return;
            }
        }
    }
}

//Display Table with width fixed to widthArray position
void University::printTopPickUniTable() {
    quickSort(getHeadRef(), compareTotalPicks);
    theTopLines();
    char choice;
    UniList* uniTemp = uniHead;
    while (uniTemp != NULL) {
        if (cnt < 20) {
            cout << "|" << setw(widthArray[0]) << left << uniTemp->Rank << "|" << setw(widthArray[1]) << left << uniTemp->Institution << "|" << setw(widthArray[2]) << left << uniTemp->LocationCode << "|" << setw(widthArray[3]) << left << uniTemp->Location << "|" << setw(widthArray[4]) << left << uniTemp->ArScore << "|" << setw(widthArray[5]) << left << uniTemp->ArRank << "|" << setw(widthArray[6]) << left << uniTemp->ErScore << "|" << setw(widthArray[7]) << left << uniTemp->ErRank << "|" << setw(widthArray[8]) << left << uniTemp->FsrScore << "|" << setw(widthArray[9]) << left << uniTemp->FsrRank << "|" << setw(widthArray[10]) << left << uniTemp->CpfScore << "|" << setw(widthArray[11]) << left << uniTemp->CpfRank << "|" << setw(widthArray[12]) << left << uniTemp->IfrScore << "|" << setw(widthArray[13]) << left << uniTemp->IfrRank << "|" << setw(widthArray[14]) << left << uniTemp->IsrScore << "|" << setw(widthArray[15]) << left << uniTemp->IsrRank << "|" << setw(widthArray[16]) << left << uniTemp->IrnScore << "|" << setw(widthArray[17]) << left << uniTemp->IrnRank << "|" << setw(widthArray[18]) << left << uniTemp->GerScore << "|" << setw(widthArray[19]) << left << uniTemp->GerRank << "|" << setw(widthArray[20]) << left << uniTemp->ScoreScaled << "|" << setw(widthArray[21]) << left << uniTemp->Region << "|" << setw(widthArray[22]) << left << uniTemp->TotalPick << "|" << endl;
            printTopBorder();
            uniTemp = uniTemp->nextNode;
            cnt += 1;
        }
        else {
            while (true) {
                cout << "Go back to menu? Press(y)" << endl;
                cout << "Input:" << "\t";
                cin >> choice;
                if (choice == 'y' || choice == 'Y') {
                    system("cls");
                    return showRegisteredCustomerMenu();
                }
                else {
                    cout << "Invalid input. Please enter 'y' or 'Y'." << endl;
                }
            }
        }
    }
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

bool compareTotalPicks(UniList* a, UniList* b) {
    return a->TotalPick > b->TotalPick;
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

void University::quickSort(UniList** headRef, bool (*compare)(UniList*, UniList*)) {
    (*headRef) = quickSortRecur(*headRef, getUniTail(*headRef), compare);
    return;
}

void sortForRegisterCustomerPanel() {
    int option;
    University myUniversity; // Create a University object
    myUniversity.importUni(); // Call the importUni function using the University object
    cout << " " << endl;
    cout << "===============================" << endl;
    cout << setw(2) << "        " << "SORT OPTIONS" << endl;
    cout << "===============================" << endl;
    cout << setw(2) << " " << "1. Sort by ArScore" << endl;
    cout << setw(2) << " " << "2. Sort by FsrScore" << endl;
    cout << setw(2) << " " << "3. Sort by ErScore" << endl;
    cout << "===============================" << endl;
    cout << "Input:" << "\t";

    cin >> option;

    if (option == 1) {
        myUniversity.quickSort(myUniversity.getHeadRef(), compareArScore);
    }
    else if (option == 2) {
        myUniversity.quickSort(myUniversity.getHeadRef(), compareFsrScore);
    }
    else if (option == 3) {
        myUniversity.quickSort(myUniversity.getHeadRef(), compareErScore);
    }
    /*else if (option == 4) {
        myUniversity.quickSort(myUniversity.getHeadRef(), compareName);
    }*/
    else {
        cout << "Invalid Option" << endl;
    }

    myUniversity.printTable(); // Call the printTable function using the University object

}
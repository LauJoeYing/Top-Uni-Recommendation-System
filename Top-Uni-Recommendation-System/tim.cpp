#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>

using namespace std;

int widthArray[23] = { 4,90,12,30,7,6,7,6,8,7,8,7,8,7,8,7,8,7,8,7,11,13,10 };
int cnt = 0;
string chgPage = "Type '<' to go to prev page, '>' to go to next page, or 'q' to quit: ";

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

}*head, *tail;


void insertAtEnd(int Rank, string Institution, string LocationCode, string Location, double ArScore, int ArRank, double ErScore, int ErRank, double FsrScore, int FsrRank, double CpfScore, int CpfRank, double IfrScore, int IfrRank, double IsrScore, int IsrRank, double IrnScore, int IrnRank, double GerScore, int GerRank, double ScoreScaled, string Region, int TotalPick) {
    Uni* newNode = new Uni{Rank, Institution, LocationCode, Location, ArScore, ArRank, ErScore, ErRank, FsrScore, FsrRank, CpfScore, CpfRank, IfrScore, IfrRank, IsrScore, IsrRank, IrnScore, IrnRank, GerScore, GerRank, ScoreScaled, Region, TotalPick,nullptr,nullptr};
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

//Tim Sort is a hybrid of Insertion Sort and Merge Sort
//First define insertion sort then merge sort
//The size of run is 32
//The size of array is 1500
//The variable to compare is the ArScore, sort it in ascending order
//Sorting is done by changing the address of the pointers not the parameter of the linked list
//The sorting is done by comparing the ArScore of the current node and the next node
//If the ArScore of the current node is greater than the next node, swap the address of the current node and the next node
//If the ArScore of the current node is less than the next node, move to the next node
//If the ArScore of the current node is equal to the next node, compare the ErScore of the current node and the next node
//To change from descending to ascending, change the sign of the comparison operator in line 98 and 100 which is in function insertionSort

void sortedInsert(Uni** head_ref, Uni* new_node) {
    Uni* current;
    if (*head_ref == NULL) {
        *head_ref = new_node;
    }
    else if ((*head_ref)->ArScore >= new_node->ArScore) {
        new_node->nextNode = *head_ref;
        new_node->nextNode->prevNode = new_node;
        *head_ref = new_node;
    }
    else {
        current = *head_ref;
        while (current->nextNode != NULL && current->nextNode->ArScore > new_node->ArScore) {
            current = current->nextNode;
        }
        new_node->nextNode = current->nextNode;
        if (current->nextNode != NULL) {
            new_node->nextNode->prevNode = new_node;
        }
        current->nextNode = new_node;
        new_node->prevNode = current;
    }
}

void insertionSort(Uni** head_ref) {  
    Uni* sorted = NULL;
    Uni* current = *head_ref;
    while (current != NULL) {
        Uni* next = current->nextNode;
        current->prevNode = current->nextNode = NULL;
        sortedInsert(&sorted, current);
        current = next;
    }
    *head_ref = sorted;
}


void merge(Uni* head, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    Uni* L = NULL;
    Uni* R = NULL;
    for (i = 0; i < n1; i++) {
        L = head;
        for (int j = 0; j < i; j++) {
            L = L->nextNode;
        }
    }
    for (j = 0; j < n2; j++) {
        R = head;
        for (int k = 0; k < j; k++) {
            R = R->nextNode;
        }
    }
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L->ArScore >= R->ArScore) {
            head = L;
            L = L->nextNode;
        }
        else {
            head = R;
            R = R->nextNode;
        }
        k++;
    }
    while (i < n1) {
        head = L;
        L = L->nextNode;
        k++;
    }
    while (j < n2) {
        head = R;
        R = R->nextNode;
        k++;
    }
}

void timSort(Uni* head, int n) { //the integer n is the size of the array
    for (int i = 0; i < n; i += 16) {
        insertionSort(&head);
    }
    for (int size = 32; size < n; size = 2 * size) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = left + size - 1;
            int right = min((left + 2 * size - 1), (n - 1));
            merge(head, left, mid, right);
        }
    }
    
}
void printRow(Uni* current) {
    cout << "|" << setw(widthArray[0]) << left << current->Rank << "|" << setw(widthArray[1]) << left << current->Institution << "|" << setw(widthArray[2]) << left << current->LocationCode << "|" << setw(widthArray[3]) << left << current->Location << "|" << setw(widthArray[4]) << left << current->ArScore << "|" << setw(widthArray[5]) << left << current->ArRank << "|" << setw(widthArray[6]) << left << current->ErScore << "|" << setw(widthArray[7]) << left << current->ErRank << "|" << setw(widthArray[8]) << left << current->FsrScore << "|" << setw(widthArray[9]) << left << current->FsrRank << "|" << setw(widthArray[10]) << left << current->CpfScore << "|" << setw(widthArray[11]) << left << current->CpfRank << "|" << setw(widthArray[12]) << left << current->IfrScore << "|" << setw(widthArray[13]) << left << current->IfrRank << "|" << setw(widthArray[14]) << left << current->IsrScore << "|" << setw(widthArray[15]) << left << current->IsrRank << "|" << setw(widthArray[16]) << left << current->IrnScore << "|" << setw(widthArray[17]) << left << current->IrnRank << "|" << setw(widthArray[18]) << left << current->GerScore << "|" << setw(widthArray[19]) << left << current->GerRank << "|" << setw(widthArray[20]) << left << current->ScoreScaled << "|" << setw(widthArray[21]) << left << current->Region << "|" << setw(widthArray[22]) << left << current->TotalPick << "|" << endl;
}





void printTopBorder() {
    cout << "-----+";
    for (int i = 0; i < 23; i++) {
        for (int j = 0; j < widthArray[i]; j++) {
            cout << "=";
        }
        cout << "+";
    }
    cout << endl;
}

void printHeader() {
    cout << "|" << setw(widthArray[0]) << left << "Rank" << "|" << setw(4) << left << "cnt" << "|" << setw(widthArray[1]) << left << "Institution" << "|" << setw(widthArray[2]) << left << "LocationCode" << "|" << setw(widthArray[3]) << left << "Location" << "|" << setw(widthArray[4]) << left << "ArScore" << "|" << setw(widthArray[5]) << left << "ArRank" << "|" << setw(widthArray[6]) << left << "ErScore" << "|" << setw(widthArray[7]) << left << "ErRank" << "|" << setw(widthArray[8]) << left << "FsrScore" << "|" << setw(widthArray[9]) << left << "FsrRank" << "|" << setw(widthArray[10]) << left << "CpfScore" << "|" << setw(widthArray[11]) << left << "CpfRank" << "|" << setw(widthArray[12]) << left << "IfrScore" << "|" << setw(widthArray[13]) << left << "IfrRank" << "|" << setw(widthArray[14]) << left << "IsrScore" << "|" << setw(widthArray[15]) << left << "IsrRank" << "|" << setw(widthArray[16]) << left << "IrnScore" << "|" << setw(widthArray[17]) << left << "IrnRank" << "|" << setw(widthArray[18]) << left << "GerScore" << "|" << setw(widthArray[19]) << left << "GerRank" << "|" << setw(widthArray[20]) << left << "ScoreScaled" << "|" << setw(widthArray[21]) << left << "Region" << "|" << setw(widthArray[22]) << left << "TotalPick" << "|" << endl;
}

void theTopLines() {
    printTopBorder();
    printHeader();
    printTopBorder();
    return;
}


void firstPrint(){
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


// Display Table with width fixed to widthArray position
// void displayTable() {
//     theTopLines();
//     char choice;
//     Uni* temp = head;
    // while (temp != NULL) {
    //     if (cnt < 142) {
    //         cout << "|" << setw(widthArray[0]) << left << temp->Rank << "|" << setw(widthArray[1]) << left << temp->Institution << "|" << setw(widthArray[2]) << left << temp->LocationCode << "|" << setw(widthArray[3]) << left << temp->Location << "|" << setw(widthArray[4]) << left << temp->ArScore << "|" << setw(widthArray[5]) << left << temp->ArRank << "|" << setw(widthArray[6]) << left << temp->ErScore << "|" << setw(widthArray[7]) << left << temp->ErRank << "|" << setw(widthArray[8]) << left << temp->FsrScore << "|" << setw(widthArray[9]) << left << temp->FsrRank << "|" << setw(widthArray[10]) << left << temp->CpfScore << "|" << setw(widthArray[11]) << left << temp->CpfRank << "|" << setw(widthArray[12]) << left << temp->IfrScore << "|" << setw(widthArray[13]) << left << temp->IfrRank << "|" << setw(widthArray[14]) << left << temp->IsrScore << "|" << setw(widthArray[15]) << left << temp->IsrRank << "|" << setw(widthArray[16]) << left << temp->IrnScore << "|" << setw(widthArray[17]) << left << temp->IrnRank << "|" << setw(widthArray[18]) << left << temp->GerScore << "|" << setw(widthArray[19]) << left << temp->GerRank << "|" << setw(widthArray[20]) << left << temp->ScoreScaled << "|" << setw(widthArray[21]) << left << temp->Region << "|" << setw(widthArray[22]) << left << temp->TotalPick << "|" << endl;
    //         printTopBorder();
    //         temp = temp->nextNode;
    //         cnt += 1;
    //     }
    //     else {
    //         cout << "\n\n" << chgPage << endl;
    //         cout << "Input:" << "\t";
    //         cin >> choice;
    //         switch (choice) {
    //         case '<':
    //             system("cls");
    //             theTopLines();
    //             for (int k = 0; k < 80; k++) {
    //                 temp = temp->prevNode;
    //             }
    //             cnt = 0;
    //             break;
    //         case '>':
    //             system("cls");
    //             theTopLines();
    //             cnt = 0;
    //             break;
    //         case 'q':
    //             system("cls");
    //             cout << "Thank you for using this program!" << endl;
    //             return;
    //         default:
    //             system("cls");
    //             cout << "Invalid input!" << endl;
    //             return;
    //         }
    //     }
    // }

//     return;
// }

void displayTable() {
    theTopLines();
    char choice;
    Uni* temp = tail;
    cnt = 0;
    while (1) {
        if (cnt < 1423) {
            cout << "|" << setw(widthArray[0]) << left << temp->Rank << "|" << setw(4) << left << cnt << "|" << setw(widthArray[1]) << left << temp->Institution << "|" << setw(widthArray[2]) << left << temp->LocationCode << "|" << setw(widthArray[3]) << left << temp->Location << "|" << setw(widthArray[4]) << left << temp->ArScore << "|" << setw(widthArray[5]) << left << temp->ArRank << "|" << setw(widthArray[6]) << left << temp->ErScore << "|" << setw(widthArray[7]) << left << temp->ErRank << "|" << setw(widthArray[8]) << left << temp->FsrScore << "|" << setw(widthArray[9]) << left << temp->FsrRank << "|" << setw(widthArray[10]) << left << temp->CpfScore << "|" << setw(widthArray[11]) << left << temp->CpfRank << "|" << setw(widthArray[12]) << left << temp->IfrScore << "|" << setw(widthArray[13]) << left << temp->IfrRank << "|" << setw(widthArray[14]) << left << temp->IsrScore << "|" << setw(widthArray[15]) << left << temp->IsrRank << "|" << setw(widthArray[16]) << left << temp->IrnScore << "|" << setw(widthArray[17]) << left << temp->IrnRank << "|" << setw(widthArray[18]) << left << temp->GerScore << "|" << setw(widthArray[19]) << left << temp->GerRank << "|" << setw(widthArray[20]) << left << temp->ScoreScaled << "|" << setw(widthArray[21]) << left << temp->Region << "|" << setw(widthArray[22]) << left << temp->TotalPick << "|" << endl;
            printTopBorder();
            temp = temp->prevNode;
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
                for (int k = 0; k < 80; k++) {
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


void displayFromTail(){
    theTopLines();
    int count = 0;
    Uni* temp = tail;
    while (temp != NULL) {
        if (count < 20) {
            cout << "|" << setw(widthArray[0]) << left << temp->Rank << "|" << setw(widthArray[1]) << left << temp->Institution << "|" << setw(widthArray[2]) << left << temp->LocationCode << "|" << setw(widthArray[3]) << left << temp->Location << "|" << setw(widthArray[4]) << left << temp->ArScore << "|" << setw(widthArray[5]) << left << temp->ArRank << "|" << setw(widthArray[6]) << left << temp->ErScore << "|" << setw(widthArray[7]) << left << temp->ErRank << "|" << setw(widthArray[8]) << left << temp->FsrScore << "|" << setw(widthArray[9]) << left << temp->FsrRank << "|" << setw(widthArray[10]) << left << temp->CpfScore << "|" << setw(widthArray[11]) << left << temp->CpfRank << "|" << setw(widthArray[12]) << left << temp->IfrScore << "|" << setw(widthArray[13]) << left << temp->IfrRank << "|" << setw(widthArray[14]) << left << temp->IsrScore << "|" << setw(widthArray[15]) << left << temp->IsrRank << "|" << setw(widthArray[16]) << left << temp->IrnScore << "|" << setw(widthArray[17]) << left << temp->IrnRank << "|" << setw(widthArray[18]) << left << temp->GerScore << "|" << setw(widthArray[19]) << left << temp->GerRank << "|" << setw(widthArray[20]) << left << temp->ScoreScaled << "|" << setw(widthArray[21]) << left << temp->Region << "|" << setw(widthArray[22]) << left << temp->TotalPick << "|" << endl;
            printTopBorder();
            temp = temp->prevNode;
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

void printTable(Uni* head) {
    Uni* current = head;
    printTopBorder();
    printHeader();
    printTopBorder();
    while (current != NULL) {
        printRow(current);
        current = current->nextNode;
    }
    printTopBorder();
}


int main() {
    importUni();
    timSort(head, 32);
    Uni* temp = head->prevNode;
    temp->nextNode = NULL;
    while(tail->ArScore != 2){
        tail = tail->nextNode;
    }
    temp->prevNode = tail;
    tail->nextNode = temp;
    tail = temp;
    delete(head->prevNode);
    displayTable();

}
#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>
#include <ctime>

using namespace std;

//declaration

const int widthArray[23] = { 4,90,12,30,7,6,7,6,8,7,8,7,8,7,8,7,8,7,8,7,11,13,10 };

void displayUniversity();
void theTopLines();
void printHeader();
void printTopBorder();
void quicksortForGuest();
void quicksortForRegisteredCustomer();
void resetUniList();
void quickSort(UniList** headRef, bool (*compare)(UniList*, UniList*));
UniList* quickSortRecur(UniList* uniHead, UniList* end, bool (*compare)(UniList*, UniList*));
UniList* partition(UniList* uniHead, UniList* end, UniList** newHead, UniList** newEnd, bool (*compare)(UniList*, UniList*));
UniList** getHeadRef();
UniList* getUniTail(UniList* uniCur);
bool compareTotalPicks(UniList* a, UniList* b);
bool compareArScore(UniList* a, UniList* b);
bool compareFsrScore(UniList* a, UniList* b);
bool compareErScore(UniList* a, UniList* b);
bool compareName(UniList* a, UniList* b);
bool compareRank(UniList* a, UniList* b);
UniList* findNewHead(UniList** head_ref);
UniList* findNewTail(UniList** tail_ref);
void sortedInsert(UniList** head_ref, UniList* new_node);
void insertionSort(UniList** head_ref);
void merge(UniList* head, int left, int mid, int right);
void timSort(UniList * head, int n);

//initialization

void printTopBorder() {
    cout << "+";
    for (int i = 0; i < 23; i++) {
        for (int j = 0; j < widthArray[i]; j++) {
            cout << "=";
        }
        cout << "+";
    }   cout << endl;
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

void displayUniversity() {
    theTopLines();
    char choice;
    int currentPage = 1, cnt = 0;
    string chgPage = "Type '<' to go to prev page, '>' to go to next page, or 'q' to quit: ";
    UniList* uniTemp = universityHead;
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
                    uniTemp = universityHead;
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

//quicksort

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

bool compareRank(UniList* a, UniList* b) {
    return a->Rank < b->Rank;
}

bool compareTotalPicks(UniList* a, UniList* b) {
    return a->TotalPick > b->TotalPick;
}

UniList* getUniTail(UniList* uniCur) {
    while (uniCur != NULL && uniCur->nextNode != NULL)
        uniCur = uniCur->nextNode;
    return uniCur;
}



UniList** getHeadRef() {
    return &universityHead;
}

UniList* partition(UniList* uniHead, UniList* end, UniList** newHead, UniList** newEnd, bool (*compare)(UniList*, UniList*)) {
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
UniList* quickSortRecur(UniList* uniHead, UniList* end, bool (*compare)(UniList*, UniList*)) {


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

void quickSort(UniList** headRef, bool (*compare)(UniList*, UniList*)) {
    (*headRef) = quickSortRecur(*headRef, getUniTail(*headRef), compare);
    return;
}

void resetUniList() {
    quickSort(getHeadRef(), compareRank);
}

void quicksortForRegisteredCustomer() {
    int option;
    cout << " " << endl;
    cout << "===============================" << endl;
    cout << setw(2) << "\t" << "SORT OPTIONS" << endl;
    cout << "===============================" << endl;
    cout << setw(2) << " " << "[ 1 ]\tSort by ArScore" << endl;
    cout << setw(2) << " " << "[ 2 ]\tSort by FsrScore" << endl;
    cout << setw(2) << " " << "[ 3 ]\tSort by ErScore" << endl;
    cout << "===============================" << endl;
    cout << "Input:" << "\t";

    cin >> option;
    auto start = std::chrono::high_resolution_clock::now();
    if (option == 1) {
        quickSort(getHeadRef(), compareArScore);
    }
    else if (option == 2) {
        quickSort(getHeadRef(), compareFsrScore);
    }
    else if (option == 3) {
        quickSort(getHeadRef(), compareErScore);
    }
    else {
        cout << "Invalid Option" << endl;
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto micros = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Elapsed time: " << micros.count() << " ms" << std::endl;
    displayUniversity();
    resetUniList();  //reset
}

void quicksortForGuest() {
    auto start = std::chrono::high_resolution_clock::now();
    quickSort(getHeadRef(), compareName);
    auto end = std::chrono::high_resolution_clock::now();
    auto micros = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Elapsed time: " << micros.count() << " ms" << std::endl;
    displayUniversity();
    resetUniList();  //reset
}


//tim Sort

UniList* findNewHead(UniList** head_ref) {
    UniList* new_head = *head_ref;
    while (new_head->prevNode != NULL) {
        new_head = new_head->prevNode;
    }

    return new_head;
}

UniList* findNewTail(UniList** tail_ref) {
    UniList* new_tail = *tail_ref;
    while (new_tail->nextNode != NULL) {
        new_tail = new_tail->nextNode;
    }
    return new_tail;
}

void sortedInsert(UniList** head_ref, UniList* new_node) {
    UniList* current;
    if (*head_ref == NULL) {
        *head_ref = new_node;
    }
    else if ((*head_ref)->Institution >= new_node->Institution) {
        new_node->nextNode = *head_ref;
        new_node->nextNode->prevNode = new_node;
        *head_ref = new_node;
    }
    else {
        current = *head_ref;
        while (current->nextNode != NULL && current->nextNode->Institution > new_node->Institution) {
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

void insertionSort(UniList** head_ref) {
    UniList* sorted = NULL;
    UniList* current = *head_ref;
    while (current != NULL) {
        UniList* next = current->nextNode;
        current->prevNode = current->nextNode = NULL;
        sortedInsert(&sorted, current);
        current = next;
    }
    *head_ref = sorted;
}


void merge(UniList* head, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    UniList* L = NULL;
    UniList* R = NULL;
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
        if (L->Institution >= R->Institution) {
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

void timSort(UniList* head, int n) { //the integer n is the size of the array
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
    universityHead = findNewHead(&universityHead);
    universityTail = findNewTail(&universityTail);
    universityTail->nextNode = universityHead;
    universityHead->prevNode = universityTail;
    universityTail = universityHead;
    universityHead = universityHead->nextNode;
    universityHead->prevNode = NULL;
    universityTail->nextNode = NULL;
}

void timsortForGuest() {
    auto start = std::chrono::high_resolution_clock::now();
    timSort(universityHead, 32);
    auto end = std::chrono::high_resolution_clock::now();
    auto micros = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Elapsed time: " << micros.count() << " ms" << std::endl;
    displayUniversity();
    resetUniList();  //reset
}


//Binary Search

UniList* binarySearchUni(string uniName) {
    UniList* uniHead = universityHead;
    UniList* uniTail = universityTail;
    while (uniHead != nullptr && uniTail != nullptr && uniHead != uniTail && uniTail->nextNode != uniHead) {
        UniList* mid = uniHead;
        int count = 0;
        while (mid != nullptr && mid != uniTail && mid->Institution != uniName && uniTail->nextNode != uniHead && count < 1422) {
            mid = mid->nextNode;
            count++;
        }
        if (mid == nullptr || mid == uniTail || mid == uniHead || count >= 1422) {
            break;
        }
        if (mid->Institution == uniName) {
            return mid;
        }
        else if (mid->Institution > uniName) {
            uniTail = mid->prevNode;
        }
        else {
            uniHead = mid->nextNode;
        }
    }
    if (uniHead != nullptr && uniHead->Institution == uniName) {
        return uniHead;
    }
    else if (uniTail != nullptr && uniTail->Institution == uniName) {
        return uniTail;
    }
    else {
        return nullptr;
    }
}


void callBinarySearch() {
    string uniName;
    cout << "Enter university name: " << endl;
    getline(cin, uniName);
    auto start = std::chrono::high_resolution_clock::now();
    UniList* result = binarySearchUni(uniName);
    auto end = std::chrono::high_resolution_clock::now();
    auto micros = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Elapsed time: " << micros.count() << " ms" << std::endl;
    if (result != nullptr) {
        theTopLines();
        cout << "|" << setw(widthArray[0]) << left << result->Rank << "|" << setw(widthArray[1]) << left << result->Institution << "|" << setw(widthArray[2]) << left << result->LocationCode << "|" << setw(widthArray[3]) << left << result->Location << "|" << setw(widthArray[4]) << left << result->ArScore << "|" << setw(widthArray[5]) << left << result->ArRank << "|" << setw(widthArray[6]) << left << result->ErScore << "|" << setw(widthArray[7]) << left << result->ErRank << "|" << setw(widthArray[8]) << left << result->FsrScore << "|" << setw(widthArray[9]) << left << result->FsrRank << "|" << setw(widthArray[10]) << left << result->CpfScore << "|" << setw(widthArray[11]) << left << result->CpfRank << "|" << setw(widthArray[12]) << left << result->IfrScore << "|" << setw(widthArray[13]) << left << result->IfrRank << "|" << setw(widthArray[14]) << left << result->IsrScore << "|" << setw(widthArray[15]) << left << result->IsrRank << "|" << setw(widthArray[16]) << left << result->IrnScore << "|" << setw(widthArray[17]) << left << result->IrnRank << "|" << setw(widthArray[18]) << left << result->GerScore << "|" << setw(widthArray[19]) << left << result->GerRank << "|" << setw(widthArray[20]) << left << result->ScoreScaled << "|" << setw(widthArray[21]) << left << result->Region << "|" << setw(widthArray[22]) << left << result->TotalPick << "|" << endl;
        printTopBorder();
    }
    else {
        cout << "University not found." << endl;
    }
}

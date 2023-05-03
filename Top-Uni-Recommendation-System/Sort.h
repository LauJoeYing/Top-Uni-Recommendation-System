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

}*head, * tail;

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





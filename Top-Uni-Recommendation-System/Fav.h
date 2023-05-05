#ifndef FAV_H
#define FAV_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>

using namespace std;

void importFavouriteFile();
void insertFav(string Institution, string userId);

struct Favourite{
    string Institution;
    string userId;

    Favourite *nextNode;
}*favHead;




#endif
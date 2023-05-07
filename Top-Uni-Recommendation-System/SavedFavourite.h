#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>

#include "University.h"
#include "User.h"

using namespace std;

CurrentUser currentUser;

struct Favourite {
	string userId;
	int userFavRankArr[10];  //Assume maximum of 10 favourite Uni each user, or else I will die
	int counter;
	
	Favourite* nextNode;
};

class SavedFavourite {
private:
	Favourite* favouriteHead;
	int arrLength;

public:
	//void getCurrentUser();
	Favourite* getFavouriteHead();

	SavedFavourite();
	~SavedFavourite();

	//File IO
	void importFavourite();
	void insertFavourite(string, string, string);
	void writeFavourite();

	//Calc current user fav record length
	void getLength(); //In function, arrLength = while(!NULL||0){int cnt++;}

	//Print Record
	void printFavourite(); //Show list of (userId ,favourited Uni[By referencing the Rank value with the records in University Linked List]), then prompt choice "Which Favourited Uni would you like to view"
	/*
	       | ID            |  U0001
		   =======================================================
	[ 1 ]  | Favourited    |  Xiamen University
		   =======================================================
	[ 2 ]  |               |  APU Uni
		   =======================================================
	[ 3 ]  |               |  Tanjung Rambutan Uni
		   =======================================================
	[ 4 ]  |               |  MIT
		   =======================================================
	*/
	void printSelectedFavourite(); //Prints the single row of selected Uni using Univerisity struct

	//Append New Favourite
	void isFavourited(int rankNumber); //Adds to favourite, append userPRefRankArr array, and make counter
};
#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <cmath>
#include "Map.h"


using namespace std;

class Player {
public:
	
	bool movePlayer(char direction, Map* newMap, int score, bool* isRunning);
	bool checkMove(vector<int> playerLocation, vector< vector<char> > dungeonMap, bool* isRunning);
	//int convertPlayerPos(int playerPos);
	int getPlayerPos(Map newMap); // retrive players origin position.

	Player() {}
private:

	int playerPos = 0;
	



};








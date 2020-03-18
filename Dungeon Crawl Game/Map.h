#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <cmath>


const int mapWidth = 10;
const int mapHeight = 10;

using namespace std;

class Map {
	public:
		Map() {
			
		}

		vector<int> getPlayerLocation();
		void setPlayerLocation(int loc1, int loc2);
		void setMap(int score);
		vector< vector<char> > getMap(); //Retrives the current map state.
		
		void printMap(vector< vector<char> > dungeonMap, int score); //Handles map render.
		int getRandomNumber(int limit); //To regenerate random numbers
		void updateMap(int loc1, int loc2, char newItem);

	private:
		vector< vector<char> > dungeonMap;
		vector <char> newColumn;
		
		int treasurePos = getRandomNumber(mapHeight * mapWidth);
		vector<int> playerLocation;
		int startingPlayerLoc = getRandomNumber(mapHeight * mapWidth);





		
};








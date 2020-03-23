#include "Map.h"
#include "Player.h"


void Map::setMap(int score) {
	int counter = 0;
	int playerPos = this->startingPlayerLoc;
	for (int row = 0; row < mapHeight; row++) {
		for (int col = 0; col < mapWidth; col++) {
			//New column item
			dungeonMap.push_back(newColumn);
			int maxWidth = mapWidth;
			int maxHeight = mapHeight;

			int trapChance = getRandomNumber(10);

			if (playerPos == treasurePos) {
				treasurePos = getRandomNumber(maxWidth * maxHeight);
			}

			if (playerPos == counter) {
				dungeonMap.at(row).push_back('@'); //Place player randomly on to map.
				
				//Store player location in its own vector for easy reference.
				playerLocation.push_back(row);
				playerLocation.push_back(col);
			}
			else if (treasurePos == counter) { //When counter is equal to random treasure pos, place it.
				dungeonMap.at(row).push_back('X');
			}
			else if (trapChance < 3 && (row + 1 * col + 1) != treasurePos){
				dungeonMap.at(row).push_back('T');
			}
			else {
				dungeonMap.at(row).push_back('.'); //If nothing to spawn, just fill with dots.
			}
			counter++;
		}
	}
}

vector< vector<char> > Map::getMap() {
	return dungeonMap;
}

void Map::printMap(vector< vector<char> > dungeonMap, int score) {
	system("cls"); //Clear console before printing out map.
	for (int row = 0; row < mapHeight; row++) {
		for (int col = 0; col < mapWidth; col++) {
			//check bounds of vector.
			cout << dungeonMap.at(row).at(col); //Print the value.
			//cout << dungeonMap[row][col];
		}
		cout << endl; //To seperate the map into visual rows.
	}
	cout << "Score: " << score << endl; //Print out players score.
	Sleep(0); //Add a little latency to reduce cpu usage.
}

vector<int> Map::getPlayerLocation() { //Returns the current location of the player.
	return playerLocation;
}

void Map::setPlayerLocation(int loc1, int loc2) {
	playerLocation[0] = loc1;
	playerLocation[1] = loc2;
}

int Map::getRandomNumber(int limit) {
	int randNumber = (rand() % limit);
	return randNumber;
}

void Map::updateMap(int loc1, int loc2, char newItem) {
	dungeonMap[loc1][loc2] = newItem;
}
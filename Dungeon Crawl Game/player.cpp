#include "Player.h"
#include "Map.h"
#include <vector>


int score = 0;

int Player::getPlayerPos(Map newMap) {
	vector<int> playerLocation = newMap.getPlayerLocation();
	return (playerLocation[0] + 1 * playerLocation[1] + 1);
}


bool Player::movePlayer(char direction, Map* newMap, int score, bool* isRunning) {
	vector<int> playerLocation = newMap->getPlayerLocation();
	vector< vector<char> > dungeonMap = newMap->getMap();
	bool running = true;
	switch(direction){
		case 'a':
		{
			newMap->updateMap(playerLocation[0], playerLocation[1], '.');
			if (playerLocation[1] - 1 < 0) { //If off bounds left side
				playerLocation[1] = mapWidth - 1;
				if (checkMove(playerLocation, dungeonMap, isRunning) == true) { return true; }

			
			} else {
				playerLocation[1] = playerLocation[1] - 1;
				if (checkMove(playerLocation, dungeonMap, isRunning) == true) { return true; }


			}

			newMap->updateMap(playerLocation[0], playerLocation[1], '@');
			newMap->setPlayerLocation(playerLocation[0], playerLocation[1]);
			break;

		}
		case 'd':
		{

			newMap->updateMap(playerLocation[0], playerLocation[1], '.');
			if (playerLocation[1] + 1 > mapWidth - 1) { //If off bounds right side
				playerLocation[1] = 0;
				if (checkMove(playerLocation, dungeonMap, isRunning) == true) { return true; }


			}
			else {
				playerLocation[1] = playerLocation[1] + 1;
				if (checkMove(playerLocation, dungeonMap, isRunning) == true) { return true; }


			}

			newMap->updateMap(playerLocation[0], playerLocation[1], '@');
			newMap->setPlayerLocation(playerLocation[0], playerLocation[1]);
			break;
		}
		case 'w':
		{
			newMap->updateMap(playerLocation[0], playerLocation[1], '.');

			if (playerLocation[0] - 1 < 0) { //If off upper bounds
				playerLocation[0] = mapHeight - 1;
				if (checkMove(playerLocation, dungeonMap, isRunning) == true) { return true; }


			}
			else {
				playerLocation[0] = playerLocation[0] - 1;
				if (checkMove(playerLocation, dungeonMap, isRunning) == true) { return true; }


			}

			newMap->updateMap(playerLocation[0], playerLocation[1], '@');
			newMap->setPlayerLocation(playerLocation[0], playerLocation[1]);
			break;
		}
		case 's':
		{
			newMap->updateMap(playerLocation[0], playerLocation[1], '.');

			if (playerLocation[0] + 1 > mapHeight - 1) { //if off lower bounds
				playerLocation[0] = 0;
				if (checkMove(playerLocation, dungeonMap, isRunning) == true) { return true; }


			}
			else {
				playerLocation[0] = playerLocation[0] + 1;
				if (checkMove(playerLocation, dungeonMap, isRunning) == true) { return true; }

			}

			newMap->updateMap(playerLocation[0], playerLocation[1], '@');
			newMap->setPlayerLocation(playerLocation[0], playerLocation[1]);
			break;
		}
	}
	newMap->printMap(newMap->getMap(), score);
	
	//bool move = movePlayer(_getch(), newMap, score, isRunning);
}

bool Player::checkMove(vector<int> playerLocation, vector< vector<char> > dungeonMap, bool* isRunning) {
	switch (dungeonMap[playerLocation[0]][playerLocation[1]]) {
		case 'X':
		{
			return true;
		}
		case 'T':
		{
			*isRunning = false;
			return false;
		}
	}
}

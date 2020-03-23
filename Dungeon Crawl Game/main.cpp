//Dungeon Crawl Game, main.cpp 26/10/17
#include "Map.h"
#include "Player.h"
#include <iostream>
#include <vector>
#include "conio.h"
#include <time.h>

using namespace std;

int main() {
	srand(time(NULL));
	int score = 0;
	bool* isRunning = new bool;

	Map* newMap = new Map;
	newMap->setMap(score);

	Player newPlayer;

	*isRunning = true;
	while (*isRunning == true) {

		newMap->printMap(newMap->getMap(), score);
		if (newPlayer.movePlayer(_getch(), newMap, score, isRunning) == true) {
			newMap = new Map;
			newMap->setMap(++score);
		}
	}

	cout << "You hit a trap!";
	_getch();
	return 0;
}
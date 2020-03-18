//Dungeon Crawl Game, main.cpp 26/10/17
#include "Map.h"
#include "Player.h"
#include <iostream>
#include <vector>
#include "conio.h"
#include <time.h>

using namespace std;



int run(int score) {
	//Init the map
	Map newMap;
	Player newPlayer;
	newMap.setMap(score);
	newMap.printMap(newMap.getMap(), score);

	if (newPlayer.movePlayer(_getch(), newMap, score) == false) {
		cout << "You hit a trap!";
		_getch();
		return 0;
	} else {
		run(++score);
	}

}

int main() {
	srand(time(NULL));
	int score = 0;
	run(score);

	return 0;
}
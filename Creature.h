#ifndef CREATURE_H
#define CREATURE_H

//using namespace std;
#include "Species.h"
#include "Darwin.h"
#include <cstdlib>

class Darwin;

class Creature {
private:
	Species sp;
	int pc;
	bool moved;
	int row;
	int col;
	int dir;
	int max_row;
	int max_col;

public:
	Creature(Species, int, int, int, int, int);

	void readInstruction(Darwin*);

	void hop();

	void left();

	void right();

	void infect();

	void if_empty(Darwin*, int);

	void if_wall(Darwin*, int);

	void if_random(Darwin*, int);

	void if_enemy(Darwin*, int);

	void go(Darwin*, int);
};

#endif

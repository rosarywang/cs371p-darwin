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
	Creature();

	Creature(Species, int, int, int, int, int, int);

	int index;

	void reset_moved();

	char get_species();

	bool checkSameSpecies(Creature);

	void readInstruction(Darwin*);

	void hop(Darwin*);

	void left(Darwin*);

	void right(Darwin*);

	void infect(Darwin*);

	void if_empty(Darwin*, int);

	void if_wall(Darwin*, int);

	void if_random(Darwin*, int);

	void if_enemy(Darwin*, int);

	void go(Darwin*, int);
};

#endif

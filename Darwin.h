
#ifndef Darwin_h
#define Darwin_h

#include "Creature.h"

//using namespace std;

class Creature;

class Darwin {
	private:
		int rows;
		int cols;
		//Creature board[rows][cols] = {};
		
	public:
		Darwin(int, int);

		void addCreature(Creature&, int, int);

		// Creature infect(Creature);
};

#endif
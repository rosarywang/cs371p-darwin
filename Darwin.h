
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

		void addCreature(Creature*, int, int);

		// Creature infect(Creature);

		bool is_wall(int, int, int);
		
		bool is_empty(int, int, int);

		bool is_enemy(int, int, int);
};

#endif
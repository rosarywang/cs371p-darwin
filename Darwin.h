
#ifndef Darwin_h
#define Darwin_h

#include <vector>
#include "Creature.h"

using namespace std;

class Creature;

class Darwin {
	private:
		int rows;
		int cols;
		vector<Creature> creatures;
		vector<vector<int>> board;
		
	public:
		Darwin(int, int);

		void addCreature(Creature*, int, int);

		// Creature infect(Creature);

		bool is_wall(int, int, int);
		
		bool is_empty(int, int, int);

		bool is_enemy(Creature*, int, int, int);
};

#endif
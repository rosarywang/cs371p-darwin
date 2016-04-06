
#ifndef Darwin_h
#define Darwin_h

#include <vector>
#include <iterator>
#include "Creature.h"
#include <iostream>

using namespace std;

class Creature;

class Darwin {
	private:
		int rows;
		int cols;
		vector<Creature> creatures;
		vector<vector<int>> board;
		
	public:
		Darwin();

		Darwin(int, int);

		void add_creature(Creature&, int, int);

		vector<vector<int>>::iterator begin();

		vector<vector<int>>::iterator end();
		
		const Creature& at(int, int);

		// Creature infect(Creature&);

		bool is_wall(int, int, int);
		
		bool is_empty(int, int, int);

		bool is_enemy(Creature&, int, int, int);

		void update_board(Creature&, int, int, int, int);

		void play();

		void print_board(int);
};

#endif
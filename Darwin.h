
#ifndef Darwin_h
#define Darwin_h

#include <vector>
#include <iterator>
#include "Creature.h"
#include <iostream>
#include "gtest/gtest.h"

using namespace std;

class Creature;

class Darwin {
	private:
		friend class DarwinTest;
		FRIEND_TEST(DarwinTest, add_creature_1);
		FRIEND_TEST(DarwinTest, add_creature_2);
		FRIEND_TEST(DarwinTest, add_creature_3);
		FRIEND_TEST(DarwinTest, parameters_1);
		FRIEND_TEST(DarwinTest, parameters_2);
		FRIEND_TEST(DarwinTest, parameters_3);
		FRIEND_TEST(DarwinTest, begin_1);
		FRIEND_TEST(DarwinTest, end_1);
		FRIEND_TEST(DarwinTest, at_1);
		FRIEND_TEST(DarwinTest, at_2);
		FRIEND_TEST(DarwinTest, at_3);
		FRIEND_TEST(DarwinTest, play_1);
		FRIEND_TEST(DarwinTest, play_2);
		FRIEND_TEST(DarwinTest, play_3);
		FRIEND_TEST(DarwinTest, update_board_1);
		FRIEND_TEST(DarwinTest, update_board_2);
		FRIEND_TEST(DarwinTest, update_board_3);
		FRIEND_TEST(DarwinCreature, hop_1);
		FRIEND_TEST(DarwinCreature, hop_2);
		FRIEND_TEST(DarwinCreature, hop_3);
		FRIEND_TEST(DarwinCreature, infect_2);
		FRIEND_TEST(DarwinCreature, infect_3);


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

		bool is_wall(int, int, int);
		
		bool is_empty(int, int, int);

		bool is_enemy(Creature&, int, int, int);

		Creature& get_enemy(Creature&, int, int, int);

		void update_board(Creature&, int, int, int, int);

		void play();

		void print_board(ostream&, int);
};

#endif
#ifndef CREATURE_H
#define CREATURE_H

using namespace std;
#include "Species.h"
#include "Darwin.h"
#include "gtest/gtest.h"
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
	int index;

public:
	friend class DarwinCreature;
	FRIEND_TEST(DarwinCreature, creature_default_1);
	FRIEND_TEST(DarwinCreature, creature_default_2);
	FRIEND_TEST(DarwinCreature, creature_default_3);
	FRIEND_TEST(DarwinCreature, creature_parameters_1);
	FRIEND_TEST(DarwinCreature, creature_parameters_2);
	FRIEND_TEST(DarwinCreature, creature_parameters_3);
	FRIEND_TEST(DarwinCreature, reset_moved_1);
	FRIEND_TEST(DarwinCreature, reset_moved_2);
	FRIEND_TEST(DarwinCreature, reset_moved_3);
	FRIEND_TEST(DarwinCreature, read_instruction_1);
	FRIEND_TEST(DarwinCreature, read_instruction_2);
	FRIEND_TEST(DarwinCreature, read_instruction_3);
	FRIEND_TEST(DarwinCreature, left_1);
	FRIEND_TEST(DarwinCreature, left_2);
	FRIEND_TEST(DarwinCreature, left_3);
	FRIEND_TEST(DarwinCreature, right_1);
	FRIEND_TEST(DarwinCreature, right_2);
	FRIEND_TEST(DarwinCreature, right_3);
	FRIEND_TEST(DarwinCreature, infect_1);
	FRIEND_TEST(DarwinCreature, infect_2);
	FRIEND_TEST(DarwinCreature, if_empty_1);
	FRIEND_TEST(DarwinCreature, if_empty_2);
	FRIEND_TEST(DarwinCreature, if_empty_3);
	FRIEND_TEST(DarwinCreature, if_wall_1);
	FRIEND_TEST(DarwinCreature, if_wall_2);
	FRIEND_TEST(DarwinCreature, if_wall_3);
	FRIEND_TEST(DarwinCreature, if_random_1);
	FRIEND_TEST(DarwinCreature, if_random_2);
	FRIEND_TEST(DarwinCreature, if_random_3);
	FRIEND_TEST(DarwinCreature, if_enemy_1);
	FRIEND_TEST(DarwinCreature, if_enemy_2);
	FRIEND_TEST(DarwinCreature, if_enemy_3);
	FRIEND_TEST(DarwinCreature, go_1);
	FRIEND_TEST(DarwinCreature, go_2);
	FRIEND_TEST(DarwinCreature, go_3);
	FRIEND_TEST(DarwinTest, at_1);
	FRIEND_TEST(DarwinTest, play_1);


	Creature();

	Creature(Species, int, int, int, int, int, int);

	int get_index();

	char get_species();

	bool check_same_species(Creature);

	void reset_moved();

	void read_instruction(Darwin*);

	void hop(Darwin*);

	void left();

	void right();

	void infect(Darwin*);

	void if_empty(Darwin*, int);

	void if_wall(Darwin*, int);

	void if_random(Darwin*, int);

	void if_enemy(Darwin*, int);

	void go(Darwin*, int);
};

#endif

#ifndef CREATURE_H
#define CREATURE_H

using namespace std;
#include "Species.h"
#include "Darwin.h"
#include "gtest/gtest.h"
#include <cstdlib>

class Darwin;

// --------
// Creature
// --------

class Creature {
private:

	// -----------
	// FRIEND_TEST
	// -----------

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
	FRIEND_TEST(DarwinTest, at_3);
	FRIEND_TEST(DarwinTest, play_1);


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
	// ------------
    // constructors
    // ------------

    /**
     * Default Constructor
     * initialize moved to true and index to -1
     */
	Creature();

	/**
     * Regular Constructor
     * create a Creature object
     * @param sp a Species
     * @param int row
     * @param int col
     * @param int dir
     * @param int max_row
     * @param int max_col
     * @param int index
     */
	Creature(Species, int, int, int, int, int, int);

	// ---------
	// get_index
	// ---------

	/**
	* @return int index of this creature in creatures vector
	*/
	int get_index();

	// -----------
	// get_species
	// -----------

	/**
	* @return char initial of this creature's species
	*/
	char get_species();

	// ------------------
	// check_same_species
	// ------------------

	/**
	* check if this and given creature have same Species
	* @param c a Creature
	* @return boolean for equality of Species
	*/
	bool check_same_species(Creature);

	// -----------
	// reset_moved
	// -----------

	/**
	* reset all existing creature's moved to false
	*/
	void reset_moved();

	// ----------------
	// read_instruction
	// ----------------

	/**
	* read next instruction for creature from its species's instructions set
	* @param darwin a Darwin instance
	*/
	void read_instruction(Darwin*);

	// ---
	// hop
	// ---

	/**
	* perform hop
	* if the space ahead is empty, move forward, otherwise, do nothing
	* @param darwin a Darwin instance
	*/
	void hop(Darwin*);

	// ----
	// left
	// ----

	/**
	* perform left
	* turn to face left
	*/
	void left();

	// -----
	// right
	// -----

	/**
	* perform right
	* turn to face right
	*/
	void right();

	// ------
	// infect
	// ------

	/**
	* perform infect
	* if the space ahead contains a creature of a different species, 
	* change that creature to be of your species, reset the program counter to zero, 
	* but leave the direction unchanged, otherwise, do nothing
	* @param darwin a Darwin instance
	*/
	void infect(Darwin*);

	// --------
	// if_empty
	// --------

	/**
	* perform if_empty
	* if the space ahead is empty, go to line n, otherwise, go to the next line
	* @param darwin a Darwin instance
	* @param n an int
	*/
	void if_empty(Darwin*, int);

	// -------
	// if_wall
	// -------

	/**
	* perform if_wall
	* if the space ahead is a wall, go to line n, otherwise, go to the next line
	* @param darwin a Darwin instance
	* @param n an int
	*/
	void if_wall(Darwin*, int);

	// ---------
	// if_random
	// ---------

	/**
	* perform if_wall
	* randomly choose between going to line n or the next line. 
	* If rand() from <cstdlib> returns an odd number, go to line n. 
	* Call srand(0) at the start of every test case that uses rand()
	* @param darwin a Darwin instance
	* @param n an int
	*/
	void if_random(Darwin*, int);

	// --------
	// if_enemy
	// --------

	/**
	* perform if_enemy
	* if the space ahead contains a creature of a different species, go to line n, otherwise, go to the next line
	* @param darwin a Darwin instance
	* @param n an int
	*/
	void if_enemy(Darwin*, int);

	// --
	// go
	// --

	/**
	* perform go
	* go to line n
	* @param darwin a Darwin instance
	* @param n an int
	*/
	void go(Darwin*, int);
};

#endif

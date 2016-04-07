#ifndef Darwin_h
#define Darwin_h

// --------
// includes
// --------

#include <vector>
#include <iterator>
#include "Creature.h"
#include <iostream>
#include <stdexcept>
#include "gtest/gtest.h"

using namespace std;

class Creature;

// ------
// Darwin
// ------

class Darwin {
	private:
		// -----------
		// FRIEND_TEST
		// -----------

		friend class DarwinTest;
		FRIEND_TEST(DarwinTest, add_creature_1);
		FRIEND_TEST(DarwinTest, add_creature_2);
		FRIEND_TEST(DarwinTest, add_creature_3);
		FRIEND_TEST(DarwinTest, parameters_1);
		FRIEND_TEST(DarwinTest, parameters_2);
		FRIEND_TEST(DarwinTest, parameters_3);
		FRIEND_TEST(DarwinTest, begin_1);
		FRIEND_TEST(DarwinTest, begin_2);
		FRIEND_TEST(DarwinTest, end_1);
		FRIEND_TEST(DarwinTest, end_2);
		FRIEND_TEST(DarwinTest, at_1);
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
		// ------------
		// constructors
		// ------------

		/** Default Constructor
		*/

		Darwin();

		/** 
		* Creates an instance of Darwin
		* @param int row
		* @param int column
		*/

		Darwin(int, int);

		// ------------
		// add_creature
		// ------------

		/**
		* add a creature to the boad
		* @param creature a Creature
		* @param row an int	
		* @param column an int
		*/

		void add_creature(Creature&, int, int);

		// -----
		// begin
		// -----

		/**
		* @return an iterator to the beginning of the board
		*/

		vector<vector<int>>::iterator begin();

		// ---
		// end
		// ---

		/**
		* @return an iterator to the end of the board
		*/

		vector<vector<int>>::iterator end();

		// --
		// at
		// --

		/**
		* find the creature at the given position
		* @param int row
		* @param int column
		* @return a creature at the given position or out of range exception
		*/
		
		const Creature& at(int, int);

		// -------
		// is_wall
		// -------

		/**
		* check if you're at the edge of the board
		* @param int row
		* @param int column
		* @param int direction
		* @return true if there is a wall in given location
		*/

		bool is_wall(int, int, int);

		// --------
		// is_empty
		// --------

		/**
		* check if there is an empty space at given loaction
		* @param int row
		* @param int column
		* @param int direction
		* @return true if the given location is an empty space
		*/
		
		bool is_empty(int, int, int);

		// --------
		// is_enemy
		// --------

		/**
		* check if there is an enemy at given location
		* @param int row
		* @param int column
		* @param int direction
		* @return true if there is an enemy in given location
		*/

		bool is_enemy(Creature&, int, int, int);

		// ---------
		// get_enemy
		// ---------

		/**
		* get the enemy creature that's in the given location
		* @param Creature creature
		* @param int row
		* @param int column
		* @param int direction
		* @return the Creature in the given location
		*/

		Creature& get_enemy(Creature&, int, int, int);

		// ------------
		// update_board
		// ------------

		/**
		* updates the creature's movements on the board
		* @param Creature creature
		* @param int old row
		* @param int old column
		* @param int new row
		* @param int new column
		*/

		void update_board(Creature&, int, int, int, int);

		// ----
		// play
		// ----

		/**
		* reads the instructions and plays Darwin
		*/

		void play();

		// -------
		// is_wall
		// -------

		/**
		* prints the board at each specified turn
		* @param ostream w
		* @param int turn
		*/

		void print_board(ostream&, int);
};

#endif
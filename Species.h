#ifndef Species_h
#define Species_h
#include "gtest/gtest.h"
#include <cassert>   // assert

using namespace std;

// -------
// Species
// -------

class Species {
private:

	// -----------
	// FRIEND_TEST
	// -----------

	friend class DarwinSpecies;
	FRIEND_TEST(DarwinSpecies, species_default_1);
	FRIEND_TEST(DarwinSpecies, species_default_2);
	FRIEND_TEST(DarwinSpecies, species_default_3);
	FRIEND_TEST(DarwinSpecies, species_copy_1);
	FRIEND_TEST(DarwinSpecies, species_copy_2);
	FRIEND_TEST(DarwinSpecies, species_copy_3);
	FRIEND_TEST(DarwinSpecies, get_initial_1);
	FRIEND_TEST(DarwinSpecies, get_initial_2);
	FRIEND_TEST(DarwinSpecies, get_initial_3);
	FRIEND_TEST(DarwinSpecies, add_instruction_1);
	FRIEND_TEST(DarwinSpecies, add_instruction_2);
	FRIEND_TEST(DarwinSpecies, add_instruction_3);
	FRIEND_TEST(DarwinTest, at_1);
	FRIEND_TEST(DarwinTest, at_3);

	// ----
	// data
	// ----

	int instructions[15];
	int index;
	char initial;

public:

	// ------------
    // constructors
    // ------------

    /**
     * Default Constructor
     * initialize index and initial
     * if no argument is provided, default initial to '\0'
     */
	Species(char c = '\0'){
		this->index = 0;
		this->initial = c;
	}

	 /**
     * Copy Constructor
     * copy the initial and instructions from given Species
     */
	Species(const Species& s){
		this->initial = s.initial;
		for (int i = 0; i < 15; ++i)
			this->instructions[i] = s.instructions[i];
	}

	// ---------
	// operators
	// ---------

	/**
     * == operator
     * checks the equlity of initials between this and given Species
     * @param s a Species
 	 * @return bool, equality of initials
     */
	bool operator == (Species s) {
		return this->initial == s.initial;
	}

	/**
     * [] operator
     * return 
     * @param pc a int
 	 * @return int, the instruction from Species instructions
     */
	int operator [] (int pc) {
		assert(pc >= 0);
		assert(pc < 15);
		return this->instructions[pc];
	}

	// -----------
	// get_initial
	// -----------

	/** 
 	 * @return char, the initial of this Species
     */
	char get_initial(){
		return this->initial;
	}

	// ---------------
	// add_instruction
	// ---------------

	/** 
	 * instructions are defined as
	 * instruction valueStored
	 * hop 0
	 * left 1
	 * right 2
	 * infect 3
	 * if_empty 4
	 * if_wall 5
	 * if_random 6
	 * if_enemy 7
	 * go 8
	 * @param instruction int, n int
     */
	void add_instruction(int instruction, int n){
		assert(instruction >= 0);
		assert(instruction < 9);
		assert(n >= 0);
		assert(n < 15);
		if (instruction > 3) {
			this->instructions[index] = instruction+n*10;
		} else {
			this->instructions[index] = instruction;
		}
		++this->index;
	}

};

#endif
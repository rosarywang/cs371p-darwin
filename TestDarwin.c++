// --------
// includes
// --------

#include <iostream> // cout, endl

#include "gtest/gtest.h"

#include "Species.h"
#include "Creature.h"
#include "Darwin.h"

using namespace std;

// ----------
// TestDarwin
// ----------

// -------
// Species
// -------

// -----------
// get_initial
//------------

TEST(DarwinSpecies, get_initial_1) {
    Species s = Species('a');
    char c = s.get_initial();
    ASSERT_EQ('a', c);
}

TEST(DarwinSpecies, get_initial_2) {
    Species s = Species('X');
    char c = s.get_initial();
    ASSERT_EQ('X', c);
}

TEST(DarwinSpecies, get_initial_3) {
    Species s = Species('j');
    char c = s.get_initial();
    ASSERT_EQ('j', c);
}

// -----------
// operator ==
//------------

TEST(DarwinSpecies, operator_equal_1) {
    Species s1 = Species('a');
    Species s2 = Species('a');
    ASSERT_TRUE(s1==s2);
}

TEST(DarwinSpecies, operator_equal_2) {
    Species s1 = Species('x');
    Species s2 = Species('a');
    ASSERT_FALSE(s1==s2);
}

TEST(DarwinSpecies, operator_equal_3) {
    Species s1 = Species('b');
    Species s2 = Species('a');
    ASSERT_FALSE(s1==s2);
}

// -----------
// operator []
//------------

TEST(DarwinSpecies, operator_index_1) {
    Species s = Species('a');
    s.add_instruction(0, 0);
    ASSERT_EQ(s[0], 0);
}

TEST(DarwinSpecies, operator_index_2) {
    Species s = Species('a');
    s.add_instruction(7, 9);
    s.add_instruction(4, 7);
    s.add_instruction(6, 5);
    s.add_instruction(1, 0);
    s.add_instruction(8, 0);
    ASSERT_EQ(s[0], 97);
    ASSERT_EQ(s[1], 74);
    ASSERT_EQ(s[2], 56);
    ASSERT_EQ(s[3], 1);
    ASSERT_EQ(s[4], 8);
}

TEST(DarwinSpecies, operator_index_3) {
    Species s = Species('j');
    s.add_instruction(2, 0);
    s.add_instruction(8, 0);
    s.add_instruction(0, 0);
    s.add_instruction(8, 0);
    s.add_instruction(3, 0);
    ASSERT_EQ(s[0], 2);
    ASSERT_EQ(s[1], 8);
    ASSERT_EQ(s[2], 0);
    ASSERT_EQ(s[3], 8);
    ASSERT_EQ(s[4], 3);
}


// ---------------
// add_instruction
//----------------

TEST(DarwinSpecies, add_instruction_1) {
    Species s = Species('a');
    s.add_instruction(0, 0);
    ASSERT_EQ(s[0], 0);
}

TEST(DarwinSpecies, add_instruction_2) {
    Species s = Species('a');
    s.add_instruction(7, 9);
    ASSERT_EQ(s[0], 97);
}

TEST(DarwinSpecies, add_instruction_3) {
    Species s = Species('a');
    s.add_instruction(8, 0);
    ASSERT_EQ(s[0], 8);
}

// --------
// Creature
// --------

// ---------
// get_index
// ---------

TEST(DarwinCreature, get_index_1) {
    Species food = Species('f');
    food.add_instruction(1, 0);
    food.add_instruction(8, 0);
    Creature f1 = Creature(food, 0, 0, 1, 8, 8, 0);
    ASSERT_EQ(f1.get_index(), 0);
}

TEST(DarwinCreature, get_index_2) {
    Species food = Species('b');
    Creature f1 = Creature(food, 7, 7, 0, 3, 3, 1);
    ASSERT_EQ(f1.get_index(), 1);
}

TEST(DarwinCreature, get_index_3) {
    Species food = Species('z');
    Creature f1 = Creature(food, 5, 3, 2, 5, 2, 3);
    ASSERT_EQ(f1.get_index(), 3);
}

// -----------
// get_species
// -----------

TEST(DarwinCreature, get_species_1) {
    Species food = Species('f');
    food.add_instruction(1, 0);
    food.add_instruction(8, 0);
    Creature f1 = Creature(food, 0, 0, 1, 8, 8, 0);
    ASSERT_EQ(f1.get_species(), 'f');
}

TEST(DarwinCreature, get_species_2) {
    Species food = Species('b');
    Creature f1 = Creature(food, 7, 7, 0, 3, 3, 1);
    ASSERT_EQ(f1.get_species(), 'b');
}

TEST(DarwinCreature, get_species_3) {
    Species food = Species('z');
    Creature f1 = Creature(food, 5, 3, 2, 5, 2, 3);
    ASSERT_EQ(f1.get_species(), 'z');
}

// ------------------
// check_same_species
// ------------------

TEST(DarwinCreature, check_same_species_1) {
    Species food = Species('f');
    food.add_instruction(1, 0);
    food.add_instruction(8, 0);
    Creature f1 = Creature(food, 0, 0, 1, 8, 8, 0);
    Creature f2 = Creature(food, 7, 7, 0, 3, 3, 1);
    ASSERT_TRUE(f1.check_same_species(f2));
}

TEST(DarwinCreature, check_same_species_2) {
    Species food = Species('b');
    Species hooper = Species('h');
    Creature f1 = Creature(food, 7, 7, 0, 3, 3, 1);
    Creature f2 = Creature(hooper, 0, 0, 1, 8, 8, 0);
    ASSERT_FALSE(f1.check_same_species(f2));
}

TEST(DarwinCreature, check_same_species_3) {
    Species food = Species('z');
    Creature f1 = Creature(food, 5, 3, 2, 5, 2, 3);
    Creature f2 = Creature(food, 0, 0, 1, 8, 8, 0);
    ASSERT_TRUE(f1.check_same_species(f2));
}

// -----------
// reset_moved
// -----------

TEST(CreatureTest, reset_moved_1) {
    Darwin darwin = Darwin(5,5);
    Darwin* d = &darwin;
    Species food = Species('f');
    food.add_instruction(1, 0);
    food.add_instruction(8, 0);
    Creature f1 = Creature(food, 0, 0, 1, 8, 8, 0);
    darwin.add_creature(f1, 0, 0);
    f1.read_instruction(d);
    ASSERT_TRUE(f1.moved);
    f1.reset_moved();
    ASSERT_FALSE(f1.moved);
}

TEST(CreatureTest, reset_moved_2) {
    Darwin darwin = Darwin(10,5);
    Darwin* d = &darwin;
    Species food = Species('f');
    food.add_instruction(1, 0);
    food.add_instruction(8, 0);
    Creature f1 = Creature(food, 0, 0, 1, 8, 8, 0);
    Creature f2 = Creature(food, 1, 1, 2, 8, 8, 1);
    darwin.add_creature(f1, 0, 0);
    darwin.add_creature(f1, 1, 1);
    f1.read_instruction(d);
    f2.read_instruction(d);
    ASSERT_TRUE(f1.moved);
    ASSERT_TRUE(f2.moved);
    f2.reset_moved();
    ASSERT_TRUE(f1.moved);
    ASSERT_FALSE(f2.moved);
}

TEST(CreatureTest, reset_moved_3) {
    Creature f1 = Creature();
    ASSERT_TRUE(f1.moved);
    f1.reset_moved();
    ASSERT_TRUE(f1.moved);
}

// ----------------
// read_instruction
// ----------------

// ---
// hop
// ---

TEST(DarwinCreature, hop_1) {
	Species hopper = Species('h');
	hopper.add_instruction(0, 0);
    hopper.add_instruction(8, 0);

    Creature hop = Creature(hopper, 2, 2, 1, 7, 7, 0);

    Darwin darwin = Darwin(7, 7);
    Darwin* d = &darwin;
    darwin.add_creature(hop, 2, 2);
    hop.read_instruction(d);
    ASSERT_EQ(darwin.board[1][2], 0);
}

TEST(DarwinCreature, hop_2) {
	Species hopper = Species('h');
	hopper.add_instruction(0, 0);
    hopper.add_instruction(8, 0);

    Creature hop = Creature(hopper, 0, 0, 0, 7, 9, 0);
    Creature hop2 = Creature(hopper, 4, 5, 3, 7, 9, 1);
    Creature hop3 = Creature(hopper, 6, 3, 2, 7, 9, 2);

    Darwin darwin = Darwin(7, 9);
    Darwin* d = &darwin;
    darwin.add_creature(hop, 0, 0);
    darwin.add_creature(hop2, 4, 5);
    darwin.add_creature(hop3, 6, 3);
    hop.read_instruction(d);
    ASSERT_EQ(darwin.board[0][0], 0);
    hop2.read_instruction(d);
    ASSERT_EQ(darwin.board[5][5], 1);
    hop3.read_instruction(d);
    ASSERT_EQ(darwin.board[6][4], 2);
}

TEST(DarwinCreature, hop_3) {
	Species hopper = Species('h');
	hopper.add_instruction(0, 0);
    hopper.add_instruction(8, 0);

    Creature hop = Creature(hopper, 1, 2, 0, 6, 4, 0);
    Creature hop2 = Creature(hopper, 4, 0, 3, 6, 4, 1);
    Creature hop3 = Creature(hopper, 5, 3, 2, 6, 4, 2);
    Creature hop4 = Creature(hopper, 2, 2, 1, 6, 4, 3);

    Darwin darwin = Darwin(6, 4);
    Darwin* d = &darwin;
    darwin.add_creature(hop, 1, 2);
    darwin.add_creature(hop2, 4, 0);
    darwin.add_creature(hop3, 5, 3);
    darwin.add_creature(hop4, 2, 2);
    hop.read_instruction(d);
    ASSERT_EQ(darwin.board[1][1], 0);
    hop2.read_instruction(d);
    ASSERT_EQ(darwin.board[5][0], 1);
    hop3.read_instruction(d);
    ASSERT_EQ(darwin.board[5][3], 2);
    hop4.read_instruction(d);
    ASSERT_EQ(darwin.board[1][2], 3);
}

// ----
// left
// ----


// -----
// right
// -----

// ------
// infect
// ------

// --------
// if empty
// --------

// -------
// if_wall
// -------

// ---------
// if_random
// ---------

// --------
// if_enemy
// --------

// --
// go
// --




// ------
// Darwin
// ------

// ------------
// add_creature
// ------------

TEST(DarwinTest, add_creature_1) {
    Species food = Species('f');

    Creature f1 = Creature(food, 0, 0, 1, 8, 8, 0);
    Creature f2 = Creature(food, 7, 7, 0, 8, 8, 1);

    Darwin darwin = Darwin(8, 8);
    darwin.add_creature(f1, 0, 0);
    darwin.add_creature(f2, 7, 7);
    ASSERT_EQ(darwin.board[0][0] , 0);
    ASSERT_EQ(darwin.board[7][7] , 1);
}

TEST(DarwinTest, add_creature_2) {
    Species hopper = Species('h');

    Creature h1 = Creature(hopper, 1, 1, 1, 8, 8, 0);
    Creature h2 = Creature(hopper, 5, 3, 0, 8, 8, 1);

    Darwin darwin = Darwin(8, 8);
    darwin.add_creature(h1, 1, 1);
    darwin.add_creature(h2, 5, 3);
    ASSERT_EQ(darwin.board[1][1] , 0);
    ASSERT_EQ(darwin.board[5][3] , 1);
}

TEST(DarwinTest, add_creature_3) {
	Species hopper = Species('h');
   	Species trap = Species('t');
    Species rover = Species('r');

    Creature t1 = Creature(trap, 0, 0, 2, 7, 9, 0);
    Creature h1 = Creature(hopper, 3, 2, 1, 7, 9, 1);
    Creature r1 = Creature(rover, 5, 4, 0, 7, 9, 2);
    Creature t2 = Creature(trap, 6, 8, 3, 7, 9, 3);

    Darwin darwin = Darwin(7, 9);
    darwin.add_creature(t1, 0, 0);
    darwin.add_creature(h1, 3, 2);
    darwin.add_creature(r1, 5, 4);
    darwin.add_creature(t2, 6, 8);
    ASSERT_EQ(darwin.board[0][0] , 0);
    ASSERT_EQ(darwin.board[3][2] , 1);
    ASSERT_EQ(darwin.board[5][4] , 2);
    ASSERT_EQ(darwin.board[6][8] , 3);
}

// -----
// begin
// -----

// TEST(DarwinTest, begin_1) {

// }

// ---
// end
// ---

// --
// at
// --

// -------
// is_wall
// -------

TEST(DarwinTest, is_wall_1) {
	Darwin darwin = Darwin(2, 2);
	ASSERT_TRUE(darwin.is_wall(0, 1, 1));
}

TEST(DarwinTest, is_wall_2) {
	Darwin darwin = Darwin(4, 4);
	ASSERT_FALSE(darwin.is_wall(2, 1, 2));
	ASSERT_TRUE(darwin.is_wall(3, 2, 3));
}

TEST(DarwinTest, is_wall_3) {
	Darwin darwin = Darwin(7, 7);
	ASSERT_TRUE(darwin.is_wall(0, 4, 1));
	ASSERT_TRUE(darwin.is_wall(4, 6, 2));
	ASSERT_TRUE(darwin.is_wall(6, 2, 3));
	ASSERT_TRUE(darwin.is_wall(5, 0, 0));

}
// --------
// is_empty
// --------

// --------
// is_enemy
// --------

// ---------
// get_enemy
// ---------

// ------------
// update_board
// ------------

// ----
// play
// ----

// -----------
// print_board
// -----------

TEST(DarwinTest, print_1) {
Species food = Species('f');

Creature f1 = Creature(food, 0, 0, 0, 2, 2, 0);
Creature f2 = Creature(food, 1, 1, 0, 2, 2, 1);
Darwin darwin = Darwin(2, 2);
darwin.add_creature(f1, 0, 0);
darwin.add_creature(f2, 1, 1);

ostringstream w;
darwin.print_board(w, 0);

ASSERT_EQ("Turn = 0.\n  01\n0 f.\n1 .f\n\n", w.str());

}

TEST(DarwinTest, print_2) {
Species food = Species('f');
Species hopper = Species('h');
Species rover = Species('r');

Creature f1 = Creature(food, 2, 1, 0, 4, 4, 0);
Creature f2 = Creature(food, 3, 0, 0, 4, 4, 1);
Creature h1 = Creature(hopper, 1, 1, 0, 4, 4, 1);
Creature h2 = Creature(hopper, 0, 3, 0, 4, 4, 1);
Creature r1 = Creature(rover, 2, 2, 0, 4, 4, 1);
Creature r2 = Creature(rover, 1, 0, 0, 4, 4, 1);

Darwin darwin = Darwin(4, 4);
darwin.add_creature(f1, 2, 1);
darwin.add_creature(f2, 3, 0);
darwin.add_creature(h1, 1, 1);
darwin.add_creature(h2, 0, 3);
darwin.add_creature(r1, 2, 2);
darwin.add_creature(r2, 1, 0);

ostringstream w;
darwin.print_board(w, 0);

ASSERT_EQ("Turn = 0.\n  0123\n0 ...r\n1 rr..\n2 .fr.\n3 r...\n\n", w.str());
}

TEST(DarwinTest, print_3) {
	Species food = Species('f');
	Species hopper = Species('h');
	Species rover = Species('r');
	Species trap = Species('t');

	Creature f1 = Creature(food, 2, 1, 0, 6, 6, 0);
	Creature f2 = Creature(food, 4, 0, 0, 6, 6, 1);
	Creature h1 = Creature(hopper, 3, 3, 0, 6, 6, 1);
	Creature h2 = Creature(hopper, 1, 5, 0, 6, 6, 1);
	Creature r1 = Creature(rover, 5, 5, 0, 6, 6, 1);
	Creature r2 = Creature(rover, 3, 2, 0, 6, 6, 1);
	Creature t1 = Creature(trap, 1, 4, 0, 6, 6, 1);
	Creature t2 = Creature(trap, 4, 3, 0, 6, 6, 1);
	Creature t3 = Creature(trap, 2, 0, 0, 6, 6, 1);
	Creature t4 = Creature(trap, 1, 1, 0, 6, 6, 1);

	Darwin darwin = Darwin(6, 6);
	darwin.add_creature(f1, 2, 1);
	darwin.add_creature(f2, 4, 0);
	darwin.add_creature(h1, 3, 3);
	darwin.add_creature(h2, 1, 5);
	darwin.add_creature(r1, 5, 5);
	darwin.add_creature(r2, 3, 2);
	darwin.add_creature(t1, 1, 4);
	darwin.add_creature(t2, 4, 3);
	darwin.add_creature(t3, 2, 0);
	darwin.add_creature(t4, 1, 1);

	ostringstream w;
	darwin.print_board(w, 0);

	ASSERT_EQ("Turn = 0.\n  012345\n0 ......\n1 .t..tt\n2 tf....\n3 ..tt..\n4 t..t..\n5 .....t\n\n", w.str());
}



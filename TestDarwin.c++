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

// TEST(DarwinCreature, reset_moved_1) {
//     Darwin d = Darwin(5,5);
//     Species food = Species('f');
//     food.add_instruction(1, 0);
//     food.add_instruction(8, 0);
//     Creature f1 = Creature(food, 0, 0, 1, 8, 8, 0);
//     f1.read_instruction(*d);
//     ASSERT_TRUE(f1.moved);
//     f1.reset_moved();
//     ASSERT_FALSE(f1.moved);
// }

// ----------------
// read_instruction
// ----------------

// ---
// hop
// ---

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
    food.add_instruction(1, 0);
    food.add_instruction(8, 0);

    Creature f1 = Creature(food, 0, 0, 1, 8, 8, 0);
    Creature f2 = Creature(food, 7, 7, 0, 8, 8, 1);

    Darwin darwin = Darwin(8, 8);
    darwin.add_creature(f1, 0, 0);
    darwin.add_creature(f2, 7, 7);
    ASSERT_EQ(darwin.board[0][0] , 0);
    ASSERT_EQ(darwin.board[7][7] , 1);
}

// -----
// begin
// -----

// ---
// end
// ---

// --
// at
// --

// -------
// is_wall
// -------

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
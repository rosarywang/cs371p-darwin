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

// -------------
// Species(char)
// -------------

TEST(DarwinSpecies, species_default_1) {
    Species s = Species();
    ASSERT_EQ('\0', s.initial);
}

TEST(DarwinSpecies, species_default_2) {
    Species s = Species('c');
    ASSERT_EQ('c', s.initial);
}

TEST(DarwinSpecies, species_default_3) {
    Species s = Species('c');
    ASSERT_EQ(0, s.index);
}

// -----------------------
// Species(const Species&)
// -----------------------

TEST(DarwinSpecies, species_copy_1) {
    Species s = Species('s');
    Species c = Species('c');
    s = Species(c);
    ASSERT_EQ('c', s.initial);
}

TEST(DarwinSpecies, species_copy_2) {
    Species s = Species();
    Species c = Species('c');
    s = Species(c);
    ASSERT_EQ('c', s.initial);
}

TEST(DarwinSpecies, species_copy_3) {
    Species s = Species('s');
    s.instructions[0] = 1;
    Species c = Species('c');
    c.instructions[0] = 2;
    s = Species(c);
    ASSERT_EQ('c', s.initial);
    ASSERT_EQ(2, s.instructions[0]);
}

// -----------
// get_initial
//------------

TEST(DarwinSpecies, get_initial_1) {
    Species s = Species('a');
    ASSERT_EQ('a', s.initial);
}

TEST(DarwinSpecies, get_initial_2) {
    Species s = Species('X');
    ASSERT_EQ('X', s.initial);
}

TEST(DarwinSpecies, get_initial_3) {
    Species s = Species('j');
    ASSERT_EQ('j', s.initial);
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
    s.add_instruction(3, 0);
    s.add_instruction(8, 0);
    ASSERT_EQ(s.instructions[0], 0);
    ASSERT_EQ(s.instructions[1], 3);
    ASSERT_EQ(s.instructions[2], 8);
}

TEST(DarwinSpecies, add_instruction_2) {
    Species s = Species('a');
    s.add_instruction(7, 9);
    s.add_instruction(5, 11);
    s.add_instruction(3, 0);
    s.add_instruction(8, 10);
    ASSERT_EQ(s.instructions[0], 97);
    ASSERT_EQ(s.instructions[1], 115);
    ASSERT_EQ(s.instructions[2], 3);
    ASSERT_EQ(s.instructions[3], 108);
}

TEST(DarwinSpecies, add_instruction_3) {
    Species s = Species('a');
    s.add_instruction(3, 0);
    s.add_instruction(7, 3);
    s.add_instruction(8, 0);
    ASSERT_EQ(s.instructions[0], 3);
    ASSERT_EQ(s.instructions[1], 37);
    ASSERT_EQ(s.instructions[2], 8);
}

// --------
// Creature
// --------

// ----------
// Creature()
// ----------

TEST(DarwinCreature, creature_default_1) {
    Creature c = Creature();
    ASSERT_TRUE(c.moved);
}

TEST(DarwinCreature, creature_default_2) {
    Creature c = Creature();
    ASSERT_EQ(-1, c.index);
}

TEST(DarwinCreature, creature_default_3) {
    Creature x = Creature();
    ASSERT_TRUE(x.moved);
    ASSERT_EQ(-1, x.index);
}

// --------------------
// Creature(parameters)
// --------------------

TEST(DarwinCreature, creature_parameters_1) {
    Species s = Species();
    Creature c = Creature(s, 0, 0, 0, 3, 5, 0);
    ASSERT_EQ(0, c.row);
    ASSERT_EQ(0, c.col);
    ASSERT_EQ(0, c.dir);
    ASSERT_EQ(0, c.pc);
    ASSERT_FALSE(c.moved);
    ASSERT_EQ(3, c.max_row);
    ASSERT_EQ(5, c.max_col);
    ASSERT_EQ(0, c.index);
}

TEST(DarwinCreature, creature_parameters_2) {
    Species s = Species();
    Creature c = Creature(s, 1, 2, 3, 3, 5, 1);
    ASSERT_EQ(1, c.row);
    ASSERT_EQ(2, c.col);
    ASSERT_EQ(3, c.dir);
    ASSERT_EQ(0, c.pc);
    ASSERT_FALSE(c.moved);
    ASSERT_EQ(3, c.max_row);
    ASSERT_EQ(5, c.max_col);
    ASSERT_EQ(1, c.index);
}

TEST(DarwinCreature, creature_parameters_3) {
    Species s = Species();
    Creature c = Creature(s, 2, 4, 2, 3, 5, 0);
    ASSERT_EQ(2, c.row);
    ASSERT_EQ(4, c.col);
    ASSERT_EQ(2, c.dir);
    ASSERT_EQ(0, c.pc);
    ASSERT_FALSE(c.moved);
    ASSERT_EQ(3, c.max_row);
    ASSERT_EQ(5, c.max_col);
    ASSERT_EQ(0, c.index);
}

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

TEST(DarwinCreature, reset_moved_1) {
    Darwin darwin = Darwin(5,5);
    Darwin* d = &darwin;
    Species food = Species('f');
    food.add_instruction(1, 0);
    food.add_instruction(8, 0);
    Creature f1 = Creature(food, 0, 0, 1, 5, 5, 0);
    darwin.add_creature(f1, 0, 0);
    f1.read_instruction(d);
    ASSERT_TRUE(f1.moved);
    f1.reset_moved();
    ASSERT_FALSE(f1.moved);
}

TEST(DarwinCreature, reset_moved_2) {
    Darwin darwin = Darwin(10,5);
    Darwin* d = &darwin;
    Species food = Species('f');
    food.add_instruction(1, 0);
    food.add_instruction(8, 0);
    Creature f1 = Creature(food, 0, 0, 1, 10, 5, 0);
    Creature f2 = Creature(food, 1, 1, 2, 10, 5, 1);
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

TEST(DarwinCreature, reset_moved_3) {
    Creature f1 = Creature();
    ASSERT_TRUE(f1.moved);
    f1.reset_moved();
    ASSERT_TRUE(f1.moved);
}

// ----------------
// read_instruction
// ----------------

TEST(DarwinCreature, read_instruction_1) {
    Darwin darwin = Darwin(8,8);
    Darwin* d = &darwin;
    Species food = Species('f');
    food.add_instruction(1, 0);
    food.add_instruction(8, 0);
    Creature f1 = Creature(food, 0, 0, 1, 8, 8, 0);
    darwin.add_creature(f1, 0, 0);
    ASSERT_FALSE(f1.moved);
    f1.read_instruction(d);
    ASSERT_TRUE(f1.moved);
    ASSERT_EQ(0, f1.row);
    ASSERT_EQ(0, f1.col);
    ASSERT_EQ(0, f1.dir);
    ASSERT_EQ(8, f1.max_row);
    ASSERT_EQ(8, f1.max_col);
    ASSERT_EQ(0, f1.index);
    ASSERT_EQ(1, f1.pc);

}

TEST(DarwinCreature, read_instruction_2) {
    Darwin darwin = Darwin(8,8);
    Darwin* d = &darwin;
    Species food = Species('f');
    food.add_instruction(0, 0);
    food.add_instruction(8, 0);
    Creature f1 = Creature(food, 1, 1, 1, 8, 8, 0);
    darwin.add_creature(f1, 1, 1);
    ASSERT_FALSE(f1.moved);
    f1.read_instruction(d);
    ASSERT_TRUE(f1.moved);
    ASSERT_EQ(0, f1.row);
    ASSERT_EQ(1, f1.col);
    ASSERT_EQ(1, f1.dir);
    ASSERT_EQ(8, f1.max_row);
    ASSERT_EQ(8, f1.max_col);
    ASSERT_EQ(0, f1.index);
    ASSERT_EQ(1, f1.pc);
}

TEST(DarwinCreature, read_instruction_3) {
    Darwin darwin = Darwin(8,8);
    Darwin* d = &darwin;
    Species food = Species('f');
    Species good = Species('g');
    food.add_instruction(3, 0);
    food.add_instruction(8, 0);
    Creature f1 = Creature(food, 1, 1, 1, 8, 8, 0);
    Creature g1 = Creature(good, 0, 1, 1, 8, 8, 1);
    darwin.add_creature(f1, 1, 1);
    darwin.add_creature(g1, 0, 1);
    ASSERT_FALSE(f1.moved);
    f1.read_instruction(d);
    ASSERT_TRUE(f1.moved);
    ASSERT_EQ(1, f1.row);
    ASSERT_EQ(1, f1.col);
    ASSERT_EQ(1, f1.dir);
    ASSERT_EQ(8, f1.max_row);
    ASSERT_EQ(8, f1.max_col);
    ASSERT_EQ(0, f1.index);
    ASSERT_EQ(1, f1.pc);
}

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

TEST(DarwinCreature, left_1) {
    Species food = Species('f');
    Creature f1 = Creature(food, 0, 0, 1, 8, 8, 0);
    ASSERT_FALSE(f1.moved);
    f1.left();
    ASSERT_TRUE(f1.moved);
    ASSERT_EQ(0, f1.row);
    ASSERT_EQ(0, f1.col);
    ASSERT_EQ(0, f1.dir);
    ASSERT_EQ(8, f1.max_row);
    ASSERT_EQ(8, f1.max_col);
    ASSERT_EQ(0, f1.index);
    ASSERT_EQ(1, f1.pc);
}

TEST(DarwinCreature, left_2) {
    Species food = Species('f');
    Creature f1 = Creature(food, 0, 0, 1, 8, 8, 0);
    f1.left();
    f1.left();
    ASSERT_EQ(3, f1.dir);
}

TEST(DarwinCreature, left_3) {
    Species food = Species('f');
    Creature f1 = Creature(food, 0, 0, 1, 8, 8, 0);
    f1.left();
    f1.left();
    f1.left();
    ASSERT_EQ(2, f1.dir);
}

// -----
// right
// -----

TEST(DarwinCreature, right_1) {
    Species food = Species('f');
    Creature f1 = Creature(food, 0, 0, 1, 8, 8, 0);
    ASSERT_FALSE(f1.moved);
    f1.right();
    ASSERT_TRUE(f1.moved);
    ASSERT_EQ(0, f1.row);
    ASSERT_EQ(0, f1.col);
    ASSERT_EQ(2, f1.dir);
    ASSERT_EQ(8, f1.max_row);
    ASSERT_EQ(8, f1.max_col);
    ASSERT_EQ(0, f1.index);
    ASSERT_EQ(1, f1.pc);
}

TEST(DarwinCreature, right_2) {
    Species food = Species('f');
    Creature f1 = Creature(food, 0, 0, 1, 8, 8, 0);
    f1.right();
    f1.right();
    ASSERT_EQ(3, f1.dir);
}

TEST(DarwinCreature, right_3) {
    Species food = Species('f');
    Creature f1 = Creature(food, 0, 0, 1, 8, 8, 0);
    f1.right();
    f1.right();
    f1.right();
    ASSERT_EQ(0, f1.dir);
}

// ------
// infect
// ------

TEST(DarwinCreature, infect_1) {
    Darwin darwin = Darwin(8,8);
    Darwin* d = &darwin;
    Species food = Species('f');
    Species good = Species('g');
    Creature f1 = Creature(food, 1, 1, 1, 8, 8, 0);
    Creature f2 = Creature(good, 0, 1, 1, 8, 8, 1);
    darwin.add_creature(f1, 1, 1);
    darwin.add_creature(f2, 0, 1);
    ASSERT_FALSE(f1.moved);
    ASSERT_FALSE(f1.check_same_species(f2));
    f1.infect(d);
    ASSERT_TRUE(f1.moved);
    ASSERT_EQ(1, f1.row);
    ASSERT_EQ(1, f1.col);
    ASSERT_EQ(1, f1.dir);
    ASSERT_EQ(8, f1.max_row);
    ASSERT_EQ(8, f1.max_col);
    ASSERT_EQ(0, f1.index);
    ASSERT_EQ(1, f1.pc);
    ASSERT_EQ(0, f2.row);
    ASSERT_EQ(1, f2.col);
    ASSERT_EQ(1, f2.dir);
    ASSERT_EQ(8, f2.max_row);
    ASSERT_EQ(8, f2.max_col);
    ASSERT_EQ(1, f2.index);
    ASSERT_EQ(0, f2.pc);
}

TEST(DarwinCreature, infect_2) {
    Darwin darwin = Darwin(8,8);
    Darwin* d = &darwin;
    Species food = Species('f');
    food.add_instruction(0, 0);
    Species good = Species('g');
    good.add_instruction(3, 0);
    Creature f1 = Creature(food, 5, 5, 3, 8, 8, 0);
    Creature f2 = Creature(good, 6, 5, 1, 8, 8, 1);
    darwin.add_creature(f1, 5, 5);
    darwin.add_creature(f2, 6, 5);
    ASSERT_NE(f1.sp[0], f2.sp[0]);
    f1.infect(d);
    ASSERT_EQ(f1.sp[0], (d->creatures[d->board[6][5]]).sp[0]);
}

TEST(DarwinCreature, infect_3) {
    Darwin darwin = Darwin(8,8);
    Darwin* d = &darwin;
    Species food = Species('f');
    food.add_instruction(0, 0);
    Species good = Species('g');
    good.add_instruction(3, 0);
    Creature f1 = Creature(food, 5, 5, 3, 8, 8, 0);
    Creature f2 = Creature(good, 6, 5, 1, 8, 8, 1);
    darwin.add_creature(f1, 5, 5);
    darwin.add_creature(f2, 6, 5);
    ASSERT_FALSE(f1.check_same_species(f2));
    f1.infect(d);
    ASSERT_TRUE(f1.check_same_species(d->creatures[d->board[6][5]]));
}

// --------
// if_empty
// --------

TEST(DarwinCreature, if_empty_1) {
    Darwin darwin = Darwin(8,8);
    Darwin* d = &darwin;
    Species food = Species('f');
    Creature f1 = Creature(food, 1, 1, 1, 8, 8, 0);
    darwin.add_creature(f1, 1, 1);
    ASSERT_EQ(0, f1.pc);
    f1.moved = true;
    f1.if_empty(d, 2);
    ASSERT_EQ(2, f1.pc);
}

TEST(DarwinCreature, if_empty_2) {
    Darwin darwin = Darwin(8,8);
    Darwin* d = &darwin;
    Species food = Species('f');
    Creature f1 = Creature(food, 1, 1, 1, 8, 8, 0);
    Creature f2 = Creature(food, 0, 1, 1, 8, 8, 0);
    darwin.add_creature(f1, 1, 1);
    darwin.add_creature(f2, 0, 1);
    ASSERT_EQ(0, f1.pc);
    f1.moved = true;
    f1.if_empty(d, 10);
    ASSERT_EQ(1, f1.pc);
}

TEST(DarwinCreature, if_empty_3) {
    Darwin darwin = Darwin(8,8);
    Darwin* d = &darwin;
    Species food = Species('f');
    Creature f1 = Creature(food, 1, 1, 1, 8, 8, 0);
    darwin.add_creature(f1, 1, 1);
    ASSERT_EQ(0, f1.pc);
    f1.moved = true;
    f1.if_empty(d, 10);
    ASSERT_EQ(10, f1.pc);
}

// -------
// if_wall
// -------

TEST(DarwinCreature, if_wall_1) {
    Darwin darwin = Darwin(8,8);
    Darwin* d = &darwin;
    Species food = Species('f');
    Creature f1 = Creature(food, 1, 1, 1, 8, 8, 0);
    darwin.add_creature(f1, 1, 1);
    ASSERT_EQ(0, f1.pc);
    f1.moved = true;
    f1.if_wall(d, 2);
    ASSERT_EQ(1, f1.pc);
}

TEST(DarwinCreature, if_wall_2) {
    Darwin darwin = Darwin(8,8);
    Darwin* d = &darwin;
    Species food = Species('f');
    Creature f1 = Creature(food, 1, 1, 1, 8, 8, 0);
    Creature f2 = Creature(food, 0, 1, 1, 8, 8, 0);
    darwin.add_creature(f1, 1, 1);
    darwin.add_creature(f2, 0, 1);
    ASSERT_EQ(0, f1.pc);
    f1.moved = true;
    f1.if_wall(d, 10);
    ASSERT_EQ(1, f1.pc);
}

TEST(DarwinCreature, if_wall_3) {
    Darwin darwin = Darwin(8,8);
    Darwin* d = &darwin;
    Species food = Species('f');
    Creature f1 = Creature(food, 0, 1, 1, 8, 8, 0);
    darwin.add_creature(f1, 0, 1);
    ASSERT_EQ(0, f1.pc);
    f1.moved = true;
    f1.if_wall(d, 10);
    ASSERT_EQ(10, f1.pc);
}

// ---------
// if_random
// ---------

TEST(DarwinCreature, if_random_1) {
    Darwin darwin = Darwin(8,8);
    Darwin* d = &darwin;
    Species food = Species('f');
    Creature f1 = Creature(food, 1, 1, 1, 8, 8, 0);
    darwin.add_creature(f1, 1, 1);
    ASSERT_EQ(0, f1.pc);
    f1.moved = true;
    f1.if_random(d, 2);
    ASSERT_NE(0, f1.pc);
}

TEST(DarwinCreature, if_random_2) {
    Darwin darwin = Darwin(8,8);
    Darwin* d = &darwin;
    Species food = Species('f');
    Creature f1 = Creature(food, 1, 1, 1, 8, 8, 0);
    darwin.add_creature(f1, 1, 1);
    ASSERT_EQ(0, f1.pc);
    f1.moved = true;
    f1.if_random(d, 10);
    ASSERT_LT(0, f1.pc);
}

TEST(DarwinCreature, if_random_3) {
    Darwin darwin = Darwin(8,8);
    Darwin* d = &darwin;
    Species food = Species('f');
    Creature f1 = Creature(food, 0, 1, 1, 8, 8, 0);
    darwin.add_creature(f1, 0, 1);
    ASSERT_EQ(0, f1.pc);
    f1.moved = true;
    f1.if_random(d, 10);
    ASSERT_LE(1, f1.pc);
}

// --------
// if_enemy
// --------

TEST(DarwinCreature, if_enemy_1) {
    Darwin darwin = Darwin(8,8);
    Darwin* d = &darwin;
    Species food = Species('f');
    Creature f1 = Creature(food, 1, 1, 1, 8, 8, 0);
    darwin.add_creature(f1, 1, 1);
    ASSERT_EQ(0, f1.pc);
    f1.moved = true;
    f1.if_enemy(d, 2);
    ASSERT_EQ(1, f1.pc);
}

TEST(DarwinCreature, if_enemy_2) {
    Darwin darwin = Darwin(8,8);
    Darwin* d = &darwin;
    Species food = Species('f');
    Creature f1 = Creature(food, 1, 1, 1, 8, 8, 0);
    Creature f2 = Creature(food, 0, 1, 1, 8, 8, 0);
    darwin.add_creature(f1, 1, 1);
    darwin.add_creature(f2, 0, 1);
    ASSERT_EQ(0, f1.pc);
    f1.moved = true;
    f1.if_enemy(d, 10);
    ASSERT_EQ(1, f1.pc);
}

TEST(DarwinCreature, if_enemy_3) {
    Darwin darwin = Darwin(8,8);
    Darwin* d = &darwin;
    Species food = Species('f');
    Species good = Species('g');
    Creature f1 = Creature(food, 1, 1, 1, 8, 8, 0);
    Creature g1 = Creature(good, 0, 1, 1, 8, 8, 0);
    darwin.add_creature(f1, 1, 1);
    darwin.add_creature(g1, 0, 1);
    ASSERT_EQ(0, f1.pc);
    f1.moved = true;
    f1.if_enemy(d, 10);
    ASSERT_EQ(10, f1.pc);
}

// --
// go
// --

TEST(DarwinCreature, go_1) {
    Darwin darwin = Darwin(8,8);
    Darwin* d = &darwin;
    Species food = Species('f');
    Creature f1 = Creature(food, 1, 1, 1, 8, 8, 0);
    darwin.add_creature(f1, 1, 1);
    ASSERT_EQ(0, f1.pc);
    f1.moved = true;
    f1.go(d, 20);
    ASSERT_EQ(20, f1.pc);
}

TEST(DarwinCreature, go_2) {
    Darwin darwin = Darwin(8,8);
    Darwin* d = &darwin;
    Species food = Species('f');
    Creature f1 = Creature(food, 1, 1, 1, 8, 8, 0);
    Creature f2 = Creature(food, 0, 1, 1, 8, 8, 0);
    darwin.add_creature(f1, 1, 1);
    darwin.add_creature(f2, 0, 1);
    ASSERT_EQ(0, f1.pc);
    f1.moved = true;
    f1.go(d, 10);
    ASSERT_EQ(10, f1.pc);
}

TEST(DarwinCreature, go_3) {
    Darwin darwin = Darwin(8,8);
    Darwin* d = &darwin;
    Species food = Species('f');
    Creature f1 = Creature(food, 1, 1, 1, 8, 8, 0);
    darwin.add_creature(f1, 1, 1);
    ASSERT_EQ(0, f1.pc);
    f1.moved = true;
    f1.go(d, 10);
    ASSERT_EQ(10, f1.pc);
}

// ------
// Darwin
// ------

// ----------------
// Darwin(int, int)
// ----------------

TEST(DarwinTest, parameters_1) {
	Darwin d = Darwin(4, 5);
	ASSERT_EQ(d.rows, 4);
	ASSERT_EQ(d.cols, 5);
	ASSERT_EQ(d.creatures.size(), 20);
	ASSERT_EQ(d.board.size(), 4);
	ASSERT_EQ(d.board[0].size(), 5);
}

TEST(DarwinTest, parameters_2) {
	Darwin d = Darwin(10, 10);
	ASSERT_EQ(d.rows, 10);
	ASSERT_EQ(d.cols, 10);
	ASSERT_EQ(d.creatures.size(), 100);
	ASSERT_EQ(d.board.size(), 10);
	ASSERT_EQ(d.board[0].size(), 10);
}

TEST(DarwinTest, parameters_3) {
	Darwin d = Darwin(7, 9);
	ASSERT_EQ(d.rows, 7);
	ASSERT_EQ(d.cols, 9);
	ASSERT_EQ(d.creatures.size(), 63);
	ASSERT_EQ(d.board.size(), 7);
	ASSERT_EQ(d.board[0].size(), 9);
}

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

TEST(DarwinTest, begin_1) {
	Darwin darwin = Darwin(3, 3);
	ASSERT_EQ(darwin.begin(), darwin.board.begin());
}

// ---
// end
// ---

TEST(DarwinTest, end_1) {
	Darwin darwin = Darwin(12, 12);
	ASSERT_EQ(darwin.end(), darwin.board.end());
}

// --
// at
// --
TEST(DarwinTest, at_1) {
	Species ape = Species('a');

	Creature a1 = Creature(ape, 2, 1, 0, 4, 4, 0);
	Creature a2 = Creature(ape, 3, 0, 1, 4, 4, 1);
	Creature a3 = Creature(ape, 1, 3, 3, 4, 4, 2);

	Darwin darwin = Darwin(4, 4);
	darwin.add_creature(a1, 2, 1);
	darwin.add_creature(a2, 3, 0);
	darwin.add_creature(a3, 1, 3);

	// ASSERT_EQ(darwin.at(2, 1), a1);
	// ASSERT_EQ(darwin.at(3, 0), a2);
	// ASSERT_EQ(darwin.at(1, 3), a3);
}

TEST(DarwinTest, at_2) {
	Species food = Species('f');

	Creature f = Creature(food, 6, 6, 0, 13, 13, 0);

	Darwin darwin = Darwin(13, 13);
	darwin.add_creature(f, 6, 6);
	//test the exception
}

TEST(DarwinTest, at_3) {
	Species f = Species('f');

	Creature f1 = Creature(f, 3, 1, 1, 4, 4, 0);
	Creature f2 = Creature(f, 0, 3, 2, 4, 4, 1);

	Darwin darwin = Darwin(4, 4);
	darwin.add_creature(f1, 3, 1);
	darwin.add_creature(f2, 0, 3);

	// ASSERT_EQ(darwin.at(3, 1), f1);
	// ASSERT_EQ(darwin.at(0, 3), f2);
	//test the exception
}

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

TEST(DarwinTest, is_wall_4) {
	Darwin darwin = Darwin(5, 3);
	ASSERT_TRUE(darwin.is_wall(4, 2, 3));
	ASSERT_FALSE(darwin.is_wall(2, 1, 0));
}

// --------
// is_empty
// --------

TEST(DarwinTest, is_empty_1) {
	Species food = Species('f');
	Creature f = Creature(food, 0, 2, 1, 3, 3, 0);
	Creature f1 = Creature(food, 1, 0, 1, 3, 3, 1);
	Darwin d = Darwin(3, 3);
	d.add_creature(f, 0, 2);
	d.add_creature(f1, 1, 0);

	ASSERT_TRUE(d.is_empty(1, 1, 2));
	ASSERT_FALSE(d.is_empty(1, 2, 1));
	ASSERT_FALSE(d.is_empty(0, 1, 2));
}

TEST(DarwinTest, is_empty_2) {
	Species food = Species('f');
	Species hopper = Species('h');
	Creature f =  Creature(food, 3, 4, 1, 5, 5, 0);
	Creature h =  Creature(hopper, 0, 3, 2, 5, 5, 0);

	Darwin d = Darwin(5, 5);
	d.add_creature(f, 3, 4);
	d.add_creature(h, 0, 3);

	ASSERT_TRUE(d.is_empty(2, 2, 0));
	ASSERT_FALSE(d.is_empty(3, 3, 2));
	ASSERT_FALSE(d.is_empty(2, 4, 3));
	ASSERT_FALSE(d.is_empty(4, 4, 1));
	ASSERT_FALSE(d.is_empty(1, 3, 1));
	ASSERT_TRUE(d.is_empty(1, 1, 2));
	
}

TEST(DarwinTest, is_empty_3) {
	Species food = Species('f');
	Creature f = Creature(food, 0, 0, 2, 2, 2, 0);
	Creature f2 = Creature(food, 0, 1, 2, 2, 2, 1);
	Creature f3 = Creature(food, 1, 0, 2, 2, 2, 2);
	Creature f4 = Creature(food, 1, 1, 2, 2, 2, 3);

	Darwin d = Darwin(2, 2);
	d.add_creature(f, 0, 0);
	d.add_creature(f2, 0, 1);
	d.add_creature(f3, 1, 0);
	d.add_creature(f4, 1, 1);

	ASSERT_FALSE(d.is_empty(0, 0, 3));
	ASSERT_FALSE(d.is_empty(0, 1, 0));
	ASSERT_FALSE(d.is_empty(1, 0, 2));
	ASSERT_FALSE(d.is_empty(1, 1, 0));
}

TEST(DarwinTest, is_empty_4) {
	Species rover = Species('r');
	Creature r1 = Creature(rover, 2, 3, 1, 5, 5, 0);
	Creature r2 = Creature(rover, 1, 0, 3, 5, 5, 1);
	Creature r3 = Creature(rover, 3, 3, 0, 5, 5, 2);

	Darwin d = Darwin(5, 5);
	d.add_creature(r1, 2, 3);
	d.add_creature(r2, 1, 0);
	d.add_creature(r3, 3, 3);

	ASSERT_TRUE(d.is_empty(0, 3, 0));
	ASSERT_FALSE(d.is_empty(2, 3, 3));
	ASSERT_TRUE(d.is_empty(4, 4, 2));
	ASSERT_FALSE(d.is_empty(0, 0, 3));

}

// --------
// is_enemy
// --------
TEST(DarwinTest, is_enemy_1) {
	Species cat = Species('c');
	Species dog = Species('d');

	Creature c = Creature(cat, 1, 2, 3, 3, 3, 0);
	Creature d = Creature(dog, 2, 2, 1, 3, 1, 1);

	Darwin darwin = Darwin(3, 3);
	darwin.add_creature(c, 1, 2);
	darwin.add_creature(d, 2, 2);

	ASSERT_TRUE(darwin.is_enemy(c, 1, 2, 3));
	ASSERT_TRUE(darwin.is_enemy(d, 2, 2, 1));
}

TEST(DarwinTest, is_enemy_2) {
	Species cat = Species('c');
	Species dog = Species('d');

	Creature c1 = Creature(cat, 0, 0, 3, 2, 2, 0);
	Creature c2 = Creature(cat, 0, 1, 3, 2, 2, 1);
	Creature d1 = Creature(dog, 1, 0, 0, 2, 2, 2);
	Creature d2 = Creature(dog, 1, 1, 1, 2, 2, 3);

	Darwin d = Darwin(2, 2);
	d.add_creature(c1, 0, 0);
	d.add_creature(c2, 0, 1);
	d.add_creature(d1, 1, 0);
	d.add_creature(d2, 1, 1);

	ASSERT_FALSE(d.is_enemy(c1, 0, 0, 2));
	ASSERT_TRUE(d.is_enemy(c1, 0, 0, 3));
	ASSERT_FALSE(d.is_enemy(d1, 1, 1, 0));
	ASSERT_TRUE(d.is_enemy(d1, 1, 1, 1));
}

TEST(DarwinTest, is_enemy_3) {
	Species cat = Species('c');
	Species dog = Species('d');
	Species frog = Species('f');

	Creature c1 = Creature(cat, 0, 1, 3, 4, 4, 0);
	Creature d1 = Creature(dog, 1, 0, 0, 4, 4, 1);
	Creature f1 = Creature(frog, 0, 0, 2, 4, 4, 2);

	Darwin d = Darwin(4, 4);
	d.add_creature(c1, 0, 1);
	d.add_creature(d1, 1, 0);
	d.add_creature(f1, 0, 0);

	ASSERT_FALSE(d.is_enemy(c1, 0, 1, 2));
	ASSERT_TRUE(d.is_enemy(d1, 1, 0, 1));
	ASSERT_TRUE(d.is_enemy(f1, 0, 0, 2));
	ASSERT_TRUE(d.is_enemy(f1, 0, 0, 3));
	ASSERT_FALSE(d.is_enemy(d1, 1, 0, 2));
}

TEST(DarwinTest, is_enemy_4) {
	Species ape = Species('a');
	Species bee = Species('b');
	Species cow = Species('c');

	Creature a = Creature(ape, 2, 4, 2, 5, 6, 0);
	Creature b = Creature(bee, 1, 0, 1, 5, 6, 1);
	Creature c = Creature(cow, 3, 4, 0, 5, 6, 2);

	Darwin d = Darwin(5, 6);
	d.add_creature(a, 2, 4);
	d.add_creature(b, 1, 0);
	d.add_creature(c, 3, 4);

	ASSERT_FALSE(d.is_enemy(b, 1, 0, 3));
	ASSERT_FALSE(d.is_enemy(a, 2, 4, 0));
	ASSERT_FALSE(d.is_enemy(c, 3, 4, 2));
	ASSERT_TRUE(d.is_enemy(c, 3, 4, 1));
}

// ---------
// get_enemy
// ---------

// TEST(DarwinTest, get_enemy_1) {
// 	Species cat = Species('c');
// 	Species dog = Species('d');

// 	Creature d1 = Creature(dog, 3, 2, 3, 5, 5, 0);
// 	Creature c1 = Creature(cat, 2, 2, 2, 5, 5, 1);

// 	Darwin darwin = Darwin(5, 5);
// 	darwin.add_creature(d1, 3, 2);
// 	darwin.add_creature(c1, 2, 2);

// 	Creature& enemy = darwin.get_enemy(d1, 3, 2, 3);
// 	enemy.sp = Species(this->sp);

// 	ASSERT_EQ(enemy->sp.get_initial(), 'c');
// }

// ------------
// update_board
// ------------

TEST(DarwinTest, update_board_1) {
	Species food = Species('f');
	food.add_instruction(1, 0);
    food.add_instruction(8, 0);

	Species rover = Species('r');
	rover.add_instruction(7, 9);
    rover.add_instruction(4, 7);
    rover.add_instruction(6, 5);
    rover.add_instruction(1, 0);
    rover.add_instruction(8, 0);
    rover.add_instruction(2, 0);
    rover.add_instruction(8, 0);
    rover.add_instruction(0, 0);
    rover.add_instruction(8, 0);
    rover.add_instruction(3, 0);
    rover.add_instruction(8, 0);

    Creature f = Creature(food, 0, 1, 2, 3, 3, 0);
    Creature r = Creature(rover, 0, 2, 0, 3, 3, 1);

    Darwin darwin = Darwin(3, 3);
    Darwin* d = &darwin;
    darwin.add_creature(f, 0, 1);
    darwin.add_creature(r, 0, 2);
    r.read_instruction(d);

    ASSERT_EQ(darwin.board[0][1], 0);
    // ASSERT_EQ(darwin.creatures[0], 'r');
}

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

TEST(DarwinTest, print_board_4) {
	Species food = Species('f');
	Species best = Species('b');
	Species trap = Species('t');

	Creature f1 = Creature(food, 2, 4, 1, 8, 8, 0);
	Creature f2 = Creature(food, 0, 7, 3, 8, 8, 1);
	Creature b1 = Creature(best, 5, 6, 2, 8, 8, 2);
	Creature t1 = Creature(trap, 3, 2, 0, 8, 8, 3);

	Darwin darwin = Darwin(8, 8);
	darwin.add_creature(f1, 2, 4);
	darwin.add_creature(f2, 0, 7);
	darwin.add_creature(b1, 5, 6);
	darwin.add_creature(t1, 3, 2);

	ostringstream w;
	darwin.print_board(w, 0);

	ASSERT_EQ("Turn = 0.\n  01234567\n0 .......f\n1 ........\n2 ....f...\n3 ..t.....\n4 ........\n5 ......b.\n6 ........\n7 ........\n\n", w.str());
}



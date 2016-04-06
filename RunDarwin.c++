// -----------------------------
// projects/darwin/RunDarwin.c++
// Copyright (C) 2015
// Glenn P. Downing
// -----------------------------

// --------
// includes
// --------

#include <cassert>   // assert
#include <cstdlib>   // rand, srand
#include <iostream>  // cout, endl
#include <stdexcept> // invalid_argument, out_of_range
#include "Darwin.h"

// ----
// main
// ----

int main () {
    using namespace std;

    // ----
    // food
    // ----

    /*
     0: left
     1: go 0
    */

    // ------
    // hopper
    // ------

    /*
     0: hop
     1: go 0
    */

    // -----
    // rover
    // -----

    /*
     0: if_enemy 9
     1: if_empty 7
     2: if_random 5
     3: left
     4: go 0
     5: right
     6: go 0
     7: hop
     8: go 0
     9: infect
    10: go 0
    */

    // ----
    // trap
    // ----

    /*
     0: if_enemy 3
     1: left
     2: go 0
     3: infect
     4: go 0
    */

    // ----------
    // darwin 8x8
    // ----------

    /*
    8x8 Darwin
    Food,   facing east,  at (0, 0)
    Hopper, facing north, at (3, 3)
    Hopper, facing east,  at (3, 4)
    Hopper, facing south, at (4, 4)
    Hopper, facing west,  at (4, 3)
    Food,   facing north, at (7, 7)
    Simulate 5 moves.
    Print every grid.
    */

    cout << "*** Darwin 8x8 ***" << endl;
    Species food = Species('f');
    food.add_instruction(1, 0);
    food.add_instruction(8, 0);

    Species hopper = Species('h');
    hopper.add_instruction(0, 0);
    hopper.add_instruction(8, 0);

    Creature f1 = Creature(food, 0, 0, 1, 8, 8, 0);
    Creature h1 = Creature(hopper, 3, 3, 0, 8, 8, 1);
    Creature h2 = Creature(hopper, 3, 4, 1, 8, 8, 2);
    Creature h3 = Creature(hopper, 4, 4, 2, 8, 8, 3);
    Creature h4 = Creature(hopper, 4, 3, 3, 8, 8, 4);
    Creature f2 = Creature(food, 7, 7, 0, 8, 8, 5);

    Darwin darwin = Darwin(8, 8);
    darwin.add_creature(f1, 0, 0);
    darwin.add_creature(h1, 3, 3);
    darwin.add_creature(h2, 3, 4);
    darwin.add_creature(h3, 4, 4);
    darwin.add_creature(h4, 4, 3);
    darwin.add_creature(f2, 7, 7);

    int rounds = 5;
    int turn = 0;

    while(turn <= rounds) {
        darwin.print_board(turn);
        darwin.play();
        ++turn;
    }

    // ----------
    // darwin 7x9
    // ----------

    cout << "*** Darwin 7x9 ***" << endl;
    srand(0);
    /*
    7x9 Darwin
    Trap,   facing south, at (0, 0)
    Hopper, facing east,  at (3, 2)
    Rover,  facing north, at (5, 4)
    Trap,   facing west,  at (6, 8)
    Simulate 5 moves.
    Print every grid.
    */

    Species trap = Species('t');
    trap.add_instruction(7, 3);
    trap.add_instruction(1, 0);
    trap.add_instruction(8, 0);
    trap.add_instruction(3, 0);
    trap.add_instruction(8, 0);

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

    Creature t1 = Creature(trap, 0, 0, 2, 7, 9, 0);
    Creature h5 = Creature(hopper, 3, 2, 1, 7, 9, 1);
    Creature r1 = Creature(rover, 5, 4, 0, 7, 9, 2);
    Creature t2 = Creature(trap, 6, 8, 3, 7, 9, 3);

    darwin = Darwin(7, 9);
    darwin.add_creature(t1, 0, 0);
    darwin.add_creature(h5, 3, 2);
    darwin.add_creature(r1, 5, 4);
    darwin.add_creature(t2, 6, 8);

    rounds = 5;
    turn = 0;

    while(turn <= rounds) {
        darwin.print_board(turn);
        darwin.play();
        ++turn;
    }


    // ------------
    // darwin 72x72
    // without best
    // ------------

    cout << "*** Darwin 72x72 without Best ***" << endl;
    srand(0);
    /*
    Randomly place the following creatures facing randomly.
    Call rand(), mod it with 5184 (72x72), and use that for the position
    in a row-major order grid.
    Call rand() again, mod it with 4 and use that for it's direction with
    the ordering: west, north, east, south.
    Do that for each kind of creature.
    10 Food
    10 Hopper
    10 Rover
    10 Trap
    Simulate 1000 moves.
    Print the first 10 grids          (i.e. 0, 1, 2...9).
    Print every 100th grid after that (i.e. 100, 200, 300...1000).
    */

    // ------------
    // darwin 72x72
    // with best
    // ------------

    cout << "*** Darwin 72x72 with Best ***" << endl;
    srand(0);
    /*
    Randomly place the following creatures facing randomly.
    Call rand(), mod it with 5184 (72x72), and use that for the position
    in a row-major order grid.
    Call rand() again, mod it with 4 and use that for it's direction with
    the ordering: 0:west, 1:north, 2:east, 3:south.
    Do that for each kind of creature.
    10 Food
    10 Hopper
    10 Rover
    10 Trap
    10 Best
    Simulate 1000 moves.
    Best MUST outnumber ALL other species for the bonus pts.
    Print the first 10 grids          (i.e. 0, 1, 2...9).
    Print every 100th grid after that (i.e. 100, 200, 300...1000).
    */

    return 0;}

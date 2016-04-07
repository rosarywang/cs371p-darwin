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

    // ----
    // best
    // ----

    /*
     0: if_empty 4
     1: if_enemy 9
     2: left
     3: go 0
     4: if_random 7
     5: right
     6: go 0
     7: hop
     8: go 0
     9: infect
    10: go 0
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

    Creature f1 = Creature(food, 0, 0, 2, 8, 8, 0);
    Creature h1 = Creature(hopper, 3, 3, 1, 8, 8, 1);
    Creature h2 = Creature(hopper, 3, 4, 2, 8, 8, 2);
    Creature h3 = Creature(hopper, 4, 4, 3, 8, 8, 3);
    Creature h4 = Creature(hopper, 4, 3, 0, 8, 8, 4);
    Creature f2 = Creature(food, 7, 7, 1, 8, 8, 5);

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
        darwin.print_board(cout, turn);
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

    Creature t1 = Creature(trap, 0, 0, 3, 7, 9, 0);
    Creature h5 = Creature(hopper, 3, 2, 2, 7, 9, 1);
    Creature r1 = Creature(rover, 5, 4, 1, 7, 9, 2);
    Creature t2 = Creature(trap, 6, 8, 0, 7, 9, 3);

    darwin = Darwin(7, 9);
    darwin.add_creature(t1, 0, 0);
    darwin.add_creature(h5, 3, 2);
    darwin.add_creature(r1, 5, 4);
    darwin.add_creature(t2, 6, 8);

    rounds = 5;
    turn = 0;

    while(turn <= rounds) {
        darwin.print_board(cout, turn);
        darwin.play();
        ++turn;
    }

    // ------------
    // darwin 72x72
    // without best
    // ------------

    cout << "*** Darwin 72x72 without Best ***" << endl;
    cout << "..." << endl;
    cout << endl;
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

    int rand_1 = rand()%72, rand_2 = rand()%72, rand_3 = rand()%72, rand_4 = rand()%72, rand_5 = rand()%72,
        rand_6 = rand()%72, rand_7 = rand()%72, rand_8 = rand()%72, rand_9 = rand()%72, rand_10 = rand()%72,
        rand_11 = rand()%72, rand_12 = rand()%72, rand_13 = rand()%72, rand_14 = rand()%72, rand_15 = rand()%72,
        rand_16 = rand()%72, rand_17 = rand()%72, rand_18 = rand()%72, rand_19 = rand()%72, rand_20 = rand()%72,
        rand_21 = rand()%72, rand_22 = rand()%72, rand_23 = rand()%72, rand_24 = rand()%72, rand_25 = rand()%72,
        rand_26 = rand()%72, rand_27 = rand()%72, rand_28 = rand()%72, rand_29 = rand()%72, rand_30 = rand()%72,
        rand_31 = rand()%72, rand_32 = rand()%72, rand_33 = rand()%72, rand_34 = rand()%72, rand_35 = rand()%72,
        rand_36 = rand()%72, rand_37 = rand()%72, rand_38 = rand()%72, rand_39 = rand()%72, rand_40 = rand()%72,
        rand_41 = rand()%72, rand_42 = rand()%72, rand_43 = rand()%72, rand_44 = rand()%72, rand_45 = rand()%72,
        rand_46 = rand()%72, rand_47 = rand()%72, rand_48 = rand()%72, rand_49 = rand()%72, rand_50 = rand()%72,
        rand_51 = rand()%72, rand_52 = rand()%72, rand_53 = rand()%72, rand_54 = rand()%72, rand_55 = rand()%72,
        rand_56 = rand()%72, rand_57 = rand()%72, rand_58 = rand()%72, rand_59 = rand()%72, rand_60 = rand()%72,
        rand_61 = rand()%72, rand_62 = rand()%72, rand_63 = rand()%72, rand_64 = rand()%72, rand_65 = rand()%72,
        rand_66 = rand()%72, rand_67 = rand()%72, rand_68 = rand()%72, rand_69 = rand()%72, rand_70 = rand()%72,
        rand_71 = rand()%72, rand_72 = rand()%72, rand_73 = rand()%72, rand_74 = rand()%72, rand_75 = rand()%72,
        rand_76 = rand()%72, rand_77 = rand()%72, rand_78 = rand()%72, rand_79 = rand()%72, rand_80 = rand()%72;


    Creature f3 = Creature(food, rand_1, rand_2, rand()%4, 72, 72, 0);
    Creature f4 = Creature(food, rand_3, rand_4, rand()%4, 72, 72, 1);
    Creature f5 = Creature(food, rand_5, rand_6, rand()%4, 72, 72, 2);
    Creature f6 = Creature(food, rand_7, rand_8, rand()%4, 72, 72, 3);
    Creature f7 = Creature(food, rand_9, rand_10, rand()%4, 72, 72, 4);
    Creature f8 = Creature(food, rand_11, rand_12, rand()%4, 72, 72, 5);
    Creature f9 = Creature(food, rand_13, rand_14, rand()%4, 72, 72, 6);
    Creature f10 = Creature(food, rand_15, rand_16, rand()%4, 72, 72, 7);
    Creature f11 = Creature(food, rand_17, rand_18, rand()%4, 72, 72, 8);
    Creature f12 = Creature(food, rand_19, rand_20, rand()%4, 72, 72, 9);

    Creature h6 = Creature(hopper, rand_21, rand_22, rand()%4, 72, 72, 10);
    Creature h7 = Creature(hopper, rand_23, rand_24, rand()%4, 72, 72, 11);
    Creature h8 = Creature(hopper, rand_25, rand_26, rand()%4, 72, 72, 12);
    Creature h9 = Creature(hopper, rand_27, rand_28, rand()%4, 72, 72, 13);
    Creature h10 = Creature(hopper, rand_29, rand_30, rand()%4, 72, 72, 14);
    Creature h11 = Creature(hopper, rand_31, rand_32, rand()%4, 72, 72, 15);
    Creature h12 = Creature(hopper, rand_33, rand_34, rand()%4, 72, 72, 16);
    Creature h13 = Creature(hopper, rand_35, rand_36, rand()%4, 72, 72, 17);
    Creature h14 = Creature(hopper, rand_37, rand_38, rand()%4, 72, 72, 18);
    Creature h15 = Creature(hopper, rand_39, rand_40, rand()%4, 72, 72, 19);

    Creature t3 = Creature(trap, rand_41, rand_42, rand()%4, 72, 72, 20);
    Creature t4 = Creature(trap, rand_43, rand_44, rand()%4, 72, 72, 21);
    Creature t5 = Creature(trap, rand_45, rand_46, rand()%4, 72, 72, 22);
    Creature t6 = Creature(trap, rand_47, rand_48, rand()%4, 72, 72, 23);
    Creature t7 = Creature(trap, rand_49, rand_50, rand()%4, 72, 72, 24);
    Creature t8 = Creature(trap, rand_51, rand_52, rand()%4, 72, 72, 25);
    Creature t9 = Creature(trap, rand_53, rand_54, rand()%4, 72, 72, 26);
    Creature t10 = Creature(trap, rand_55, rand_56, rand()%4, 72, 72, 27);
    Creature t11 = Creature(trap, rand_57, rand_58, rand()%4, 72, 72, 28);
    Creature t12 = Creature(trap, rand_59, rand_60, rand()%4, 72, 72, 29);

    Creature r2 = Creature(rover, rand_61, rand_62, rand()%4, 72, 72, 30);
    Creature r3 = Creature(rover, rand_63, rand_64, rand()%4, 72, 72, 31);
    Creature r4 = Creature(rover, rand_65, rand_66, rand()%4, 72, 72, 32);
    Creature r5 = Creature(rover, rand_67, rand_68, rand()%4, 72, 72, 33);
    Creature r6 = Creature(rover, rand_69, rand_70, rand()%4, 72, 72, 34);
    Creature r7 = Creature(rover, rand_71, rand_72, rand()%4, 72, 72, 35);
    Creature r8 = Creature(rover, rand_73, rand_74, rand()%4, 72, 72, 36);
    Creature r9 = Creature(rover, rand_75, rand_76, rand()%4, 72, 72, 37);
    Creature r10 = Creature(rover, rand_77, rand_78, rand()%4, 72, 72, 38);
    Creature r11 = Creature(rover, rand_79, rand_80, rand()%4, 72, 72, 39);

    darwin = Darwin(72, 72);
    darwin.add_creature(f3, rand_1, rand_2);
    darwin.add_creature(f4, rand_3, rand_4);
    darwin.add_creature(f5, rand_5, rand_6);
    darwin.add_creature(f6, rand_7, rand_8);
    darwin.add_creature(f7, rand_9, rand_10);
    darwin.add_creature(f8, rand_11, rand_12);
    darwin.add_creature(f9, rand_13, rand_14);
    darwin.add_creature(f10, rand_15, rand_16);
    darwin.add_creature(f11, rand_17, rand_18);
    darwin.add_creature(f12, rand_19, rand_20);

    darwin.add_creature(h6, rand_21, rand_22);
    darwin.add_creature(h7, rand_23, rand_24);
    darwin.add_creature(h8, rand_25, rand_26);
    darwin.add_creature(h9, rand_27, rand_28);
    darwin.add_creature(h10, rand_29, rand_30);
    darwin.add_creature(h11, rand_31, rand_32);
    darwin.add_creature(h12, rand_33, rand_34);
    darwin.add_creature(h13, rand_35, rand_36);
    darwin.add_creature(h14, rand_37, rand_38);
    darwin.add_creature(h15, rand_39, rand_40);

    darwin.add_creature(t3, rand_41, rand_42);
    darwin.add_creature(t4, rand_43, rand_44);
    darwin.add_creature(t5, rand_45, rand_46);
    darwin.add_creature(t6, rand_47, rand_48);
    darwin.add_creature(t7, rand_49, rand_50);
    darwin.add_creature(t8, rand_51, rand_52);
    darwin.add_creature(t9, rand_53, rand_54);
    darwin.add_creature(t10, rand_55, rand_56);
    darwin.add_creature(t11, rand_57, rand_58);
    darwin.add_creature(t12, rand_59, rand_60);

    darwin.add_creature(r2, rand_61, rand_62);
    darwin.add_creature(r3, rand_63, rand_64);
    darwin.add_creature(r4, rand_65, rand_66);
    darwin.add_creature(r5, rand_67, rand_68);
    darwin.add_creature(r6, rand_69, rand_70);
    darwin.add_creature(r7, rand_71, rand_72);
    darwin.add_creature(r8, rand_73, rand_74);
    darwin.add_creature(r9, rand_75, rand_76);
    darwin.add_creature(r10, rand_77, rand_78);
    darwin.add_creature(r11, rand_79, rand_80);

    rounds = 1000;
    turn = 0;

    while(turn <= rounds) {
        if((turn < 10 )|| (turn%100 == 0))
            darwin.print_board(cout, turn);
        darwin.play();
        ++turn;
    }


    // ------------
    // darwin 72x72
    // with best
    // ------------

    cout << "*** Darwin 72x72 with Best ***" << endl;
    cout << "..." << endl;
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

    // ----
    // best
    // ----

    /*
     0: if_empty 4
     1: if_enemy 9
     2: left
     3: go 0
     4: if_random 7
     5: right
     6: go 0
     7: hop
     8: go 0
     9: infect
    10: go 0
    */

    Species best = Species('b');
    best.add_instruction(4, 4);
    best.add_instruction(7, 9);
    best.add_instruction(1, 0);
    best.add_instruction(8, 0);
    best.add_instruction(6, 7);
    best.add_instruction(2, 0);
    best.add_instruction(8, 0);
    best.add_instruction(0, 0);
    best.add_instruction(8 ,0);
    best.add_instruction(3, 0);
    best.add_instruction(8 ,0);

    rand_1 = rand()%72, rand_2 = rand()%72, rand_3 = rand()%72, rand_4 = rand()%72, rand_5 = rand()%72,
    rand_6 = rand()%72, rand_7 = rand()%72, rand_8 = rand()%72, rand_9 = rand()%72, rand_10 = rand()%72,
    rand_11 = rand()%72, rand_12 = rand()%72, rand_13 = rand()%72, rand_14 = rand()%72, rand_15 = rand()%72,
    rand_16 = rand()%72, rand_17 = rand()%72, rand_18 = rand()%72, rand_19 = rand()%72, rand_20 = rand()%72,
    rand_21 = rand()%72, rand_22 = rand()%72, rand_23 = rand()%72, rand_24 = rand()%72, rand_25 = rand()%72,
    rand_26 = rand()%72, rand_27 = rand()%72, rand_28 = rand()%72, rand_29 = rand()%72, rand_30 = rand()%72,
    rand_31 = rand()%72, rand_32 = rand()%72, rand_33 = rand()%72, rand_34 = rand()%72, rand_35 = rand()%72,
    rand_36 = rand()%72, rand_37 = rand()%72, rand_38 = rand()%72, rand_39 = rand()%72, rand_40 = rand()%72,
    rand_41 = rand()%72, rand_42 = rand()%72, rand_43 = rand()%72, rand_44 = rand()%72, rand_45 = rand()%72,
    rand_46 = rand()%72, rand_47 = rand()%72, rand_48 = rand()%72, rand_49 = rand()%72, rand_50 = rand()%72,
    rand_51 = rand()%72, rand_52 = rand()%72, rand_53 = rand()%72, rand_54 = rand()%72, rand_55 = rand()%72,
    rand_56 = rand()%72, rand_57 = rand()%72, rand_58 = rand()%72, rand_59 = rand()%72, rand_60 = rand()%72,
    rand_61 = rand()%72, rand_62 = rand()%72, rand_63 = rand()%72, rand_64 = rand()%72, rand_65 = rand()%72,
    rand_66 = rand()%72, rand_67 = rand()%72, rand_68 = rand()%72, rand_69 = rand()%72, rand_70 = rand()%72,
    rand_71 = rand()%72, rand_72 = rand()%72, rand_73 = rand()%72, rand_74 = rand()%72, rand_75 = rand()%72,
    rand_76 = rand()%72, rand_77 = rand()%72, rand_78 = rand()%72, rand_79 = rand()%72, rand_80 = rand()%72;

    int rand_81 = rand()%72, rand_82 = rand()%72, rand_83 = rand()%72, rand_84 = rand()%72, rand_85 = rand()%72,
        rand_86 = rand()%72, rand_87 = rand()%72, rand_88 = rand()%72, rand_89 = rand()%72, rand_90 = rand()%72,
        rand_91 = rand()%72, rand_92 = rand()%72, rand_93 = rand()%72, rand_94 = rand()%72, rand_95 = rand()%72,
        rand_96 = rand()%72, rand_97 = rand()%72, rand_98 = rand()%72, rand_99 = rand()%72, rand_100 = rand()%72;


    Creature f3_b = Creature(food, rand_1, rand_2, rand()%4, 72, 72, 0);
    Creature f4_b = Creature(food, rand_3, rand_4, rand()%4, 72, 72, 1);
    Creature f5_b = Creature(food, rand_5, rand_6, rand()%4, 72, 72, 2);
    Creature f6_b = Creature(food, rand_7, rand_8, rand()%4, 72, 72, 3);
    Creature f7_b = Creature(food, rand_9, rand_10, rand()%4, 72, 72, 4);
    Creature f8_b = Creature(food, rand_11, rand_12, rand()%4, 72, 72, 5);
    Creature f9_b = Creature(food, rand_13, rand_14, rand()%4, 72, 72, 6);
    Creature f10_b = Creature(food, rand_15, rand_16, rand()%4, 72, 72, 7);
    Creature f11_b = Creature(food, rand_17, rand_18, rand()%4, 72, 72, 8);
    Creature f12_b = Creature(food, rand_19, rand_20, rand()%4, 72, 72, 9);

    Creature h6_b = Creature(hopper, rand_21, rand_22, rand()%4, 72, 72, 10);
    Creature h7_b = Creature(hopper, rand_23, rand_24, rand()%4, 72, 72, 11);
    Creature h8_b = Creature(hopper, rand_25, rand_26, rand()%4, 72, 72, 12);
    Creature h9_b = Creature(hopper, rand_27, rand_28, rand()%4, 72, 72, 13);
    Creature h10_b = Creature(hopper, rand_29, rand_30, rand()%4, 72, 72, 14);
    Creature h11_b = Creature(hopper, rand_31, rand_32, rand()%4, 72, 72, 15);
    Creature h12_b = Creature(hopper, rand_33, rand_34, rand()%4, 72, 72, 16);
    Creature h13_b = Creature(hopper, rand_35, rand_36, rand()%4, 72, 72, 17);
    Creature h14_b = Creature(hopper, rand_37, rand_38, rand()%4, 72, 72, 18);
    Creature h15_b = Creature(hopper, rand_39, rand_40, rand()%4, 72, 72, 19);

    Creature t3_b = Creature(trap, rand_41, rand_42, rand()%4, 72, 72, 20);
    Creature t4_b = Creature(trap, rand_43, rand_44, rand()%4, 72, 72, 21);
    Creature t5_b = Creature(trap, rand_45, rand_46, rand()%4, 72, 72, 22);
    Creature t6_b = Creature(trap, rand_47, rand_48, rand()%4, 72, 72, 23);
    Creature t7_b = Creature(trap, rand_49, rand_50, rand()%4, 72, 72, 24);
    Creature t8_b = Creature(trap, rand_51, rand_52, rand()%4, 72, 72, 25);
    Creature t9_b = Creature(trap, rand_53, rand_54, rand()%4, 72, 72, 26);
    Creature t10_b = Creature(trap, rand_55, rand_56, rand()%4, 72, 72, 27);
    Creature t11_b = Creature(trap, rand_57, rand_58, rand()%4, 72, 72, 28);
    Creature t12_b = Creature(trap, rand_59, rand_60, rand()%4, 72, 72, 29);

    Creature r2_b = Creature(rover, rand_61, rand_62, rand()%4, 72, 72, 30);
    Creature r3_b = Creature(rover, rand_63, rand_64, rand()%4, 72, 72, 31);
    Creature r4_b = Creature(rover, rand_65, rand_66, rand()%4, 72, 72, 32);
    Creature r5_b = Creature(rover, rand_67, rand_68, rand()%4, 72, 72, 33);
    Creature r6_b = Creature(rover, rand_69, rand_70, rand()%4, 72, 72, 34);
    Creature r7_b = Creature(rover, rand_71, rand_72, rand()%4, 72, 72, 35);
    Creature r8_b = Creature(rover, rand_73, rand_74, rand()%4, 72, 72, 36);
    Creature r9_b = Creature(rover, rand_75, rand_76, rand()%4, 72, 72, 37);
    Creature r10_b = Creature(rover, rand_77, rand_78, rand()%4, 72, 72, 38);
    Creature r11_b = Creature(rover, rand_79, rand_80, rand()%4, 72, 72, 39);

    Creature b2_b = Creature(best, rand_81, rand_82, rand()%4, 72, 72, 40);
    Creature b3_b = Creature(best, rand_83, rand_84, rand()%4, 72, 72, 41);
    Creature b4_b = Creature(best, rand_85, rand_86, rand()%4, 72, 72, 42);
    Creature b5_b = Creature(best, rand_87, rand_88, rand()%4, 72, 72, 43);
    Creature b6_b = Creature(best, rand_89, rand_90, rand()%4, 72, 72, 44);
    Creature b7_b = Creature(best, rand_91, rand_92, rand()%4, 72, 72, 45);
    Creature b8_b = Creature(best, rand_93, rand_94, rand()%4, 72, 72, 46);
    Creature b9_b = Creature(best, rand_95, rand_96, rand()%4, 72, 72, 47);
    Creature b10_b = Creature(best, rand_97, rand_98, rand()%4, 72, 72, 48);
    Creature b11_b = Creature(best, rand_99, rand_100, rand()%4, 72, 72, 49);

    darwin = Darwin(72, 72);
    darwin.add_creature(f3_b, rand_1, rand_2);
    darwin.add_creature(f4_b, rand_3, rand_4);
    darwin.add_creature(f5_b, rand_5, rand_6);
    darwin.add_creature(f6_b, rand_7, rand_8);
    darwin.add_creature(f7_b, rand_9, rand_10);
    darwin.add_creature(f8_b, rand_11, rand_12);
    darwin.add_creature(f9_b, rand_13, rand_14);
    darwin.add_creature(f10_b, rand_15, rand_16);
    darwin.add_creature(f11_b, rand_17, rand_18);
    darwin.add_creature(f12_b, rand_19, rand_20);

    darwin.add_creature(h6_b, rand_21, rand_22);
    darwin.add_creature(h7_b, rand_23, rand_24);
    darwin.add_creature(h8_b, rand_25, rand_26);
    darwin.add_creature(h9_b, rand_27, rand_28);
    darwin.add_creature(h10_b, rand_29, rand_30);
    darwin.add_creature(h11_b, rand_31, rand_32);
    darwin.add_creature(h12_b, rand_33, rand_34);
    darwin.add_creature(h13_b, rand_35, rand_36);
    darwin.add_creature(h14_b, rand_37, rand_38);
    darwin.add_creature(h15_b, rand_39, rand_40);

    darwin.add_creature(t3_b, rand_41, rand_42);
    darwin.add_creature(t4_b, rand_43, rand_44);
    darwin.add_creature(t5_b, rand_45, rand_46);
    darwin.add_creature(t6_b, rand_47, rand_48);
    darwin.add_creature(t7_b, rand_49, rand_50);
    darwin.add_creature(t8_b, rand_51, rand_52);
    darwin.add_creature(t9_b, rand_53, rand_54);
    darwin.add_creature(t10_b, rand_55, rand_56);
    darwin.add_creature(t11_b, rand_57, rand_58);
    darwin.add_creature(t12_b, rand_59, rand_60);

    darwin.add_creature(r2_b, rand_61, rand_62);
    darwin.add_creature(r3_b, rand_63, rand_64);
    darwin.add_creature(r4_b, rand_65, rand_66);
    darwin.add_creature(r5_b, rand_67, rand_68);
    darwin.add_creature(r6_b, rand_69, rand_70);
    darwin.add_creature(r7_b, rand_71, rand_72);
    darwin.add_creature(r8_b, rand_73, rand_74);
    darwin.add_creature(r9_b, rand_75, rand_76);
    darwin.add_creature(r10_b, rand_77, rand_78);
    darwin.add_creature(r11_b, rand_79, rand_80);

    darwin.add_creature(b2_b, rand_81, rand_82);
    darwin.add_creature(b3_b, rand_83, rand_84);
    darwin.add_creature(b4_b, rand_85, rand_86);
    darwin.add_creature(b5_b, rand_87, rand_88);
    darwin.add_creature(b6_b, rand_89, rand_90);
    darwin.add_creature(b7_b, rand_91, rand_92);
    darwin.add_creature(b8_b, rand_93, rand_94);
    darwin.add_creature(b9_b, rand_95, rand_96);
    darwin.add_creature(b10_b, rand_97, rand_98);
    darwin.add_creature(b11_b, rand_99, rand_100);

    rounds = 1000;
    turn = 0;

    while(turn <= rounds) {
        if((turn < 10 )|| (turn%100 == 0))
            darwin.print_board(cout, turn);
        darwin.play();
        ++turn;
    }

    return 0;}

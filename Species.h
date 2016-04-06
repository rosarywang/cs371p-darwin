#ifndef Species_h
#define Species_h

using namespace std;

class Species {
private:
	// FRIEND_TEST(DarwinSpecies, add_instruction_1);
	// FRIEND_TEST(DarwinSpecies, add_instruction_2);
	// FRIEND_TEST(DarwinSpecies, add_instruction_3);
	int instructions[15];
	int index;
	char initial;

public:
	Species() {}

	Species(char c){
		this->index = 0;
		this->initial = c;
	}

	Species(const Species& s){
		this->initial = s.initial;
		for (int i = 0; i < 15; ++i)
			this->instructions[i] = s.instructions[i];
	}

	bool operator == (Species s) {
		return this->initial == s.initial;
	}

	int operator [] (int pc) {
		return this->instructions[pc];
	}

	char get_initial(){
		return this->initial;
	}

	void add_instruction(int instruction, int n){
		//hop 0
		//left 1
		//right 2
		//infect 3

		//if_empty 4
		//if_wall 5
		//if_random 6
		//if_enemy 7
		//go 8

		if (instruction > 3) {
			this->instructions[index] = instruction+n*10;
		} else {
			this->instructions[index] = instruction;
		}
		++this->index;
	}

};

#endif
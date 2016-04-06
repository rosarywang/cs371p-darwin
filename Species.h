using namespace std;

class Species {
private:
	int instructions[15];
	int index;
	char initial;

public:
	Species() {}

	Species(char c){
		index = 0;
		initial = c;
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

	void addInstruction(int instruction, int n){
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
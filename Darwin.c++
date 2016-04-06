using namespace std;

#include "Darwin.h"

	Darwin::Darwin(){
	}

	Darwin::Darwin(int rows, int cols) {
		this->rows = rows;
		this->cols = cols;
		this->creatures.resize(rows*cols);
		this->board.resize(rows, vector<int>(cols , -1));
	}

	void Darwin::add_creature(Creature& c, int row, int col){
		this->creatures[c.get_index()] = c;
		this->board[row][col] = c.get_index();
	}

	vector<vector<int>>::iterator Darwin::begin() {
		return this->board.begin();
	}

	vector<vector<int>>::iterator Darwin::end() {
		return this->board.end();
	}

	const Creature& Darwin::at(int row, int col) {
		return this->creatures[this->board[row][col]];
	}

	bool Darwin::is_wall(int r, int c, int d) {
		switch(d){
			case 0:
				if(r == 0)
					return true;
			case 1:
				if(c == this->cols-1)
					return true;
			case 2:
				if(r == this->rows-1)
					return true;
			case 3:
				if(c == 0)
					return true;
			default:
					return false;
		}
		return false;
	}

	bool Darwin::is_empty(int r, int c, int d){
		if(!is_wall(r, c, d)) {
			switch(d) {
				case 0: 
					if(this->board[r-1][c] == -1)
						return true;
				case 1: 
					if(this->board[r][c+1] == -1)
						return true;
				case 2: 
					if(this->board[r+1][c] == -1)
						return true;
				case 3: 
					if(this->board[r][c-1] == -1)
						return true;
			}
		}
		return false;
	}

	bool Darwin::is_enemy(Creature& creature, int r, int c, int d){
		if(!is_wall(r, c, d)) {
			switch(d) {
				case 0: 
					return !creature.check_same_species(this->creatures[this->board[r-1][c]]);
				case 1: 
					return !creature.check_same_species(this->creatures[this->board[r][c+1]]);
				case 2: 
					return !creature.check_same_species(this->creatures[this->board[r+1][c]]);
				case 3: 
					return !creature.check_same_species(this->creatures[this->board[r][c-1]]);
			}
		}
		return false;
	}

	Creature& Darwin::get_enemy(Creature& creature, int r, int c, int d) {
		switch(d) {
			case 0: 
				return this->creatures[this->board[r-1][c]];
			case 1: 
				return this->creatures[this->board[r][c+1]];
			case 2: 
				return this->creatures[this->board[r+1][c]];
			case 3: 
				return this->creatures[this->board[r][c-1]];
		}
		return creature;
	}

	void Darwin::update_board(Creature& creature, int oldR, int oldC, int newR, int newC) {
		board[oldR][oldC] = -1;
		board[newR][newC] = creature.get_index();
		creatures[creature.get_index()] = creature;
	}

	void Darwin::play() {
		for (int i = 0; i < this->rows; ++i)
			for (int j = 0; j < this->cols; ++j)
				if(this->board[i][j] != -1) 
					this->creatures[this->board[i][j]].read_instruction(this);
	}

	void Darwin::print_board(int turn) {
		cout << "Turn = " << turn << "." <<endl;
		cout << "  ";
		for(int k = 0; k < this->cols; ++k) {
			cout << k;
		}
		cout << endl;
		char c;
		for (int i = 0; i < this->rows; ++i) {
			cout << i << " ";
			for (int j = 0; j < this->cols; ++j) {
				if(this->board[i][j] == -1) 
					cout << ".";
				else {
					c = this->creatures[this->board[i][j]].get_species();
					this->creatures[this->board[i][j]].reset_moved();
					cout << c;
				}
			}
			cout << endl;
		}
		cout << endl;
	}


using namespace std;

#include "Darwin.h"

	Darwin::Darwin(){
	}

	Darwin::Darwin(int rows, int cols) {
		this->rows = rows;
		this->cols = cols;
		this->creatures.resize(rows*cols);
		this->board.resize(cols, vector<int>(rows , -1));
	}

	void Darwin::add_creature(Creature& c, int row, int col){
		this->creatures[c.get_index()] = c;
		this->board[row][col] = c.get_index();
	}

	// Creature Darwin::infect(Creature& c){
	// 	return null;
	// }

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
				if(c > 0)
					return false;
			case 1:
				if(r < this->rows-1)
					return false;
			case 2:
				if(c < this->cols-1)
					return false;
			case 3:
				if(r > 0)
					return false;
			default:
					return true;
		}
		return true;
	}

	bool Darwin::is_empty(int r, int c, int d){
		// cout << r << " " << c << " " << d << endl;
		// for (int i = 0; i < this->rows; ++i) {
		// 	cout << i << " ";
		// 	for (int j = 0; j < this->cols; ++j) {
		// 		cout << this->board[i][j];
		// 	}
		// 	cout << endl;
		// }
		// cout << endl;
		if(!is_wall(r, c, d)) {
			switch(d) {
				case 0: 

					if(this->board[r-1][c] == -1)
						return true;
				case 1: 
					if(this->board[r][c+1] < 0)
						return true;
				case 2: 
					if(this->board[r+1][c] < 0)
						return true;
				case 3: 
					if(this->board[r][c-1] < 0)
						return true;
				default:
					return false;
			}
		}
		return false;
	}

	bool Darwin::is_enemy(Creature& creature, int r, int c, int d){
		if(!is_empty(r, c, d)) {
			switch(d) {
				case 0: 
					if(creature.checkSameSpecies(this->creatures[this->board[r-1][c]]))
						return true;
				case 1: 
					if(creature.checkSameSpecies(this->creatures[this->board[r][c+1]]))
						return true;
				case 2: 
					if(creature.checkSameSpecies(this->creatures[this->board[r+1][c]]))
						return true;
				case 3: 
					if(creature.checkSameSpecies(this->creatures[this->board[r][c-1]]))
						return true;
				default:
					return false;
			}
		}
		return false;
	}

	void Darwin::update_board(Creature& creature, int oldR, int oldC, int newR, int newC) {
		board[oldR][oldC] = -1;
		board[newR][newC] = creature.get_index();
		// this->creatures[creature*] = creature;
	}

	void Darwin::play() {
		for(int i = 0; i < (int)this->creatures.size(); ++i) {
			this->creatures[i].readInstruction(this);
		}
		for(int i = 0; i < (int)this->creatures.size(); ++i) 
			this->creatures[i].reset_moved();
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
					cout << c;
				}
			}
			cout << endl;
		}
		cout << endl;
	}


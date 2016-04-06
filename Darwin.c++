using namespace std;

#include "Darwin.h"

	Darwin::Darwin(int rows, int cols) {
		this->rows = rows;
		this->cols = cols;
		this->creatures.resize(rows*cols);
		this->board.resize(cols, vector<int>(rows , -1));
	}

	void Darwin::add_creature(Creature& c, int row, int col){
		creatures[c.index] = c;
		board[row][col] = c.index;
	}

	// Creature Darwin::infect(Creature& c){
	// 	return null;
	// }

	vector<vector<int>>::iterator Darwin::begin() {
		return board.begin();
	}

	vector<vector<int>>::iterator Darwin::end() {
		return board.end();
	}

	const Creature& Darwin::at(int rows, int cols) {
		return creatures[board[rows][cols]];
	}

	bool Darwin::is_wall(int r, int c, int d) {
		switch(d){
			case 0:
				if(r > 0)
					return false;
			case 1:
				if(c < cols-1)
					return false;
			case 2:
				if(r < rows-1)
					return false;
			case 3:
				if(c > 0 )
					return false;
			default:
					return true;
		}
		return true;
	}

	bool Darwin::is_empty(int r, int c, int d){
		if(!is_wall(r, c, d)) {
			switch(d) {
				case 0: 
					if(board[r-1][c] < 0)
						return true;
				case 1: 
					if(board[r][c+1] < 0)
						return true;
				case 2: 
					if(board[r+1][c] < 0)
						return true;
				case 3: 
					if(board[r][c-1] < 0)
						return true;
				default:
					return false;
			}
		}
		return false;
	}

	bool Darwin::is_enemy(Creature* creature, int r, int c, int d){
		if(!is_empty(r, c, d)) {
			switch(d) {
				case 0: 
					if(creature->checkSameSpecies(creatures[board[r-1][c]]))
						return true;
				case 1: 
					if(creature->checkSameSpecies(creatures[board[r][c+1]]))
						return true;
				case 2: 
					if(creature->checkSameSpecies(creatures[board[r+1][c]]))
						return true;
				case 3: 
					if(creature->checkSameSpecies(creatures[board[r][c-1]]))
						return true;
				default:
					return false;
			}
		}
		return false;
	}

	void Darwin::update_board(Creature& creature, int oldR, int oldC, int newR, int newC) {
		board[oldR][oldC] = -1;
		board[newR][newC] = creature.index;
		creatures[creature.index] = creature;
	}

	void Darwin::play() {
		for(int i = 0; i < (int)creatures.size(); ++i) {
			creatures[i].readInstruction(this);
		}
		for(int i = 0; i < (int)creatures.size(); ++i) 
			creatures[i].reset_moved();

	}

	void Darwin::print_board(int turn) {
		cout << "Turn = " << turn << "." <<endl;
		cout << "  ";
		for(int k = 0; k < cols; ++k) {
			cout << k;
		}
		cout << endl;
		char c;
		for (int i = 0; i < rows; ++i) {
			cout << i << " ";
			for (int j = 0; j < cols; ++j) {
				if(board[i][j] == -1) 
					cout << ".";
				else {
					c = creatures[board[i][j]].get_species();
					cout << c;
				}
			}
			cout << endl;
		}
		cout << endl;
	}


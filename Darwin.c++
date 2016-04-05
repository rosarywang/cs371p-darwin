using namespace std;

#include "Darwin.h"

	Darwin::Darwin(int rows, int cols) {
		this->rows = rows;
		this->cols = cols;
		this->board.resize(cols, vector<int>(rows , -1));
	}

	void Darwin::addCreature(Creature* c, int row, int col){
		creatures.push_back(*c);
		board[row][col] = creatures.size()-1;
	}

	// Creature Darwin::infect(Creature c){
	// 	return null;
	// }

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

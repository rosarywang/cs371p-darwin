#include "Darwin.h"

using namespace std;

	// ------------
	// constructors
	// ------------

	Darwin::Darwin(){
	}

	Darwin::Darwin(int rows, int cols) {
		assert(rows > -1);
		assert(cols > -1);

		this->rows = rows;
		this->cols = cols;
		this->creatures.resize(rows*cols);
		this->board.resize(rows, vector<int>(cols , -1));
	}

	// ------------
	// add_creature
	// ------------

	void Darwin::add_creature(Creature& c, int row, int col){
		assert(row > -1);
		assert(row < this->rows);
		assert(col > -1);
		assert(col < this->cols);
		
		this->creatures[c.get_index()] = c;
		this->board[row][col] = c.get_index();
	}

	// -----
	// begin
	// -----

	vector<vector<int>>::iterator Darwin::begin() {
		return this->board.begin();
	}

	// ---
	// end
	// ---

	vector<vector<int>>::iterator Darwin::end() {
		return this->board.end();
	}

	// --
	// at
	// --

	const Creature& Darwin::at(int row, int col) {
		assert(row > -1);
		assert(row < this->rows);
		assert(col > -1);
		assert(col < this->cols);

		if(this->board[row][col]>-1)
			return this->creatures[this->board[row][col]];
		else
			throw out_of_range ("index out of bound");
	}

	// -------
	// is_wall
	// -------

	bool Darwin::is_wall(int r, int c, int d) {
		assert(r > -1);
		assert(r < this->rows);
		assert(c > -1);
		assert(c < this->cols);
		assert(d > -1);
		assert(d < 4);

		switch(d){
			case 1:
				if(r == 0)
					return true;
				break;
			case 2:
				if(c == this->cols-1)
					return true;
				break;
			case 3:
				if(r == this->rows-1)
					return true;
				break;
			case 0:
				if(c == 0)
					return true;
				break;
			default:
					return false;
		}
		return false;
	}

	// --------
	// is_empty
	// --------

	bool Darwin::is_empty(int r, int c, int d){
		assert(r > -1);
		assert(r < this->rows);
		assert(c > -1);
		assert(c < this->cols);
		assert(d > -1);
		assert(d < 4);

		if(!is_wall(r, c, d)) {
			switch(d) {
				case 1: 
					if(this->board[r-1][c] != -1)
						return false;
					break;
				case 2: 
					if(this->board[r][c+1] != -1)
						return false;
					break;
				case 3: 
					if(this->board[r+1][c] != -1)
						return false;
					break;
				case 0: 
					if(this->board[r][c-1] != -1)
						return false;
					break;
			}
		}
		return true;
	}

	// --------
	// is_enemy
	// --------

	bool Darwin::is_enemy(Creature& creature, int r, int c, int d){
		assert(r > -1);
		assert(r < this->rows);
		assert(c > -1);
		assert(c < this->cols);
		assert(d > -1);
		assert(d < 4);

		if(!is_empty(r, c, d)&&!is_wall(r, c, d)) {
			switch(d) {
				case 1: 
					return !creature.check_same_species(this->creatures[this->board[r-1][c]]);
				case 2: 
					return !creature.check_same_species(this->creatures[this->board[r][c+1]]);
				case 3: 
					return !creature.check_same_species(this->creatures[this->board[r+1][c]]);
				case 0: 
					return !creature.check_same_species(this->creatures[this->board[r][c-1]]);
			}
		}
		return false;
	}

	// ---------
	// get_enemy
	// ---------

	Creature& Darwin::get_enemy(Creature& creature, int r, int c, int d) {
		assert(r > -1);
		assert(r < this->rows);
		assert(c > -1);
		assert(c < this->cols);
		assert(d > -1);
		assert(d < 4);

		switch(d) {
			case 1: 
				return this->creatures[this->board[r-1][c]];
			case 2: 
				return this->creatures[this->board[r][c+1]];
			case 3: 
				return this->creatures[this->board[r+1][c]];
			case 0: 
				return this->creatures[this->board[r][c-1]];
		}
		return creature;
	}

	// ------------
	// update_board
	// ------------

	void Darwin::update_board(Creature& creature, int oldR, int oldC, int newR, int newC) {
		assert(oldR > -1);
		assert(oldR < this->rows);
		assert(oldC > -1);
		assert(oldC < this->cols);
		assert(newR > -1); 
		assert(newR < this->rows); 
		assert(newC > -1);
		assert(newC < this->cols);

		board[oldR][oldC] = -1;
		board[newR][newC] = creature.get_index();
	}

	// ----
	// play
	// ----

	void Darwin::play() {
		for (int i = 0; i < this->rows; ++i) {
			for (int j = 0; j < this->cols; ++j) {
				if(this->board[i][j] != -1) {
					this->creatures[this->board[i][j]].read_instruction(this);
				}
			}
		}
	}

	// -----------
	// print_board
	// -----------

	void Darwin::print_board(ostream & w, int turn) {
		assert(turn > -1);

		w << "Turn = " << turn << "." <<endl;
		w << "  ";
		for(int k = 0; k < this->cols; ++k) {
			w << k%10;
		}
		w << endl;
		char c;
		for (int i = 0; i < this->rows; ++i) {
			w << i%10 << " ";
			for (int j = 0; j < this->cols; ++j) {
				if(this->board[i][j] == -1) 
					w << ".";
				else {
					c = this->creatures[this->board[i][j]].get_species();
					this->creatures[this->board[i][j]].reset_moved();
					w << c;
				}
			}
			w << endl;
		}
		w << endl;
	}


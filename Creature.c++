#include "Creature.h"

	Creature::Creature(Species sp, int row, int col, int dir, int max_row, int max_col){
		this->sp = sp;
		this->row = row;
		this->col = col;
		this->dir = dir;
		this->pc = 0;
		this->moved = false;
		this->max_row = max_row;
		this->max_col = max_col;
	}

	// int operator [][] 

	//instructions function
	void Creature::readInstruction(Darwin& board){
		if(!moved) {
			int n = sp[pc]/10;
			switch(sp[pc]%10){
				case 0:
					hop();
					break;
				case 1:
					left();
					break;
				case 2:
					right();
					break;
				case 3:
					infect();
					break;
				case 4:
					if_empty(board, n);
					break;
				case 5:
					if_wall(board, n);
					break;
				case 6:
					if_random(board, n);
					break;
				case 7:
					if_enemy(board, n);
					break;
				case 8:
					go(board, n);
					break;
			}
		}
	}

	void Creature::hop(){
		switch(dir){
			case 0:
				if(row > 0)
					--row;
				break;
			case 1:
				if(col < max_col-1)
					++col;
				break;
			case 2:
				if(row < max_row-1)
					++row;
				break;
			case 3:
				if(col > 0 )
					--col;
				break;
		}
		moved = true;
	}

	void Creature::left(){
		dir = (dir+3)%4;
		moved = true;
	}

	void Creature::right(){
		dir = (dir+1)%4;
		moved = true;
	}

	void Creature::infect(){
	// 	bool infect = Darwin::infect(this);
	}

	void Creature::if_empty(Darwin& board, int n){
		bool empty = is_empty(board, row, col, dir);
		if(empty)
			pc = n;
		else
			++pc;
		readInstruction(board);
	}

	void Creature::if_wall(Darwin& board, int n){
		bool wall = is_wall(board, row, col, dir);
		if(wall)
			pc = n;
		else
			++pc;
		readInstruction(board);
	}

	void Creature::if_random(Darwin& board, int n){
		int r = rand();
		if(r % 2 == 0)
			++pc;
		else
			pc = n;
		readInstruction(board);
	}

	void Creature::if_enemy(Darwin& board, int n){
		bool enemy = is_enemy(board, row, col, dir);
		if(enemy)
			pc = n;
		else
			++pc;
		readInstruction(board);
	}

	void Creature::go(Darwin& board, int n){
		pc = n;
		readInstruction(board);
	}

	bool Creature::is_wall(Darwin& board, int r, int c, int d) {
		// switch(d){
		// 	case 0:
		// 		if(r > 0)
		// 			return false;
		// 	case 1:
		// 		if(c < cols-1)
		// 			return false;
		// 	case 2:
		// 		if(r < rows-1)
		// 			return false;
		// 	case 3:
		// 		if(c > 0 )
		// 			return false;
		// 	default:
		// 			return true;
		// }
		return true;
	}
 
	bool Creature::is_empty(Darwin& board, int r, int c, int d) {
		// if(!is_wall(board, r, c, d)) {
		// 	switch(d) {
		// 		case 0: 
		// 			if((r > 0) && (board[r-1][c] < 0))
		// 				return true;
		// 		case 1: 
		// 			if((c < col-1) && (board[r][c+1] < 0))
		// 				return true;
		// 		case 2: 
		// 			if((r < row-1) && (board[r+1][c] < 0))
		// 				return true;
		// 		case 3: 
		// 			if((c > 0) && (board[r][c-1] < 0))
		// 				return true;
		// 		default:
		// 			return false;
		// 	}
		// }
		return false;
	}

	bool Creature::is_enemy(Darwin& board, int r, int c, int d) {
		// if(!is_empty(board, r, c, d)) {
		// 	switch(d) {
		// 		case 0: 
		// 			if(board[r-1][c].s != c.s)
		// 				return true;
		// 		case 1: 
		// 			if(board[r][c+1].s != c.s)
		// 				return true;
		// 		case 2: 
		// 			if(board[r+1][c].s != c.s)
		// 				return true;
		// 		case 3: 
		// 			if(board[r][c-1].s != c.s)
		// 				return true;
		// 		default:
		// 			return false;
		// 	}
		// }
		return false;
	}
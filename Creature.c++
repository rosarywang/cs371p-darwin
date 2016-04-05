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


	bool Creature::checkSameSpecies(Creature c){
		return this->sp == c.sp;
	}

	//instructions function
	void Creature::readInstruction(Darwin* darwin){
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
					if_empty(darwin, n);
					break;
				case 5:
					if_wall(darwin, n);
					break;
				case 6:
					if_random(darwin, n);
					break;
				case 7:
					if_enemy(darwin, n);
					break;
				case 8:
					go(darwin, n);
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
		//update board (put in Darwin)
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

	void Creature::if_empty(Darwin* darwin, int n){
		bool empty = darwin->is_empty(row, col, dir);
		if(empty)
			pc = n;
		else
			++pc;
		readInstruction(darwin);
	}

	void Creature::if_wall(Darwin* darwin, int n){
		bool wall = darwin->is_wall(row, col, dir);
		if(wall)
			pc = n;
		else
			++pc;
		// switch(dir){
		// 	case 0:
		// 		if(row > 0)
		// 			pc = n;
		// 		break;
		// 	case 1:
		// 		if(col < max_col-1)
		// 			pc = n;
		// 		break;
		// 	case 2:
		// 		if(row < max_row-1)
		// 			pc = n;
		// 		break;
		// 	case 3:
		// 		if(col > 0 )
		// 			pc = n;
		// 		break;
		// 	default:
		// 		++pc;
		// }
		readInstruction(darwin);
	}

	void Creature::if_random(Darwin* darwin, int n){
		int r = rand();
		if(r % 2 == 0)
			++pc;
		else
			pc = n;
		readInstruction(darwin);
	}

	void Creature::if_enemy(Darwin* darwin, int n){
		bool enemy = darwin->is_enemy(this, row, col, dir);
		if(enemy)
			pc = n;
		else
			++pc;
		readInstruction(darwin);
	}

	void Creature::go(Darwin* darwin, int n){
		pc = n;
		readInstruction(darwin);
	}